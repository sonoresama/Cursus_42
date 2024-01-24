/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:51 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:34:19 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Client.hpp"

Client::Client()
{
 // CGREEN("A client has been created");
}

Client::Client(int socket) : _socket(socket)
{
//  CGREEN("A client has been created");
}

Client::~Client()
{
//  CGREEN("Client destroyed");
}
