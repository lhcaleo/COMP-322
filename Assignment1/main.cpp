#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//declare functions
void countLetter();
void convertPhonetic();

void factorial();
int factHelper(int n, int r);

void enhancedFactorial();
int factHelperEnhanced(int n, int r);


int main()
{
    countLetter();
    convertPhonetic();
    factorial();
    enhancedFactorial();
    
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
    cin.ignore(); // or use getchar() to remove the "\n"



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

    result = factHelper(number,result);

    cout << "The factorial of " << number << " is " << result << endl;
}
int factHelper(int n, int r){
    if (n == 0) return r;
    return factHelper(n-1, n*r);
}
// if n = 4, fact(4,1) -> fact(3,4*1) -> fact(2,3*4*1) 
//           -> fact(1, 2*3*4*1) -> fact(0,1*2*3*4*1) -> return 1*2*3*4*1

// question 5
void enhancedFactorial(){

    // an array stores the values for the first 6 factorials
    int calculatedFac[6] = {1,2,6,24,120,720};
    
    int number,result = 1;
    cout << "Please enter a number: ";
    cin >> number;

    // if the input number is the one of the first six
    if(number >= 1 && number <= 6){
    cout << "The factorial of " << number << " is " << calculatedFac[number] << endl;
    }
    // when input > 6
    else{

    result = factHelperEnhanced(number,calculatedFac[5]);
    cout << "The factorial of " << number << " is " << result << endl;
    // fact(7,720 = 6!) -> fact(6,7*6!) -> n==6 return 7*6!
    }
}


int factHelperEnhanced(int n, int r){
    if (n == 6) return r;
    return factHelperEnhanced(n-1, n*r);
}





