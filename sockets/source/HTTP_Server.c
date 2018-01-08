/*
  Program:  HTTP_Server.c
  Author:   Ryan Khan
  Date:     2018-01-07
  Description:  This is a demonstraction of simple HTTP Server as a tutorial. The source code can not be used by anyone without a
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

#define PORT_NO 9000
#define RESPONSE_SIZE 1024
#define HEADER_SIZE 2048

int main(int argc, char const *argv[]) {
  // char server_message[BUFF_SIZE] = "SPARTA IS ALIVE";

  //01. OPEN A FILE TO SERVE
  FILE *html_data;
  html_data = fopen("index.html", "r");

  char response_data[RESPONSE_SIZE];
  char http_header[HEADER_SIZE] = "HTTP/1.1 200 OK\r\n\n";

  while (!feof(html_data)) {
    if (fgets(response_data, RESPONSE_SIZE, html_data) != NULL) {
      strcat(http_header, response_data);
    }
  }
  fclose(html_data);


  /* 02.  Create a socket*/
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  /* 03.  Bind Server IP address and Port number to the socket  */
  struct sockaddr_in server_address, client_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT_NO);
  server_address.sin_addr.s_addr = INADDR_ANY;    //INADDR_ANY is a constant for any local address

  bind(server_socket,(struct sockaddr *) &server_address, sizeof(server_address));

  /* 03.  Listen for incoming connections */
  listen(server_socket, 5);
  int client_len = sizeof(client_address);
  time_t current_time = time(NULL);
  printf("HTTP SERVER STARTED AT : %s\n", ctime(&current_time));

  while (1) {

    /* 04.  Accept the connection */
    int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_len);

    /* 05.  Send a response */
    send(client_socket, http_header, sizeof(http_header),0);
    close(client_socket);

    current_time = time(NULL);    //Record the ressponse time
    printf("%s - %s AT %s\n", "HTTP RESPONSE SENT TO..", inet_ntoa(client_address.sin_addr), ctime(&current_time));
  }


  return 0;
}
