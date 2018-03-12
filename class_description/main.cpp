#include <iostream>
#include "classes.h"
// #include <QtGui>

using namespace std;

int main(){
    Object3D o = Object3D("out.txt");
    o.vertices();
    // o.edges();

    Object2D ob = o.project(0.0, 0.0, 1.0);
    // ob.print_edges();
    ob.print_vertex();
    o.vertices();
}
