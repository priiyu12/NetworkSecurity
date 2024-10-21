#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <cstring> // For strerror
#include <errno.h> // For errno

void receiveMessages(int client_fd) {
    char buffer[1024] = {0};
    while (true) {
        int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // Null-terminate the received string
            std::cout << "Server: " << buffer << std::endl;
        } else if (bytes_read == 0) {
            std::cout << "Server disconnected." << std::endl;
            break;
        } else {
            std::cerr << "Read failed" << std::endl;
            break;
        }
    }
}

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        std::cerr << "Socket creation failed: " << strerror(errno) << std::endl;
        return -1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(client_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Connection failed: " << strerror(errno) << std::endl;
        close(client_fd);
        return -1;
    }

    // Start a thread to receive messages from the server
    std::thread receiver(receiveMessages, client_fd);
    receiver.detach(); // Detach the thread to run independently

    std::string message;
    while (true) {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);
        if (message == "exit") { // Check for exit command
            send(client_fd, "Server disconnected", 19, 0); // Send exit command to server
            break;
        }
        send(client_fd, message.c_str(), message.size(), 0);
    }

    close(client_fd);
    return 0;
}
