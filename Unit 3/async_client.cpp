#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    
    connect(client_fd, (sockaddr*)&server_addr, sizeof(server_addr));
    
    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);
    std::cout << "Server: " << buffer << std::endl;
    
    const char *reply = "Hello from Client";
    send(client_fd, reply, strlen(reply), 0);
    
    close(client_fd);
    return 0;
}
