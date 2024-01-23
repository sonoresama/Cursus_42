/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:21 by eorer             #+#    #+#             */
/*   Updated: 2024/01/23 17:48:11 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "irc.hpp"
# include "Client.hpp"

class Client;

class Server 
{
  public:
    Server();
    Server(int port, std::string pwd);
    ~Server();

    int _socket;
    void  run();
    int _port; //in public cause not used
 //   void  handleCommunication();

  private:
    struct  sockaddr_in _address;
    int _epfd;
    std::string  _pwd;
    std::list<Client> _clients;
};

#endif
