/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:56:19 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 16:38:29 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "irc.hpp"

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
    void  _setTopic(std::string topic);

    void  broadcast(std::string message);
    void  broadcast(std::string message, Client& client);
    void  addClient(Client& newClient);
    bool  deleteClient(Client& client);

  private:
    std::string         _name;
    std::string         _topic;
    std::vector<Client> _members;
};

#endif
