#include <iostream>

int main(){
  using namespace std;
  //Declare an integer variable x initialized to 42. Declare an integer pointer p1 that points to x. 
  //Declare a double integer pointer (pointer to a pointer) p2 that points to p1.
  //Access and print the initial value of x using the double pointer p2.

  //declaring the var
  int x = 42;

  //declaring a pointer
  int* p1 = &x;
  //double int pointer p2
  int** p2 = &p1;
  cout<<"this is p1: "<<*p1<<endl;
  cout<<"here we used the p2: "<< **p2 <<endl;
  return 0;
}
