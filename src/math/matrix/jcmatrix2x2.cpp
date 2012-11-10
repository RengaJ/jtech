////////////////////////////////////////////////////////////////////////////////
// jCMatrix2x2 - Implementation File
// Author: justin.renga@gmail.com
// jtech Engine
//
// Copyright (c) 2012, Justin Renga
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
// DESCRIPTION:
//
// The jMatrix's goal is to provide light-weight way to represent NxN matrices
// for mathematical computations. Matrix dimensions come in 3 variants:
//  o 2x2
//  o 3x3
//  o 4x4
// This is the concrete implementation of the row-major 2x2 matrix
////////////////////////////////////////////////////////////////////////////////

#include <math/jmatrix.h>

jCMatrix2x2::jCMatrix2x2()
{
	mMatrix = new jVector2[2];
	mMatrix[0] = jVector2();
	mMatrix[1] = jVector2();
}

jCMatrix2x2::jCMatrix2x2(float matrix[4])
{
	mMatrix = new jVector2[2];
	mMatrix[0] = jVector2(matrix[0], matrix[2]);
	mMatrix[1] = jVector2(matrix[1], matrix[3]);
}

jCMatrix2x2::jCMatrix2x2(jVector2 col1, jVector2 col2)
{
	mMatrix = new jVector2[2];
	mMatrix[0] = col1;
	mMatrix[1] = col2;
}

/**
 * Creates a matrix that looks like the following, given a,b,c,d:
 * [[a, c]
 *  [b, d]]
 **/
jCMatrix2x2::jCMatrix2x2(float a, float c, float b, float d)
{
	mMatrix = new jVector2[2];
	mMatrix[0] = jVector2(a, b);
	mMatrix[1] = jVector2(c, d);
}

jCMatrix2x2::jCMatrix2x2(const jCMatrix2x2 &matrix)
{
	*this = matrix;
}

jCMatrix2x2 jCMatrix2x2::operator*(float scalar)
{
	return jCMatrix2x2(mMatrix[0][0] * scalar, mMatrix[0][1] * scalar,
					   mMatrix[1][0] * scalar, mMatrix[1][1] * scalar);
}

jCMatrix2x2 jCMatrix2x2::operator*(jCMatrix2x2 &matrix)
{
	return jCMatrix2x2( matrix[0].dot(jVector2(mMatrix[0][0], mMatrix[0][1])),
					    matrix[1].dot(jVector2(mMatrix[0][0], mMatrix[0][1])),
						matrix[0].dot(jVector2(mMatrix[1][0], mMatrix[1][1])),
						matrix[1].dot(jVector2(mMatrix[1][0], mMatrix[1][1])));
}

jCMatrix2x2 jCMatrix2x2::operator=(const jCMatrix2x2 &matrix)
{
	if (this == &matrix)
		return *this;
	
	if (mMatrix == NULL)
		mMatrix = new jVector2[2];
	mMatrix[0] = matrix[0];
	mMatrix[1] = matrix[1];
	
	return *this;
}

jCMatrix2x2 jCMatrix2x2::operator-()
{
	return jCMatrix2x2(-mMatrix[0], mMatrix[1]);
}
jCMatrix2x2 jCMatrix2x2::operator/(float scalar)
{
	return jCMatrix2x2(mMatrix[0]/scalar, mMatrix[1]/scalar);
}

jVector2 jCMatrix2x2::operator[](int index) const
{
	return mMatrix[index%2];
}
jVector2 jCMatrix2x2::operator()(int index) const
{
	return mMatrix[index%2];
}

float jCMatrix2x2::determinant()
{
	return (mMatrix[0][0] * mMatrix[1][1]) - (mMatrix[1][0] * mMatrix[0][1]);
}

bool jCMatrix2x2::hasInverse()
{
	return (determinant() != 0.0f);
}

jCMatrix2x2 jCMatrix2x2::inverse()
{
	float det = determinant();
	if (det == 0.0f)
		return *this;
	// a c b d
	return jCMatrix2x2(mMatrix[1][1], -mMatrix[1][0], -mMatrix[0][1], mMatrix[0][0]) / det;
}

jCMatrix2x2::~jCMatrix2x2()
{
	delete [] mMatrix;
	mMatrix = NULL;
}
