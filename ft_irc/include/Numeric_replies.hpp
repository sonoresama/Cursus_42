#ifndef NUMERICAL_REPLIES_HPP
# define NUMERICAL_REPLIES_HPP

# define ERR_UNKNOWNCOMMAND(command) "421 " + command + " :Unknown command"
# define ERR_NEEDMOREPARAMS(command) "461 " + command + " :Not enough parameters"
# define ERR_NOSUCHNICK(target) "401 " + target + " :No such nick/channel"
# define ERR_ALREADYREGISTRED "462 :Unauthorized command (already registered)"
# define ERR_NOORIGIN "409 :No origin specified"

# define RPL_WELCOME(nick, user, host) "001 " + user + " :Welcome on irc Server <3 " + nick + "!" + user + "@" + host
# define RPL_TOPIC(channel, topic) "332 " + channel + " :" + topic
# define RPL_NAMREPLY(user, channel, users) "353 " + user + " = " + channel + " :" + users
# define RPL_ENDOFNAMES(user, channel) "366 " + user + " " + channel + " :End of /NAMES list"

# define RPL_PONG(prefix, dest) ":" + prefix + " PONG " + dest
# define RPL_JOIN(prefix, channel) ":" + prefix + " JOIN " + channel
# define RPL_PRIVMSG(source, target, message) ":" + source + " PRIVMSG " + target + " :" + message

#endif
