////////////////////////////////////////////////////////////////////////////////
// jMatrix - Header File
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
// jMatrixNxN comes in both row and column majors (by default, it is row-major).
// Column-major matrices are denoted by jCMatrixNxN (jCMatrix3x3, for example).
////////////////////////////////////////////////////////////////////////////////

#ifndef J_MATRIX_H
#define J_MATRIX_H

#include <cmath>
#include <jobject.h>

// Row Major 2x2 Matrix
class jMatrix2x2 : public jObject
{
	public:
		jMatrix2x2();
		jMatrix2x2(float matrix[4]);
	//	jMatrix2x2(const jMatrix2x2 &matrix);
		~jMatrix2x2();

		//! Returns the 2x2 identity matrix
		/*!
			\return The identity matrix.
		 */
		static jMatrix2x2 identity()
		{
			float contents[4] = {1.0f, 0.0f, 0.0f, 1.0f};
			return jMatrix2x2(contents);
		}

		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mMatrix;
};

// Row Major 3x3 Matrix
class jMatrix3x3 : public jObject
{
	public:
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mMatrix;
};

// Row Major 4x4 Matrix
class jMatrix4x4 : public jObject
{
	public:
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mMatrix;
};

// Column Major 2x2 Matrix
class jCMatrix2x2 : public jObject
{
	public:
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mMatrix;
};

// Column Major 3x3 Matrix
class jCMatrix3x3 : public jObject
{
	public:
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mMatrix;
};

// Column Major 4x4 Matrix
class jCMatrix4x4 : public jObject
{
	public:
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mMatrix;
};

#endif
