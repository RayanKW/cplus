#include <iostream>
using namespace std; 

class monster{
  int health, ammo;
  public:
  monster(int he=100, int am=10){
    health = he;
    ammo = am;
  }
  void draw(int x, int y, int scale, int position);
  int get_health(){return health;}
  int get_ammo(){return ammo;}
};
int main(){
  monster m; //making the moster object.
  cout<<"print this: "<< m.get_ammo()<<endl; // here to access
}
