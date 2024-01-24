/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:25 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:34:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"
#include <fcntl.h>

/*************** Constructors and destructor ****************/
Server::Server()
{
  COUT("Mets des parametres fdp");
}

Server::Server(int port, std::string pwd) : _port(port), _pwd(pwd)
{
  int opt_value = 1;

  if (port < 0 || port > 65535)
    throw ("Error: port number wrong");
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  if (_socket == -1)
    throw ("Error: Failed to create socket");
  memset(&_address, 0, sizeof(sockaddr_in));
  _address.sin_family = AF_INET;
  _address.sin_port = htons(_port);
  _address.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (_address.sin_addr.s_addr == INADDR_NONE)
    throw ("Error: IP address conversion failed");
  if(setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &opt_value, sizeof(opt_value)) == -1)
    throw ("Error: setsockopt failed");
  if (bind(_socket, reinterpret_cast<struct sockaddr*>(&_address), sizeof(_address)) == -1)
    throw ("Error: failed to bind socket to address");
  if (listen(_socket, 32) == -1)
    throw ("Error: failed to set socket socket as listen");
  COUT("Connexion established");


  /* Creating a new test Channel */
  Channel test("test");
  _channels[test._getName()] = test;
}

Server::~Server()
{
  close(_socket);
  for (C_ITERATOR it = _clients.begin(); it != _clients.end(); ++it)
  {
    close(it->_socket);
  }
  close(_epfd);
}

/*************** Public Functions ****************/
void  Server::run(void)
{
  const int maxEvent = 20;
  struct  epoll_event e_recv[maxEvent];
  struct  epoll_event event;

        //Creation d'une instance epoll
  _epfd = epoll_create(1);
  if (_epfd == -1)
    throw ("Error: failed ot create epoll instance");
  event.events = EPOLLIN | EPOLLHUP | EPOLLERR;
  event.data.fd = _socket;
  if (epoll_ctl(_epfd, EPOLL_CTL_ADD, _socket, &event) == -1)
    throw ("Error: failed to add socketServer to epoll interest list");
  
        //Main loop
  while (true)
  {
    int waitfds;

    waitfds = epoll_wait(_epfd, e_recv, maxEvent, -1);
    if (waitfds == -1)
      throw("Error: waiting events on epoll interest list");
    usleep(500);

    for (int i = 0; i < waitfds; i++)
    {
                      //Handle errors
      if (e_recv[i].events & EPOLLERR || e_recv[i].events & EPOLLHUP)
        handleSocketError(e_recv[i].data.fd);
                    //Handle new connections
      else if (e_recv[i].data.fd == _socket)
        handleNewConnection();
                  //Handle clients events
      else
      {
        int bytesRead;
        char  buffer[300];

        C_ITERATOR speakingClient = findClient(e_recv[i].data.fd);
        if (speakingClient == _clients.end())
          throw ("Error: client not found in database");
        bytesRead = recv(speakingClient->_socket, buffer, sizeof(buffer), MSG_DONTWAIT);
        if (bytesRead == 0)
        {
          std::cout << "Connection with a client has been lost" << std::endl;
          if (epoll_ctl(_epfd, EPOLL_CTL_DEL, speakingClient->_socket, NULL) == -1)
            throw ("Error: failed to del client socket to epoll interest list");
          close(speakingClient->_socket);
          _clients.erase(speakingClient);
        }
        else if (bytesRead == -1)
        {
          if (errno == EAGAIN || errno == EWOULDBLOCK)
            continue;
          else
            throw ("Error: could not read what the client sent");
        }
        else
        {
          _channels["test"].sendMsg(buffer, *speakingClient);
        }
      }
    }
  }
}

void  Server::handleNewConnection()
{
  int fd;
  struct  epoll_event event;
  socklen_t addrLen = sizeof(struct sockaddr_in);
  struct  sockaddr_in address;
  
  fd = accept(_socket, reinterpret_cast<struct sockaddr*>(&address), &addrLen);
  if (fd == -1)
    throw ("Error: failed to accept socket");
  event.events = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLHUP;
  event.data.fd = fd;
  //fcntl(fd, F_SETFL, O_NONBLOCK);
  if (epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &event) == -1)
    throw ("Error: failed to add client socket to epoll interest list");
  _clients.push_back(Client(fd));
  std::cout << "Connection established with client " << _clients.size() << ". Socket is : " << _clients.back()._socket << std::endl;

  /* Adding client to Channel test */
  _channels["test"].addClient(_clients.back());
}

void  Server::handleSocketError(int socket)
{
  C_ITERATOR client = findClient(socket);

  close(client->_socket);
  if (epoll_ctl(_epfd, EPOLL_CTL_DEL, client->_socket, NULL) == -1)
    throw ("Error: failed to del client socket to epoll interest list");
  _clients.erase(client);
  std::cout << "Connection with a client has been lost" << std::endl;
}

C_ITERATOR  Server::findClient(int socket)
{
  C_ITERATOR client;

  for (client = _clients.begin(); client != _clients.end(); ++client)
  {
    if (client->_socket == socket)
      return (client);
  }
  return (client);
}

/*************** GARBAGE ****************/
void  Server::wait()
{
  Client newClient;
  socklen_t addrLen = sizeof(struct sockaddr_in);
  int br;
  char  buffer[200];

  newClient._socket = accept(_socket, reinterpret_cast<struct sockaddr*>(&newClient._address), &addrLen);
  COUT("Connection established");
  while (true)
  {
    br = recv(newClient._socket, buffer, sizeof(buffer), 0);
    if (br == 0)
    {
      COUT("Connection lost");
      return ;
    }
    else if (br == -1)
      throw ("Bad read");
    else
    {
      COUT("  read successful");
      COUT(buffer);
      send(newClient._socket, "Wesh\n", strlen("Wesh\n"), 0);
    }
  }
}

