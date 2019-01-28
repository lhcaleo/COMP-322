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
// Assume ignoring any input that is not an alphabetical character
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

/* 
Question: Research tail recursivity and explain in your own words 
          why it is better to design your recursive function this way. 
Answer:
    Since we can achieve some optimization from tail recursion, 
  so tail recursion is better than non-tail recursion. 
    By using tail recursion, many extra computations in the recursive 
  calls can be avoid. When we apply regular recursion, a stack is required
  to store all the each recursive calls, and the stack will be poped in
  the last recursive call in order to compute all the results together.
    Depending on the compilers, tail recursion may not need a such long call 
  stack because we return the final result immediately when we reached the last
  recursive call.
    
Question: Can any recursive function be designed to be tail recursive? 
          Please develop your answer by providing clear explanation  
Answer:
    Yes, modifing local code, using control flow mechanisms, and helper functions
     can turn a recursive function to be tail recursive. It is noticable that 
     Continuing-passing(CPS) can be used to transform any function calls to
     tail calls.

*/

// question 4
void factorial(){
    int number,result = 1;
    cout << "Please enter a number: ";
    cin >> number;
    // input check, assume positive integers
    if(number < 0) {
        cout<<"Your input is invalid"<<endl;
        exit(1);
    }
    result = factHelper(number,result);

    cout << "The factorial of " << number << " is " << result << endl;
}
//helper function
int factHelper(int n, int r){
    if (n == 0) return r;
    return factHelper(n-1, n*r);
}

// question 5
void enhancedFactorial(){

    // an array stores the values for the first 6 factorials
    int calculatedFac[6] = {1,2,6,24,120,720};
    
    int number,result = 1;
    cout << "Please enter a number: ";
    cin >> number;
    // input check, assume positive integers
    if(number < 0) {
        cout<<"Your input is invalid"<<endl;
        exit(1);
    }

    // if the input number is the one of the first six
    if(number >= 1 && number <= 6){
    cout << "The factorial of " << number << " is " << calculatedFac[number-1] << endl;
    }
    // when input > 6
    else{

    result = factHelperEnhanced(number,calculatedFac[5]);
    cout << "The factorial of " << number << " is " << result << endl;
    // fact(7,720 = 6!) -> fact(6,7*6!) -> n==6 return 7*6!
    }
}
//helper function
int factHelperEnhanced(int n, int r){
    if (n == 6) return r;
    return factHelperEnhanced(n-1, n*r);
}





