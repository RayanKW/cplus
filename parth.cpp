#include <iostream>

int main(){
  using namespace std;
  //Declare an integer array named data with the elements {10, 20, 30, 40, 50}. 
  //Declare an integer pointer data_ptr and point it to the first element of the array. 
  //Use pointer increment (ptr++) and the dereference operator to traverse the array and print all five elements.
  //Given:
    //int data[] = {10, 20, 30, 40, 50};
    //
  int data[] = {10, 20, 30, 40, 50};
  int* data_ptr = data; 
                       //alt:
                       //
                       //int* data_ptr = &data[0]
                       //notice we used the pointer symbol 
  int* end_ptr = end(data);
  while(data_ptr!= end_ptr){
    cout<<"This is the value: "<<*data_ptr<<endl;
    data_ptr++;
  }
  return 0;

}
