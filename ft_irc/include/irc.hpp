/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:46 by eorer             #+#    #+#             */
/*   Updated: 2024/01/25 16:13:50 by eorer            ###   ########.fr       */
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
# include <netdb.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <vector>
# include <map>
# include <iostream>
# include "Server.hpp"
# include "Client.hpp"
# include "Channel.hpp"
# include "color.h"

# define COUT(x) std::cout << x << std::endl;
# define CYELLOW(x) std::cout << YELLOW << x << DEFAULT << std::endl;
# define CRED(x) std::cout << RED << x << DEFAULT << std::endl;
# define CGREEN(x) std::cout << GREEN << x << DEFAULT << std::endl;
# define CMAGENTA(x) std::cout << MAGENTA << x << DEFAULT << std::endl;
# define CBLUE(x) std::cout << BLUE << x << DEFAULT << std::endl;
# define CERR(x) std::cerr << x << std::endl;

#endif
