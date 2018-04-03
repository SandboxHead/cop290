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
//    void rotate_z (double theta){
//        double trans[4][4] = {{cos(theta), -sin(theta), 0.0, 0.0},
//                              {sin(theta), cos(theta), 0.0, 0.0},
//                              {0.0, 0.0, 1.0, 0.0},
//                              {0.0, 0.0, 0.0, 1.0}};
//        product(trans);
//
//    }
//    void rotate_x (double theta){
//        double trans[4][4] = {{1.0, 0.0, 0.0, 0.0},
//                              {0.0, cos(theta), -sin(theta), 0.0},
//                              {0.0, sin(theta), cos(theta), 0.0},
//                              {0.0, 0.0, 0.0, 1.0}};
//        product(trans);
//
//    }
//    void rotate_y(double theta){
//        double trans[4][4] = {{cos(theta), 0.0, sin(theta), 0.0},
//                              {0.0, 1.0, 0.0, 0.0},
//                              {-sin(theta), 0.0, cos(theta), 0.0},
//                              {0.0, 0.0, 0.0, 1.0}};
//        product(trans);
//
//    }
//    void rotate(double theta, double a, double b, double c){
//        double alpha;
//        if (b==0.0 && c==0.0){
//            alpha = 0.0;
//        }
//        else{
//            alpha = atan(b/c);
//        }
//        double beta = atan(a/sqrt(b*b + c*c));
//        cout << beta << endl;
//        rotate_x(alpha);
//        rotate_y(-beta);
//        rotate_z(theta);
//        rotate_y(beta);
//        rotate_x(-alpha);
//    }
//    void rotate(double theta, double a, double b, double c, double x0, double y0, double z0){
//        translate(-x0, -y0, -z0);
//        rotate(theta, a, b, c);
//        translate(x0, y0, z0);
//    }
//    vector<> project_xy(){
//
//    }
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
        // cout << beta << endl;
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

    Point2D project_yz(){
        Point2D p = Point2D(arr[1], arr[2]);
        return p;
    }

    Point2D project_zx(){
        Point2D p = Point2D(arr[2], arr[0]);
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
    vector<Point2D> vertices;
    vector<vector<int> > edges;
    int total_vertex = 0;
    int total_edge = 0;

public:
    Object2D(string file){
        ifstream myfile;
        myfile.open(file.c_str());
        string line;
        bool vertex_break = true;
        double a, b;
        int x, y;
        while (getline(myfile, line)){
            istringstream iss(line);
            if (iss >> a >> b && vertex_break) {
                Point2D p = Point2D(a, b);
                total_vertex++;
                vertices.push_back(p);
            }
            else if (vertex_break){
                vertex_break = false;
                for (int i=0; i<total_vertex; i++){
                    // cout << "done" << "\n";
                    vector<int> v;
                    edges.push_back(v);
                }
            }
            else{
                istringstream isss(line);
                if (isss >> x >> y){
                    total_edge++;
                    // cout << x << " " << y << "\n";
                    edges.at(x).push_back(y);
                    edges.at(y).push_back(x);
                }
            }
        }
        myfile.close();
    }


    Object2D(vector<Point2D> vertices_inp, vector<vector<int> > edges_inp){
        vertices = vertices_inp;
        edges = edges_inp;
    }
    vector<Point2D> give_vertices(){
        return vertices;
    }
    int edges_total(){
        return total_edge;
    }
    vector<vector<int> > give_edges(){
        return edges;
    }

    void translate(double a, double b){
        for (int i=0; i<vertices.size(); i++){
            vertices[i].translate(a, b);
        }
    }
    /*!
     *This function will take a input and store the 2D projections in appropriate data structures.
     *Input can be provided in suitable data structures, such as a array or list of edges and overlapping points in different set of lists or array.
     *The 2D graph generated will be used by different classes.
     */
    void print_edges()
    {
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
    void print_vertices()
    {
        int point_size = vertices.size();
        for (int i=0; i<point_size; i++) {
            cout << vertices[i].getX() << "," << vertices[i].getY()  << " " << endl;
        }

    }

};

class Object3D{
private:
    vector<Point> vertices;
    vector<vector<int> > edges;
    int total_vertex = 0;
    int total_edge = 0;
public:
    Object3D(){
        
    }
    Object3D(string file){
        ifstream myfile;
        myfile.open(file.c_str());
        string line;
        bool vertex_break = true;
        double a, b, c;
        int x, y;
        while (getline(myfile, line)){
            istringstream iss(line);
            if (iss >> a >> b >> c) {
                Point p = Point(a, b, c);
                total_vertex++;
                vertices.push_back(p);
            }
            else if (vertex_break){
                vertex_break = false;
                for (int i=0; i<total_vertex; i++){
                    // cout << "done" << "\n";
                    vector<int> v;
                    edges.push_back(v);
                }
            }
            istringstream isss(line);
            if (isss >> x >> y){
                total_edge++;
                // cout << x << " " << y << "\n";
                edges.at(x).push_back(y);
                edges.at(y).push_back(x);
            }
        }
        myfile.close();
    }
    void print_vertices(){
        for (int i=0; i<total_vertex; i++){
            vertices[i].print();
        }
    }

    vector<Point> give_vertices(){
        return vertices;
    }
    void print_edges(){
        int size_edge = edges.size();
        for (int i=0; i<size_edge; i++){
            vector<int> v = edges.at(i);
            int size_v = v.size();
            for (int j=0; j< size_v; j++){
                cout << v[j] << " ";
            }
            cout << "\n";
        }
    }

    vector<vector<int> > give_edges(){
        return edges;
    }
    void translate(double a, double b, double c){
        for (int i=0; i<total_vertex; i++){
            vertices[i].translate(a, b, c);
        }
    }
    void scale(double a){
        for (int i=0; i<total_vertex; i++){
            vertices[i].scale(a);
        }
    }
    void rotate_z(double theta){
        for (int i=0; i<total_vertex; i++){
            vertices[i].rotate_z(theta);
        }
    }
    void rotate(double theta, double a, double b, double c){
        for (int i=0; i<total_vertex; i++){
            vertices[i].rotate(theta, a, b, c);
        }
    }
    void rotate(double theta, double a, double b, double c, double x0, double y0, double z0){
        for (int i=0; i<total_vertex; i++){
            vertices[i].rotate(theta, a, b, c, x0, y0, z0);
        }
    }
    Object2D project_xy(){
        vector<Point2D> points;
        for (int i=0; i<total_vertex; i++){
            Point2D temp = vertices[i].project_xy();
            points.push_back(temp);
        }
        Object2D out = Object2D(points, edges);
        return out;
    }

    Object2D project_yz(){
        vector<Point2D> points;
        for (int i=0; i<total_vertex; i++){
            Point2D temp = vertices[i].project_yz();
            points.push_back(temp);
        }
        Object2D out = Object2D(points, edges);
        return out;
    }

    Object2D project_zx(){
        vector<Point2D> points;
        for (int i=0; i<total_vertex; i++){
            Point2D temp = vertices[i].project_zx();
            points.push_back(temp);
        }
        Object2D out = Object2D(points, edges);
        return out;
    }

    Object2D project(double a, double b, double c){
        vector<Point2D> points;
        for (int i=0; i<total_vertex; i++){
            Point2D temp = vertices[i].project(a, b, c);
            points.push_back(temp);
        }
        Object2D out = Object2D(points, edges);
        return out;
    }

    Object3D(string file1, string file2, int plane1, int plane2) {
        Object2D projection1 = Object2D(file1);
        Object2D projection2 = Object2D(file2);
        // projection1.print_vertices();
        // projection2.print_edges();
        vector<Point2D> vertices1 = projection1.give_vertices();
        vector<Point2D> vertices2 = projection2.give_vertices();

        vector<vector<int> > edges1 = projection1.give_edges();
        vector<vector<int> > edges2 = projection2.give_edges();

        edges = edges1;
        if (plane1 == 1 && plane2 == 2) {
            for (int i = 0; i < vertices1.size(); i++) {
                vertices.push_back(Point(vertices1[i].getX(), vertices1[i].getY(), vertices2[i].getY()));
            }
        } else if (plane1 == 2 && plane2 == 3) {
            for (int i = 0; i < vertices1.size(); i++) {
                vertices.push_back(Point(vertices2[i].getY(), vertices1[i].getX(), vertices1[i].getY()));
            }
        } else if (plane2 == 3 && plane1 == 1) {
            for (int i = 0; i < vertices1.size(); i++) {
                vertices.push_back(Point(vertices1[i].getX(), vertices1[i].getY(), vertices2[i].getX()));
            }
        }
        total_vertex = vertices.size();
        total_edge = projection1.edges_total();
        
    }
};