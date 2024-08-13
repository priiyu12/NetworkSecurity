#include<iostream>
#include<string>

using namespace std;

int main(){
	string key, temp;
	cout<<"Enter Key : ";
	cin>>temp;
	
	for(char &i : temp)
		key+= toupper(i);

	string plainText;
	cout<<"Enter Plain Text : ";
	cin>>plainText;
	
	int n = key.length(); 
	char arr[n][n];
	int k=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==0)
				arr[i][j] = key[j];
			else	
				arr[i][j] = plainText[k++];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<arr[i][j]<<", ";
		}
		cout<<endl;
	}

	 int kval[n] = {0};
    bool used[n] = {false};

    for (int i = 0; i < n; i++) {
        int min = 91; // ASCII value just above 'Z'
        int ind = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && key[j] < min) {
                min = key[j];
                ind = j;
            }
        }

        kval[i] = ind;
        used[ind] = true; // Mark this index as used
    }

	for(int i : kval)
		cout<<i<<" ";

	string cipherText;
	for (int i = 0; i < n; i++)
	{
		int ind = kval[i];
		for (int j = 1; j < n; j++)
		{
			cipherText += arr[j][ind];
		}
	}

	cout<<"Cipher Text: "<<cipherText<<endl;


	return 0;
}