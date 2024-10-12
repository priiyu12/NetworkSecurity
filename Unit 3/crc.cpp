#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b){
    string result = "";

    for (int i = 1; i < b.length(); i++)    //Start from index 1 skipping the leading bits
        result += (a[i] == b[i]) ? '0' : '1'; //If equal then 0, else 1

    return result;
}

string crcDivision(string dividend, string divisor, int keylen){
    string tempDiv = dividend.substr(0, keylen);

    for (int i = keylen; i < dividend.length(); i++) {
        
        if (tempDiv[0] == '1')  // If the first bit of tempDiv is '1', perform XOR with the divisor
            tempDiv = xorOperation(divisor, tempDiv) + dividend[i];
        
        else    // Else perform XOR with a string of zeroes equal to keylength
            tempDiv = xorOperation(string(keylen, '0'), tempDiv) + dividend[i];
    }

    //If tempDiv has 1 in leading, one last XOR operation for the remaining bits
    if (tempDiv[0] == '1')
        tempDiv = xorOperation(divisor, tempDiv);

    return tempDiv;
}

int main() {
	string data, key;
	cout<<"Enter the data:";
    cin>>data;
    cout<<"Enter the key:";
    cin>>key;

    int keylen = key.length();
    string dividend = data + string(keylen - 1, '0');
    string remainder = crcDivision(dividend, key, keylen);

    string encodedData = data + remainder; //Adding CRC behind the data to send to receiver's end

    cout << "Remainder (CRC): " << remainder << endl;
    cout << "Encoded Data (data + CRC): " << encodedData << endl;

	return 0;
}