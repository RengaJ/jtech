#include <math/jtech_vector.h>

#include <iostream>

int main()
{
	jtech::vector2 vec1;
	jtech::vector2 vec2(1,1);
	
	jtech::vector3 vec3;
	jtech::vector3 vec4(0,1,0);

	// print the contents of an "empty" vector2
	std::cout << "vec1: " << vec1 << std::endl;
	// print the contents of a "non-empty" vector2
	std::cout << "vec2: " << vec2 << std::endl;
	// print the contents of an "empty" vector3
	std::cout << "vec3: " << vec3 << std::endl;
	// print the contents of a "non-empty" vector3
	std::cout << "vec4: " << vec4 << std::endl;
	// test equality operator
	if (vec1 == jtech::vector2(0,0))
		std::cout << "Equality Operator has passed." << std::endl;
	else
		std::cout << "Equality Operator has failed." << std::endl;
	// test the inequality operator
	if (vec1 != vec2)
		std::cout << "Inequality Operator has passed." << std::endl;
	else
		std::cout << "Inequality Operator has failed." << std::endl;
		
	
	// print the static vector2 objects
	std::cout << "jtech::vector2::up: " << jtech::vector2::up() << std::endl;
	std::cout << "jtech::vector2::down: " << jtech::vector2::down() << std::endl;
	std::cout << "jtech::vector2::left: " << jtech::vector2::left() << std::endl;
	std::cout << "jtech::vector2::right: " << jtech::vector2::right() << std::endl;

	return 0;
}
