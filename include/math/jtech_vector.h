////////////////////////////////////////////////////////////////////////////////
// $Id$
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
////////////////////////////////////////////////////////////////////////////////

#ifndef JTECH_VECTOR_H
#define JTECH_VECTOR_H

#include <iostream>
#include <cmath>

#include <util/jtech_utility.h>

namespace jtech
{
	class vector2  // jtech::vector2
	{
		public:
			float x, y;

			// Constructors
			vector2() : x(0.0f), y(0.0f) {}
			vector2(float px) : x(px), y(0.0f) {}
			vector2(float px, float py) : x(px), y(py) {}
			vector2(const vector2 &vec) { *this = vec; }
			// Addition Operator
			vector2 operator+(const vector2 &vec) { return vector2(x+vec.x, y+vec.y); }
			// Subtraction Operator
			vector2 operator-(const vector2 &vec) { return vector2(x-vec.x, y-vec.y); }
			// Division Operators
			vector2 operator/(float scalar) { return vector2(x/scalar, y/scalar); }
			vector2 operator/(int scalar) { return vector2((float)x/scalar, (float)y/scalar); }
			vector2 operator/(double scalar) { return vector2(x/scalar, y/scalar); }
			// Mutliplication Operators
			vector2 operator*(float scalar) { return vector2(x*scalar, y*scalar); }
			vector2 operator*(int scalar) { return vector2(x*scalar, y*scalar); }
			vector2 operator*(double scalar) { return vector2(x*scalar, y*scalar); }
			// Special Multiplcation Operators ( Scalar * vector2 )
			friend vector2 operator*(float scalar, vector2 &vec) { return vector2(vec.x*scalar, vec.y*scalar); }
			friend vector2 operator*(int  scalar, vector2 &vec) { return vector2(vec.x*scalar, vec.y*scalar); }
			friend vector2 operator*(double scalar, vector2 &vec) { return vector2(vec.x*scalar, vec.y*scalar); }
			// Assignment Operator
			vector2 operator=(const vector2 &vec)
			{
				if (this == &vec)
					return *this;

				x = vec.x;
				y = vec.y;

				return *this;
			}
			// Equality Operator
			bool operator==(const vector2 &vec) { return (x == vec.x && y == vec.y); }
			// Inequality Operator
			bool operator!=(const vector2 &vec) { return (x != vec.x || y != vec.y); }
			// Index Operator
			float operator[](const int index) { return (index%2 == 0 ? x : y); }
			// Parenthesis Operator
			float operator()(const int index) { return (index%2 == 0 ? x : y); }
			// Output Stream Operator
			friend std::ostream& operator<<(std::ostream &out, vector2 &vec)
			{ out << "(" << vec.x << ", " << vec.y << ")"; return out; }
			// Input Stream Operator
			friend std::istream& operator>>(std::istream &in, vector2 &vec)
			{ in >> vec.x >> vec.y; return in;}
			// Normal Functions
			vector2 normal() { float length = magnitude(); return *this/length; }
			void normalize() { *this = normal(); }
			// Magnitude Functions
			float magnitude() { return sqrt(pow(x,2) + pow(y,2)); }
			float magnitude_squared() { return (pow(x,2) + pow(y,2)); }
			// Dot Product Function
			float dot(vector2 &vec) { return (x*vec.x + y*vec.y); }
			// Distance Function
			float distance(vector2 &vec) { return sqrt(pow(vec.x - x,2) + pow(vec.y - y, 2)); }
			// Dot Product Function (static)
			static float dot(vector2 &vec1, vector2 &vec2) { return vec1.dot(vec2); }
			// Distance Function (static)
			static float distance(vector2 &vec1, vector2 &vec2)
			{ return vec1.distance(vec2); }
			
			vector2 lerp(vector2 &to, float weight) { weight = jtech::util::clampf01(weight);
													  return ((1 - weight) * (*this)) + weight * to; }

			static const vector2 up;
			static const vector2 down;
			static const vector2 left;
			static const vector2 right;
	}; // end vector2 declaration

