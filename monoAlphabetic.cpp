#include<iostream>
#include<string>
using namespace std;
int main(){
	char key[26] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
	int ch;
	cout<<"Choose : "<<endl<<"1. Encryption\t2. Decryption"<<endl;
	cin>>ch;
	cin.ignore();
	
	if(ch==1){
		string plainText;
		cout<<"Enter string: ";
		getline(cin, plainText);
		cout<<plainText<<endl;
		string cipherText;

		for(int i = 0; i < plainText.length(); i++)
		{
			if(plainText[i] == ' '){
				cipherText += plainText[i];
			}
			else{
				if(isupper(plainText[i])){
					int num = int(plainText[i]);
					cipherText += toupper(key[num-65]);				
				}
				else{
					int num = int(plainText[i]);
					cipherText += key[num-97];
				}

			}
		}
		cout<<"Cipher Text: "<<cipherText<<endl;
	}
	else if(ch==2){
		string cipherText;
		string decryptText;
		char element;

		cout<<"Enter string: ";
		getline(cin, cipherText);

		for (int i = 0; i < cipherText.length(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if(cipherText[i] == ' ')
					decryptText += cipherText[i];

				else if(isupper(cipherText[i])){
					element = tolower(cipherText[i]);
					if(element == key[j])
						decryptText += static_cast<char>(j+65);
				}
				else{
					if(cipherText[i] == key[j])
						decryptText += static_cast<char>(j+97);
				}
			}
		}
		cout<<"Decrypted Text : "<<decryptText;
	}
	else{
		cout<<"Invalid Choice!";
	}
	return 0;
}