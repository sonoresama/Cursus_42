/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:21:20 by eorer             #+#    #+#             */
/*   Updated: 2024/01/23 17:16:28 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int main(void)
{
//  struct sockaddr_in clientAddress;
//  int clientSocket;
//  char  readBuffer[64];
//  socklen_t clientAddrLen = sizeof(struct sockaddr_in);

  try
  {
    Server  serv(4243, "");

    serv.run();
  }
  catch (char const * str)
  {
    CERR(str);
    perror(NULL);
    return (1);
  }
  return (0);
}
    
/********************************************/
//
//  int epfd = epoll_create(1);
//  if (epfd == -1)
//  {
//    std::cerr << "Error: failed ot create epoll instance" << std::endl;
//    return (1);
//  }
//  _event.events = EPOLLIN;
//  _event.data.fd = serverSocker;
//  if (epoll_ctl(epfd, EPOLL_CTL_ADD, serverSocket, &event) == -1)
//    throw ("Error: failed to add socketServer to epoll interest list");
//
//  struct  epoll_event e_recv;
//  while (true)
//  {
//    int waitfd;
//    waitfd = epoll_wait(epfd, &e_recv, 1, -1);
//    if (waitfd == -1)
//    {
//      std::cerr << "Error: waiting events on epoll interest list" << std::endl;
//      perror();
//      return (1);
//    }
//    if (e_recv.data.fd != serverSocket)
//    {
//      std::cerr << "FDP" << std::endl;
//      return (1);
//    }
//    clientSocket.push_back(accept(serverSocket, reinterpret_cast))
//  }
//
///********************************************/
//    clientSocket = accept(serv._socket, reinterpret_cast<struct sockaddr*>(&clientAddress), &clientAddrLen);
//    if (clientSocket == -1)
//    {
//      std::cerr << "Error: failed to accept socket" << std::endl;
//      return (1);
//    }
//  
//    /************************************************************/
//  
//    std::cout << "Connection established with " << ntohs(clientAddress.sin_addr.s_addr) << std::endl;
//    send(clientSocket, "CONNECTED\n", strlen("CONNECTED\n"), 0);
//    while (1)
//    {
//      int bytesRead = recv(clientSocket, readBuffer, sizeof(readBuffer), 0);
//      if (bytesRead == 0)
//      {
//        std::cout << "Connection with " << ntohs(clientAddress.sin_addr.s_addr) << " closed" << std::endl;
//        close(clientSocket);
//        return (0);
//      }
//      else if (bytesRead == -1)
//      {
//        std::cerr << "Error: read issue" << std::endl;
//        close(clientSocket);
//        return (1);
//      }
//      else
//      {
//        std::cout << "Message received : " << std::endl << "--> " << readBuffer;// << std::endl;
//        send(clientSocket, "Bien vu\n", strlen("Bien vu\n"), 0);
//      }
//    }
//    close(clientSocket);
