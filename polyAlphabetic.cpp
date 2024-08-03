#include<iostream>
#include<string>
using namespace std;
void encrypt(){
	string plainText;
	cout<<"Enter string: ";
	getline(cin, plainText);

	cout<<plainText<<endl;

	string cipherText;
	int length = plainText.length();
    int p_val[length];
    int key[length + 1];

	cout<<"Enter initial key: ";
	cin>>key[0];

	if(key[0]>25 || key[0]<0){
		cout<<"Invalid Key Value! Please enter key between 0-26";
		exit(0);
	}
	for (int i = 0; i < plainText.length(); i++){
		//For Space
		if(plainText[i] == ' '){
			cipherText += plainText[i];
            key[i + 1] = key[i];
		}
		//For UpperCase
		else if(isupper(plainText[i])){
			p_val[i] = int(plainText[i]) - 65;
			int sum = key[i]+p_val[i];
			if(sum>=26){
				sum = sum - 26;
			}
			cipherText += static_cast<char>(sum+65);
			key[i + 1] = p_val[i];
		}
		//For LowerCase
		else{
			p_val[i] = int(plainText[i]) - 97;
			int sum = key[i]+p_val[i];
			if(sum>=26){
				sum = sum - 26;
			}
			cipherText += static_cast<char>(sum+97);
			key[i + 1] = p_val[i];
		}
		
	}

	cout<<"Cipher Text : "<<cipherText;
}

void decrypt(){
	string cipherText;
    cout << "Enter cipher text: ";
    getline(cin, cipherText);

    cout << cipherText << endl;

    string decryptedText;
    int length = cipherText.length();
    int c_val[length];
    int key[length + 1];

    cout << "Enter initial key: ";
    cin >> key[0];

    if(key[0] > 25 || key[0] < 0) {
        cout << "Invalid Key Value! Please enter key between 0-25";
        exit(0);
    }

    for(int i = 0; i < cipherText.length(); i++) {
    	//For Space
    	if(cipherText[i] == ' '){
			decryptedText += cipherText[i];
            key[i + 1] = key[i];
		}
		//For UpperCase
        else if(isupper(cipherText[i])){
            c_val[i] = int(cipherText[i]) - 65;
            int diff = c_val[i] - key[i];
            if(diff < 0) {
                diff = diff + 26;
            }
            decryptedText += static_cast<char>(diff + 65);
            key[i + 1] = diff;
        }
        //For LowerCase
        else{
            c_val[i] = int(cipherText[i]) - 97;
            int diff = c_val[i] - key[i];
            if(diff < 0) {
                diff = diff + 26;
            }
            decryptedText += static_cast<char>(diff + 97);
            key[i + 1] = diff;
        }
    }

    cout << "Decrypted Text : " << decryptedText;
}
int main(){
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
}