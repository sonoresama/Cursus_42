/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:47:06 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 18:08:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/irc.hpp"

static int is_valid_nickname(std::string nickname)
{
    const std::string special_chars = "_\\^|[]{}`";

    if (!(nickname.size() >= 1 && nickname.size() <= 9))
        return (0);
    if (!std::isalpha(nickname[0]) && special_chars.find(nickname[0]) == std::string::npos)
        return (0);
    for (size_t i = 1; i < nickname.size(); i++)
    {
        if (!std::isalnum(nickname[i]) && special_chars.find(nickname[i]) == std::string::npos && nickname[i] != '-')
            return (0);
    }
    return (1);
}

void  nick(Server* serv, t_msg msg, Client *client)
{
    C_ITERATOR it;
    if (msg.params.size() == 0)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->_getPrefix(), msg.command));
        return ;
    }
    std::string nickname = msg.params[0];
    if (nickname.empty())
        client->reply(ERR_NONICKNAMEGIVEN(client->_getPrefix()));
    else if (!is_valid_nickname(nickname) || msg.params.size() > 1)
        client->reply(ERR_ERRONEUSNICKNAME(client->_getPrefix(), nickname));
    else if (serv->nickname_in_use(nickname))
        client->reply(ERR_NICKNAMEINUSE(client->_getPrefix(), nickname));
    else
    {
        if (client->_getNickname().compare("*") != 0)
        {
            Channel *channel = client->_getChannel();
            std::string old_nickname = client->_getNickname();

            client->set_nickname(nickname);
            COUT(old_nickname + " changed his nickname to " + client->_getNickname());
            if (channel != NULL)
                channel->broadcast(RPL_NICK(old_nickname, client->_getNickname()));
            else
                client->reply(RPL_NICK(old_nickname, client->_getNickname()));
        }
        else
            client->set_nickname(nickname);
    }
}
