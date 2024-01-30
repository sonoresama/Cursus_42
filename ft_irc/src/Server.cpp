/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:25 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 15:16:43 by eorer            ###   ########.fr       */
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

  _initializeCommands();
  test = 0;
  COUT("Server created");;
}

void  Server::_initializeCommands()
{
  _commands["CAP"] = &cap;
//  _commands["USER"] = &user;
  _commands["PING"] = &ping;
  _commands["JOIN"] = &join;
  _commands["PRIVMSG"] = &privmsg;
  _commands["KICK"] = &kick;
  _commands["PART"] = &part;
  _commands["QUIT"] = &quit;
}

Server::~Server()
{
  close(_socket);
  for (C_ITERATOR it = _clients.begin(); it != _clients.end(); ++it)
  {
    it->closeSocket();
  }
  for (CH_ITERATOR it = _channels.begin(); it != _channels.end(); ++it)
  {
    delete it->second;
  }
  close(_epfd);
}


/*************** Accessors ****************/
std::string Server::_getHostname()
{
  return (_hostname);
}

Channel*  Server::_getChannel(std::string name)
{
  for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
  {
    if (it->second->_getName() == name)
      return (it->second);
  }
  return (NULL);
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

    COUT("Waiting...");
    waitfds = epoll_wait(_epfd, e_recv, maxEvent, -1);
    if (waitfds == -1)
      throw("Error: waiting events on epoll interest list");
    usleep(500); //Optional

    for (int i = 0; i < waitfds; i++)
    {
      if (e_recv[i].events & EPOLLERR || e_recv[i].events & EPOLLHUP)
        handleDeconnection(e_recv[i].data.fd);
      else if (e_recv[i].data.fd == _socket)
        handleNewConnection();
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
  int           fd;
  std::string   answer;
  char          hostname[100];
  struct        epoll_event event;
  socklen_t     addrLen = sizeof(struct sockaddr_in);
  struct        sockaddr_in address;
  
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
}

void  Server::handleCommunication(Client& client)
{
  std::string message;
  struct s_message msg;

  try
  {
    message = readRequest(client);
    if (message.empty())
      return ;
   parseMessage(message, msg);
   executeCommand(client, msg);

   // if (strncmp(message.c_str(), "CAP", 3))
   //   handleDeconnection(client._getSocket());
   // sendWelcome(client, message);
  }
  catch (char const * str)
  {
    throw(str);
  }
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
  for (CH_ITERATOR it = _channels.begin(); it != _channels.end(); it++)
  {
    it->second->deleteClient(*it_client);
  }
  std::cout << "Connection with a client has been lost" << std::endl;
}

std::string Server::readRequest(Client& client)
{
  int         bytesRead;
  char        buffer[512];
  std::string message;

  memset(&buffer, 0, sizeof(buffer));
  bytesRead = recv(client._getSocket(), buffer, sizeof(buffer), MSG_DONTWAIT);
  if (bytesRead == 0)
    handleDeconnection(client._getSocket());
  else if (bytesRead == -1)
  {
    /************************ A RETIRER !!!!!! **********************/
    if (errno == EAGAIN || errno == EWOULDBLOCK)
      return ("");
    else
      throw ("Error: could not read what the client sent");
  }
  else
  {
    COUT("Read -> " + std::string(buffer));
    message.append(buffer);
  }
  return (message);
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

Client*  Server::findClient(std::string nickname)
{
  C_ITERATOR client;

  for (client = _clients.begin(); client != _clients.end(); ++client)
  {
    if (client->_getNickname() == nickname)
      return (&(*client));
  }
  return (NULL);
}

int Server::parseMessage(std::string message, s_message &msg)
{
    std::string tmp = message;

    if (message.empty())
        return (0);
    if (message[0] == ':') //prefixe
	{
		if (message.find(" ") != std::string::npos)
        {
            msg.prefix = message.substr(0, message.find(' '));
			tmp.erase(0, tmp.find_first_of(' ') + 1);
        }
	}
	if (tmp.find(" ") != std::string::npos) //command
	{
		for (size_t i = 0; i < tmp.find(" "); ++i) {
            msg.command += std::toupper(tmp[i]);}
        tmp.erase(0, tmp.find(" ") + 1);
    }
    else
    {
        msg.command = tmp;
        tmp.clear();
    }
    if (tmp.size() > 0) //params
    {
        std::stringstream ss(tmp);
        std::string arg;
        std::string sub;

        while (ss >> arg)
        {
          if (arg[0] == ':')
          {
            arg += " ";
            while (ss >> sub)
              arg += sub + " ";
            msg.params.push_back(arg);
            break;
          }
          msg.params.push_back(arg);
        }
    }
    return (1);
}

void Server::executeCommand(Client &client, s_message msg)
{
  commandFunction f;

  f = _commands[msg.command];
  if (f == 0)
    client.reply(ERR_UNKNOWNCOMMAND(msg.command));
  else
    f(this, msg, client);
}

Channel*  Server::createChannel(std::string name)
{
  Channel* newChannel = new Channel(name);

  _channels[name] = newChannel;
  return (newChannel);
}
/*************** GARBAGE ****************/
