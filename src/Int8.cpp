//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include "Int8.h"

Int8::Int8() : _number(0)
{ }

Int8::~Int8()
{ }

Int8::Int8(Int8 const &src) : _number(src._number)
{
	*this = src;
}

Int8 &Int8::operator=(Int8 const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}

Int8::Int8(std::string const &value) : _number(std::atoi(value.c_str()))
{

}

int Int8::getPrecision(void) const
{
	return 0;
}

eOperandType Int8::getType(void) const
{
	return eDouble;
}

const IOperand *Int8::operator+(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int8::operator-(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int8::operator*(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int8::operator/(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int8::operator%(IOperand const &rhs) const
{
	return nullptr;
}

const std::string &Int8::toString(void) const
{
	return std::to_string(_number);
}
