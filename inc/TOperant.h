//
// Created by Oleh IVANYTSKYI on 2019-08-01.
//

#ifndef ABSTRACTVM_TOPERANT_H
#define ABSTRACTVM_TOPERANT_H

#include "IOperand.h"
#include "Creator.h"
#include "ErrorMng.h"
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
			if (ret1 > std::numeric_limits<T>::max())
				throw RuntimeErr("Overflow " + basicString);
			else if (ret1 < std::numeric_limits<T>::min())
				throw RuntimeErr("Underflow " + basicString);
			ret = static_cast<T>(ret1);
			return (ret);
		}
		tmp >> ret;
		if (!tmp.eof() || tmp.fail())
		{
			T lng;
			tmp >> lng;
			if (lng > std::numeric_limits<T>::max())
				throw RuntimeErr("Overflow " + basicString);
			else if (lng < std::numeric_limits<T>::min())
				throw RuntimeErr("Underflow " + basicString);
		}
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
		: _number(toNum(value)), _type(setType(_number)), _str(std::to_string(_number)) {};
	~TOperant() {};
	TOperant(TOperant const &src) { (void)src; }; //
	TOperant &operator=(TOperant const &rhs) { (void)rhs; }; //

	int getPrecision(void) const override {	return static_cast<int>(getType()); }

	eOperandType getType(void) const override { return _type; }

	const IOperand *operator+(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		long double		num = _number + std::stod(rhs.toString());

		return ret.createOperand(type, std::to_string((num)));
	}

	const IOperand *operator-(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		long double		num = _number - std::stod(rhs.toString());

		return ret.createOperand(type, std::to_string((num)));
	}

	const IOperand *operator*(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		long double		num = _number * std::stod(rhs.toString());

		return ret.createOperand(type, std::to_string((num)));
	}

	const IOperand *operator/(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		if (std::stod(rhs.toString()) == 0.0)
		{
			throw RuntimeErr("Division by 0");
		}
		long double		num = _number / std::stod(rhs.toString());

		return ret.createOperand(type, std::to_string((num)));
	}

	const IOperand *operator%(IOperand const &rhs) const override
	{
		Creator			ret;
		eOperandType	type = std::max(this->_type, rhs.getType());
		if (std::stod(rhs.toString()) == 0.0)
		{
			throw RuntimeErr("Modulo by 0");
		}
		long double		num = fmod(_number , std::stod(rhs.toString()));

		return ret.createOperand(type, std::to_string((num)));
	}

	inline bool operator==(const IOperand & lhs, const IOperand& rhs) { return true; };

	const std::string &toString(void) const override
	{
		return _str;
	}

private:
	T	const				_number;
	eOperandType const	 	_type;
	std::string const		_str;
};

#endif //ABSTRACTVM_TOPERANT_H
