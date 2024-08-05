#include<iostream>
#include<string>

using namespace std;

char encode(char element){
    //Substitution
    string key[26] = { "QWE", "RTY", "UIO", "PAS", "DFG", "HJK", "LZX", "CVB", "NMQ", "WER",
        "TYU", "IOP", "ASD", "FGH", "JKL", "ZXC", "VBN", "MQW", "ERT", "YUI",
        "OPA", "SDF", "GHJ", "KLZ", "XCV", "BNM"};

    //set the starting seed for generating random numbers
    srand(time(0));

    //Randomly generating index for substitution character
    int ind = rand() % 3;
    
    //Converting character to integer
    char letter = int(toupper(element)) - 65;
    char ch;

    //Substituting character
    ch = key[letter][ind];

    //If the character to be substituted is in lowercase the key will be converted to lowercase
    if(islower(element))
        ch = tolower(ch);

    //Returning the substituted character
    return ch;
}

int main()
{
    string plainText;
    cout<<"Enter Plain Text: ";
    getline(cin, plainText);

    string cipherText;
    for (int i = 0; i < plainText.length(); i++)
    {
        if(plainText[i] == ' ')
            cipherText += plainText[i];
        else{
            char element = encode(plainText[i]);
            cipherText += element;
        }
    }
    cout<<"Cipher Text : "<<cipherText;
    return 0;
}