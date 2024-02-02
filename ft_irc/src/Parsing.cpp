#include "../include/Commands.hpp"
#include "../include/Server.hpp"
#include "../include/irc.hpp"

int Server::parseMessage(std::string message, t_msg &msg)
{
    std::string tmp = message;
    std::string command;

    if (message.empty())
        return (0);
    if (message[0] == ':') //prefixe
	{
		if (message.find(" ") != std::string::npos)
        {
            msg.prefix = message.substr(0, message.find(' '));
			tmp.erase(0, tmp.find_first_of(' ') + 1);
            // COUT("prefix : " << msg.prefix);    
        }
	}
	if (tmp.find(" ") != std::string::npos) //command
	{
		for (size_t i = 0; i < tmp.find(" "); ++i) {
            command += std::toupper(tmp[i]);}
        msg.command = command;
        tmp.erase(0, tmp.find(" ") + 1);
        // COUT("command : " << msg.command);
    }
    else
    {
        for (size_t i = 0; i < tmp.size() - 2; ++i) {
            command += std::toupper(tmp[i]);}
        msg.command = command;
        tmp.clear();
    }
    if (tmp.size() > 0) //params
    {
	    tmp.erase(tmp.find("\n"), tmp.size());
        std::stringstream ss(tmp);
        std::string arg;
        std::string sub;

        while (ss >> arg)
        {
        //   arg.erase(std::remove_if(arg.begin(), arg.end(), isNotPrintable), arg.end());
          if (arg[0] == ':')
          {
            arg += " ";
            while (ss >> sub)
              arg += sub + " ";
            msg.params.push_back(arg);
            break;
          }
          else
            msg.params.push_back(arg);
        }
        // size_t i = 0;
        // while (i < msg.params.size())
        // {
        //     COUT("param " << i << " : " << msg.params[i])
        //     i++;
        // }
    }
    else
        msg.params.push_back("");
    return (1);
}

void Server::executeCommand(Client &client, std::string message)
{
    t_msg msg;
    std::string	valid_cmds[9] = {
        "PASS",
        "USER",
        "NICK",
        "JOIN",
        "PRIVMSG",
        "KICK",
        "INVITE",
        "TOPIC",
        "MODE"};
    int i = 0;

    if (!parseMessage(message, msg))
        return;
    if (!client.is_fully_registered())
    {
        if (msg.command == "PASS")
        {
            // COUT("la commande cest bien pass")
            pass(this, client, msg);
        }
        if (msg.command == "USER")
        {
            // COUT("la commande cest bien user")
            user(client, msg);
        }
        if (msg.command == "NICK")
        {
            // COUT("la commande cest bien nick")
            nick(this, client, msg);
        }
        if (client.is_fully_registered())
            COUT(RPL_WELCOME(client.get_nickname(), client.get_username(), this->_getHostname()))
    }
    else
    {
        while (i <= 9)
        {
            if (msg.command == valid_cmds[i])
                break;
            i++;
        }
        switch(i + 1)
        {
            case 1: pass(this, client, msg); break;
            case 2: user(client, msg); break;
            case 3: nick(this, client, msg); break;
            // case 4: join(client, msg); break;
            // case 5: privmsg(client, msg); break;
            // case 6: kick(client, msg); break;
            // case 7: invite(client, msg); break;
            // case 8: topic(client, msg); break;
            // case 9: mode(client, msg); break;
            default:
                COUT(ERR_UNKNOWNCOMMAND(client.get_nickname(), msg.command))
        }
    }
}

