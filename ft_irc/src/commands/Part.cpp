/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:52 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 16:59:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/irc.hpp"

void  part(Server *serv, t_msg msg, Client* client)
{
  std::string reason = msg.params.size() > 1 ? msg.params[1].substr(1) : "No reason";
  std::string prefix = client->_getPrefix();
  Channel *channel;

  if (msg.params.empty())
  {
    client->reply(ERR_NEEDMOREPARAMS(client->_getNickname(), msg.command));
    return ;
  }
  channel = serv->_getChannel(msg.params[0]);
  if (!channel || !client->_getChannel())
    client->reply(ERR_NOSUCHCHANNEL(client->_getNickname(), msg.params[0]));
  else
  {
    if (client->_getChannel()->_getName() != channel->_getName())
      client->reply(ERR_NOTONCHANNEL(client->_getNickname(), channel->_getName()));
    else
    {
      channel->broadcast(RPL_PART(prefix, channel->_getName(), reason));
      client->reply(RPL_PART(prefix, channel->_getName(), reason));
      channel->deleteClient(client);
  //    channel->broadcast(RPL_NAMREPLY(serv->_getHostname(), channel->_getName(), channel->_getNicknames()));
  //    channel->broadcast(RPL_ENDOFNAMES(serv->_getHostname(), channel->_getName()));
    }
  }
}
