//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#include "Float.h"

Float::Float() : _number(0)
{

}

Float::~Float()
{

}

Float::Float(std::string const &value) : _number(atoi(value.c_str()))
{

}

Float::Float(Float const &src) : _number(src._number)
{
	*this = src;
}

Float &Float::operator=(Float const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}

int Float::getPrecision(void) const
{
	return 0;
}

eOperandType Float::getType(void) const
{
	return eDouble;
}

const IOperand *Float::operator+(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Float::operator-(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Float::operator*(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Float::operator/(IOperand const &rhs) const
{
	return nullptr;
}

const IOperand *Float::operator%(IOperand const &rhs) const
{
	return nullptr;
}

const std::string &Float::toString(void) const
{
	return std::to_string(_number);
}
