////////////////////////////////////////////////////////////////////////////////
// jVector2 - Implementation File
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
// The jVector's goal is to provide a light-weight way to encapsulate the
// major positional information of a given object (assuming it has a position).
//
////////////////////////////////////////////////////////////////////////////////

#include <math/jvector.h>

jVector2::jVector2()
{
	mVals = new float[2];
	mVals[0] = mVals[1] = 0.0f;
}

jVector2::jVector2(float x)
{
	mVals = new float[2];
	mVals[0] = x; mVals[1] = 0.0f;
}

jVector2::jVector2(float x, float y)
{
	mVals = new float[2];
	mVals[0] = x; mVals[1] = y;
}

jVector2::jVector2(const jVector2 &vector)
{
	*this = vector;
}

jVector2::~jVector2()
{
	if (mVals)
	{
		delete [] mVals;
		mVals = NULL;
	}
}
// Assignment Operator
jVector2 jVector2::operator=(const jVector2 &vector)
{
	if (this == &vector)
		return *this;

	if (mVals == NULL) mVals = new float[2];

	mVals[0] = vector.mVals[0];
	mVals[1] = vector.mVals[1];

	return *this;
}
// Access Operators
float jVector2::operator()(int index) const
{
	return mVals[index%2];
}
float jVector2::operator[](int index) const
{
	return mVals[index%2];
}
// Equality Operators
bool jVector2::operator==(jVector2 &vector) const
{
	return (mVals[0] == vector.mVals[0] &&
			mVals[1] == vector.mVals[1]);
}
bool jVector2::operator!=(jVector2 &vector) const
{
	return (mVals[0] != vector.mVals[0] ||
			mVals[1] != vector.mVals[1]);
}
// Arithmetic Operators
jVector2 jVector2::operator+(const jVector2 &vector)
{
	return jVector2(mVals[0] + vector.mVals[0],
					mVals[1] + vector.mVals[1]);
}
jVector2 jVector2::operator-(const jVector2 &vector)
{
	return jVector2(mVals[0] - vector.mVals[0],
					mVals[1] - vector.mVals[1]);
}
jVector2 jVector2::operator*(float scalar)
{
	return jVector2(mVals[0] * scalar,
					mVals[1] * scalar);
}
jVector2 jVector2::operator/(float scalar)
{
	return jVector2(mVals[0] / scalar,
					mVals[1] / scalar);
}
// Aritmetic Operations (non-operators)
jVector2 jVector2::normalized()
{
	return *this/sqrt(magnitude_sqr());
}
float jVector2::cross(jVector2 &vector) const
{
	return (mVals[0] * vector.mVals[1]) - (mVals[1] * vector.mVals[0]);
}
float jVector2::dot(jVector2 &vector) const
{
	return (mVals[0] * vector.mVals[0]) + (mVals[1] * vector.mVals[1]);
}

float jVector2::magnitude_sqr() const
{
	return (mVals[0] * mVals[0]) + (mVals[1] * mVals[1]);
}

std::string jVector2::toString()
{
	std::stringstream ss;
	ss << "(" << mVals[0] << ", " << mVals[1] << ")";
	return ss.str();
}

int jVector2::hashCode()
{
	return (int)(mVals[0] * mVals[0] * 17) +
		   (int)(mVals[1] * mVals[1] * 23);
}
