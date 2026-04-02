// Declare an integer variable named value and initialize it to 100. Declare an integer pointer named ptr.
// Assign the memory address of value to ptr. Finally, print the integer stored in value by using only the 
// pointer ptr and the dereference operator.

#include <iostream>

int main(){
  int value = 100;
  int* ptr = &value;
  std::cout << "this is the value: " << *ptr << std::endl;
  return 0
}
