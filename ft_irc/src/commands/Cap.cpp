/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:28:45 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 15:12:28 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  cap(Server *serv, struct s_message msg, Client& client->
{
  std::string user = "eorer";
  std::string nick = "tito";
  std::string User = "blerouss";
  std::string Nick = "boss";
  std::string User2 = "sacha";
  std::string Nick2 = "titi";

  (void)serv;
  if (msg.command != "CAP")
    return;
//  if (msg.params.empty())
//    client->reply(ERR_NEEDMOREPARAMS(msg.command));
//  client->send(RPL_WELCOME(client->_getNickname(), client->_getUsername(), client->_getHostname()));
  if (client->_getSocket() == 5)
  {
    client->set_username(user);
    client->set_nickname(nick);
  }
  else if (client->_getSocket() == 6)
  {
    client->set_username(User);
    client->set_nickname(Nick);
  }
  else
  {
    client->set_username(User2);
    client->set_nickname(Nick2);
  }
  client->reply(RPL_WELCOME(client->_getNickname(), client->_getUsername(), client->_getHostname()));
}
