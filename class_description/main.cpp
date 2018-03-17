#include <bits/stdc++.h>

#include <math.h>
#include <QtCore>
#include <QtGui>
#include <classes.h>

#define PI 3.1415926536
#define SIZE 200
#define FACTOR 100

const float STEP = 2*PI/SIZE;

using namespace Qt;


int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QLabel l;
   QPicture pi;
   QPainter p(&pi);

   p.setRenderHint(QPainter::Antialiasing);
   p.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
   

   Object3D o = Object3D("obj.txt");
   o.rotate(PI/3, 0, 0, 1);
   // o.rotate_z(0.513587);make
   o.rotate(0.523587, 1, 0, 0);
   std::vector<Point> vertices = o.give_vertices();
   std::vector<std::vector<int> > edges = o.give_edges();
   p.drawLine(0, 0 , 200, -400);
   int ver = vertices.size();
   int edg = edges.size();
   for (int i=0; i<edg; i++){
   		int len = edges[i].size();
   		for (int j=0; j<len; j++){
   			int b = edges[i][j];
   			if(i<=b){
	   			Point point1 = vertices[i];
	   			Point point2 = vertices[b];
	   			double x1 = point1.getX();
	   			double x2 = point2.getX();
	   			double y1 = point1.getZ();
	   			double y2 = point2.getZ();
	   			std::printf ("%f %f\n", x1, y1);
	   			std::printf ("%f %f\n\n",x2, y2);
	   			p.drawLine(x1, -y1, x2, -y2);
	   		}
	   	}
   }

   p.end(); // Don't forget this line!

   l.setPicture(pi);
   l.show();
   return a.exec();
}