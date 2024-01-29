/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:07 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 18:51:05 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/irc.hpp"

void user(Server* serv, struct s_message msg, Client &client)
{
    std::string tmp = msg.params;
    std::string username;
    std::string mode;
    std::string hostname;
    std::string realname;

    if (msg.params.find(" ") != std::string::npos)
    {
        username = msg.params.substr(0, msg.params.find(" "));
        tmp.erase(0, tmp.find(" ") + 1);
    }
    if (tmp.find(" ") != std::string::npos)
    {
        mode = tmp.substr(0, tmp.find(" "));
        tmp.erase(0, tmp.find(" ") + 1);
    }
    if (tmp.find(" ") != std::string::npos)
    {
        hostname = tmp.substr(0, tmp.find(" "));
        tmp.erase(0, tmp.find(" ") + 1);
    }
    if (tmp[0] == ':' && tmp[1])
        realname = tmp.substr(1, tmp.size() - 1);
    if (username.empty() || mode.empty() || hostname.empty() || realname.empty())
        client.reply(ERR_NEEDMOREPARAMS(msg.command));
    if (client.is_fully_registered())
        client.reply(ERR_ALREADYREGISTRED);
    else
    {
        client.set_username(username);
        client.set_mode(mode);
        client.set_hostname(hostname);
        client.set_realname(realname);
    }
}
