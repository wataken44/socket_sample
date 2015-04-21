
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main()
{
  int sockfd;
  int len;
  int result;
  struct sockaddr_in addr;

  // address
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // connect to local
  addr.sin_port = 51000;
  len = sizeof(addr);

  // socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // connect
  result = connect(sockfd, (struct sockaddr *)&addr, len);

  if(result < 0) {
    perror("[client] couldn't connect\n");
    return -1;
  }

  printf("[client] connected\n");
  // do nothing;

  // sleep 60 secs
  sleep(60);

  // close
  close(sockfd);
  printf("[client] closed\n");
  
  return 0;
}
