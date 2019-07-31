//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include "Int32.h"

Int32::Int32() : _number(0)
{

}
Int32::Int32(std::string const &value) : _number(atoi(value.c_str()))
{

}
Int32::~Int32()
{

}

Int32::Int32(Int32 const &src) : _number(src._number)
{
	*this = src;
}

Int32 &Int32::operator=(Int32 const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}

int Int32::getPrecision(void) const
{
	return 0;
}

eOperandType Int32::getType(void) const
{
	return eDouble;
}

const IOperand *Int32::operator+(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int32::operator-(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int32::operator*(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int32::operator/(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Int32::operator%(IOperand const &rhs) const
{
	return nullptr;
}

const std::string &Int32::toString(void) const
{
	return std::to_string(_number);
}
