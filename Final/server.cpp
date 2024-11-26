#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("Bind failed");
        return 1;
    }

    if (listen(server_fd, 3) == -1) {
        perror("Listen failed");
        return 1;
    }
    std::cout << "Server: Waiting for a client connection..." << std::endl;

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd == -1) {
        perror("Accept failed");
        return 1;
    }

    std::cout << "Server: Client connected" << std::endl;

    send(client_fd, "Hello from Server", strlen("Hello from Server"), 0);

    char buffer[1024] = {0};
    int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        std::cout << "Server received: " << buffer << std::endl;
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
