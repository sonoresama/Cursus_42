/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:58:51 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 16:47:38 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  kick(Server *serv, struct s_message msg, Client& client)
{
  Channel *channel;
  Client* target;
  std::string reason = msg.params.size() > 2 ? msg.params[2].substr(1) : "No reason";
  std::string prefix = msg.prefix.empty() ? client._getNickname() : msg.prefix;

  if (msg.params.size() < 2)
  {
    client.reply(ERR_NEEDMOREPARAMS(msg.command));
    return;
  }
  channel = serv->_getChannel(msg.params[0]);
  if (!channel)
    client.reply(ERR_NOSUCHCHANNEL(client._getNickname(), msg.params[0]));
  else if (!client.is_operator())
    client.reply(ERR_CHANOPRIVSNEEDED(client._getNickname(), channel->_getName()));
  else
  {
    target = serv->findClient(msg.params[1]);
    if (!target || !channel->deleteClient(*target))
      client.reply(ERR_USERNOTINCHANNEL(client._getNickname(), msg.params[1], channel->_getName()));
    else
    {
      channel->broadcast(RPL_KICK(prefix, channel->_getName(), target->_getNickname(), reason));
      target->reply(RPL_KICK(prefix, channel->_getName(), target->_getNickname(), reason));
    }
  }
}
