#include <iostream>
int main(){
  using namespace std;
  int data[]= {10, 20, 30, 40, 50};
  int* data_ptr = &data[0];
  int size = sizeof(data)/sizeof(data[0]);
  cout<<"this is weird"<<endl;
  for(int i = 0; i<size; i++){
    cout<< "this are the values of data: "<<*data_ptr<<endl;

    data_ptr ++;
  }
}
