/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:20 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 14:55:46 by eorer            ###   ########.fr       */
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
    Client(int socket, std::string hostname);
    Client(const Client& cpy);
    ~Client();

      /* Accessors */
    int         _getSocket();
    std::string _getHostname() const;
    std::string _getNickname();
    std::string _getUsername() const;
    std::string _getPrefix();
    Channel*    _getChannel();
    bool        is_fully_registered(void);

    void set_nickname(std::string nickname);
    void set_username(std::string username);
    void set_realname(std::string realname);
    void set_hostname(std::string hostname);
    void set_mode(std::string mode);
    void set_channel(Channel* channel);
    void set_fully_registered(bool fully_registered);
    void set_entered_valid_password(bool entered_valid_password);

      /* Public functions */
    void  closeSocket();
    void  reply(std::string reply);
    void  welcome();

    class InvalidUsernameException : public std::exception {};
	  class InvalidNicknameException : public std::exception {};
	  class NicknameTooLongException : public std::exception {};

  private:
    int         _socket;
    std::string _hostname;
    std::string _nickname;
    std::string _username;
    std::string _realname;
    std::string _mode;
    Channel*    _channel;
    bool        _fully_registered;
    bool        _entered_valid_password;
    bool        _welcome;
};

#endif
