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
    int total_edge = 0;
public:
    Object3D(string file){
        ifstream myfile;
        myfile.open(file);
        string line;
        int total = 0;
        double a, b, c;
        while (getline(myfile, line)){
            istringstream iss(line);
            if (iss >> a >> b >> c) {
                Point p = Point(a, b, c);
                total++;
                vertex.push_back(p);
            }
            else break;
        }
        myfile.close();
        for (int i=0; i<total; i++){
            vector<int> v;
            edge.push_back(v);
        }
        int x, y;
        ifstream myfile2;
        myfile2.open(file);
        while (getline(myfile2, line)){
            istringstream iss(line);
            if (iss >> x >> y){
            	total_edge++;
                edge.at(x).push_back(y);
                edge.at(y).push_back(x);
            }
        }
        myfile2.close();
       
    }
    int vertices(){
        return vertex.size();
    }
    int edges(){
    	int out = 0;
    	int size_edge = edge.size();
    	for (int i=0; i<size_edge; i++){
    		vector<int> v = edge.at(i);
    		int size_v = v.size();
    		for (int j=0; j< size_v; j++){
    			out++;
    		}
    	}
    	return out;
    }

};