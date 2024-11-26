#include <iostream>
#include <string>

using namespace std;

string createCertificateName;
string createCertificatePublicKey;
string createCertificateSignature;

void createCertificate(const string& name, const string& publicKey) {
    createCertificateName = name;
    createCertificatePublicKey = publicKey;
    createCertificateSignature = "secure_signature"; // Simulating a signature
}

bool validateCertificate() {
    return createCertificateSignature == "secure_signature";
}

int main() {
    createCertificate("Alice", "PublicKey123");
    cout << "Certificate Created for: " << createCertificateName << endl;
    cout << "Validating Certificate..." << endl;

    if (validateCertificate()) {
        cout << "Certificate is valid!" << endl;
    } else {
        cout << "Certificate is invalid!" << endl;
    }

    return 0;
}