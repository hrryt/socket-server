//
// Created by harry on 01/10/22.
//

#include <netdb.h>
#include <sys/socket.h>

// Gets the listen address ready for the server
struct sockaddr_in get_sock_addr() {
    struct sockaddr_in addr;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = 8080;
    addr.sin_family = AF_INET;
}

// Creates the socket file descriptor and returns it
int create_sock() {
    return socket(AF_INET, SOCK_STREAM, 0);
}