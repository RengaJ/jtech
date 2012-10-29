////////////////////////////////////////////////////
//
// main.cpp
//
// The main file (to contain the starting code for the engine).
//
// October 29, 2012: This file is to be used for testing jVectorN classes
// for functionality and potential memory leaks.
//
///////////////////////////////////////////////////

#include <math/jvector.h>

#include <iostream>

int main()
{
	//**************//
	//** jVector2 **//
	//**************//

	// Create an "empty" jVector2:  (0,0)
	jVector2 vector1;
	// Create "partial" jVector2: (5,0)
	jVector2 vector2(5.0f);
	// Create "full" jVector2: (1,2)
	jVector2 vector3(1.0f, 2.0f);
	// print the vectors out
	std::cout << vector1.toString() << std::endl;
	std::cout << vector2.toString() << std::endl;
	std::cout << vector3.toString() << std::endl;
	// add two vectors together
	jVector2 sum23 = vector2 + vector3;
	std::cout << sum23.toString() << std::endl;
	// subtract two vectors
	jVector2 diff = jVector2(6.0f, 4.0f) - jVector2(10.0f, 2.0f);
	std::cout << diff.toString() << std::endl;
	// multiply vector by scalar
	std::cout << (vector3 * 1.25f).toString() << std::endl;
	// divide vector by scalar
	std::cout << (sum23 / 10.0f).toString() << std::endl;
	// test equality
	std::cout << (sum23 == diff) << std::endl;
	// test inequality
	std::cout << (diff != vector1) << std::endl;
	// get magnitude
	std::cout << vector3.magnitude_sqr() << std::endl;
	// normalize vector
	std::cout << (vector3.normalized()).toString() << std::endl;

	return 0;
}
