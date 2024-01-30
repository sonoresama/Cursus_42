/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:50:11 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 16:18:53 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  join(Server *serv, struct s_message msg, Client& client)
{
  std::string tmp;
  std::vector<std::string>  channels;
  std::stringstream ss(msg.params[0]);

  if (msg.params.empty())
  {
    client.reply(ERR_NEEDMOREPARAMS(msg.command));
    return ;
  }
  while (std::getline(ss, tmp, ','))
    channels.push_back(tmp);
  for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
  {
    Channel* channel = serv->_getChannel(*it);
    if (!channel)
    {
      channel = serv->createChannel(*it);
      channel->addClient(client);
    }
    else
      channel->addClient(client);
    client.set_channel(channel);
    if (channel->_getTopic().empty())
      client.reply(RPL_NOTOPIC(client._getNickname(), channel->_getName()));
    else
      client.reply(RPL_TOPIC(client._getNickname(), channel->_getName(), channel->_getTopic()));
    client.reply(RPL_NAMREPLY(client._getNickname(), channel->_getName(), channel->_getNicknames()));
    client.reply(RPL_ENDOFNAMES(client._getNickname(), channel->_getName()));
  }
}
