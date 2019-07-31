//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include "Double.h"

Double::Double() : _number(0)
{

}

Double::~Double()
{

}

Double::Double(Double const &src) : _number(src._number)
{
	*this = src;
}

Double &Double::operator=(Double const &rhs)
{
	if (&rhs != this)
	{

	}
	return *this;
}

Double::Double(std::string const &value)  : _number(atoi(value.c_str()))
{

}

int Double::getPrecision(void) const
{
	return 0;
}

eOperandType Double::getType(void) const
{
	return eDouble;
}

const IOperand *Double::operator+(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Double::operator-(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Double::operator*(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Double::operator/(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Double::operator%(IOperand const &rhs) const
{
	return nullptr;
}

const std::string &Double::toString(void) const
{
	return std::to_string(_number);
}
