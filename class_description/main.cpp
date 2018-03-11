#include <iostream>
// #include "point.h"
#include "object3D.h"
using namespace std;

int main(){
	Object3D o = Object3D("out.txt");
	o.vertices();
	// o.edges();

	o.translate(1.0,1.0,1.0);
	// o.vertices();

	o.scale(2.0);
	o.vertices();

	o.rotate(3.141525, 0.0, 0.0, 1.0);
    o.vertices();
}
