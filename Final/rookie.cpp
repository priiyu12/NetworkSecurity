#include <iostream>
#include <string>
using namespace std;

void rootkitHunter() {
    const string files[] = {"normal_file.txt", "hidden_malware", "user_data.txt"};
    
    for (int i = 0; i < 3; ++i) {
        if (files[i].find("malware") != string::npos) {
            cout << "Potential Malware Found: " << files[i] << endl;
        }
    }
}

int main() {
    cout << "Running Rootkit Hunter..." << endl;
    rootkitHunter();
    return 0;
}
