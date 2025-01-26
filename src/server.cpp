// This is for Linux users

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

int main(int argc, char **argv) {

  cout << unitbuf;
  cerr << unitbuf;
  
  cout << "Logs from your program will appear here!\n";

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
   cerr << "Failed to create server socket\n";
   return 1;
  }
  
  // To restarts your program quite often, we use SO_REUSEADDR
  // ensures that we don't run into 'Address already in use' errors
  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0) {
    cerr << "setsockopt failed\n";
    return 1;
  }
  
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(4221);
  
  if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) != 0) {
    cerr << "Failed to bind to port 4221\n";
    return 1;
  }
  
  int connection_backlog = 5;
  if (listen(server_fd, connection_backlog) != 0) {
    cerr << "listen failed\n";
    return 1;
  }
  
  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);
  
  cout << "Waiting for a client to connect...\n";
  
  int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
  if (client_fd < 0)
  {
    cerr << "error handling client connection\n";
    close(server_fd);
    return 1;
  }
  cout << "Client connected\n";

  string client_msg(1024,'\0');

    ssize_t brecvd = recv(client_fd, (void *)&client_message[0], client_message.max_size(), 0);
  if (brecvd < 0)
  {
    cerr << "error receiving message from client\n";
    close(client_fd);
    close(server_fd);
    return 1;
  }

  cerr << "Client Message (length: " << client_message.size() << ")" << std::endl;
  clog << client_message << std::endl;
  string response = client_message.starts_with("GET / HTTP/1.1\r\n") ? "HTTP/1.1 200 OK\r\n\r\n" : "HTTP/1.1 404 Not Found\r\n\r\n" ;

  ssize_t bsent = send(client_fd, response.c_str(), response.size(), 0);
  if (bsent < 0)
  {
    cerr << "error sending response to client\n";
    close(client_fd);
    close(server_fd);
    return 1;
  }

  close(client_fd);
  close(server_fd);
  return 0;

}

// This is for window users 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <winsock2.h> 
#include <ws2tcpip.h>

using namespace std;

// Link with ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed.\n";
        return 1;
    }

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        cerr << "Socket creation failed: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    int reuse = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) == SOCKET_ERROR) {
        cerr << "setsockopt failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(4221);

    if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cerr << "Bind failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    cout << "Server listening on port 4221...\n";

    sockaddr_in client_addr{};
    int client_addr_len = sizeof(client_addr);

    SOCKET client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_addr_len);
    if (client_fd == INVALID_SOCKET) {
        cerr << "Error handling client connection: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    cout << "Client connected\n";

    string client_message(1024, '\0');

    int brecvd = recv(client_fd, &client_message[0], client_message.size(), 0);
    if (brecvd == SOCKET_ERROR) {
        cerr << "Error receiving message from client: " << WSAGetLastError() << "\n";
        closesocket(client_fd);
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    client_message.resize(brecvd);
    cerr << "Client Message (length: " << client_message.size() << ")\n";
    clog << client_message << endl;

    string response = (client_message.compare(0, 14, "GET / HTTP/1.1") == 0)
                          ? "HTTP/1.1 200 OK\r\n\r\n"
                          : "HTTP/1.1 404 Not Found\r\n\r\n";

    int bsent = send(client_fd, response.c_str(), response.size(), 0);
    if (bsent == SOCKET_ERROR) {
        cerr << "Error sending response to client: " << WSAGetLastError() << "\n";
        closesocket(client_fd);
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
