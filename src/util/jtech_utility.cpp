#include <util/jtech_utility.h>

float jtech::util::clampf01 (float value )
{
	return ( value < 0 ? 0 : value > 1 ? 1 : value );
}

float jtech::util::clampf ( float value, float min, float max )
{
	return ( value < min ? min : value > max ? max : value );
}

float jtech::util::clampi ( int value, int min, int max )
{
	return ( value < min ? min : value > max ? max : value );
}

void jtech::util::swap( float *v1, float *v2 )
{
	float v = *v1;
	*v1 = *v2;
	*v2 = v;
}

