#include<iostream>
#include<string>

using namespace std;

string xorOperation(string a, string b){
	string result = "";

	for(int i=1; i<b.length(); i++)
		result += (a[i]==b[i]) ? '0' : '1';
	return result;
}

string crcDivision(string dividend, string key, int keylen){
	string tempDiv = dividend.substr(0, keylen);
	for(i=keylen; i<dividend.length(); i++){
		
		if(tempDiv[0]=='1')
			tempDiv = xorOperation(key, tempDiv) + dividend[i];

		else
			tempDiv = xorOperation(string(keylen, '0'), tempDiv) + dividend[i];
	}

	if(tempDiv[0]=='1'){
		tempDiv = xorOperation(key, tempDiv);
	}

	return tempDiv;
}

int main(){

	string key, data;

	cout<<"Enter data : ";
	cin>>data;

	cout<<"Enter data : ";
	cin>>key;

	int keylen = key.length();

	string dividend = data + string(keylen-1, '0');
	string remainder = crcDivision(dividend, key, keylen)

	string encodedData = data + remainder;

	cout << "Remainder (CRC): " << remainder << endl;
    cout << "Encoded Data (data + CRC): " << encodedData << endl;

	return 0;
}