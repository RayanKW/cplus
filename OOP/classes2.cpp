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
  static int ammo(){return 2;}
};

