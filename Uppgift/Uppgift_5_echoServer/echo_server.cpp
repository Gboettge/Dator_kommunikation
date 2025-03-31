#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
int main() {
   int sockfd;
   struct sockaddr_in server_addr, client_addr;
   socklen_t addr_len = sizeof(client_addr);
   // TODO: Create UDP socket
   // TODO: Bind to a port
   while (true) {
       char buffer[1024];
       memset(buffer, 0, sizeof(buffer));
       // TODO: Receive message from client
       // TODO: Print received message
       // TODO (Optional): Send acknowledgment
   }
   // TODO: Close socket
   return 0;
}