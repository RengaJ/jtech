////////////////////////////////////////////////////////////////////////////////
// jDebug - Header File
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
// The jDebug's goal is to encapsulate per-module logging methods.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef J_DEBUG_H
#define J_DEBUG_H

#include <jobject.h>

#include <fstream>
#include <ostream>

#include <map>
#include <string>

// Windows specific functionality
#ifdef _WIN32
	#include <windows.h>
#endif

class jDebug // NOTE: THIS DOES NOT INHERIT FROM jObject, since there is no point to it.
{
	public:
		//static void Log(char* message);
		static void Log(std::string message);
		static void Log(jObject& object);
		//static void Log(std::string logger, char* message);
		static void Log(std::string logger, std::string message);
		//static void Log(std::string logger, jObject& object);

		//static void LogWarning(char* message);
		static void LogWarning(std::string message);
		static void LogWarning(jObject& object);
		//static void LogWarning(std::string logger, char* message);
		//static void LogWarning(std::string logger, std::string message);
		//static void LogWarning(std::string logger, jObject& object);

		//static void LogError(char* message);
		static void LogError(std::string message);
		static void LogError(jObject& object);
		static void LogError(std::string logger, std::string message);
		//static void LogError(std::string logger, char* message);
		//static void LogError(std::string logger, jObject& object);

		static void AddLogger(std::string name, std::string filepath);
		static void DestructLoggers();

	private:
		// Keeps track of different logging streams
		static std::map<std::string, std::ofstream*> mLogStreams;
		#ifdef _WIN32
		static HANDLE mHStdOut;
		static CONSOLE_SCREEN_BUFFER_INFO csbi;
		#endif
};

#endif
