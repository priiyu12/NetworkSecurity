#include<iostream>
#include<string>

using namespace std;

void encrypt(){
    string plainText;
    cout<<"Enter Plain Text: ";
    getline(cin,plainText);

    int key;
    cout<<"Enter key: ";
    cin>>key;

    string cipherText;

    for (int i = 0; i < plainText.length(); i++)
    {
        if(plainText[i] == ' ')
            cipherText += plainText[i];
        else{
            if(isupper(plainText[i])){
                int val = (plainText[i] - 'A' + key) % 26;
                cipherText += static_cast<char>(val + 'A');
            }
            else{
                int val = (plainText[i] - 'a' + key) % 26;
                cipherText += static_cast<char>(val + 'a');
            }
        }
    }
    cout<<"Cipher Text : "<<cipherText;
}
void decrypt(){
    string cipherText;
    cout<<"Enter Cipher Text: ";
    getline(cin,cipherText);

    int key;
    cout<<"Enter key: ";
    cin>>key;

    string plainText;

    for (int i = 0; i < cipherText.length(); i++)
    {
        if(cipherText[i] == ' ')
            plainText += cipherText[i];
        else{
            if(isupper(cipherText[i])){
                int val = (cipherText[i] - 'A' - key + 26) % 26;
                plainText += static_cast<char>(val + 'A');
            }
            else{
               int val = (cipherText[i] - 'a' - key + 26) % 26;
                plainText += static_cast<char>(val + 'a');
            }
        }
    }
    cout<<"Plain Text : "<<plainText;
}
int main()
{
    int ch;
    cout<<"Choose: \n1,Encryption\n2.Decryption\n";
    cin>>ch;
    cin.ignore();

    if (ch == 1)
        encrypt();
    else if(ch == 2)
        decrypt();
    else
        cout<<"Invalid Choice!";
    return 0;
}