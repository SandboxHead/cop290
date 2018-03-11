#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    void product(double inp[4][4]){
        double temp[4] = {0.0 , 0.0, 0.0, 0.0};
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                temp[i] = temp[i] + arr[j]*inp[i][j];
            }
        }
        for (int i=0; i<4; i++){
            arr[i] = temp[i];
        }
    }
    
    double arr[4];
public:
    Point (double inp[4]){
        for (int i=0; i<4; i++){
            arr[i] = inp[i];
        }
    }
    Point(double a, double b, double c){
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = 1.0;
    }
    double getX(){
        return arr[0];
    }
    double getY(){
        return arr[1];
    }
    double getZ(){
        return arr[2];
    }

    void changeVal(double a, double b, double c){
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
    }
    void changeX(double a){
        arr[0] = a;
    }
    void changeY(double b){
        arr[1] = b;
    }
    void changeZ(double c){
        arr[2] = c;
    }
    void print(){
        printf ("(%f, %f, %f)\n", arr[0] , arr[1], arr[2]);
    }
    void translate(double a, double b, double c){
        double trans[4][4] = {{1.0, 0.0, 0.0, a},
                              {0.0, 1.0, 0.0, b},
                              {0.0, 0.0, 1.0, c},
                              {0.0, 0.0, 0.0, 1.0}};
        product(trans);;
    }
    void scale (double a){
        changeVal(arr[0]*a, arr[1]*a, arr[2]*a);
    }
    void rotate_z (double theta){
        double trans[4][4] = {{cos(theta), -sin(theta), 0.0, 0.0},
                              {sin(theta), cos(theta), 0.0, 0.0},
                              {0.0, 0.0, 1.0, 0.0},
                              {0.0, 0.0, 0.0, 1.0}};
        product(trans);
    }
};

