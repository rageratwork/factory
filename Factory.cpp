/*
 * Factory.cpp
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
#include "Factory.h"
#include "Creator.h"

void Factory::registerit(const std::string& classname, Creator* creator)
{
	get_table()[classname] = creator;
}

Base* Factory::create(const std::string& classname)
{
	std::map<std::string, Creator*>::iterator i;
	i = get_table().find(classname);

	if(i != get_table().end())
		return i->second->create();
	else
		return (Base*)NULL;
}

std::map<std::string, Creator*>& Factory::get_table()
{
	static std::map<std::string, Creator*> table;
	return table;
}

