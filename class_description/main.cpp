#include <bits/stdc++.h>

#include <math.h>
#include <QtCore>
// #include <QString>
#include <QtGui>
#include <classes.h>
#include <fstream>
#include <string>
#define PI 3.1415926536
#define SIZE 200
#define FACTOR 100

const float STEP = 2*PI/SIZE;

using namespace Qt;

std::string dtos(double dbl){
    char buf[BUFSIZ];
    sprintf(buf, "%lf", dbl);
    return buf;
}

void save2D(string name, Object2D o){
   std::ofstream myfile;
      myfile.open((name + ".txt").c_str());
      std::vector<Point2D> vr = o.give_vertices();
      // vector<int> ed = ob_xy.give_edges();
      for (int i=0; i<vr.size(); i++){
         Point2D current = vr[i];
         myfile << dtos(current.getX()) << " " << dtos(current.getY()) << "\n";
      }
      myfile << "2\n" ;
      std::vector<vector<int> > ed = o.give_edges();
      for (int i=0; i<ed.size(); i++){
         for (int j=0; j<ed[i].size(); j++){
            if(ed[i][j]>i){
               myfile << i << " " << ed[i][j] << "\n";
            }
         }
      }
      myfile.close();
}

int main(int argc, char *argv[])
{
   std::cout << "Welcome..." << endl;
   bool valid = true;
   Object3D obj;
   while(valid){
      std::cout << "[*] Type <1 for 2Dto3D> or <2 for 3Dto2D> according to your input type: ";
      int mode;
      std::cin >> mode;
      valid = false;

      if (mode == 1){
         std::cout << "[*] Input 2 2D files seperated by space in given format. Planes can be xy, yz, zx. " << endl;
         std::cout << "file1.txt plane1 file2.txt plane2" << endl;
         std::cout << "Input 2D files: ";
         std::string file1, file2, plane1, plane2;
         cin >> file1 >> plane1 >> file2 >> plane2;
         std::string temp;
         int plane11, plane12;
         if (plane1 == "xy" and plane2 == "yz"){
            plane11 = 1;
            plane12 = 2;
         }
         else if (plane1 == "yz" and plane2 == "xy"){
            plane11 = 1;
            plane12 = 2;
            temp = file2;
            file2 = file1;
            file1 = temp;
         }
         else if (plane1 == "xy" and plane2 == "zx"){
            plane11 = 1;
            plane12 = 3;
         }
         else if (plane1 == "zx" and plane2 == "xy"){
            plane11 = 1;
            plane12 = 3;
            temp = file2;
            file2 = file1;
            file1 = temp;
         }
         else if (plane1 == "yz" and plane2 == "zx"){
            plane11 = 2;
            plane12 = 3;
         }
         else if (plane1 == "zx" and plane2 == "yz"){
            plane11 = 2;
            plane12 = 3;
            temp = file2;
            file2 = file1;
            file1 = temp;
         }
         else{
            std::cout << "Invalid input!!" << endl;
            valid = true;
            continue;
         }
         obj = Object3D(file1, file2, plane11, plane12);
      }
      else if (mode == 2){
         std::cout << "[*] Input 3D file: ";
         string file;
         cin >> file;
         obj = Object3D(file);

      }
      else{
         std::cout << "problem with input!! Try again" << endl;
         valid = true;
         continue;
      }
      
   }
   Object3D o = obj;

   cout << "[*] Your 3D object is ready. Type yes or no for rotation: ";
   string rotate;
   cin >> rotate;
   if (rotate=="yes"){
      double theta, a, b, c, x0, y0, z0;
      cout << "[*] Input theta and rotation axis credentials in following order: ";
      cout << "theta a b c x0 y0 zo." << endl;
      cout << "[*] Type your inputs here: ";
      cin >> theta >> a >> b >> c >> x0 >> y0 >> z0;
      obj.rotate(theta, a, b, c, x0, y0, z0);
   }

   
   cout << "[*] You can scale up or scale down your object, type yes or no: ";
   string scale;
   cin >> scale;
   if (scale=="yes"){
      double s;
      cout << "[*] Type your inputs here: ";
      cin >> s;
      obj.scale(s);
   }

   cout << "[*] Type yes to save and no to skip saving: ";
   string save;
   cin >> save;

   if (save == "yes"){
      cout << "[*] Type save file name (excluding format): ";
      std::string filename;
      cin >> filename;
      // string inputt = filename + '.txt';
      std::ofstream myfile;
      myfile.open((filename + ".txt").c_str());
      std::vector<Point> vertices_save = o.give_vertices();
      for (int i=0; i<vertices_save.size(); i++){
         Point current = vertices_save[i];
         myfile << dtos(current.getX()) << " " << dtos(current.getY()) << " " << dtos(current.getZ()) << "\n";
      }
      myfile << "2\n" ;
      std::vector<vector<int> > edges_save = o.give_edges();
      for (int i=0; i<edges_save.size(); i++){
         for (int j=0; j<edges_save[i].size(); j++){
            if(edges_save[i][j]>i){
               myfile << i << " " << edges_save[i][j] << "\n";
            }
         }
      }
      myfile.close();
   }
   cout << "[*] Press yes to save orthographic projections. Skip to ignore: ";
   string projection_save;
   cin >> projection_save;

   QApplication a(argc, argv);
   QLabel l;
   QLabel r;
   //QPicture pi;
   QPicture pi2;
   //QPainter p(&pi);
   QPainter q(&pi2);

   // p.setRenderHint(QPainter::Antialiasing);
   // p.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));

   
   // o.rotate(PI/3, 0, 0, 1);
   // // o.rotate_z(0.513587);make
   // o.rotate(PI/6, 1, 0, 0);
   // std::vector<Point> vertices = o.give_vertices();
   // std::vector<std::vector<int> > edges = o.give_edges();
   // // p.drawLine(0, 0 , 200, -400);
   // int ver = vertices.size();
   // // printf ("%d", ver);
   // int edg = edges.size();
   // for (int i=0; i<edg; i++){
   //       int len = edges[i].size();
   //       for (int j=0; j<len; j++){
   //          int b = edges[i][j];
   //          if(i<=b){
   //             Point point1 = vertices[i];
   //             Point point2 = vertices[b];
   //             double x1 = point1.getX();
   //             double x2 = point2.getX();
   //             double y1 = point1.getZ();
   //             double y2 = point2.getZ();
   //             // std::printf ("%f %f\n", x1, y1);
   //             // std::printf ("%f %f\n\n",x2, y2);
   //             p.drawLine(x1, -y1, x2, -y2);
   //          }
   //       }
   // }

   // p.end(); // Don't forget this line!


   std::vector<Point> ver_check =  obj.give_vertices();
   int t = ver_check.size();
   double s_x=0;
   double s_y=0;
   double s_z=0;
   for(int i=0; i<t; i++){
      if(ver_check[i].getX()<-1*s_x){
         s_x=abs(ver_check[i].getX());
      }
      if(ver_check[i].getY()<-1*s_y){
         s_y=abs(ver_check[i].getY());
      }
      if(ver_check[i].getZ()<-1*s_z){
         s_z=abs(ver_check[i].getZ());
      }
   }
   obj.translate(s_x+20, s_y+20, s_z+20);
   
   // q.end();
   
   
   // l.setPicture(pi);
   // l.show();

   q.setRenderHint(QPainter::Antialiasing);
   q.setPen(QPen(Qt::black, 3, Qt::DotLine, Qt::RoundCap));
   
   q.drawLine(500, 0 , -500, 0);
   q.drawLine(0, -500 , 0, 500);
   q.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
   // p.drawLine(0, 0 , 200, -400);

   // string str = "Front";
   // QString qstr = QString::fromStdString(str);

   //q.drawText(400, -400, "Front");
   
   bool save_2D = false;
   if (projection_save == "yes") save_2D = true;
   string front, top, side;
   if (save_2D){
      cout << "Type file name in order of 'front top side': ";
      cin >> front >> top >> side;
   }


   Object2D ob_xy = obj.project_xy();
   std::vector<Point2D> vertices2 = ob_xy.give_vertices();
   std::vector<std::vector<int> > edges2 = ob_xy.give_edges();
   int ver = vertices2.size();
   
   printf ("%d", ver);
   int edg = edges2.size();
   for (int i=0; i<edg; i++){
         int len = edges2[i].size();
         for (int j=0; j<len; j++){
            int b = edges2[i][j];
            if(i<=b){
               Point2D point1 = vertices2[i];
               Point2D point2 = vertices2[b];
               double x1 = point1.getX();
               double x2 = point2.getX();
               double y1 = point1.getY();
               double y2 = point2.getY();
               q.drawLine(x1, -y1, x2, -y2);
            }
         }
   }



   Object2D ob_zx = obj.project_zx();

  
   std::vector<Point2D> vertices21 = ob_zx.give_vertices();
   std::vector<std::vector<int> > edges21 = ob_zx.give_edges();
   ver = vertices21.size();
   
   printf ("%d", ver);
   edg = edges21.size();
   for (int i=0; i<edg; i++){
      int len = edges21[i].size();
      for (int j=0; j<len; j++){
         int b = edges21[i][j];
         if(i<=b){
            Point2D point1 = vertices21[i];
            Point2D point2 = vertices21[b];
            double x1 = point1.getY();
            double x2 = point2.getY();
            double z1 = point1.getX();
            double z2 = point2.getX();
            q.drawLine(x1, z1 , x2, z2 );
         }
      }
   }




   Object2D ob_yz = obj.project_yz();

   std::vector<Point2D> vertices3 = ob_yz.give_vertices();
   std::vector<std::vector<int> > edges3 = ob_yz.give_edges();
   ver = vertices3.size();
   
   printf ("%d", ver);
   edg = edges3.size();
   for (int i=0; i<edg; i++){
         int len = edges3[i].size();
         for (int j=0; j<len; j++){
            int b = edges3[i][j];
            if(i<=b){
               Point2D point1 = vertices3[i];
               Point2D point2 = vertices3[b];
               double y1 = point1.getX();
               double y2 = point2.getX();
               double z1 = point1.getY();
               double z2 = point2.getY();
               q.drawLine(-z1, -y1, -z2, -y2);
            }
         }
   }

   ob_yz.translate(-s_y-20, -s_z-20);
   ob_xy.translate(-s_x-20, -s_y-20);
   ob_zx.translate(-s_z-20, -s_z-20);

   if (save_2D){
      save2D(front, ob_xy);
      save2D(top, ob_zx);
      save2D(side, ob_yz);
   }

   obj.rotate(PI/6, 1, 0, 0);
   obj.rotate(-PI/6, 0, 1, 0);

   std::vector<Point> ver_check2 =  obj.give_vertices();
   t = ver_check2.size();
   double maxx = 0.0;
   for (int i=0; i<t; i++){
      if (maxx < ver_check2[i].getX()){
         maxx = ver_check2[i].getX();
      }
   } 
   double maxy = 0.0;
   for (int i=0; i<t; i++){
      if (maxy < ver_check2[i].getY()){
         maxy = ver_check2[i].getY();
      }
   } 

   obj.translate(-maxx-20, -maxy - 20, 0);

   std::vector<Point> vertices4 = obj.give_vertices();
   std::vector<std::vector<int> > edges4 = obj.give_edges();
   
   ver = vertices4.size();
   // printf ("%d", ver);
   edg = edges4.size();
   for (int i=0; i<edg; i++){
         int len = edges4[i].size();
         for (int j=0; j<len; j++){
            int b = edges4[i][j];
            if(i<=b){
               Point point1 = vertices4[i];
               Point point2 = vertices4[b];
               double x1 = point1.getX();
               double x2 = point2.getX();
               double y1 = point1.getY();
               double y2 = point2.getY();
               // std::printf ("%f %f\n", x1, y1);
               // std::printf ("%f %f\n\n",x2, y2);
               q.drawLine(x1, -y1, x2, -y2);
            }
         }
   }

   q.end();
   // show_2D(ob);
   r.setPicture(pi2);
   r.show();
   return a.exec();
}