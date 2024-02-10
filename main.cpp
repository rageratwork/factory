/*
 * main.cpp
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
#include "Base.h"

#include <iostream>

int main(int argc, char* argv[])
{
	Base* p;

	if(argc < 2)
	{
		std::cout << "Please specify a class name!" << std::endl;
		return 0;
	}
	
	p = Factory::create(argv[1]);

	if(p != NULL)
		p->foo();
	else
		std::cout << "Class not found!" << std::endl;

	delete p;

	return 0;
}

