/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:57:28 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 16:47:50 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  topic(Server *serv, struct s_message msg, Client& client)
{
  Channel*  channel;
  std::string topic;

  if (msg.params.size() == 0)
  {
    client.reply(ERR_NEEDMOREPARAMS(msg.command));
    return ;
  }
  channel = serv->_getChannel(msg.params[0]);
  if (!channel)
  {
    client.reply(ERR_NOSUCHCHANNEL(client._getNickname(), msg.params[0]));
    return ;
  }
  if (msg.params.size() == 1 && channel->_getTopic().empty())
      client.reply(RPL_NOTOPIC(client._getNickname(), channel->_getName()));
  else if (msg.params.size() == 1 && !channel->_getTopic().empty())
      client.reply(RPL_TOPIC(client._getNickname(), channel->_getName(), channel->_getTopic()));
  else 
  {
    if (!client.is_operator())
    {
      client.reply(ERR_CHANOPRIVSNEEDED(client._getNickname(), channel->_getName()));
      return;
    }
    topic = msg.params[1].substr(1);
    channel->_setTopic(topic);
    channel->broadcast(CMD_TOPIC(client._getNickname(), channel->_getName(), topic));
  }
}
