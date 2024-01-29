/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:14:08 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 13:38:28 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void  ping(Server *serv, struct s_message msg, Client& client)
{
  if (msg.params.empty())
    client.reply(ERR_NOORIGIN);
  client.reply(RPL_PONG(serv->_getHostname(), msg.params[0]));
}
