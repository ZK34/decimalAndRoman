#include <iostream>
using namespace std; 

//Function of the decimal to roman
string decimalToRoman(int input) {
  string output;
  
  //Make a string array and an integer array to store all the possible 
  //combinations of the roman characters
  string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  //Check every place in the input decimal to create the corresponding roman
  for (int i = 0; i < 13; ++i) {
    while(input - decimal[i] >= 0) {
      output += roman[i];
      input -= decimal[i];
    }
  }
  
  return output;
}

//Function of the roman to decimal
int romanToDecimal(string input) {
  int romanLength = input.length();
  int output;
  
  //If the length of the input roman is 0, then return nothing
  if (romanLength == 0) {
    return 0;
  }
  
  //Rule No.1 and No.2
  //Use switch to go over each roman character 
  for (int i = 0; i < romanLength; i++) {
    switch (input[i]) {
      case 'M':
        output += 1000;
        break;
      case 'D':
        output += 500;
        break;
      case 'C':
        output += 100;
        break;
      case 'L':
        output += 50;
        break;
      case 'X':
        output += 10;
        break;
      case 'V':
        output += 5;
        break;
      case 'I':
        output += 1;
        break;
    }
  }

  //Rule No.3 and No.4
  //To check is there are subtractive or representing situation
  for (int i = 1; i < romanLength; i++) {

    if ((input[i] == 'D' || input[i] == 'M') && input[i - 1] == 'C') {
      output -= 100 + 100;
    }

    if ((input[i] == 'L' || input[i] == 'C') && input[i - 1] == 'X') {
      output -= 10 + 10;
    }
    
    if ((input[i] == 'V' || input[i] == 'X') && input[i - 1] == 'I') {
      output -= 1 + 1;
    }
  }
  
  return output;
}

  
int main() { 
  string choice1;
  string choice2;
  int decimal;
  string roman;

  cout << "Is your input a decimal? (Y/N)" << endl;
  cin >> choice1;

  //User wants to make decimal to roman
  if (choice1 == "Y") {
    cout << "Your decimal is : ";
    cin >> decimal;
    cout << "The Roman of this decimal is : " << decimalToRoman(decimal) << endl;
    cout << "Thank you!" << endl;
  }			

  //User wants to make roman to decimal
  else if (choice1 == "N") {
    cout << "Is your input a roman? (Y/N)" << endl;
    cin >> choice2;
    
    if (choice2 == "Y") {
      cout << "Your roman is : ";
      cin >> roman;
      cout << "The decimal of this Roman is : " << romanToDecimal(roman) << endl;
      cout << "Thank you!" << endl;
    }
      
    //Error input
    else {
      cout << "Error input." << endl;
    }
  }
    
  //Error input
  else {
    cout << "Error input." << endl;
  }
  
  return 0;  
}  
