/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:25 by eorer             #+#    #+#             */
/*   Updated: 2024/01/23 17:53:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server()
{
  COUT("Mets des parametres fdp");
}

Server::Server(int port, std::string pwd) : _port(port), _pwd(pwd)
{
  //handle port error i.e throw exception if port < 0 or port > 65...
  int opt_value = 1;

  _socket = socket(AF_INET, SOCK_STREAM, 0);
  if (_socket == -1)
    throw ("Error: Failed to create socket");
  memset(&_address, 0, sizeof(sockaddr_in));
  _address.sin_family = AF_INET;
  _address.sin_port = htons(4243);
  _address.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (_address.sin_addr.s_addr == INADDR_NONE)
    throw ("Error: IP address conversion failed");
  if(setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &opt_value, sizeof(opt_value)) == -1)
    throw ("Error: setsockopt failed");
  if (bind(_socket, reinterpret_cast<struct sockaddr*>(&_address), sizeof(_address)) == -1)
    throw ("Error: failed to bind socket to address");
  if (listen(_socket, 32) == -1)
    throw ("Error: failed to set socket socket as listen");
  COUT("Server object well constructed");
}

void  Server::run(void)
{
  const int maxEvent = 10;
  struct  epoll_event e_recv[maxEvent];
  struct  epoll_event event;
  socklen_t addrLen = sizeof(struct sockaddr_in);

  _epfd = epoll_create(1);
  if (_epfd == -1)
    throw ("Error: failed ot create epoll instance");
  event.events = EPOLLIN;
  event.data.fd = _socket;
  if (epoll_ctl(_epfd, EPOLL_CTL_ADD, _socket, &event) == -1)
    throw ("Error: failed to add socketServer to epoll interest list");
  
  while (true)
  {
    int waitfds;
    char  buffer[100];

    COUT("Waiting...");
    waitfds = epoll_wait(_epfd, e_recv, maxEvent, -1);
    if (waitfds == -1)
      throw("Error: waiting events on epoll interest list");

    for (int i = 0; i < waitfds; i++)
    {
                   //Handle new connections
      if (e_recv[i].data.fd == _socket)
      {
        Client  newClient;

        newClient._socket = accept(_socket, reinterpret_cast<struct sockaddr*>(&newClient._address), &addrLen);
        if (newClient._socket == -1)
          throw ("Error: failed to accept socket");
        _clients.push_back(newClient);
        event.events = EPOLLIN;
        event.data.fd = newClient._socket;
        if (epoll_ctl(_epfd, EPOLL_CTL_ADD, newClient._socket, &event) == -1)
          throw ("Error: failed to add client socket to epoll interest list");
        std::cout << "Connection established with client " << _clients.size() << std::endl;
      }
                   //Handle clients events
      else
      {
        int bytesRead;

        COUT("HANDLING CLIENT REQUEST");
        std::list<Client>::iterator speakingClient;
        for (speakingClient = _clients.begin(); speakingClient != _clients.end(); ++speakingClient)
        {
          if (speakingClient->_socket == e_recv[i].data.fd)
            break;
        }
        std::cout << "Input from the client " << ntohs(speakingClient->_address.sin_addr.s_addr) << std::endl;
        bytesRead = recv(speakingClient->_socket, buffer, sizeof(buffer), 0);
        if (bytesRead == 0)
        {
          std::cout << "Connection with a client has been lost" << std::endl;
          if (epoll_ctl(_epfd, EPOLL_CTL_DEL, speakingClient->_socket, NULL) == -1)
            throw ("Error: failed to del client socket to epoll interest list");
          close(speakingClient->_socket);
          _clients.erase(speakingClient);
        }
        else if (bytesRead == -1)
          throw ("Error: could not read what the client sent");
        else
        {
          for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
          {
            if (it == speakingClient)
              continue;
            send(it->_socket, buffer, strlen(buffer), 0);
          }
        }
      }
    }
  }
}

Server::~Server()
{
  close(_socket);
  for (std::list<Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
  {
    close(it->_socket);
  }
}
