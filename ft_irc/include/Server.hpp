/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:21 by eorer             #+#    #+#             */
/*   Updated: 2024/01/25 17:52:38 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Client.hpp"
# include "irc.hpp"

# define C_ITERATOR std::vector<Client>::iterator

class Client;
class Channel;

class Server 
{
  public:
    Server();
    Server(int port, std::string pwd);
    ~Server();

    void  run();
    void  handleCommunication(Client& client);
    void  handleNewConnection();
    void  sendWelcome(Client& client, std::string message);
    std::string readRequest(Client& client);
    C_ITERATOR findClient(int socket);
    void  handleDeconnection(int socket);

//Test function --> not relevant

  private:
    struct                          sockaddr_in _address;
    int                             _epfd;
    int                             _port;
    int                             _socket;
    std::string                     _pwd;
    std::string                     _hostname;
    std::vector<Client>             _clients;
    std::map<std::string, Channel>  _channels;
};

#endif
