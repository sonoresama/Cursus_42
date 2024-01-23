
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>




int main(void)
{
  int _socket;
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  if (_socket == -1)
    return (1);
  std::cout << "Socket fd : " << _socket << std::endl;
  close(_socket);
  std::cout << "Socket fd : " << _socket << std::endl;
  return (0);
}
