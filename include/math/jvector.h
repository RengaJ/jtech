////////////////////////////////////////////////////////////////////////////////
// jVector - Header File
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

#ifndef J_VECTOR_H
#define J_VECTOR_H

#include <cmath>
#include <jobject.h>

class jVector2 : public jObject
{
	public:
		// Constructors
		//! Default Constructor
		/*!
			This defaults the jVector2 to contain the value (0,0).
		 */
		jVector2();
		//! Partial Constructor
		/*!
			This partially constructs the jVector2 to contain the value (x,0).
			\param x The x component of the jVector2.
		 */
		jVector2(float x);
		//! Full Constructor
		/*!
			This fully constructs the jVector2 to contain the value (x,y).
			\param x The x component of the jVector2.
			\param y The y component of the jVector2.
		 */
		jVector2(float x, float y);
		//! Copy Constructor
		/*!
			This constructs a jVector2 with the values contained in vector.
			\param vector The vector to be copied.
		 */
		jVector2(const jVector2 &vector);
		// Destructor
		~jVector2();
		//! Assignment Operator
		/*!
			\param vector The RHS of the assignment expression.
			\return A copy of the newly assigned jVector2.
		 */
		jVector2 operator=(const jVector2 &vector);
		// Access Operators
		float operator()(int index) const;
		float operator[](int index) const;
		// Equality Operators
		bool operator==(jVector2 &vector) const;
		bool operator!=(jVector2 &vector) const;
		// Arithmetic Operators
		jVector2 operator+(const jVector2 &vector);
		jVector2 operator-(const jVector2 &vector);
		jVector2 operator*(float scalar);
		jVector2 operator/(float scalar);
		
		jVector2 operator-(); // negation operator
		
		// Aritmetic Operations (non-operators)
		jVector2 normalized();
		float cross(jVector2 vector) const;
		float dot(jVector2 vector) const;
		float magnitude_sqr() const;
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mVals;
};

class jVector3 : public jObject
{
	public:
		// Constructors
		//! Default Constructor
		/*!
			This defaults the jVector3 to contain the value (0,0,0).
		 */
		jVector3();
		//! Partial Constructor
		/*!
			This partially constructs the jVector3 to contain the value (x,0,0).
			\param x The x component of the jVector3.
		 */
		jVector3(float x);
		//! Full Constructor
		/*!
			This fully constructs the jVector3 to contain the value (x,y,z).
			\param x The x component of the jVector3.
			\param y The y component of the jVector3.
			\param z The z component of the jVector3.
		 */
		jVector3(float x, float y, float z);
		//! Copy Constructor
		/*!
			This constructs a jVector3 with the values contained in vector.
			\param vector The vector to be copied.
		 */
		jVector3(const jVector3 &vector);
		// Destructor
		~jVector3();
		//! Assignment Operator
		/*!
			\param vector The RHS of the assignment expression.
			\return A copy of the newly assigned jVector3.
		 */
		jVector3 operator=(const jVector3 &vector);
		// Access Operators
		float operator()(int index) const;
		float operator[](int index) const;
		// Equality Operators
		bool operator==(jVector3 &vector) const;
		bool operator!=(jVector3 &vector) const;
		// Arithmetic Operators
		jVector3 operator+(const jVector3 &vector);
		jVector3 operator-(const jVector3 &vector);
		jVector3 operator*(float scalar);
		jVector3 operator/(float scalar);
		// Aritmetic Operations (non-operators)
		jVector3 normalized();
		jVector3 cross(jVector3 &vector) const;
		float dot(jVector3 &vector) const;
		float magnitude_sqr() const;
		// Methods inherited from jObject
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mVals; // the data contained within the jVector3
};

class jVector4 : public jObject
{
		// Constructors
		//! Default Constructor
		/*!
			This defaults the jVector4 to contain the value (0,0,0,0).
		 */
		jVector4();
		//! Partial Constructor
		/*!
			This partially constructs the jVector4 to contain the value (x,0,0,0).
			\param x The x component of the jVector4.
		 */
		jVector4(float x);
		//! Full Constructor
		/*!
			This fully constructs the jVector4 to contain the value (x,y,z,w).
			\param x The x component of the jVector4.
			\param y The y component of the jVector4.
			\param z The z component of the jVector4.
			\param w The w component of the jVector4.
		 */
		jVector4(float x, float y, float z, float w);
		//! Copy Constructor
		/*!
			This constructs a jVector4 with the values contained in vector.
			\param vector The vector to be copied.
		 */
		jVector4(const jVector4 &vector);
		// Destructor
		~jVector4();
		//! Assignment Operator
		/*!
			\param vector The RHS of the assignment expression.
			\return A copy of the newly assigned jVector4.
		 */
		jVector4 operator=(const jVector4 &vector);
		// Access Operators
		float operator()(int index) const;
		float operator[](int index) const;
		// Equality Operators
		bool operator==(jVector4 &vector) const;
		bool operator!=(jVector4 &vector) const;
		// Arithmetic Operators
		jVector4 operator+(const jVector4 &vector);
		jVector4 operator-(const jVector4 &vector);
		jVector4 operator*(float scalar);
		jVector4 operator/(float scalar);
		// Aritmetic Operations (non-operators)
		jVector4 normalized();
		float dot(jVector4 &vector) const;
		float magnitude_sqr() const;
		// Methods inherited from jObject
		virtual std::string toString();
		virtual int hashCode();
	private:
		float* mVals; // the data contained within the jVector4
};

#endif
