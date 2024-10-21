#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>

void handleClient(int client_socket, int server_fd) {
    char buffer[1024] = {0};
    while (true) {
        int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // Null-terminate the received string
            std::cout << "Client: " << buffer << std::endl;

            // Check for exit message
            if (strcmp(buffer, "exit") == 0) {
                std::cout << "Client has exited the conversation." << std::endl;
                break;
            }

            // Send acknowledgment back to client
            send(client_socket, "Message received", 16, 0);
        } else if (bytes_read == 0) {
            std::cout << "Client disconnected." << std::endl;
            break;
        } else {
            std::cerr << "Read failed" << std::endl;
            break;
        }
    }
    close(client_socket);
    close(server_fd);
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        return -1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    while (true) {
        int client_socket = accept(server_fd, nullptr, nullptr);
        if (client_socket < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }
        std::cout << "New client connected." << std::endl;
        std::thread(handleClient, client_socket, server_fd).detach(); // Handle client in a separate thread
    }

    close(server_fd);
    return 0;
}
