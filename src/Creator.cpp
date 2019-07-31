//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include <iostream>
#include "Creator.h"

#include "Double.h"
#include "Float.h"
#include "Int8.h"
#include "Int16.h"
#include "Int32.h"

Creator::Creator() { }

Creator::Creator(Creator const &src)
{
	*this = src;
}

Creator::~Creator() {}

Creator &Creator::operator=(Creator const &rhs)
{
	if (&rhs != this)
	{

	}
	return *this;
}

IOperand const *Creator::createInt8(std::string const &value) const
{
	return new Int8(value);
}

IOperand const *Creator::createInt16(std::string const &value) const
{
	return new Int16(value);
}

IOperand const *Creator::createInt32(std::string const &value) const
{
	return new Int32(value);
}

IOperand const *Creator::createFloat(std::string const &value) const
{
	return new Float(value);
}

IOperand const *Creator::createDouble(std::string const &value) const
{
	return new Double(value);
}

IOperand const *Creator::createOperand(eOperandType type, std::string const &value) const
{
	switch (type)
	{
		case eInt8 :
			return createInt8(value);
		case eInt16 :
			return createInt16(value);
		case eInt32 :
			return createInt32(value);
		case eFloat :
			return createFloat(value);
		case eDouble :
			return createDouble(value);
	}
	return nullptr;
}

