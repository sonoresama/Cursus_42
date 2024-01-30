#ifndef NUMERICAL_REPLIES_HPP
# define NUMERICAL_REPLIES_HPP

# define ERR_UNKNOWNCOMMAND(command) "421 " + command + " :Unknown command"
# define ERR_NEEDMOREPARAMS(command) "461 " + command + " :Not enough parameters"
# define ERR_NOSUCHNICK(target) "401 " + target + " :No such nick/channel"
# define ERR_CHANOPRIVSNEEDED(client, channel) "482 " + client + " " + channel + " :You are not channel operator"
# define ERR_NOSUCHCHANNEL(client, channel) "403 " + client + " " + channel + " :No such channel"
# define ERR_USERNOTINCHANNEL(client, nick, channel) "441 " + client + " " + nick + " " + channel + " :They are not in the channel"
# define ERR_CANNOTSENDTOCHAN(channel) "404 " + channel + " :Cannot send to channel"
# define ERR_NOTONCHANNEL(channel) "442 " + channel + " :You are not on the channel"
# define ERR_ALREADYREGISTRED "462 :Unauthorized command (already registered)"
# define ERR_NOORIGIN "409 :No origin specified"

# define RPL_WELCOME(nick, user, host) "001 " + user + " :Welcome on irc Server <3 " + nick + "!" + user + "@" + host
# define RPL_TOPIC(channel, topic) "332 " + channel + " :" + topic
# define RPL_NAMREPLY(user, channel, users) "353 " + user + " = " + channel + " :" + users
# define RPL_ENDOFNAMES(user, channel) "366 " + user + " " + channel + " :End of /NAMES list"

# define RPL_PONG(prefix, dest) ":" + prefix + " PONG " + dest
# define RPL_JOIN(prefix, channel) ":" + prefix + " JOIN " + channel
# define RPL_PRIVMSG(prefix, target, message) ":" + prefix + " PRIVMSG " + target + " :" + message
# define RPL_KICK(prefix, channel, user, reason) ":" + prefix + " KICK " + channel + " " + user + " :" + reason
# define RPL_PART(prefix, channel, reason) ":" + prefix + " PART " + channel + " :" + reason
# define RPL_ERROR(prefix, reason) ":" + prefix + " ERROR :" + reason

#endif
