#include <iostream>
using namespace std;
// Equation for comapring the output of the 2 expressions and the answers are either 1 == Equivalent or 0 == Not Equivalent 
bool isEqual(bool array1[8], bool array2[8]) {
    for (int i = 0; i < 8; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

//Function to calculate the Original expression(Given expression)
 bool expression(bool a , bool b, bool c){
     return (~(a | ~b) | (a & b)) & c;
 }
 //Function to calculate the Simplified expression
  bool simplExpression(bool a , bool b, bool c){
     return b & c;
  }
  //Function to print out the answers stored in an array 
  void printArray(bool array[]){
      for (int i =0; i<sizeof(array);i++){
          cout << array[i];
      }
      cout << endl;
  }
  

int main (){
// Initialized arrays to store the output of the expressions
bool origArray[8];
bool simplArray[8];
// Counter to help us store the outputs in the arrays
int counter = 0 ;

// Code to produce the truth table
cout << "a     b     c            Original Expression  Simplified Expression"<<endl;
for (int a = 1; a >= 0; a--){

    for (int b = 1; b >= 0; b--){
        for (int c = 1; c >= 0; c--){
            origArray[counter] = expression(a,b,c);
            simplArray[counter] = simplExpression(a,b,c);
            cout << a << "     " << b << "     " << c << "                    " << expression(a,b,c) << "                    " << simplExpression(a,b,c) << endl ;
            counter ++;
        }
    }
}


cout << endl << "{ Equivalent (1) } or { Not Equivalent (0) }: " << isEqual(origArray,simplArray);


}