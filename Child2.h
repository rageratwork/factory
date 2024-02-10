/*
 * Child2.h
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
#ifndef _CHILD2_H_
#define _CHILD2_H_

#include "Base.h"

class Child2 : public Base
{
	REGISTER(Child2);

public:
	virtual ~Child2() {}

	virtual void foo();
};

#endif //_CHILD2_H_

