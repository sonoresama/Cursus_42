/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivMsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:59 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 16:46:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  privmsg(Server *serv, struct s_message msg, Client& client)
{
  std::string target = msg.params[0];
  std::string prefix = msg.prefix.empty() ? client._getNickname() : msg.prefix;
  std::string message;
  Channel *channel;

  if (msg.params.empty())
    client.reply(ERR_NEEDMOREPARAMS(msg.command));
  else if (target[0] != '&' && target[0] != '#')
  {
    Client*  dest = serv->findClient(target);
    if (!dest)
      client.reply(ERR_NOSUCHNICK(target));
    dest->reply(RPL_PRIVMSG(prefix, dest->_getNickname(), msg.params[1].substr(1)));
  }
  else
  {
    channel = serv->_getChannel(target);
    if (!channel)
      client.reply(ERR_NOSUCHCHANNEL(client._getNickname(), target));
    else if (!client._getChannel() || client._getChannel()->_getName() != channel->_getName())
      client.reply(ERR_CANNOTSENDTOCHAN(channel->_getName()));
    else
      channel->broadcast(RPL_PRIVMSG(prefix, channel->_getName(), msg.params[1].substr(1)), client);
  }
}
