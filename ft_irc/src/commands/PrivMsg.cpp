/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivMsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:59 by eorer             #+#    #+#             */
/*   Updated: 2024/02/05 17:12:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/irc.hpp"

void  privmsg(Server *serv, t_msg msg, Client* client)
{
  std::string target = msg.params[0];
  std::string prefix = client->_getPrefix();
  std::string message;
  Channel *channel;

  if (msg.params.empty())
    client->reply(ERR_NEEDMOREPARAMS(client->_getNickname(), msg.command));
  else if (target[0] != '&' && target[0] != '#')
  {
    Client*  dest = serv->findClient(target);
    if (!dest)
      client->reply(ERR_NOSUCHNICK(client->_getNickname(), target));
    else
      dest->reply(RPL_PRIVMSG(prefix, dest->_getNickname(), msg.params[1].substr(1)));
  }
  else
  {
    channel = serv->_getChannel(target);
    if (!channel)
      client->reply(ERR_NOSUCHCHANNEL(client->_getNickname(), target));
    else if (!client->_getChannel() || client->_getChannel()->_getName() != channel->_getName())
      client->reply(ERR_CANNOTSENDTOCHAN(client->_getNickname(), channel->_getName()));
    else
      channel->broadcast(RPL_PRIVMSG(prefix, channel->_getName(), (msg.params[1][0] == ':' ? msg.params[1].substr(1) : msg.params[1])), client);
  }
}
