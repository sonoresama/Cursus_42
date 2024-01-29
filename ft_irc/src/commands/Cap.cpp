/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:28:45 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 13:26:12 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  cap(Server *serv, struct s_message msg, Client& client)
{
  std::string user = "eorer";
  std::string nick = "tito";

  (void)serv;
  if (msg.command != "CAP")
    return;
//  if (msg.params.empty())
//    client.reply(ERR_NEEDMOREPARAMS(msg.command));
//  client.send(RPL_WELCOME(client._getNickname(), client._getUsername(), client._getHostname()));
  client.reply(RPL_WELCOME(nick, user, client._getHostname()));
}
