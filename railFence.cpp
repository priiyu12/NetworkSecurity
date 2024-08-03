#include<iostream>
#include<string>
using namespace std;

int main() {
    string plainText;
    int key;
    string cipherText;

    cout << "Enter Plain Text: ";
    getline(cin, plainText);

    cout << "Enter key: ";
    cin >> key;

    if (key <= 1) {
        cout << "Key should be greater than 1" << endl;
        return 1;
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

    return 0;
}
