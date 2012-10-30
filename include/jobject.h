////////////////////////////////////////////////////////////////////////////////
// jObject - Header File
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
// The jObject's main function is to be the top-level object that (eventually) all
// of the components of jTech will inherit from. Thus, every jObject that is created
// will need to be able to print a description of itself, and provide a method for generating
// hash codes. However, once the functions have been defined for larger classes (say, for
// example, the jGraphicsContext), then the subclasses won't need to redefine them, but they
// can still be printed / logged through the jDebugger class.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef J_OBJECT_H
#define J_OBJECT_H

#include <string>
#include <sstream>

#include <iostream>

class jObject
{
	public:
		// All of the methods are pure virtual to ensure that the
		// jObject class itself cannot be instantiated, but
		// all subclasses of it (which will be most of the classes)
		// will have these functions available to them.
		/* virtual char* toCharArray() = 0; */
		virtual std::string toString() = 0;
		virtual int hashCode() = 0;
		// Allow EVERY jObject the ability to interact directly with std::ostream (without code duplication)
		friend std::ostream& operator<<(std::ostream& out, jObject& object) { return out << object.toString(); }
};

#endif
