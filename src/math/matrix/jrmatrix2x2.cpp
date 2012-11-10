////////////////////////////////////////////////////////////////////////////////
// jRMatrix2x2 - Implementation File
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

jRMatrix2x2::jRMatrix2x2()
{
	mMatrix = new jVector2[2];
	mMatrix[0] = jVector2();
	mMatrix[1] = jVector2();
}

jRMatrix2x2::jRMatrix2x2(float matrix[4])
{
	mMatrix = new jVector2[2];
	mMatrix[0] = jVector2(matrix[0], matrix[1]);
	mMatrix[1] = jVector2(matrix[2], matrix[3]);
}

jRMatrix2x2::jRMatrix2x2(jVector2 row1, jVector2 row2)
{
	mMatrix = new jVector2[2];
	mMatrix[0] = row1;
	mMatrix[1] = row2;
}

jRMatrix2x2::jRMatrix2x2(float m00, float m01, float m10, float m11)
{
	mMatrix = new jVector2[2];
	mMatrix[0] = jVector2(m00, m01);
	mMatrix[1] = jVector2(m10, m11);
}

jRMatrix2x2::jRMatrix2x2(const jRMatrix2x2 &matrix)
{
	*this = matrix;
}

jRMatrix2x2 jRMatrix2x2::operator*(float scalar)
{
	return jRMatrix2x2(mMatrix[0][0] * scalar, mMatrix[0][1] * scalar,
					   mMatrix[1][0] * scalar, mMatrix[1][1] * scalar);
}

jRMatrix2x2 jRMatrix2x2::operator*(jRMatrix2x2 &matrix)
{
	return jRMatrix2x2( mMatrix[0].dot(jVector2(matrix[0][0], matrix[1][0])),
					    mMatrix[0].dot(jVector2(matrix[0][1], matrix[1][1])),
						mMatrix[1].dot(jVector2(matrix[0][0], matrix[1][0])),
						mMatrix[1].dot(jVector2(matrix[0][1], matrix[1][1])));
}

jRMatrix2x2 jRMatrix2x2::operator=(const jRMatrix2x2 &matrix)
{
	if (this == &matrix)
		return *this;
	
	if (mMatrix == NULL)
		mMatrix = new jVector2[2];
	mMatrix[0] = matrix[0];
	mMatrix[1] = matrix[1];
	
	return *this;
}

jRMatrix2x2 jRMatrix2x2::operator-()
{
	return jRMatrix2x2(-mMatrix[0][0], -mMatrix[0][1],
					   -mMatrix[1][0], -mMatrix[1][1]);
}
jRMatrix2x2 jRMatrix2x2::operator/(float scalar)
{
	return jRMatrix2x2(mMatrix[0]/scalar, mMatrix[1]/scalar);
}

jVector2 jRMatrix2x2::operator[](int index) const
{
	return mMatrix[index%2];
}
jVector2 jRMatrix2x2::operator()(int index) const
{
	return mMatrix[index%2];
}

float jRMatrix2x2::determinant()
{
	return (mMatrix[0][0] * mMatrix[1][1]) - (mMatrix[0][1] * mMatrix[1][0]);
}

bool jRMatrix2x2::hasInverse()
{
	return (determinant() != 0.0f);
}

jRMatrix2x2 jRMatrix2x2::inverse()
{
	float det = determinant();
	if (det == 0.0f)
		return *this;
	return jRMatrix2x2(mMatrix[1][1], -mMatrix[0][1], -mMatrix[1][0], mMatrix[0][0]) / det;
}

jRMatrix2x2::~jRMatrix2x2()
{
	delete [] mMatrix;
	mMatrix = NULL;
}
