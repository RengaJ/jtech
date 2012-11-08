////////////////////////////////////////////////////////////////////////////////
// jDebug - Implementation File
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

#include <jdebug.h>

std::map<std::string, std::ofstream*> jDebug::mLogStreams = std::map<std::string, std::ofstream*>();

void jDebug::Log(std::string message)
{
	std::cout << message << std::endl;
}

void jDebug::Log(jObject& object)
{
	std::cout << object.toString() << std::endl;
}

void jDebug::Log(std::string logger, std::string message)
{
	if (mLogStreams.find(logger) != mLogStreams.end())
		(*(mLogStreams[logger])) << message << std::endl;
}

void jDebug::Log(std::string logger, jObject& object)
{
	if (mLogStreams.find(logger) != mLogStreams.end())
		(*(mLogStreams[logger])) << object << std::endl;
}

void jDebug::LogWarning(std::string message)
{
	#ifdef _WIN32
		std::cout << "WARNING: " << message << std::endl;
	#else
		std::cout << "\033[4;36mWARNING: " << message << "\033[0m" << std::endl;
	#endif
}

void jDebug::LogWarning(jObject& object)
{
	#ifdef _WIN32
		std::cout << "WARNING: " << object.toString() << std::endl;
	#else
		std::cout << "\033[4;36mWARNING: " << object.toString() << std::endl;
	#endif
}

void jDebug::LogWarning(std::string logger, std::string message)
{
	if (mLogStreams.find(logger) != mLogStreams.end())
	{
		#ifdef _WIN32
			(*(mLogStreams[logger])) << "WARNING: " << message << std::endl;
		#else
			(*(mLogStreams[logger])) << "\033[4;36mWARNING: " << message << "\033[0m" << std::endl;
		#endif
	}
}

void jDebug::LogWarning(std::string logger, jObject& object)
{
	if (mLogStreams.find(logger) != mLogStreams.end())
	{
		#ifdef _WIN32
			(*(mLogStreams[logger])) << "WARNING: " << object << std::endl;
		#else
			(*(mLogStreams[logger])) << "\033[4;36mWARNING: " << object << "\033[0m" << std::endl;
		#endif
	}
}

void jDebug::LogError(std::string message)
{
	#ifdef _WIN32
		std::cerr << "ERROR: " << message << std::endl;
	#else
		std::cerr << "\033[1;31mERROR: " << message << "\033[0m" << std::endl;
	#endif
}

void jDebug::LogError(jObject& object)
{
	#ifdef _WIN32
		std::cerr << "ERROR: " << object.toString() << std::endl;
	#else
		std::cerr << "\033[1;31mERROR: " << object.toString() << "\033[0m" << std::endl;
	#endif
}

void jDebug::LogError(std::string logger, std::string message)
{
	if (mLogStreams.find(logger) != mLogStreams.end())
	{
		#ifdef _WIN32
			(*(mLogStreams[logger])) << "ERROR: " << message << std::endl;
		#else
			(*(mLogStreams[logger])) << "\033[1;31mERROR: " << message << "\033[0m" << std::endl;
		#endif
	}
}

void jDebug::LogError(std::string logger, jObject& object)
{
 if (mLogStreams.find(logger) != mLogStreams.end())
 {
 	#ifdef _WIN32
		(*(mLogStreams[logger])) << "ERROR: " << object << std::endl;
	#else
		(*(mLogStreams[logger])) << "\033[1;31mERROR: " << object << "\033[0m" << std::endl;
	#endif
 }
}

void jDebug::AddLogger(std::string name, std::string filepath)
{
	if (mLogStreams.find(name) != mLogStreams.end()) // if mLogStreams contains name
	{
		mLogStreams[name]->close();
		delete mLogStreams[name];
		mLogStreams[name] = NULL;
	}
	mLogStreams[name] = new std::ofstream(filepath.c_str(), std::ios::out);
}

void jDebug::DestructLoggers()
{
	std::map<std::string, std::ofstream*>::iterator itr = mLogStreams.begin();
	for (itr; itr != mLogStreams.end(); itr++)
	{
		itr->second->close();
		delete itr->second;
		itr->second = NULL;
	}

	mLogStreams.clear();
}
