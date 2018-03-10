#include <iostream>

using namespace std;

class Point{
    double x;
    double y;
    double z;
public:
    Point(double a, double b, double c){
        x = a;
        y = b;
        z = c;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    double getZ(){
        return z;
    }

    void changeVal(double a, double b, double c){
        x = a;
        y = b;
        z = c;
    }
    void changeX(double a){
        x = a;
    }
    void changeY(double b){
        y = b;
    }
    void changeZ(double c){
        z = c;
    }
    void print(){
        printf ("(%f, %f, %f)\n", x , y, z);
    }

};

