/*
 * Child3.cpp
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
#include <iostream>

#include "Child3.h"

REGISTERIMPL(Child3);

void Child3::foo()
{
	std::cout << "Child3" << std::endl;
}


