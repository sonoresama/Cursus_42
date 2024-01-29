#ifndef COMMANDS_HPP
#define COMMANDS_HPP

# include "irc.hpp"
# include "Server.hpp"
# include "Client.hpp"

class Server;
class Client;

struct s_message
{
	std::string	prefix;
	std::string	command;
	//std::string	params;
	std::vector<std::string>	params;
};

void user(Server *serv, struct s_message msg, Client &client);

#endif
