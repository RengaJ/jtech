#include <math/jmatrix.h>

jMatrix3x3::~jMatrix3x3()
{
	if (mMatrix != NULL)
	{
		delete [] mMatrix;
		mMatrix = NULL;
	}
}

std::string jMatrix3x3::toString()
{
	std::stringstream ss;
	ss << "[[" << mMatrix[0][0] << ", " << mMatrix[0][1] << ", " << mMatrix[0][2] << "]\n"
	           << mMatrix[1][0] << ", " << mMatrix[1][2] << ", " << mMatrix[1][2] << "]\n"
			   << mMatrix[2][0] << ", " << mMatrix[2][1] << ", " << mMatrix[2][2] << "]]";

	return ss.str();
}
int jMatrix3x3::hashCode()
{
	return (mMatrix[0].hashCode() + mMatrix[1].hashCode() + mMatrix[2].hashCode());
}
