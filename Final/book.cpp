#include <iostream>
#include <string>
using namespace std;

bool isPageAllowed(const string& permission, int page) {
    size_t pos = permission.find(':');
    if (pos == string::npos) 
        return false;

    string pages = permission.substr(pos + 1);
    while ((pos = pages.find(',')) != string::npos) {
        if (stoi(pages.substr(0, pos)) == page) 
            return true;
        pages = pages.substr(pos + 1);
    }
    return stoi(pages) == page; // Check the last page
}

int main() {
    string permission = "book1:1,2,3,4,5";
    int pageToCheck = 3;
    cout << (isPageAllowed(permission, pageToCheck) ? "Access granted" : "Access denied") << endl;
    return 0;
}
