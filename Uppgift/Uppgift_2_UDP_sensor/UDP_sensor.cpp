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
 
int main() {
   InitWinsockDLL();
   int sockfd;
   struct sockaddr_in server_addr;
   // TODO: Create UDP socket
   sockfd = socket(AF_INET, SOCK_DGRAM, 0);
   if (sockfd < 0)
   {
       perror("Socket creation failed");
       return 1;
   }

   // TODO: Fill in server information (IP, Port)
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(5000);
   server_addr.sin_addr.s_addr= inet_addr("172.16.217.216");

   while (true) {
       // TODO: Create message
       const char* message = "Gustav";
       // TODO: Send message to server
       std::cout << "Sending: " << message << std::endl;
       sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
       // TODO: Sleep for 1 second
       Sleep(1000);
   }
   // TODO: Close socket
   closesocket(sockfd);
   return 0;
}