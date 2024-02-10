/*
 * Factory.h
 * 
 *  Created on: April 14, 2013
 *      Author: David J. Rager
 *       Email: djrager@fourthwoods.com
 *
 * This code is hereby released into the public domain per the Creative Commons
 * Public Domain dedication.
 *
 * http://http://creativecommons.org/publicdomain/zero/1.0/
 */
#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>
#include <map>

#include "CreatorImpl.h"

class Base;
class Creator;

class Factory
{
public:
	static Base* create(const std::string& classname);
	static void registerit(const std::string& classname, Creator* creator);
private:
	static std::map<std::string, Creator*>& get_table();
};

#define REGISTER(classname) \
	private: \
	static const CreatorImpl<classname> creator;

#define REGISTERIMPL(classname) \
	const CreatorImpl<classname> classname::creator(#classname);

#endif //_FACTORY_H_

