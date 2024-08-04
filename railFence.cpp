#include<iostream>
#include<string>
using namespace std;
void decrypt() {
    string cipherText;
    int key;
    string plainText;

    cout << "Enter Cipher Text: ";
    getline(cin, cipherText);

    cout << "Enter key: ";
    cin >> key;

    if (key <= 1) {
        cout << "Key should be greater than 1" << endl;
        exit(0);
    }

    int length = cipherText.length();
    char arr[key][length];

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            arr[i][j] = '*';
        }
    }

    bool down = false;
    int row = 0, col = 0;

    for (int i = 0; i < length; i++) {
        if (row == 0) {
            down = true;
        }
        if (row == key - 1) {
            down = false;
        }

        arr[row][col++] = '?';

        if (down) {
            row++;
        } else {
            row--;
        }
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            if (arr[i][j] == '?' && index < length) {
                arr[i][j] = cipherText[index++];
            }
        }
    }

    down = true;
    row = 0;
    col = 0;

    for (int i = 0; i < length; i++) {
        if (row == 0) {
            down = true;
        }
        if (row == key - 1) {
            down = false;
        }

        plainText += arr[row][col++];

        if (down) {
            row++;
        } else {
            row--;
        }
    }

    cout << "Plain Text: " << plainText << endl;
}
void encrypt() {
    string plainText;
    int key;
    string cipherText;

    cout << "Enter Plain Text: ";
    getline(cin, plainText);

    cout << "Enter key: ";
    cin >> key;

    if (key <= 1) {
        cout << "Key should be greater than 1" << endl;
        exit(0);
    }

    int length = plainText.length();
    char arr[key][length];

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            arr[i][j] = '*';
        }
    }

    bool down = false;
    int row = 0, col = 0;

    for (int i = 0; i < length; i++) {
        if (row == 0 || row == key - 1) {
            down = !down;
        }

        arr[row][col++] = plainText[i];

        if (down) {
            row++;
        } else {
            row--;
        }
    }

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            if (arr[i][j] != '*') {
                cipherText += arr[i][j];
            }
        }
    }

    cout << "Cipher Text: " << cipherText << endl;
}

int main()
{
    int ch;
    cout<<"Choose : "<<endl<<"1. Encryption\t2. Decryption"<<endl;
    cin>>ch;
    cin.ignore();
    switch(ch){
        case 1:
            encrypt();
            break;

        case 2:
            decrypt();
            break;

        default :
            cout<<"Invalid choice!";
    }

    return 0;
}
