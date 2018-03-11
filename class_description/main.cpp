#include <iostream>
// #include "point.h"

#include "classes.h"
using namespace std;

int main(){
    Object3D o = Object3D("out.txt");
    o.vertices();
    o.edges();

    Object2D ob = o.project_xy();
    ob.print_edges();
    ob.print_vertex();
    
}
