#include<iostream>
#include<string>
using namespace std;

void encrypt(){
	string plainText;
	cout<<"Enter Plain Text : ";
	getline(cin, plainText);

	string key;
	cout<<"Enter Key : ";
	getline(cin, key);

	string cipherText;
	for (int i = 0; i < plainText.length(); i++)
	{
		if(plainText[i] == ' '){
			cipherText += plainText[i];
		}

		else{
			if(isupper(plainText[i])){
				int pval = int(plainText[i])-65;
				int kval = int(key[i])-65;
				int cval = pval+kval;
				if(cval>=26)
					cval -= 26;
				cipherText += static_cast<char>(cval+65);
			}
			else{
				int pval = int(plainText[i])-97;
				int kval = int(key[i])-97;
				int cval = pval+kval;
				if(cval>=26)
					cval -= 26;
				cipherText += static_cast<char>(cval+97);
			}
		}
	}
	cout<<"Cipher Text : "<<cipherText;
}

void decrypt(){
	string cipherText;
	cout<<"Enter Cipher Text : ";
	getline(cin, cipherText);

	string key;
	cout<<"Enter Key : ";
	getline(cin, key);

	string decryptedText;
	for (int i = 0; i < cipherText.length(); i++)
	{
		if(cipherText[i] == ' '){
			decryptedText += cipherText[i];
		}

		else{
			if(isupper(cipherText[i])){
				int pval = int(cipherText[i])-65;
				int kval = int(key[i])-65;
				//cout<<"pval = "<<pval<<" , cval = "<<kval<<endl;
				int cval = pval-kval;
				//cout<<"cval = "<<cval<<endl;
				if(cval>=26)
					cval -= 26;
				//cout<<"cval = "<<cval<<endl;
				if(cval<0)
					cval += 26;
				decryptedText += static_cast<char>(cval+65);
			}
			else{
				int pval = int(cipherText[i])-97;
				int kval = int(key[i])-97;
				//cout<<"pval = "<<pval<<" , cval = "<<kval<<endl;
				int cval = pval-kval;
				//cout<<"cval = "<<cval<<endl;
				if(cval>=26)
					cval -= 26;
				//cout<<"cval = "<<cval<<endl;
				if(cval<0)
					cval += 26;
				decryptedText += static_cast<char>(cval+97);
			}
		}
	}
	cout<<"Decrypted Text : "<<decryptedText;
}

int main(){
	int ch;
	int x;
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