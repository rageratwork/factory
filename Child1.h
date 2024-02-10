/*
 * Child1.h
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
#ifndef _CHILD1_H_
#define _CHILD1_H_

#include "Base.h"

class Child1 : public Base
{
	REGISTER(Child1);

public:
	virtual ~Child1() {}

	virtual void foo();
};

#endif //_CHILD1_H_

