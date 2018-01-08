/*
  Program:  TCP_Client.c
  Author:   Ryan Khan
  Date:     2018-01-07
  Description:  This is a demonstraction of simple TCP client as a tutorial. The source code can not be used by anyone without a
  explicit written permission from the Author. All rights reserved.
*/


//header requirements
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char const *argv[]) {
  /* 01.  Create a soccket*/
  int net_socket = socket(AF_INET, SOCK_STREAM, 0);

  /* 02.  Establish a connection to a TCP_Server */
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9000);
  server_address.sin_addr.s_addr = INADDR_ANY;    //INADDR_ANY is a constant for any local address

  int connection_status = connect(net_socket,(struct sockaddr *) &server_address, sizeof(server_address));
  printf("%s\n", connection_status == -1 ? "Connection Error" : "Connected" );

  /* 03.  Receive a response from the TCP_Server */
  char server_response[256] = "NOTHING RECEIVED";
  recv(net_socket, &server_response, sizeof(server_response), 0);
  printf("RECEIVED : %s\n", server_response);

  /* 04.  Close the Socket and the connection */
  close(net_socket);

  printf("%s\n", "TCP_Client is running without errors.." );


  return 0;
}
