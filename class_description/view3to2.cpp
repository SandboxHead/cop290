#include <bits/stdc++.h>
#include <QtGui>

#include <process_3D.cpp>
#include <process_2D.cpp>
#include <view2to3.cpp>
#include <mode.cpp>
#include <display.cpp>

using namespace std;


class view3Dto2D{
public:
	/*!
	 * This is the place where all the processing with 3D graph take place.
	 */

	graph_input(){
		/*!
		 * User provide a 3D graph which is required to be converted to 2D, which are projections on any plane.
		 */
	}
	give_projection_plane(){
		/*!
		 * User need to provide planes on which he wants to get 2D projections.
		 * Projections can be provided from different transformations on co-ordinates axes.
		 * For providing a transformated plane user can provide the following.
		 * 1. Rotation angles about axes x, y, z.
		 * 2. Distance from x, y, z axes.
		 * 3. If there is a scaling putted thats too.
		 */
	}

	translate_3D(){
		/*!
		 *For translating a 3D object along coordinate axes.
		 *This can be done by changing the object's data structure as per mathematical model.
		 */
	}

	rotate_3D(){
		/*!
		 * This function is meant for rotating the 3D object around different axes by angles.
		 * It will change the objects data structure in accordance with rules and lemmas stated in mathematical model.
		 */
	}

	scale_3D(){
		/*!
		 * A 3D object can be scaled for zooming in and out, it will be done using this function.
		 */
	}

	project_3D(){
		/*!
		 * Processed 3D object provided with the projection plane will output the projection of the given object on given plane using this function.
		 * user can take output as lists with different 2D projections.
		 */
		}

}
