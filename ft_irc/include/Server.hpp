/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:21 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:18:38 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "irc.hpp"
# include "Client.hpp"

# define C_ITERATOR std::vector<Client>::iterator

class Client;
class Channel;

class Server 
{
  public:
    Server();
    Server(int port, std::string pwd);
    ~Server();

    int _socket;
    void  run();
    C_ITERATOR findClient(int socket);
    void  handleNewConnection();
    void  handleSocketError(int socket);

//Test function --> not relevant
    void  wait();

  private:
    struct  sockaddr_in _address;
    int _epfd;
    int _port;
    std::string  _pwd;
    std::vector<Client> _clients;
    std::map<std::string, Channel>  _channels;
};

#endif
