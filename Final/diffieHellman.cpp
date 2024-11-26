#include <iostream>
#include<cmath>

using namespace std;

int power(int base, int exp, int p){
	int result = pow(base,exp);
	return (result % p);
}
int main(){

	int p,g;
	cout<<"Enter Prime P: ";
    cin>>p;
    
    cout<<"Enter G: ";
    cin>>g;
    
    int x, y;
    cout<<"Enter User 1 x value: ";
    cin>>x;
    
    cout<<"Enter User 2 y value: ";
    cin>>y;

    int R1 = power(g, x, p);
    int R2 = power(g, y, p);

    cout<<"Private key of A: "<<R1<<endl;
    cout<<"Private key of B: "<<R2<<endl;

    int keyA=power(R2, x, p);
    int keyB=power(R1, y, p);

    cout<<"Secret Key of User A: "<<keyA<<endl;
    cout<<"Secret Key of User B: "<<keyB<<endl;

    int result = pow(g,(x*y));
    int	key =  result % p;

	if(key==keyA && key==keyB)
		cout<<"Valid keys!";
	else
		cout<<"Invalid keys!";

	return 0;
}