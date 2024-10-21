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

void generateHmacKey(int keyLength, const string& algorithmName) {
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

    generateHmacKey(16, "HMAC-MD5");
    generateHmacKey(20, "HMAC-SHA1");

    return 0;
}
