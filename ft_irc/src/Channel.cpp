/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:59:39 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 18:42:11 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Channel.hpp"

/*************** Constructors and destructor ****************/
Channel::Channel(){}

Channel::Channel(std::string name) : _name(name), _topic("default"){}

Channel::~Channel(){}


/*************** Accessors ****************/
std::string Channel::_getName() const
{
  return (this->_name);
}

std::string Channel::_getTopic() const
{
  return (this->_topic);
}

std::string Channel::_getNicknames()
{
  std::string nicknames;

  for (C_ITERATOR it = _members.begin(); it != _members.end(); ++it)
    nicknames.append(it->_getNickname() + " ");
  return (nicknames);
}

/*************** Public Functions ****************/
void  Channel::broadcast(std::string message)
{
  for (C_ITERATOR it = _members.begin(); it != _members.end(); ++it)
  {
    if (send(it->_getSocket(), message.c_str(), strlen(message.c_str()), 0) == -1)
      throw ("Error: pb with send()");
  }
}

void  Channel::broadcast(std::string message, Client& client)
{
  for (C_ITERATOR it = _members.begin(); it != _members.end(); ++it)
  {
    if (it->_getSocket() == client._getSocket())
      continue;
    if (send(it->_getSocket(), message.c_str(), strlen(message.c_str()), 0) == -1)
      throw ("Error: pb with send()");
    CMAGENTA("sent : " + message);
  }
}

void  Channel::addClient(Client& newClient)
{
  _members.push_back(newClient);
  broadcast(RPL_JOIN(newClient._getNickname(), _name));
}
