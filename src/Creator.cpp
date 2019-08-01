//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include <iostream>
#include "TOperant.h"
#include "Creator.h"

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
	return new TOperant<int8_t>(value);
}

IOperand const *Creator::createInt16(std::string const &value) const
{
	return new TOperant<int16_t>(value);
}

IOperand const *Creator::createInt32(std::string const &value) const
{
	return new TOperant<int32_t>(value);
}

IOperand const *Creator::createFloat(std::string const &value) const
{
	return new TOperant<float>(value);
}

IOperand const *Creator::createDouble(std::string const &value) const
{
	return new TOperant<double>(value);
}

IOperand const *Creator::createOperand(eOperandType type, std::string const &value) const
{
	typedef IOperand const *(Creator::*funcptr)(std::string const &value) const;
	funcptr tmp[] = {
			&Creator::createInt8,
			&Creator::createInt16,
			&Creator::createInt32,
			&Creator::createFloat,
			&Creator::createDouble };
	return (this->*tmp[type])(value);
}

