//
// Created by Oleh IVANYTSKYI on 2019-08-01.
//

#ifndef ABSTRACTVM_TOPERANT_H
#define ABSTRACTVM_TOPERANT_H

#include "IOperand.h"
#include "Creator.h"
#include <string>
#include <sstream>
#include <cmath>

template <typename T>
class TOperant : public IOperand
{

public:
	TOperant() {};

	inline const T toNum(const std::string &basicString)
	{
		std::stringstream	tmp(basicString);
		T					ret = 0;
		if (sizeof(T) == 1)
		{
			int ret1;
			tmp >> ret1;
			ret = static_cast<T>(ret1);
			return (ret);
		}
		tmp >> ret;
		return ret;
	}

	inline eOperandType setType(int8_t)
		{ return eInt8; }
	inline eOperandType setType(int16_t)
		{ return eInt16; }
	inline eOperandType setType(int32_t)
		{ return eInt32; }
	inline eOperandType setType(float)
		{ return eFloat; }
	inline eOperandType setType(double)
		{ return eDouble; }


	TOperant(std::string const &value)
		: _number(toNum(value)), _type(setType(_number)), _str(value) {};
	~TOperant() {};
	TOperant(TOperant const &src) {};
	TOperant &operator=(TOperant const &rhs) {};

	int getPrecision(void) const override {	return static_cast<int>(getType()); }

	eOperandType getType(void) const override { return _type; }

	const IOperand *operator+(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());


		//exeption managment
		return type < eFloat
			? ret.createOperand(type, std::to_string(_number + std::stoi(rhs.toString())))
			: ret.createOperand(type, std::to_string(_number + std::stod(rhs.toString())));
	}

	const IOperand *operator-(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		//exeption managment
		return type < eFloat
			   ? ret.createOperand(type, std::to_string(_number - std::stoi(rhs.toString())))
			   : ret.createOperand(type, std::to_string(_number - std::stod(rhs.toString())));
	}

	const IOperand *operator*(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		//exeption managment
		return type < eFloat
			   ? ret.createOperand(type, std::to_string(_number * std::stoi(rhs.toString())))
			   : ret.createOperand(type, std::to_string(_number * std::stod(rhs.toString())));
	}

	const IOperand *operator/(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		//exeption managment
		return type < eFloat
			   ? ret.createOperand(type, std::to_string(_number / std::stoi(rhs.toString())))
			   : ret.createOperand(type, std::to_string(_number / std::stod(rhs.toString())));
	}

	const IOperand *operator%(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		//exeption managment
		return type < eFloat
			   ? ret.createOperand(type, std::to_string(std::fmod(_number, std::stoi(rhs.toString()))))
			   : ret.createOperand(type, std::to_string(std::fmod(_number, std::stod(rhs.toString()))));
	}

	const std::string &toString(void) const override
	{ return _str; }

private:
	T	const				_number;
	eOperandType const	 	_type;
	std::string const 		_str;
};


#endif //ABSTRACTVM_TOPERANT_H
