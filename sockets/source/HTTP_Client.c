/*
  Program:  HTTP_Client.c
  Author:   Ryan Khan
  Date:     2018-01-07
  Description:  This is a demonstraction of simple HTTP client as a tutorial. The source code can not be used by anyone without a
  explicit written permission from the Author. All rights reserved.
*/


//header requirements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT_NO 80
#define RESPONSE_SIZE 4096
#define REQUEST_SIZE 256

int main(int argc, char const *argv[]) {
  // 01. GET HOST IP ADDRESS
    char *address;
    address = argv[1];

  /* 02.  Create a soccket*/
  int net_socket = socket(AF_INET, SOCK_STREAM, 0);

  /* 03.  Establish a connection to a HTTP_Server */
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT_NO);
  inet_aton(address, &server_address.sin_addr.s_addr);

  int connection_status = connect(net_socket,(struct sockaddr *) &server_address, sizeof(server_address));
  printf("%s\n", connection_status == -1 ? "Connection Error" : "Connected" );

  /* 04. Send Request and Receive a response from the TCP_Server */
  char request[] = "GET / HTTP/1.1\r\n\r\n";
  char server_response[RESPONSE_SIZE];

  send(net_socket, request, sizeof(request), 0);
  recv(net_socket, &server_response, sizeof(server_response), 0);
  printf("RECEIVED : %s\n", server_response);

  /* 05.  Close the Socket and the connection */
  close(net_socket);

  printf("%s\n", "TCP_Client is running without errors.." );


  return 0;
}
