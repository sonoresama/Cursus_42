/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:56:19 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:24:14 by eorer            ###   ########.fr       */
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

    void  broadcast(char* message);
    void  sendMsg(char* message, Client& client);
    void  addClient(const Client& newClient);
    std::string _getName();

  private:
    std::string _name;
    std::vector<Client> _members;
};

#endif
