//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include "Int16.h"

Int16::Int16() : _number(0)
{

}

Int16::~Int16()
{

}

Int16::Int16(Int16 const &src) : _number(src._number)
{
	*this = src;
}

Int16::Int16(std::string const &value) : _number(atoi(value.c_str()))
{

}

Int16 &Int16::operator=(Int16 const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}

int Int16::getPrecision(void) const
{
	return 0;
}

eOperandType Int16::getType(void) const
{
	return eDouble;
}

const IOperand *Int16::operator+(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int16::operator-(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int16::operator*(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int16::operator/(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int16::operator%(IOperand const &rhs) const
{
	return nullptr;
}

const std::string &Int16::toString(void) const
{
	return std::to_string(_number);
}
