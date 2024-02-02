/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:50:11 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 17:20:33 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/irc.hpp"

void  join(Server *serv, t_msg msg, Client* client)
{
  std::string tmp;
  std::vector<std::string>  channels;
  std::stringstream ss(msg.params[0]);

  if (msg.params.empty())
  {
    client->reply(ERR_NEEDMOREPARAMS(client->_getNickname(), msg.command));
    return ;
  }
  while (std::getline(ss, tmp, ','))
    channels.push_back(tmp);
  for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
  {
    Channel* channel = serv->_getChannel(*it);
   // if (*it->begin() != '#' || *it->begin() != '&')
   // {
   //   COUT("JIUGGFUJFKVKU");
   //   continue;
   // }
    if (!channel)
    {
      channel = serv->createChannel(*it);
      channel->addClient(client);
      channel->addOperator(client);
    }
    else
      channel->addClient(client);
    client->set_channel(channel);
    if (channel->_getTopic().empty())
      client->reply(RPL_NOTOPIC(serv->_getHostname(), client->_getNickname(), channel->_getName()));
    else
      client->reply(RPL_TOPIC(serv->_getHostname(), client->_getNickname(), channel->_getName(), channel->_getTopic()));
    client->reply(RPL_NAMREPLY(serv->_getHostname(), client->_getNickname(), channel->_getName(), channel->_getNicknames()));
    client->reply(RPL_ENDOFNAMES(serv->_getHostname(), client->_getNickname(), channel->_getName()));
    channel->broadcast(RPL_JOIN(client->_getPrefix(), channel->_getName()));
  }
}
