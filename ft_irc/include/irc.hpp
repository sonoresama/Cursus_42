/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:46 by eorer             #+#    #+#             */
/*   Updated: 2024/01/29 19:07:35 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_HPP
# define IRC_HPP

# include <sys/socket.h>
# include <sys/types.h>
# include <sys/epoll.h>
# include <netdb.h>
# include <cstring>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <vector>
# include <map>
# include <iostream>
# include <sstream>
# include "Server.hpp"
# include "Client.hpp"
# include "Commands.hpp"
# include "Channel.hpp"
# include "color.h"
# include "Numeric_replies.hpp"

# define COUT(x) std::cout << x << std::endl;
# define CYELLOW(x) std::cout << YELLOW << x << DEFAULT << std::endl;
# define CRED(x) std::cout << RED << x << DEFAULT << std::endl;
# define CGREEN(x) std::cout << GREEN << x << DEFAULT << std::endl;
# define CMAGENTA(x) std::cout << MAGENTA << x << DEFAULT << std::endl;
# define CBLUE(x) std::cout << BLUE << x << DEFAULT << std::endl;
# define CERR(x) std::cerr << x << std::endl;

typedef void (*commandFunction)(Server*, s_message, Client&);

void  cap(Server *serv, struct s_message msg, Client& client);
void  ping(Server *serv, struct s_message msg, Client& client);
void  join(Server *serv, struct s_message msg, Client& client);
void  privmsg(Server *serv, struct s_message msg, Client& client);
void  user(Server *serv, struct s_message msg, Client& client);

#endif
