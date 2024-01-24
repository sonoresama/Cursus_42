/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:59:39 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:34:11 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Channel.hpp"

/*************** Constructors and destructor ****************/
Channel::Channel(){}

Channel::Channel(std::string name) : _name(name){}

Channel::~Channel(){}


/*************** Accessors ****************/
std::string Channel::_getName()
{
  return (this->_name);
}


/*************** Public Functions ****************/
void  Channel::sendMsg(char* message, Client& client)
{
  for (C_ITERATOR it = _members.begin(); it != _members.end(); ++it)
  {
    if (it->_socket == client._socket)
      continue;
    if (send(it->_socket, message, strlen(message), 0) == -1)
      throw ("Error: pb with send()");
  }
}

void  Channel::broadcast(char* message)
{
  for (C_ITERATOR it = _members.begin(); it != _members.end(); ++it)
  {
    if (send(it->_socket, message, strlen(message), 0) == -1)
      throw ("Error: pb with send()");
  }
}

void  Channel::addClient(const Client& newClient)
{
  _members.push_back(newClient);
}
