#include <iostream>
#include <fstream>
using namespace std;

void trojan() {
    ofstream file("important_file.txt");
    if (file.is_open()) {
        file << "Malicious Content Injected!" << endl;
        file.close();
    }
    std::cout << "Trojan executed!" << endl;
}

int main() {
    cout << "Simulating Trojan..." << endl;
    trojan();
    return 0;
}

