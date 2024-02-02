#include "../include/Commands.hpp"
#include "../include/Server.hpp"

//------------------regsitration------------------

void pass(Server *server, t_msg msg, Client &client)
{
    // COUT("pass : " << msg.params[0])
    if (msg.params[0].empty())
    {
        COUT(ERR_NEEDMOREPARAMS(client.get_nickname(), msg.command))
    }
    else if (client.is_fully_registered())
    {
        COUT(ERR_ALREADYREGISTERED(client.get_nickname()))
    }

    else if (msg.params[0] == server->getPwd() && msg.params.size() == 1)
    {
        client.set_entered_valid_password(true);
        // COUT("Password valid entered")
    }
    // COUT("server pwd : " << server->getPwd())
    // COUT("msg params : " << msg.params[0])
}

void user(Client &client, t_msg msg)
{
    if (msg.params.size() != 4 || msg.params[3][0] != ':')
    {
        COUT(ERR_NEEDMOREPARAMS(client.get_username(), msg.command))
    }
    else if (client.is_fully_registered())
    {
        COUT(ERR_ALREADYREGISTERED(client.get_username()))
    }
    else
    {
        client.set_username(msg.params[0]);
        // COUT("username : " << client.get_username())
        client.set_mode(msg.params[1]);
        // COUT(mode)
        client.set_hostname(msg.params[2]);
        // COUT(hostname)
        client.set_realname(msg.params[3].substr(1, msg.params[3].size()));
        // COUT("realname :" << msg.params[3].substr(1, msg.params[3].size())) 
    }
}

bool nickname_in_use(Server *server, std::string nickname)
{
    C_ITERATOR it;
    for (it = server->getClients().begin(); it != server->getClients().end(); ++it)
    {
        if (it->get_nickname() == nickname)
            return (true);
    }
    return (false);
}

void nick(Server *server, Client &client, t_msg msg)
{
    std::string nickname = msg.params[0];
    // COUT("nickname : " << nickname)
    C_ITERATOR it;
    
    // COUT(msg.params.size())
    if (msg.params[0].empty())
        COUT(ERR_NONICKNAMEGIVEN(client.get_nickname()))
    else if (!client.is_valid_nickname(nickname) || msg.params.size() > 1)
        COUT(ERR_ERRONEUSNICKNAME(client.get_nickname(), nickname))
    else if (nickname_in_use(server, nickname))
        COUT(ERR_NICKNAMEINUSE(client.get_nickname(), nickname))
    else
    {
        // COUT("troisieme boucle")
        if (client.is_fully_registered())
        {
            std::string old_nickname = client.get_nickname();
            client.set_nickname(nickname);
            COUT("[SERVER] " << old_nickname << " changed is nickname to " << client.get_nickname())
        }
        else
        {
            client.set_nickname(nickname);
            // COUT("nickname : " << client.get_nickname())
        }
    }
}


