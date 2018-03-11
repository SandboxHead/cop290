#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

#include "point.h"

using namespace std;

class generate_2D{
    /*!
     *This is for providing options to create a 2D graph(having 3 different projections) from files.
     */

private:
    vector<Point> points;
    vector<vector<int>> edges;

public:
    generate_2D(const string &filename){
        string line;
        ifstream inFile;

        inFile.open(filename);

        if(!inFile){
            cout << "Unable to open file";
        }
        double a, b, c;
        int x, y;
        bool data_change=false;
        bool data_2=false;
        int point_count=0;

        while(getline(inFile, line))
        {
            istringstream iss(line);
            if(iss >> a >> b >> c)
            {
                Point p  = Point(a, b, c);
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

    /*!
     *This function will take a input and store the 2D projections in appropriate data structures.
     *Input can be provided in suitable data structures, such as a array or list of edges and overlapping points in different set of lists or array.
     *The 2D graph generated will be used by different classes.
     */
    void print_edges()
    {
        for (int i=0; i<edges.size(); i++) {
            for(int j=0; j<2; j++)
            {
                cout << edges[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void print_vertex()
    {
        for (int i=0; i<points.size(); i++) {
            cout << points[i].getX() << "," << points[i].getY() << "," << points[i].getZ() << " " << endl;
        }

    }

};

int main()
{
    generate_2D object_2D = generate_2D("/home/abhishek/CLionProjects/untitled/test.txt");
    object_2D.print_vertex();
    object_2D.print_edges();


}