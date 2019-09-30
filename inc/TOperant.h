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
	TOperant() = default;

	~TOperant() = default;

	TOperant(TOperant const &src) : _number(src._number), _type(src._type),
									_str(src._str)
	{	};
	inline TOperant &operator=(TOperant const &rhs)
	{
		if (*this == rhs)
		{
			_number = rhs._number;
			_type = rhs._type;
			_str = rhs._str;
		}
		return *this;
	};

	inline const T toNum(const std::string &basicString)
	{
		std::stringstream	tmp(basicString);
		T					ret = 0;
		if (sizeof(T) == 1)
		{
			int ret1;
			tmp >> ret1;
			if (ret1 > std::numeric_limits<T>::max())
				throw RuntimeErr("value overflow " + basicString);
			else if (ret1 < std::numeric_limits<T>::lowest())
				throw RuntimeErr("value underflow " + basicString);
			ret = static_cast<T>(ret1);
			return (ret);
		}
		long double lng = 0;
		if (!tmp.eof() || tmp.fail())
		{
			tmp >> lng;
			if (lng > std::numeric_limits<T>::max())
			throw RuntimeErr("value overflow " + basicString);
			else if (lng < std::numeric_limits<T>::lowest())
			throw RuntimeErr("value underflow " + basicString);
		}
		return static_cast<T>(lng);
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

	TOperant(std::string const &value) : _number(toNum(value)),
	_type(setType(_number)), _str(std::to_string(_number))
	{
		if (_type != eInt8)
		{
			std::stringstream ss;
			ss << static_cast<T>(_number);
			_str = ss.str();
		}
		else
			_str = std::to_string(_number);
	};


	inline int getPrecision(void) const override
	{
		return static_cast<int>(getType());
	}

	inline eOperandType getType(void) const override { return _type; }

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

	inline bool operator==(IOperand const & rhs) const override
	{
		return (rhs.getType() == getType() && toString() == rhs.toString());
	};

	inline bool operator!=(IOperand const & rhs) const override
	{
		return (!(*this == rhs));
	};

	inline const std::string &toString(void) const override
	{
		return _str;
	}

	virtual IOperand const *fsqrt() const override
	{
		Creator			ret;

		if (_number <= 0)
			throw RuntimeErr(" cant sqrt if number <= 0");
		long double		num = std::sqrt(std::stod(toString()));
		return ret.createOperand(getType(), std::to_string((num)));
	}

	const IOperand *fpow(const IOperand &second) const override
	{
		Creator			ret;
		eOperandType	type = std::max(getType(), second.getType());
		long double		num = std::pow(std::stod(toString()) , std::stod(second.toString()));
		return ret.createOperand(type, std::to_string((num)));
	}

private:
	T	const				_number;
	eOperandType const	 	_type;
	std::string				_str;
};

#endif
