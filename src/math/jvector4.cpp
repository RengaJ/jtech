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

jVector4::jVector4()
{
	mVals = new float[4];
	mVals[0] = mVals[1] = mVals[2] = mVals[3] = 0.0f;
}
jVector4::jVector4(float x)
{
	mVals = new float[4];
	mVals[0] = x;
	mVals[1] = mVals[2] = mVals[3] = 0.0f;
}
jVector4::jVector4(float x, float y, float z, float w)
{
	mVals = new float[4];
	mVals[0] = x; mVals[1] = y;
	mVals[2] = z; mVals[2] = w;
}
jVector4::jVector4(const jVector4 &vector)
{
	*this = vector;
}
jVector4::~jVector4()
{
	if (mVals)
	{
		delete [] mVals;
		mVals = NULL;
	}
}
jVector4 jVector4::operator=(const jVector4 &vector)
{
	if (this == &vector) return *this;
	if (!mVals)
		mVals = new float[4];
	mVals[0] = vector.mVals[0];
	mVals[1] = vector.mVals[1];
	mVals[2] = vector.mVals[2];
	mVals[3] = vector.mVals[3];

	return *this;
}
float jVector4::operator()(int index) const
{
	return mVals[index % 4];
}
float jVector4::operator[](int index) const
{
	return mVals[index % 4];
}
bool jVector4::operator==(jVector4 &vector) const
{
	return mVals[0] == vector.mVals[0] &&
		   mVals[1] == vector.mVals[1] &&
		   mVals[2] == vector.mVals[2] &&
		   mVals[3] == vector.mVals[3];
}
bool jVector4::operator!=(jVector4 &vector) const
{
	return mVals[0] != vector.mVals[0] ||
		   mVals[1] != vector.mVals[1] ||
		   mVals[2] != vector.mVals[2] ||
		   mVals[3] != vector.mVals[3];
}
jVector4 jVector4::operator+(const jVector4 &vector)
{
	return jVector4(mVals[0] + vector.mVals[0],
					mVals[1] + vector.mVals[1],
					mVals[2] + vector.mVals[2],
					mVals[3] + vector.mVals[3]);
}
jVector4 jVector4::operator-(const jVector4 &vector)
{
	return jVector4(mVals[0] - vector.mVals[0],
					mVals[1] - vector.mVals[1],
					mVals[2] - vector.mVals[2],
					mVals[3] - vector.mVals[3]);
}
jVector4 jVector4::operator*(float scalar)
{
	return jVector4(mVals[0] * scalar,
					mVals[1] * scalar,
					mVals[2] * scalar,
					mVals[3] * scalar);
}
jVector4 jVector4::operator/(float scalar)
{
	return jVector4(mVals[0] / scalar,
					mVals[1] / scalar,
					mVals[2] / scalar,
					mVals[3] / scalar);
}
jVector4 jVector4::normalized()
{
	return *this / sqrt(magnitude_sqr());
}
float jVector4::dot(jVector4 &vector) const
{
	return (mVals[0] * vector.mVals[0]) +
		   (mVals[1] * vector.mVals[1]) +
		   (mVals[2] * vector.mVals[2]) +
		   (mVals[3] * vector.mVals[3]);
}
float jVector4::magnitude_sqr() const
{
	return (mVals[0] * mVals[0]) +
		   (mVals[1] * mVals[1]) +
		   (mVals[2] * mVals[2]) +
		   (mVals[3] * mVals[3]);
}
std::string jVector4::toString()
{
	std::stringstream ss;
	ss << "(" << mVals[0] <<
		  ", " << mVals[1] <<
		  ", " << mVals[2] <<
		  ", " << mVals[3] << ")";

	return ss.str();
}
int jVector4::hashCode()
{
	return (mVals[0] * mVals[0] * 13) +
		   (mVals[1] * mVals[1] * 17) -
		   (mVals[2] * mVals[2] * 19) +
		   (mVals[3] * mVals[3] * 23);
}
