#include <iostream>
// #include "point.h"
#include "object3D.h"
using namespace std;

int main(){
	Object3D o = Object3D("obj.txt");
	o.vertices();
	o.edges();

	o.translate(1.0,1.0,1.0);
	o.vertices();

	o.scale(2.0);
	o.vertices();

	o.rotate_z(3.141525);
    o.vertices();
}
