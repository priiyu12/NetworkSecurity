#include <iostream> //printing text to console
#include <sys/socket.h> //functions and constants for working with sockets
#include <netinet/in.h>//defines structures like sockaddr_in
#include <unistd.h>//provides access to the POSIX operating system API
#include <cstring>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 3);
    
    int client_socket = accept(server_fd, nullptr, nullptr);
    
    const char *hello = "Hello from Server";
    send(client_socket, hello, strlen(hello), 0);
    
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::cout << "Client: " << buffer << std::endl;
    
    close(client_socket);
    close(server_fd);
    return 0;
}
