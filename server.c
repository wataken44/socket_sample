
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main()
{
  int bind_sockfd;
  int bind_len;
  int bind_result;
  struct sockaddr_in bind_addr;
  int accept_sockfd;
  struct sockaddr_in accept_addr;
  int accept_len;
  
  // address
  bind_addr.sin_family = AF_INET;
  bind_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // connect to local
  bind_addr.sin_port = 51000;
  bind_len = sizeof(bind_addr);

  // socket
  bind_sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // bind
  bind_result = bind(bind_sockfd, (struct sockaddr *)&bind_addr, bind_len);
  
  if(bind_result < 0) {
    perror("[server] couldn't bind\n");
    return -1;
  }

  // listen
  printf("[server] listen port %d\n", bind_addr.sin_port);
  listen(bind_sockfd, 5);

  // accept
  accept_sockfd = accept(bind_sockfd, (struct sockaddr *)&accept_addr, &accept_len);
  printf("[server] accept port %d\n", accept_addr.sin_port);

  // sleep 60 secs
  sleep(60);
  
  // close
  close(accept_sockfd);
  printf("[server] closed\n");
  
  return 0;
}
