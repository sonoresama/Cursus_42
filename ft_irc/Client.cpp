/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:51 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:22:44 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

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
