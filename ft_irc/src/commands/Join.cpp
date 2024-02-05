/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:50:11 by eorer             #+#    #+#             */
/*   Updated: 2024/02/05 18:57:37 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/irc.hpp"

void  join(Server *serv, t_msg msg, Client* client)
{
  std::string tmp;
  int         arg = 0;
  std::vector<std::string>  channels;
  std::vector<std::string>  keys;
  std::stringstream ss(msg.params[0]);

  if (msg.params.empty())
  {
    client->reply(ERR_NEEDMOREPARAMS(client->_getNickname(), msg.command));
    return ;
  }
  while (std::getline(ss, tmp, ','))
    channels.push_back(tmp);
  if (msg.params.size() > 1)
  {
    std::stringstream st(msg.params[1]);
    while (std::getline(st, tmp, ','))
      keys.push_back(tmp);
  }
  for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
  {
    Channel* channel = serv->_getChannel(*it);

    if (!channel)
    {
      if ((*it)[0] != '#' && (*it)[0] != '&')
        return ;
      channel = serv->createChannel(*it);
      if (msg.params.size() > 1)
      {
        channel->_setKey(keys[arg++]);
        channel->_setMode('k', true);
      }
      channel->addOperator(client);
    }
    else if (channel->_getMode('k') && (msg.params.size() < 2 || channel->_getKey().compare(keys[arg++]) != 0))
    {
      client->reply(ERR_BADCHANNELKEY(client->_getNickname(), channel->_getName()));
      return ;
    }
    else if (channel->_getMode('l') && static_cast<int>(channel->_getMembers().size()) >= channel->_getLimit())
    {
      client->reply(ERR_CHANNELISFULL(client->_getNickname(), channel->_getName()));
      return ;
    }
    else if (channel->_getMode('i') && !channel->is_guest(client))
    {
      client->reply(ERR_INVITEONLYCHAN(client->_getNickname(), channel->_getName()));
      return ;
    }

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
