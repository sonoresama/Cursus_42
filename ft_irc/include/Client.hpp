/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:20 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 17:21:44 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "irc.hpp"

class Channel;

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
    void  set_nickname(std::string nickname);
    void  set_username(std::string username);
    void  set_channel(Channel* channel);

      /* Public functions */
    void  closeSocket();

    int   is_valid_username(std::string username);
    int   is_valid_nickname(std::string username);
    bool  is_fully_registered(void);
    // A passer en prive par la suite
    struct  sockaddr_in _address;

    class InvalidUsernameException : public std::exception {};
	class InvalidNicknameException : public std::exception {};
	class NicknameTooLongException : public std::exception {};

    void  reply(std::string reply);
  private:
    int         _socket;
    std::string _nickname;
    std::string _username;
    std::string _hostname;
    std::string _realname;
    std::string _mode;
    Channel*    _channel;
    bool        _fully_registered;
//    bool  _entered_valid_password;
};

#endif
