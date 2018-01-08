/*
  Program:  TCP_Server.c
  Author:   Ryan Khan
  Date:     2018-01-07
  Description:  This is a demonstraction of simple TCP Server as a tutorial. The source code can not be used by anyone without a
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

#define PORT_NO 9000
#define BUFF_SIZE 256


int main(int argc, char const *argv[]) {
  char server_message[BUFF_SIZE] = "SPARTA IS ALIVE";

  /* 01.  Create a socket*/
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  /* 02.  Bind Server IP address and Port number to the socket  */
  struct sockaddr_in server_address, client_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT_NO);
  server_address.sin_addr.s_addr = INADDR_ANY;    //INADDR_ANY is a constant for any local address

  bind(server_socket,(struct sockaddr *) &server_address, sizeof(server_address));

  while (1) {
    /* 03.  Listen for incoming connections */
    listen(server_socket, 5);
    int client_len = sizeof(client_address);

    /* 04.  Accept the connection */
    int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_len);

    /* 05.  Send a response */
    send(client_socket, server_message, sizeof(server_message),0);

    printf("%s - %s\n", "CONNECTED AND RESPONDED TO..", inet_ntoa(client_address.sin_addr));
  }


  return 0;
}
