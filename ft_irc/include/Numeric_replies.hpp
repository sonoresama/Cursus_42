#ifndef NUMERICAL_REPLIES_HPP
#define NUMERICAL_REPLIES_HPP

////parisng
//# define ERR_UNKNOWNCOMMAND(client, command) (std::string(":localhost 421 ") + client + " " + command + " :Unknown command")
////user
//# define ERR_NEEDMOREPARAMS(client, command) (std::string(":localhost 461 ") + client + " " + command + " :Not enough parameters.")
////nick
////welcome
//# define RPL_WELCOME(nick, user, host) (std::string(":localhost 001 ") + user + " :Welcome on irc Server <3 " + nick + "!" + user + "@" + host)

  //Numeric errors
# define ERR_ALREADYREGISTERED(client) (std::string(":localhost 462 ") + client + " :You may not reregister.")
# define ERR_NICKNAMEINUSE(client, nickname) (std::string(":localhost 433 ") + client + " " + nickname + " :Nickname is already in use.")
# define ERR_ERRONEUSNICKNAME(client, nickname) (std::string(":localhost 432 ") + client + " " + nickname + " :Erroneus nickname")
# define ERR_NONICKNAMEGIVEN(client) (std::string(":localhost 431 ") + client + " :There is no nickname.")
# define ERR_UNKNOWNCOMMAND(nick, command) "421 " + nick + " " + command + " :Unknown command"
# define ERR_NEEDMOREPARAMS(nick, command) "461 " + nick + " " + command + " :Not enough parameters"
# define ERR_NOSUCHNICK(nick, target) "401 " + nick + " " + target + " :No such nick/channel"
# define ERR_CHANOPRIVSNEEDED(nick, channel) "482 " + nick + " " + channel + " :You are not channel operator"
# define ERR_NOSUCHCHANNEL(nick, channel) "403 " + nick + " " + channel + " :No such channel"
# define ERR_USERNOTINCHANNEL(nick, target, channel) "441 " + nick + " " + target + " " + channel + " :They are not in the channel"
# define ERR_CANNOTSENDTOCHAN(nick, channel) "404 " + nick + " " + channel + " :Cannot send to channel"
# define ERR_NOTONCHANNEL(nick, channel) "442 " + nick + " " + channel + " :You are not on the channel"
# define ERR_NOORIGIN "409 :No origin specified"
# define ERR_PASSWDMISMATCH(nick) "464 " + nick + " :Password incorrect"
# define ERR_NOTREGISTERED(nick) "451 " + nick + " :You need to register"
# define ERR_UNKNOWNMODE(nick, mode, channel) "472 " + nick + " " + mode + " :is unknown mode char to me for channel " + channel

  //Numeric replies
# define RPL_WELCOME(server, nick, user, host) ":" + server + " 001 " + nick + " :Welcome on irc Server <3 " + nick + "!" + user + "@" + host
# define RPL_WELCOME_PWD(server, nick) ":" + server + " 001 " + nick + " :Password is good"
# define RPL_TOPIC(server, nick, channel, topic) ":" + server + " 332 " + nick + " " + channel + " :" + topic
# define RPL_NOTOPIC(server, nick, channel) ":" + server + " 331 " + nick + " " + channel + " :No topic set"
# define RPL_NAMREPLY(server, nick, channel, nicks) ":" + server + " 353 " + nick + " = " + channel + " :" + nicks
# define RPL_ENDOFNAMES(server, nick, channel) ":" + server + " 366 " + nick + " " + channel + " :End of /NAMES list"
# define RPL_CHANNELMODEIS(server, nick, channel, mode_string, mode_parameters) ":" + server + " 324 " + nick + " " + channel + " " + mode_string + " " + mode_parameters

  //Command replies
# define RPL_PONG(prefix, dest) ":" + prefix + " PONG " + dest
# define RPL_JOIN(prefix, channel) ":" + prefix + " JOIN " + channel
# define RPL_PRIVMSG(prefix, target, message) ":" + prefix + " PRIVMSG " + target + " :" + message
# define RPL_KICK(prefix, channel, user, reason) ":" + prefix + " KICK " + channel + " " + user + " :" + reason
# define RPL_PART(prefix, channel, reason) ":" + prefix + " PART " + channel + " :" + reason
# define RPL_ERROR(prefix, reason) ":" + prefix + " ERROR :" + reason
# define CMD_TOPIC(prefix, channel, topic) ":" + prefix + " TOPIC " + channel + " :" + topic
# define RPL_NICK(prefix, new_nick) ":" + prefix + " NICK " + new_nick
# define RPL_MODE(prefix, channel, mode_string, mode_parameters) ":" + prefix + " MODE " + channel + " " + mode_string + " " + mode_parameters

#endif
