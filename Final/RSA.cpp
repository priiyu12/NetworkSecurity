#include<iostream>
#include<cmath>
#include <numeric>

using namespace std;

int main(){
	int p, q;

	//Step 1 : p & q (prime numbers)
	cout<<"Enter p: ";
	cin>>p;
	cout<<"Enter q: ";
	cin>>q;

	//Step 2 : n = p * q
	int n = p*q;

	//Step 3 : phi = (p-1) * (q-1)
	int phi = (p-1)*(q-1);

	//Step 4 : Assume e
	int e;
	while(true){
		cout<<"Enter e: ";
		cin>>e;

		if (e > 1 && e < phi && std::gcd(e, phi) == 1)
			break;
		else
			cout<<"Invalid data as e!";
	}

	//Step 5 : Find d
	int d;
	for(int i = 1; i < phi; i++){
		int temp = ((phi * i) + 1);
		if(temp % e == 0){
			d = temp/e;
			break;
		}
	}

	cout<<"d = "<<d<<endl;

	//Step 6 : Find cipherText & plainText
	int message;
	cout<<"Enter message : ";
	cin>>message;
	
	int result = pow(message, e);
	int cipherText = result % n;
	
	result = pow(cipherText, d);
	int plainText = result % n;

	if(plainText!=message)
		cout<<"Error: Invalid Message decryption";
	else
		cout<<"Cipher Text: "<<cipherText;
}