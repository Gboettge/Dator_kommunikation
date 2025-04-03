#include <iostream>
#include <cstring>
#include <WinSock2.h>
#include <WS2tcpip.h>


int main() {
   int sockfd;
   struct sockaddr_in server_addr, client_addr;
   socklen_t addr_len = sizeof(client_addr);
   // TODO: Create UDP socket
   sockfd = socket(AF_INET, SOCK_DGRAM, 0);
   if(sockfd = -1){
    perror("Socket creation failed");
    return 1;
   }
   // TODO: Bind to a port
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(5000);

   if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
    perror("bind failed");
    closesocket(sockfd);
    return 1;
   }
   std::cout << "Listening to port: " << server_addr.sin_port << std::endl; //kanske ändra sinport till string nummber
   while (true) {
       char buffer[1024];
       memset(buffer, 0, sizeof(buffer));
       // TODO: Receive message from client
       int n = recvfrom(sockfd, buffer, sizeof(buffer), 0 ,(struct sockaddr*)&client_addr, &addr_len);

       // TODO: Print received message
       if (n > 0 ){
        //    char client_ip[INET_ADDRSTRLEN];
        //    inet_ntoa(AF_I);
           std::cout << buffer << std::endl; // ändra?
       }
       // TODO (Optional): Send acknowledgment
   }
   // TODO: Close socket
   closesocket(sockfd);
   return 0;
}