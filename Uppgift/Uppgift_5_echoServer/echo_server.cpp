#include <iostream>
#include <cstring>
#include <WinSock2.h>
#include <WS2tcpip.h>
bool InitWinsockDLL()
{
  WSADATA wsaData;
  ///* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
  WORD wVersionRequested = MAKEWORD(2, 2);
  int iResult = WSAStartup(wVersionRequested, &wsaData);
 
  if (iResult != 0)
  {
    std::cout <<  "WSAStartup failed with error: "<< iResult << std::endl;
    return false;
  }
 
  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
  {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    std::cout <<  "Could not find a usable version of Winsock.dll" << std::endl;
    WSACleanup();
    return false;
  }
  return true;
}
 
int main() 
{
   int sockfd;
   InitWinsockDLL();
   int server_fd, client_fd;
   char *buffer[54];
   struct sockaddr_in server_addr, client_addr;
   socklen_t addr_len = sizeof(client_addr);
   // TODO: Create TCP socket
   server_fd = socket(AF_INET, SOCK_STREAM, 0);
   if(server_fd < 0){
    perror("Socket creation failed");
    return 1;
   }
   // TODO: Bind to a port
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr= INADDR_ANY;
   server_addr.sin_port = htons(5001);

   int bindresult = bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
   if(bindresult < 0)
   {
    perror("Bind failed");
    closesocket(server_fd);
    return 1;
   }
   // TODO: Listen for connections
   if(listen(server_fd, 5) < 0)
   {
    perror("Listen failed");
    closesocket(server_fd);
   }

   std::cout << "Server listening on port" << htons(server_addr.sin_port) << "..." << std::endl;

   // TODO: Accept client connection
   client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
   if (client_fd < 0)
   {
       perror("Accept failed");
       closesocket(server_fd);
       return 1;
   }
    // TODO: Recieve message from client
    memset(buffer, 0, sizeof(buffer));
    int n = recv(client_fd, buffer, sizeof(buffer), 0);
    if(n > 0)
    {
        std::cout << "Recieved: " << buffer << std::endl;
    }

   while (true) {
       char buffer[1024];
       // TODO (Optional): Send acknowledgment
   }
   // TODO: Close socket
   return 0;
}