#include <iostream>
#include "classes.h"

using namespace std;

int main(){
   Object3D o = Object3D("obj.txt");
   o.rotate_z(3.14);
   o.print_vertices();
}