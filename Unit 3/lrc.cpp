#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int calculate_lrc(string line) {
    int count = 0;
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == '1')
            count++;
    }
    return count;
}

int main() {
    string lines[4];
    int count = 0;
    string line;
    string parity = "";
    string check = "";
    int num;
    int n;
    
    // Assign the file to be used
    ifstream file("data.txt");

    // Storing lines of file in array
    while (getline(file, line) && count < 4) {
        lines[count] = line;
        count++;
    }

    // Closing File
    file.close();

    cout << "Enter 0 for ODD\nENTER 1 for EVEN\n";
    cin >> n;

    // Printing content of file
    cout << "Contents of the array:\n";
    for (int i = 0; i < count; i++) {
        cout << lines[i] << endl;
    }

    // Loop to append LRC as per parity
    for (int i = 0; i < lines[0].length(); i++) {
        // Store all the 1's in vertical order
        for (int j = 0; j < count; j++) {
            check.append(1, lines[j][i]); // Append each character vertically
        }
        
        // Function to calculate number of 1's
        num = calculate_lrc(check);

        if (n == 0) {
            // If Number of 1's are even
            if (num % 2 == 0) {
                parity.append("1");
            }
            // If Number of 1's are odd
            else {
                parity.append("0");
            }
        } else if (n == 1) {
            // If Number of 1's are even
            if (num % 2 == 0) {
                parity.append("0");
            }
            // If Number of 1's are odd
            else {
                parity.append("1");
            }
        } else {
            cout << "Invalid Choice!";
        }

        // Clear the check string for the next column
        check.clear();
    }

    // Output the final parity bits
    cout << parity << endl;

    return 0;
}
