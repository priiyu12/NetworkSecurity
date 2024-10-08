#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Calculate number of 1's in the line
int calculate_vrc(string line)
{
   int count = 0;
    for(int i=0; i<line.length(); i++)
    {
        if(line[i] == '1')
        	count++;
    }
    return count;
}

int main() {
    string lines[4];
    int count = 0;
    string line;
    int num;
    int n;
    
    //Assign the file to be used
    ifstream file("data.txt");

    //Storing lines of file in array
    while (getline(file, line) && count < 4) {
        lines[count] = line;
        count++;
    }

    //Printing content of file
    cout << "Contents of the array:\n";
    for (int i = 0; i < count; i++) {
        cout << lines[i] << endl;
    }

    //Closing File
     file.close();

    cout<<"Enter 0 for ODD\nENTER 1 for EVEN\n";
    cin>>n;

    //Loop to append VRC as per parity
    for (int i = 0; i < count; i++)
    {
    	//Function to calculate number of 1's
    	num = calculate_vrc(lines[i]);

    	//Odd parity selected
    	if(n==0){

    		// If Number of 1's are even
    		if(num%2==0){
    			lines[i].append("1");
                cout<<"\n"<<lines[i];
    		}
    		// If Number of 1's are odd
    		else{
    			lines[i].append("0");
                cout<<"\n"<<lines[i];
    		}
    	}
    	else if(n==1){

    		// If Number of 1's are even
    		if(num%2==0){
    			lines[i].append("0");
                cout<<"\n"<<lines[i];
    		}

    		// If Number of 1's are odd
    		else{
    			lines[i].append("1");
                cout<<"\n"<<lines[i];
    		}
    	}
    	else{
    		cout<<"Invalid Choice!";
    	}
    }

    return 0;
}