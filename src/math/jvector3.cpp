////////////////////////////////////////////////////////////////////////////////
// jVector3 - Implementation File
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

jVector3::jVector3()
{
	mVals = new float[3];
	mVals[0] = mVals[1] = mVals[2] = 0.0f;
}

jVector3::jVector3(float x)
{
	mVals = new float[3];
	mVals[0] = x;
	mVals[1] = mVals[2] = 0.0f;
}

jVector3::jVector3(float x, float y, float z)
{
	mVals = new float[3];
	mVals[0] = x; mVals[1] = y; mVals[2] = z;
}

jVector3::jVector3(const jVector3 &vector)
{
	*this = vector;
}

jVector3::~jVector3()
{
	if (mVals)
	{
		delete [] mVals;
		mVals = NULL;
	}
}

// The assignment operator:
// Sets the LHS of the operator equal to the
// value of the RHS of the operator
jVector3 jVector3::operator=(const jVector3 &vector)
{
	// Are we looking at the same jVector3
	// (as in "mPosition = mPosition;")?
	if (this == &vector)
		return *this;
	// If this is from the copy constructor,
	// the mVals array hasn't yet been initialized
	if (!mVals) mVals = new float[3];
	// Set the current values in mVals to the new
	// values supplied by the parameter
	mVals[0] = vector.mVals[0];
	mVals[1] = vector.mVals[1];
	mVals[2] = vector.mVals[2];
	// return a copy of the current jVector3
	// so we could chain the assignments together
	return *this;
}

float jVector3::operator()(int index) const
{
	return mVals[index%3];
}

float jVector3::operator[](int index) const
{
	return mVals[index%3];
}

bool jVector3::operator==(jVector3 &vector) const
{
	return mVals[0] == vector.mVals[0] &&
		   mVals[1] == vector.mVals[1] &&
		   mVals[2] == vector.mVals[2];
}

bool jVector3::operator!=(jVector3 &vector) const
{
	return mVals[0] != vector.mVals[0] ||
		   mVals[1] != vector.mVals[1] ||
		   mVals[2] != vector.mVals[2];
}

jVector3 jVector3::operator+(const jVector3 &vector)
{
	return jVector3(mVals[0] + vector.mVals[0],
					mVals[1] + vector.mVals[1],
					mVals[2] + vector.mVals[2]);
}

jVector3 jVector3::operator-(const jVector3 &vector)
{
	return jVector3(mVals[0] - vector.mVals[0],
					mVals[1] - vector.mVals[1],
					mVals[2] - vector.mVals[2]);
}

jVector3 jVector3::operator*(float scalar)
{
	return jVector3(mVals[0] * scalar,
					mVals[1] * scalar,
					mVals[2] * scalar);
}

jVector3 jVector3::operator/(float scalar)
{
	return jVector3(mVals[0] / scalar,
					mVals[1] / scalar,
					mVals[2] / scalar);
}

jVector3 jVector3::normalized()
{
	return *this/sqrt(magnitude_sqr());
}

jVector3 jVector3::cross(jVector3 &vector) const
{
	return jVector3((mVals[1]*vector.mVals[2])-(mVals[2]*vector.mVals[1]),
					(mVals[2]*vector.mVals[0])-(mVals[0]*vector.mVals[2]),
					(mVals[0]*vector.mVals[1])-(mVals[1]*vector.mVals[0]));
}

float jVector3::dot(jVector3 &vector) const
{
	return (mVals[0] * vector.mVals[0]) +
		   (mVals[1] * vector.mVals[1]) +
		   (mVals[2] * vector.mVals[2]);
}

float jVector3::magnitude_sqr() const
{
	return (mVals[0]*mVals[0]) + (mVals[1]*mVals[1]) + (mVals[2]*mVals[2]);
}

// Returns the "string" version of the jVector3
std::string jVector3::toString()
{
	std::stringstream ss;
	ss << "(" << mVals[0] << ", " << mVals[1] << ", " << mVals[2] << ")";

	return ss.str();
}

// Returns a hashCode for the current jVector3
int jVector3::hashCode()
{
	return (int)((mVals[0] * mVals[0] * 13) +
				 (mVals[1] * mVals[1] * 17) -
				 (mVals[2] * mVals[2] * 19));
}
