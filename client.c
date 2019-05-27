#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "common.h"


int main(int argc, char** argv) {
    int sockfd;  // run until told otherwise
    // Arguments parsing
    if (argc<3) {
        printf("Syntax: ./client <ipaddr> <port>\n");
        exit(1);
    }
    int port = atoi(argv[2]);
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(struct sockaddr_in));
    inet_pton(AF_INET, argv[1], &(dest.sin_addr));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    // Socket creation
    const struct sockadrr* dest_sock = (struct sockaddr *) &dest;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("sockfd: %d\n", sockfd);
    // Greetings message
    char msg[50] = "Hello there server, how fareth thou";
    int sent = sendto(sockfd, &msg, sizeof(msg), 0, dest_sock, sizeof(dest_sock));
    printf("sent: %d\n", sent);

    // Loop 
    /*
    while (! terminate) {
        // Receive message from server
        (..)
        // Process message (and maybe interact with user? send message(s) to server?)
        (..)
    }*/
    // Terminate
    return 0;
}