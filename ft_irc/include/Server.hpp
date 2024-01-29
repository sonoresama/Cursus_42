/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:21 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 18:30:37 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "irc.hpp"
# include "Client.hpp"
# include "Commands.hpp"

# define C_ITERATOR std::vector<Client>::iterator
# define CH_ITERATOR std::map<std::string, Channel*>::iterator

typedef void (*commandFunction)(Server*, s_message, Client&);

class Client;
class Channel;
class Commands;

class Server 
{
  public:
    Server();
    Server(int port, std::string pwd);
    ~Server();

    std::string _getHostname();
    Channel* _getChannel(std::string name);

    void  run();
    void  handleCommunication(Client& client);
    void  handleNewConnection();
    void  handleDeconnection(int socket);

    int   parseMessage(std::string message, s_message &msg);
    void  executeCommand(Client& client, s_message msg);
    std::string readRequest(Client& client);
    C_ITERATOR findClient(int socket);
    Client*  findClient(std::string nickname);
    Channel*  createChannel(std::string name);

  private:
    
    void  _initializeCommands();

    struct                                  sockaddr_in _address;
    int                                     _epfd;
    int                                     _port;
    int                                     _socket;
    std::string                             _pwd;
    std::string                             _hostname;
    std::vector<Client>                     _clients;
    std::map<std::string, Channel*>         _channels;
    std::map<std::string, commandFunction>  _commands;
};

#endif
