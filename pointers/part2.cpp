#include <iostream>
#include <span>

int main(){

  using namespace std;
  int data[]={10, 20, 30, 40, 50};
  span<int>data_span(data); //span knows length
  for(int value: data_span){
    cout<<"the value: "<<value<<endl;
    
  }
return 0;

}
