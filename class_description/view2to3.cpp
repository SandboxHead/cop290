#include <bits/stdc++.h>
#include <QtGui>

#include <process_3D.cpp>
#include <process_2D.cpp>
#include <mode.cpp>
#include <view3to2.cpp>
#include <display.cpp>

using namespace std;

class view2Dto3D{
public:
	/*!
	 * 2D graphs are provided as inputs from file.
	 * The following functions of this class can be used to process 2D graphs to generate a 3D graph.
	 */

	graphs_input(){
		/*!
		 *This method simply take 2D graphs input to be processed.
		 */
	}

	make_3D_graph(){
		/*!
		 * Here we convert the provided 2D graphs to a 3D graph.
		 * Different projections in 2D graphs will be processed to genrate a 3D graph using the mathematical model planned.
		 * Then if a valid 3D graph cannot be obtained form the given projections exception can be showed.
		 * Thereafter validity of the 3D graph generated will also be checked, wheather it is the only possible solution or some other solution has been generated.
		 * 3D graph generated will be saved in suitable data structure.
		 */
	}
	check_qualify(){
		/*
		 * This is the method to check if only a single possible solution has been generated as a 3D graph or other solutions are possible.
		 * This check can be done by matching the 2D projections provided and matching them with projections of 3D object generated.
		 * Other possible methods for check can also be included.
		 */
	}
}
