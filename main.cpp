/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//declare functions
void countLetter();
void convertPhonetic();
void factorial();
void enhancedFactorial();


int main()
{
    countLetter();
    convertPhonetic();
    factorial();
 //   enhancedFactorial();
    
    return 0;
}

// question 1
void countLetter(){
    string sentence;
    char letter;
    int count = 0;
    
    cout << "Please enter a sentence: ";
    getline(cin,sentence);
    

    
    cout << "Please enter a letter: ";
    letter = getchar();
    cin.ignore();
    
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] == letter){
            count++;
        }
    }
    cout << "The letter " << letter <<" is repeated " << count << " times in your sentence" << endl;
}

// question 2
void convertPhonetic(){
    string word;
    string newWord;
    
    cout << "Please enter a word: ";
    getline(cin,word);
    
    for(int i = 0; i < word.length(); i++){
        switch (word[i]){
            case 'A':
            case 'a':
                newWord.append("Alfa ");
                break;
            case 'B':
            case 'b':
                newWord.append("Bravo ");
                break;
            case 'C':
            case 'c':
                newWord.append("Charlie ");
                break;
            case 'D':
            case 'd':
                newWord.append("Delta ");
                break;
            case 'E':
            case 'e':
                newWord.append("Echo ");
                break;
            case 'F':
            case 'f':
                newWord.append("Foxtrot ");
                break;
            case 'G':
            case 'g':
                newWord.append("Golf ");
                break;
            case 'H':
            case 'h':
                newWord.append("Hotel ");
                break;            
            case 'I':
            case 'i':
                newWord.append("India ");
                break;            
            case 'J':
            case 'j':
                newWord.append("Juliuett ");
                break;            
            case 'K':
            case 'k':
                newWord.append("Kilo");
                break;
            case 'L':
            case 'l':
                newWord.append("Lima ");
                break;            
            case 'M':
            case 'm':
                newWord.append("Mike ");
                break;            
            case 'N':
            case 'n':
                newWord.append("November ");
                break;            
            case 'O':
            case 'o':
                newWord.append("Oscar ");
                break;            
            case 'P':
            case 'p':
                newWord.append("Papa ");
                break;            
            case 'Q':
            case 'q':
                newWord.append("Quebec ");
                break;            
            case 'R':
            case 'r':
                newWord.append("Romeo ");
                break;            
            case 'S':
            case 's':
                newWord.append("Sierra ");
                break;            
            case 'T':
            case 't':
                newWord.append("Tango ");
                break;
            case 'U':
            case 'u':
                newWord.append("Uniform ");
                break;
            case 'V':
            case 'v':
                newWord.append("Victor ");
                break;
            case 'W':
            case 'w':
                newWord.append("Whiskey ");
                break;
            case 'X':
            case 'x':
                newWord.append("X-ray ");
                break;
            case 'Y':
            case 'y':
                newWord.append("Yankee ");
                break;
            case 'Z':
            case 'z':
                newWord.append("Zulu ");
                break;
        }
    }
    cout << newWord << endl;
}

// question 3

/* Answer:

*/

// question 4
void factorial(){
    int number,result = 1;
    cout << "Please enter a number: ";
    cin >> number;
// TODO



    cout << "The factorial of " << number << " is " << result;
}













