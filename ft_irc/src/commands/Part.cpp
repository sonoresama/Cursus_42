/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:52 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 16:43:59 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  part(Server *serv, struct s_message msg, Client& client)
{
  std::string reason = msg.params.size() > 1 ? msg.params[1].substr(1) : "No reason";
  std::string prefix = msg.prefix.empty() ? client._getNickname() : msg.prefix;
  Channel *channel;

  if (msg.params.empty())
  {
    client.reply(ERR_NEEDMOREPARAMS(msg.command));
    return ;
  }
  channel = serv->_getChannel(msg.params[0]);
  if (!channel)
    client.reply(ERR_NOSUCHCHANNEL(client._getNickname(), msg.params[0]));
  else
  {
    if (client._getChannel()->_getName() != channel->_getName())
      client.reply(ERR_NOTONCHANNEL(channel->_getName()));
    else
    {
      channel->deleteClient(client);
      channel->broadcast(RPL_PART(prefix, channel->_getName(), reason));
      client.reply(RPL_PART(prefix, channel->_getName(), reason));
    }
  }
}
