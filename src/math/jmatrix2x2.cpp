////////////////////////////////////////////////////////////////////////////////
// jMatrix2x2 - Implementation File
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
////////////////////////////////////////////////////////////////////////////////

#include <math/jmatrix.h>

jMatrix2x2::jMatrix2x2()
{
	mMatrix = new float[4];
	mMatrix[0] = mMatrix[1] = mMatrix[2] = mMatrix[3] = 0.0f;
}

jMatrix2x2::jMatrix2x2(float matrix[4])
{
	mMatrix = new float[4];
	for (int i = 0; i < 4; i++) mMatrix[i] = matrix[i];
}

jMatrix2x2::~jMatrix2x2()
{
	if (mMatrix)
	{
		delete [] mMatrix;
		mMatrix = NULL;
	}
}

std::string jMatrix2x2::toString()
{
	std::stringstream ss;
	ss << "[[" << mMatrix[0] << " " << mMatrix[1] << "]";
	ss << " [" << mMatrix[2] << " " << mMatrix[3] << "]]";

	return ss.str();
}

int jMatrix2x2::hashCode()
{
	return (mMatrix[0] * mMatrix[0] * 13) +
		   (mMatrix[1] * mMatrix[1] * 17) -
		   (mMatrix[2] * mMatrix[2] * 23) +
		   (mMatrix[3] * mMatrix[3] * 19);
}
