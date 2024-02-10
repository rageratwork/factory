/*
 * Base.h
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
#ifndef _BASE_H_
#define _BASE_H_

// include the factory stuff so derived classes see the REGISTER macros
// without doing any extra work.
#include "Factory.h"

class Base
{
public:
	virtual ~Base() {}

	virtual void foo() = 0;
};

#endif //_BASE_H_

