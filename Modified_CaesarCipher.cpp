//Modified_CaesarCipher.cpp
#include<iostream>
#include<string>
using namespace std;

void encrypt(){
	string plainText;
	string cipherText;
	int element;
	cout << "Enter Plain Text: ";
    getline(cin, plainText);

    int key;
    cout << "Enter key: ";
    cin >> key;

    for (int i = 0; i < plainText.length(); i++)
    {
    	if(plainText[i] == ' ')
    		cipherText += plainText[i];

    	else if(isupper(plainText[i])){
    		element = int(plainText[i]) + key;
    		cipherText += static_cast<char>(element);
    	}

    	else{
    		element = int(plainText[i]) + key;
    		cipherText += static_cast<char>(element);
    	}
    }

    cout<<"Cipher Text : "<<cipherText;
}
void decrypt(){
	string decryptText;
	string cipherText;
	int element;
	cout << "Enter Cipher Text: ";
    getline(cin, cipherText);

    int key;
    cout << "Enter key: ";
    cin >> key;

    for (int i = 0; i < cipherText.length(); i++)
    {
    	if(cipherText[i] == ' ')
    		decryptText += cipherText[i];

    	else if(isupper(cipherText[i])){
    		element = int(cipherText[i]) - key;
    		decryptText += static_cast<char>(element);
    	}

    	else{
    		element = int(cipherText[i]) - key;
    		decryptText += static_cast<char>(element);
    	}
    }

    cout<<"Decrypted Text : "<<decryptText;
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
