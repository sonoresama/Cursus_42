/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:20 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:32:17 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "irc.hpp"

class Client
{
  public :
    Client();
    Client(int socket);
    ~Client();

    // A passer en prive par la suite
    struct  sockaddr_in _address;
    int _socket;
    std::string _nickname;
    std::string _username;

  private:

};

#endif
