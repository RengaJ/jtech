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

#ifdef _WIN32
#include <windows.h>
#endif

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

	////////////////////////////////////////////////////

	// jVector3

	jVector3 vector_1;
	jVector3 vector_2(5.0f);
	jVector3 vector_3(1.0f, 2.0f, 3.0f);

	std::cout << vector_1.toString() << std::endl;
	std::cout << vector_2.toString() << std::endl;
	std::cout << vector_3.toString() << std::endl;

	// This will be put into the jDebug namespace/class.
	#ifdef linux
		// \033[|DISPLAY_FLAG|[;|COLOR|]m
		// DISPLAY_FLAG changes how the text will be altered
		// 1 --> Bold   4 --> Underlined
		// COLOR is the color to change the tty
		// m tells console to parse what it just read as color-changing
		// \033[0m --> resets colors to console default

		// A bold red error message:
		jVector3 sum = vector_2 + vector_3;
		std::cout << "\033[1;31mERROR: " << sum << "\033[0m" << std::endl;
		// A cyan underlined warning message:
		jVector3 diff2 = vector_3 - vector_2;
		std::cout << "\033[4;36mWARNING: " << diff2 << "\033[0m" << std::endl;
	#else
		// And this is why programming for Windows sucks...
		HANDLE h_stdout = GetStdHandle( STD_OUTPUT_HANDLE );
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo( h_stdout, &csbi );
		// Foreground B G R I
		// Colors     0 0 1 1
		// Background B G R I
		// Colors     0 0 0 1
		// All together, 00110001 is like this:
		SetConsoleTextAttribute( h_stdout, 0x31 );
		std::cout << vector_1 << std::endl;

		SetConsoleTextAttribute( h_stdout, csbi.wAttributes );
	#endif

	return 0;
}
