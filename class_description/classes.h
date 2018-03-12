#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <utility>
#include <cstdlib>

using namespace std;

class Point2D{
private:
    void product(double inp[3][3]){
        double temp[3] = {0.0 , 0.0, 0.0};
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                temp[i] = temp[i] + arr[j]*inp[i][j];
            }
        }
        for (int i=0; i<3; i++){
            arr[i] = temp[i];
        }
    }
    double arr[3];
public:
    Point2D (double inp[3]){
        for (int i=0; i<3; i++){
            arr[i] = inp[i];
        }
    }
    Point2D(double a, double b){
        arr[0] = a;
        arr[1] = b;
        arr[2] = 1.0;
    }
    double getX(){
        return arr[0];
    }
    double getY(){
        return arr[1];
    }
    void changeVal(double a, double b){
        arr[0] = a;
        arr[1] = b;
    }
    void changeX(double a){
        arr[0] = a;
    }
    void changeY(double b){
        arr[1] = b;
    }
    void print(){
        printf ("(%f, %f)\n", arr[0] , arr[1]);
    }
    void translate(double a, double b){
        double trans[3][3] = {{1.0, 0.0, a},
                              {0.0, 1.0, b},
                              {0.0, 0.0, 1.0}};

        product(trans);

    }
    void scale (double a){
        changeVal(arr[0]*a, arr[1]*a);
    }
    void rotate_origin (double theta){
        double trans[3][3] = {{cos(theta), -sin(theta), 0.0},
                              {sin(theta), cos(theta), 0.0},
                              {0.0, 0.0, 1.0}};
        product(trans);

    }
    void rotate(double theta, double x0, double y0){
        translate(-x0, -y0);
        rotate_origin(theta);
        translate(x0, y0);
    }
};

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
        product(trans);

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
    void rotate_x (double theta){
        double trans[4][4] = {{1.0, 0.0, 0.0, 0.0},
                              {0.0, cos(theta), -sin(theta), 0.0},
                              {0.0, sin(theta), cos(theta), 0.0},
                              {0.0, 0.0, 0.0, 1.0}};
        product(trans);

    }
    void rotate_y(double theta){
        double trans[4][4] = {{cos(theta), 0.0, sin(theta), 0.0},
                              {0.0, 1.0, 0.0, 0.0},
                              {-sin(theta), 0.0, cos(theta), 0.0},
                              {0.0, 0.0, 0.0, 1.0}};
        product(trans);

    }
    void rotate(double theta, double a, double b, double c){
        double alpha;
        if (b==0.0 && c==0.0){
            alpha = 0.0;
        }
        else{
            alpha = atan(b/c);
        }
        double beta = atan(a/sqrt(b*b + c*c));
        cout << beta << endl;
        rotate_x(alpha);
        rotate_y(-beta);
        rotate_z(theta);
        rotate_y(beta);
        rotate_x(-alpha);
    }
    void rotate(double theta, double a, double b, double c, double x0, double y0, double z0){
        translate(-x0, -y0, -z0);
        rotate(theta, a, b, c);
        translate(x0, y0, z0);
    }
    Point2D project_xy(){
        Point2D p = Point2D(arr[0], arr[1]);
        return p;
    }
    Point2D project(double a, double b, double c){
        double alpha;
        if (b==0.0 && c==0.0){
            alpha = 0.0;
        }
        else{
            alpha = atan(b/c);
        }
        double beta = atan(a/sqrt(b*b + c*c));
        rotate_x(-alpha);
        rotate_y(beta);
        Point2D out = project_xy();
        rotate_y(-beta);
        rotate_x(alpha);
        return out;
    }
};

class Object2D{
    /*!
     *This is for providing options to create a 2D graph(having 3 different projections) from files.
     */

private:
    vector<Point2D> points;
    vector<vector<int>> edges;

public:
    Object2D(const string &filename){
        string line;
        ifstream inFile;

        inFile.open(filename);

        if(!inFile){
            cout << "Unable to open file";
        }
        double a, b;
        int x, y;
        bool data_change=false;
        bool data_2=false;
        int point_count=0;

        while(getline(inFile, line))
        {
            istringstream iss(line);
            if(iss >> a >> b )
            {
                Point2D p  = Point2D(a, b);
                point_count++;
                points.push_back(p);
            }
            else if(!data_2)
            {
                data_change=true;

            }
            if(data_change)
            {
                data_change = false;
                data_2 =true;
                for(int j=0; j<point_count; j++)
                {
                    vector<int> v;
                    edges.push_back(v);
                }
            }
            istringstream ss(line);
            if(ss >> x >> y)
            {
                edges.at(x).push_back(y);
                edges.at(y).push_back(x);
            }
        }
        inFile.close();


    }
    Object2D(vector<Point2D> vertices_inp, vector<vector<int>> edges_inp){
        points = move(vertices_inp);
        edges = move(edges_inp);
    }
    /*!
     *This function will take a input and store the 2D projections in appropriate data structures.
     *Input can be provided in suitable data structures, such as a array or list of edges and overlapping points in different set of lists or array.
     *The 2D graph generated will be used by different classes.
     */
    void print_edges() {
        int edge_size = edges.size();
        for (int i=0; i<edge_size; i++) {
            int internal = edges[i].size();
            for(int j=0; j<internal; j++)
            {
                cout << edges[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void print_vertex() {
        int point_size = points.size();
        for (int i=0; i<point_size; i++) {
            cout << points[i].getX() << "," << points[i].getY()  << " " << endl;
        }

    }

};

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
    void rotate(double theta, double a, double b, double c){
        for (int i=0; i<total_vertex; i++){
            vertex[i].rotate(theta, a, b, c);
        }
    }
    void rotate(double theta, double a, double b, double c, double x0, double y0, double z0){
        for (int i=0; i<total_vertex; i++){
            vertex[i].rotate(theta, a, b, c, x0, y0, z0);
        }
    }
    Object2D project_xy(){
        vector<Point2D> points;
        for (int i=0; i<total_vertex; i++){
            Point2D temp = vertex[i].project_xy();
            points.push_back(temp);
        }
        Object2D out = Object2D(points, edge);
        return out;
    }
    Object2D project(double a, double b, double c){
        vector<Point2D> points;
        for (int i=0; i<total_vertex; i++){
            Point2D temp = vertex[i].project(a, b, c);
            points.push_back(temp);
        }
        Object2D out = Object2D(points, edge);
        return out;
    }
};