/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:51 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 19:05:05 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Client.hpp"

/*************** Constructors and destructor ****************/
Client::Client()
{
 // CGREEN("A client has been created");
}

Client::Client(int socket, std::string hostname) : _socket(socket), _hostname(hostname), _fully_registered(false)
{
//  CGREEN("A client has been created");
}

Client::~Client()
{
//  CGREEN("Client destroyed");
}

Client::Client(const Client& cpy)
{
  _nickname = cpy._nickname;
  _hostname = cpy._hostname;
  _username = cpy._username;
  _socket = cpy._socket;
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

void Client::set_username( std::string username )
{
	if (is_valid_username(username))
	{
		_username = username;
	}
	else
		throw InvalidUsernameException();
}

void Client::set_nickname(std::string nickname)
{
	if (is_valid_nickname(nickname))
	{
		_nickname = nickname;
	}
	else
		throw InvalidNicknameException();
}

void	Client::set_channel(Channel *channel)
{
	_channel = channel;
}

/************** Public Funcitons ****************/
int Client::is_valid_username( std::string username )
{
	const std::string rejected_chars = "@._";

	if (std::isdigit(username[0]))
		return (0);
	for (size_t i = 0; i < username.size(); i++)
	{
		if (!std::isalnum(username[i]) && rejected_chars.find(username[0]) != std::string::npos)
			return (0);
	}
	return (1);
}

int Client::is_valid_nickname(std::string nickname)
{
    const std::string special_chars = "_\\^|[]{}`";

    if (!(nickname.size() >= 1 && nickname.size() <= 9))
        throw NicknameTooLongException();
    if (!std::isalpha(nickname[0]) && special_chars.find(nickname[0]) == std::string::npos)
        return (0);
    for (size_t i = 1; i < nickname.size(); i++)
    {
        if (!std::isalnum(nickname[i]) && special_chars.find(nickname[i]) == std::string::npos && nickname[i] != '-')
            return (0);
    }
    return (1);
}

bool Client::is_fully_registered(void)
{
	if (_nickname.empty() || _username.empty())
		_fully_registered = true;
	return (_fully_registered);
}

void  Client::closeSocket()
{
  if (close(_socket) == -1)
    throw ("Error: could not close client socket");
}

void  Client::reply(std::string reply)
{
	reply += "\r\n";
	if (send(_socket, reply.c_str(), strlen(reply.c_str()), 0) == -1)
		throw ("Error: sending response for conenction did not work");
	CMAGENTA("sent -> " + reply);
}
