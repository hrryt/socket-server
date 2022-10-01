#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>

#include "utils/sock.h"

#define LISTEN_BACKLOG 50

int main() {

    // Define the descriptors and addresses
    int sfd, cfd;
    struct sockaddr_in my_addr, peer_addr;
    socklen_t peer_addr_size;

    // Create a socket
    sfd = create_sock();
    if (sfd == -1)
    {
        printf("Failed to create socket file descriptor\r\n");
        return 1;
    }

    // Set up the address
    my_addr = get_sock_addr();

    if (bind(sfd, (const struct sockaddr *) &my_addr,
             sizeof(my_addr)) == -1)
    {
        printf("Failed to bind to address, is it already in use?\r\n");
        return 1;
    }

    printf("Binded!\r\n");

    if (listen(sfd, LISTEN_BACKLOG) == -1)
    {
        printf("Failed to listen\r\n");
        return 1;
    }

    printf("Listening on port 8080\r\n");

    // We accept the clients here
    peer_addr_size = sizeof(peer_addr);
    cfd = accept(sfd, (struct sockaddr *) &peer_addr,
                 &peer_addr_size);

    // Rule out any bad client file descriptors
    if (cfd == -1)
    {
        printf("Failed to accept\r\n");
        return 1;
    }

    printf("Accepted client\r\n");

    // Send some buffer to the client saying Hello
    char buff[] = "Hello!\r\n";
    send(cfd, buff, sizeof(buff), 0);


}