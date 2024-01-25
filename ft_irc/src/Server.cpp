/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:25 by eorer             #+#    #+#             */
/*   Updated: 2024/01/25 18:22:12 by eorer            ###   ########.fr       */
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
  char hostname[100];

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
  if (getnameinfo(reinterpret_cast<struct sockaddr*>(&_address), sizeof(_address), hostname, 100, NULL, 0, NI_NAMEREQD))
    throw ("Error: getnameinfo");
  _hostname = std::string(hostname);
  COUT("Server created");;


  /* Creating a new test Channel */
  Channel test("test");
  _channels[test._getName()] = test;
}

Server::~Server()
{
  close(_socket);
  for (C_ITERATOR it = _clients.begin(); it != _clients.end(); ++it)
  {
    it->closeSocket();
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

   // COUT("Waiting...");
    waitfds = epoll_wait(_epfd, e_recv, maxEvent, -1);
    if (waitfds == -1)
      throw("Error: waiting events on epoll interest list");
    usleep(500);

    for (int i = 0; i < waitfds; i++)
    {
                      //Handle errors
      if (e_recv[i].events & EPOLLERR || e_recv[i].events & EPOLLHUP)
        handleDeconnection(e_recv[i].data.fd);
                    //Handle new connections
      else if (e_recv[i].data.fd == _socket)
        handleNewConnection();
                  //Handle clients events
      else
      {
        C_ITERATOR it_client = findClient(e_recv[i].data.fd);
        if (it_client == _clients.end())
          throw ("Error: couldn't find client in database");
        handleCommunication(*it_client);
      }
    }
  }
}

void  Server::handleNewConnection()
{
  int fd;
  std::string  answer;
  char  hostname[100];
  struct  epoll_event event;
  socklen_t addrLen = sizeof(struct sockaddr_in);
  struct  sockaddr_in address;
  
  fd = accept(_socket, reinterpret_cast<struct sockaddr*>(&address), &addrLen);
  if (fd == -1)
    throw ("Error: failed to accept socket");
  if (getnameinfo(reinterpret_cast<struct sockaddr*>(&address), addrLen, hostname, 100, NULL, 0, NI_NAMEREQD))
    throw ("Error: getnameinfo");
  event.events = EPOLLIN | EPOLLERR | EPOLLHUP;
  event.data.fd = fd;
  if (epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &event) == -1)
    throw ("Error: failed to add client socket to epoll interest list");
  _clients.push_back(Client(fd, std::string(hostname)));

  std::cout << "Connection established with client " << _clients.back()._getHostname() << ". Socket is : " << _clients.back()._getSocket() << std::endl;

  /* Adding client to Channel test */
  _channels["test"].addClient(_clients.back());
}

void  Server::handleCommunication(Client& client)
{
  std::string message;
  /* std::pair<std::string, std::vector<std::string>> cmd; */

  try
  {
    message = readRequest(client);
    if (message.empty())
      return ;
  /* cmd = parseMessage(message);
   * _execute(cmd.first, cmd.second);*/

    sendWelcome(client, message);
  }
  catch (char const * str)
  {
    CERR(str);
    perror(NULL);
  }
}

std::string Server::readRequest(Client& client)
{
  int         bytesRead;
  char        buffer[300];
  std::string message;

  memset(&buffer, 0, sizeof(buffer));
  bytesRead = recv(client._getSocket(), buffer, sizeof(buffer), MSG_DONTWAIT);
  if (bytesRead == 0)
    handleDeconnection(client._getSocket());
  else if (bytesRead == -1)
  {
    if (errno == EAGAIN || errno == EWOULDBLOCK)
      return ("");
    else
      throw ("Error: could not read what the client sent");
  }
  else
  {
    std::cout << "Read : " << buffer << std::endl;
    message.append(buffer);
  }
  return (message);
}

void  Server::sendWelcome(Client& client, std::string message)
{
  std::string answer;
  
  if (strncmp(message.c_str(), "CAP", 3))
    return;
  answer = ":" + std::string(_hostname) + " 001 eorer :Welcome on Tito's irc server tito!eorer@" + client._getHostname() + "\n";
  if (send(client._getSocket(), answer.c_str(), strlen(answer.c_str()), 0) == -1)
    throw ("Error: sending response for conenction did not work");
  CMAGENTA("Sent reply to client");
  std::cout << "  -> " + answer << std::endl;
}

void  Server::handleDeconnection(int socket)
{
  C_ITERATOR  it_client;

  it_client = findClient(socket);
  if (it_client == _clients.end())
    throw ("Could not find client in database");
  if (epoll_ctl(_epfd, EPOLL_CTL_DEL, it_client->_getSocket(), NULL) == -1)
    throw ("Error: failed to del client socket to epoll interest list");
  it_client->closeSocket();
  _clients.erase(it_client);
  std::cout << "Connection with a client has been lost" << std::endl;
}

C_ITERATOR  Server::findClient(int socket)
{
  C_ITERATOR client;

  for (client = _clients.begin(); client != _clients.end(); ++client)
  {
    if (client->_getSocket() == socket)
      return (client);
  }
  return (client);
}


/*************** GARBAGE ****************/
