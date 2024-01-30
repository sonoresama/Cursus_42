/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:05:38 by eorer             #+#    #+#             */
/*   Updated: 2024/01/30 15:09:43 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  quit(Server *serv, struct s_message msg, Client& client)
{
  std::string reason = msg.params.size() > 0 ? msg.params[0].substr(1) : "No reason";
  std::string prefix = msg.prefix.empty() ? client._getNickname() : msg.prefix;

  client.reply(RPL_ERROR(prefix, reason));
  serv->handleDeconnection(client._getSocket());
}
