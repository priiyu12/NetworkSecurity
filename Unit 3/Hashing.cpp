#include <iostream>
#include <string>

unsigned int RSHash(string str){
    unsigned int a = 378551;
    unsigned int b = 63689;
    unsigned int hash = 0;

    for (int i = 0; i < str.length(); i++){
        hash = hash * a + str[i];
        a = a * b;
    }
    return hash;
}

unsigned int JSHash(string str){
    unsigned int hash = 1315423911;
    for (int i = 0; i < str.length(); i++){
        hash ^= ((hash<<5) + str[i] + (hash>>2));
    }
    return hash;
}

unsigned int BKDRHash(string str){
    unsigned int hash = 131;
    for (int i = 0; i < str.length(); i++){
        hash = hash * seed + str[i];
    }
    return hash;
}

unsigned int SDBMHash(string str){
    unsigned int hash = 0;
    for (int i = 0; i < str.length(); i++){
        hash = str[i] + (hash<<6) + (hash<<16) - hash;
    }
    return hash;
}

unsigned int DJBHash(string str){
    unsigned int hash = 5381;
    for (int i = 0; i < str.length(); i++){
        hash = ((hash<<5) + hash) + str[i];
    }
}

int main() {
    string input;

    // Ask user to input a string
    cout << "Enter a string to hash: ";
    getline(cin, input);
    
    // Output hash results
    cout << "RSHash: " << RSHash(input) << endl;
    cout << "JSHash: " << JSHash(input) << endl;
    cout << "BKDRHash: " << BKDRHash(input) << endl;
    cout << "SDBMHash: " << SDBMHash(input) << endl;
    cout << "DJBHash: " << DJBHash(input) << endl;

    return 0;
}