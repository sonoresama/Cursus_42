/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:46 by eorer             #+#    #+#             */
/*   Updated: 2024/01/23 17:08:50 by eorer            ###   ########.fr       */
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
# include <iostream>
# include <unistd.h>
# include <stdio.h>
# include <list>
# include "Server.hpp"
# include "Client.hpp"

# define COUT(x) std::cout << x << std::endl;
# define CERR(x) std::cerr << x << std::endl;

#endif
