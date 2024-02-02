/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:14:08 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 13:06:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/irc.hpp"

void  ping(Server *serv, t_msg msg, Client* client)
{
  if (msg.params.empty())
    client->reply(ERR_NOORIGIN);
  client->reply(RPL_PONG(serv->_getHostname(), msg.params[0]));
}
