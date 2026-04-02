#include <iostream>

// Declare an integer variable named number initialized to 50. Declare an integer pointer named num_ptr 
// and make it point to number. Change the value of number to 99 using only the pointer num_ptr. 
// Print the final value of the variable number.

int main(){
  using namespace std;
 //declaring the int val
 int number = 50;
 int* num_ptr = &number;
 cout<< *num_ptr<<endl;
 *num_ptr = 99;
 cout<<"new num after change: "<< *num_ptr <<endl;
 return 0;
}
