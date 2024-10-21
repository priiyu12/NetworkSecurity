#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    connect(client_fd, (sockaddr*)&addr, sizeof(addr));
    
    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);
    std::cout << buffer << std::endl;
    
    send(client_fd, "Hello from Client", 17, 0);
    close(client_fd);
    return 0;
}
