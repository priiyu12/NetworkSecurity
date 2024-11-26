#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) <= 0) {
        perror("Invalid address");
        return 1;
    }

    if (connect(client_fd, (sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("Connect failed");
        return 1;
    }
    std::cout << "Client: Connected to server" << std::endl;

    char buffer[1024] = {0};
    int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        std::cout << "Client received: " << buffer << std::endl;
    }

    send(client_fd, "Hello from Client", strlen("Hello from Client"), 0);
    close(client_fd);
    return 0;
}
