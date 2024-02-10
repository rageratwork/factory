/*
 * Child3.h
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
#ifndef _CHILD3_H_
#define _CHILD3_H_

#include "Child2.h"

class Child3 : public Child2
{
	REGISTER(Child3);

public:
	virtual ~Child3() {}

	virtual void foo();
};

#endif //_CHILD3_H_

