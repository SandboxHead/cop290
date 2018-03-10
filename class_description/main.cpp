#include <iostream>
// #include "point.h"
#include "object3D.h"
using namespace std;

int main(){
	Object3D o = Object3D("obj.txt");
	int len;
	len = o.edges();
	printf ("%d", len);
}
