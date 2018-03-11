#include <iostream>
#include <stdlib.h>
#include "point.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Object3D{
private:
    vector<Point> vertex;
    vector<vector<int>> edge;
    int total_vertex = 0;
    int total_edge = 0;
public:
    Object3D(string file){
        ifstream myfile;
        myfile.open(file);
        string line;
        bool vertex_break = true;
        double a, b, c;
        int x, y;
        while (getline(myfile, line)){
            istringstream iss(line);
            if (iss >> a >> b >> c) {
                Point p = Point(a, b, c);
                total_vertex++;
                vertex.push_back(p);
            }
            else if (vertex_break){
                vertex_break = false;
                for (int i=0; i<total_vertex; i++){
                    // cout << "done" << "\n";
                    vector<int> v;
                    edge.push_back(v);
                }
            }
            istringstream isss(line);
            if (isss >> x >> y){
                total_edge++;
                // cout << x << " " << y << "\n";
                edge.at(x).push_back(y);
                edge.at(y).push_back(x);
            }
        }
        myfile.close();
    }
    void vertices(){
        for (int i=0; i<total_vertex; i++){
            vertex[i].print();
        }
    }
    void edges(){
        int size_edge = edge.size();
        for (int i=0; i<size_edge; i++){
            vector<int> v = edge.at(i);
            int size_v = v.size();
            for (int j=0; j< size_v; j++){
                cout << v[j] << " ";
            }
            cout << "\n";
        }
    }
    void translate(double a, double b, double c){
        for (int i=0; i<total_vertex; i++){
            vertex[i].translate(a, b, c);
        }
    }
    void scale(double a){
        for (int i=0; i<total_vertex; i++){
            vertex[i].scale(a);
        }
    }
    void rotate_z(double theta){
        for (int i=0; i<total_vertex; i++){
            vertex[i].rotate_z(theta);
        }
    }
};