	class vector3 // jtech::vector3
	{
		public:
			float x, y, z;

			static const vector3 up;
			static const vector3 down;
			static const vector3 left;
			static const vector3 right;
			static const vector3 forward; // out of the screen
			static const vector3 backward;  // into the screen

			// Constructors
			vector3() : x(0.0f), y(0.0f), z(0.0f) {}
			vector3(float px) : x(px), y(0.0f), z(0.0f) {}
			vector3(float px, float py, float pz) : x(px), y(py), z(pz) {}
			vector3(const vector3 &vec) { *this = vec; }
			
			// Addition Operator
			vector3 operator+(const vector3 &vec) { return vector3(x + vec.x,
																   y + vec.y,
																   z + vec.z); }
			// Subtraction Operator
			vector3 operator-(const vector3 &vec) { return vector3(x - vec.x,
																   y - vec.y,
																   z - vec.z); }
			// Division Operators
			vector3 operator/(int    scalar) { return vector3(x/scalar, y/scalar, z/scalar); }
			vector3 operator/(float  scalar) { return vector3(x/scalar, y/scalar, z/scalar); }
			vector3 operator/(double scalar) { return vector3(x/scalar, y/scalar, z/scalar); }
			// Multiplication Operators
			vector3 operator*(int    scalar) { return vector3(x*scalar, y*scalar, z*scalar); }
			vector3 operator*(float  scalar) { return vector3(x*scalar, y*scalar, z*scalar); }
			vector3 operator*(double scalar) { return vector3(x*scalar, y*scalar, z*scalar); }
			// Special Multiplication Operators
			friend vector3 operator*(int    scalar, vector3 &vec) { return vector3(vec.x*scalar, vec.y*scalar, vec.z*scalar); }
			friend vector3 operator*(float  scalar, vector3 &vec) { return vector3(vec.x*scalar, vec.y*scalar, vec.z*scalar); }
			friend vector3 operator*(double scalar, vector3 &vec) { return vector3(vec.x*scalar, vec.y*scalar, vec.z*scalar); }
			// Assignment Operator
			vector3 operator=(const vector3 &vec)
			{
				if (this == &vec)
					return *this;
				
				x = vec.x;
				y = vec.y;
				z = vec.z;
				
				return *this;
			}
			// Equality Operator
			bool operator==(const vector3 &vec) { return (x == vec.x && y == vec.y && z == vec.z); }
			// Inequality Operator
			bool operator!=(const vector3 &vec) { return (x != vec.x || y != vec.y || z != vec.z); }
			// Index Operator
			float operator[](const int index) { return (index%3 == 0 ? x : index%3 == 1 ? y : z); }
			// Parenthesis Operator
			float operator()(const int index) { return (index%3 == 0 ? x : index%3 == 1 ? y : z); }
			// Output Stream Operator
			friend std::ostream& operator<<(std::ostream &out, vector3 &vec)
			{ out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")"; return out; }
			// Input Stream Operator
			friend std::istream& operator>>(std::istream &in, vector3 &vec)
			{ in >> vec.x >> vec.y >> vec.z; return in;}
			// Normal Functions
			vector3 normal() { float length = magnitude(); return *this/length; }
			void normalize() { *this = normal(); }
			// Magnitude Functions
			float magnitude() { return sqrt(pow(x,2) + pow(y,2) + pow(z,2)); }
			float magnitude_squared() { return (pow(x,2) + pow(y,2) + pow(z,2)); }
			// Dot Product Function
			float dot(vector3 &vec) { return (x*vec.x + y*vec.y + z*vec.z); }
			// Distance Function
			float distance(vector3 &vec) { return sqrt(pow(vec.x - x,2) + pow(vec.y - y, 2) + pow(vec.z - z, 2)); }
			// Dot Product Function (static)
			static float dot(vector3 &vec1, vector3 &vec2) { return vec1.dot(vec2); }
			// Distance Function (static)
			static float distance(vector3 &vec1, vector3 &vec2)
			{ return vec1.distance(vec2); }
	};
}

#endif
