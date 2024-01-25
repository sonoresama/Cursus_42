/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:51 by eorer             #+#    #+#             */
/*   Updated: 2024/01/25 17:06:54 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Client.hpp"

/*************** Constructors and destructor ****************/
Client::Client()
{
 // CGREEN("A client has been created");
}

Client::Client(int socket, std::string hostname) : _hostname(hostname), _socket(socket) 
{
//  CGREEN("A client has been created");
}

Client::Client(const Client& cpy)
{
  _nickname = cpy._nickname;
  _hostname = cpy._hostname;
  _username = cpy._username;
  _socket = cpy._socket;
}

Client::~Client()
{
//  CGREEN("Client destroyed");
}

/*************** Accessors ****************/
std::string Client::_getHostname()
{
  return (_hostname);
}

std::string Client::_getNickname()
{
  return (_nickname);
}

std::string Client::_getUsername()
{
  return (_username);
}

int Client::_getSocket()
{
  return (_socket);
}

void  Client::closeSocket()
{
  if (close(_socket) == -1)
    throw ("Error: could not close client socket");
}
