#include <iostream>

#include "classes.h"

using namespace std;

int main(){
	Object3D o = Object3D("front.txt", "top.txt", 1, 3);
	o.print_vertices();
	o.print_edges();
	Object2D ob = o.project_xy();
	// ob.print_vertices();
	printf("Hello world!\n");
}