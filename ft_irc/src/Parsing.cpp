#include "../include/Commands.hpp"
#include "../include/irc.hpp"

int Server::parseMessage(std::string message, s_message &msg)
{
    std::string tmp = message;

    if (message.empty())
        return (0);
    if (message[0] == ':') //prefixe
	{
		if (message.find(" ") != std::string::npos)
        {
            msg.prefix = message.substr(0, message.find(' '));
			tmp.erase(0, tmp.find_first_of(' ') + 1);
            COUT("prefix : " << msg.prefix);    
        }
	}
	if (tmp.find(" ") != std::string::npos) //command
	{
		for (size_t i = 0; i < tmp.find(" "); ++i) {
            msg.command += std::toupper(tmp[i]);}
        tmp.erase(0, tmp.find(" ") + 1);
        COUT("command : " << msg.command);
    }
    else
    {
        msg.command = tmp;
        tmp.clear();
        COUT("command : " << msg.command);
    }
    if (tmp.size() > 0) //params
    {
        msg.params = tmp;
        COUT("params : " << msg.params);
    }
    return (1);
}

void Server::executeCommand(Client &client, s_message msg)
{
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
    int i = 1;
    if (!client.is_fully_registered())
    {
        if (msg.command == "PASS")
            pass(client, msg);
        if (msg.command == "USER")
            user(client, msg);
        if (msg.command == "NICK")
            nick(client, msg);
    }
    while (i <= 9)
    {
        if (msg.command == valid_cmds[i])
            break;
        i++;
    }
    switch(i)
    {
        case 1: pass(client, msg); break;
        case 2: user(client, msg); break;
        case 3: nick(client, msg); break;
        case 4: join(client, msg); break;
        case 5: privmsg(client, msg); break;
        case 6: kick(client, msg); break;
        case 7: invite(client, msg); break;
        case 8: topic(client, msg); break;
        case 9: mode(client, msg); break;
        default:
            ERR_UNKNOWNCOMMAND(client, msg.command)); //plus complique que ca je pense
    }
}

