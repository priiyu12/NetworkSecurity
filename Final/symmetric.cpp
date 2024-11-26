#include <iostream>
#include <openssl/rand.h>
#include <iomanip>

using namespace std;

void generateSymmetricKey(int keyLength, const string& algorithmName) {
    unsigned char key[keyLength];

    if (RAND_bytes(key, keyLength) != 1) {
        cout << "Error generating random bytes." << endl;
        return;
    }

    cout << algorithmName << " Symmetric Key (" << keyLength * 8 << " bits): ";
    for (int i = 0; i < keyLength; i++) {
        printf("%02X", key[i]);
    }
    cout << endl; // Add a new line for better formatting
}
int main() {
    generateSymmetricKey(8, "DES");
    generateSymmetricKey(16, "BlowFish");
    generateSymmetricKey(16, "IDEA");
    generateSymmetricKey(24, "TripleDES");

    generateSymmetricKey(16, "HMAC-MD5");
    generateSymmetricKey(20, "HMAC-SHA1");

    return 0;
}

/*#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// Function to generate a symmetric key for a given algorithm
void generateSymmetricKey(int keyLength, string algorithmName) {
    unsigned char key[64];  // Set a maximum key length (e.g., 64 bytes)

    if (keyLength > sizeof(key)) {
        cout << "Key length exceeds maximum size of " << sizeof(key) << " bytes." << endl;
        return;
    }

    std::random_device rd; // Secure random number generator
    for (int i = 0; i < keyLength; ++i) {
        key[i] = static_cast<unsigned char>(rd() % 256); // Generate random byte
    }

    cout << algorithmName << " Symmetric Key (" << keyLength * 8 << " bits): ";

    for (int i = 0; i < keyLength; i++) {
        cout << std::hex << std::setw(2) << std::setfill('0') << (int)key[i];
    }

    cout << endl;
}

int main() {
    int keyLength;
    string algorithmName;

    cout << "Enter the algorithm name: ";
    cin >> algorithmName;

    if (algorithmName == "des") {
        keyLength = 8;  
    } else if (algorithmName == "blowfish" || algorithmName == "idea" || algorithmName == "HmacMD5" || algorithmName == "AES-128") {
        keyLength = 16; 
    } else if (algorithmName == "triple des" || algorithmName == "AES-192") {
        keyLength = 24; 
    } else if (algorithmName == "HmacSHA1") {
        keyLength = 20; 
    } else if (algorithmName == "AES-256") {
        keyLength = 32; 
    } else {
        cout << "Invalid algorithm. Please choose from 'des', 'blowfish', 'idea', 'triple des', 'HmacMD5', 'HmacSHA1', 'AES-128', 'AES-192', or 'AES-256'." << endl;
        return 1;
    }

    generateSymmetricKey(keyLength, algorithmName);

    return 0;
}*/
