/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:56:19 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 13:03:34 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "irc.hpp"
# include "Client.hpp"
# include "Server.hpp"

class Client;

class Channel
{
  public:
    Channel();
    Channel(std::string name);
    ~Channel();

    std::string _getName() const;
    std::string _getTopic() const;
    std::string _getNicknames();
    int         _getMode(char mode);
    std::string _getKey();
    int         _getLimit();

    void        _setTopic(std::string topic);
    void        _setLimit(double limit);
    void        _setKey(std::string pwd);
    int         _setMode(char mode, bool value);

    void  broadcast(std::string message);
    void  broadcast(std::string message, Client*client);
    void  addClient(Client* newClient);
    void  addOperator(Client* client);
    bool  deleteClient(Client* client);
    bool  deleteOperator(Client* client);
    bool  is_operator(Client* client);

  private:
    std::string           _name;
    std::string           _topic;
    std::string           _key;
    int                   _limit;
    std::vector<Client*>  _members;
    std::vector<Client*>  _operators;
    std::map<char, bool>  _modes;
};

#endif
