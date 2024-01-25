/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:20 by eorer             #+#    #+#             */
/*   Updated: 2024/01/25 16:58:16 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "irc.hpp"

# define HOST_LEN 100

class Client
{
  public :
    Client();
    Client(const Client& cpy);
    Client(int socket, std::string hostname);
    ~Client();

      /* Accessors */
    int         _getSocket();
    std::string _getHostname();
    std::string _getNickname();
    std::string _getUsername();

      /* Public functions */
    void  closeSocket();
    // A passer en prive par la suite
    struct  sockaddr_in _address;

  private:
    std::string _nickname;
    std::string _username;
    std::string _hostname;
    int _socket;

};

#endif
