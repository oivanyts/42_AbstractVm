//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef ABSTRACTVM_INT8_H
#define ABSTRACTVM_INT8_H


#include <cstdint>
#include <string>
#include "IOperand.h"

class Int8 : public IOperand
{

public:
	Int8(std::string const &value);
	~Int8();
	Int8(Int8 const &src);
	Int8 &operator=(Int8 const &rhs);

	int getPrecision(void) const override;

	eOperandType getType(void) const override;

	const IOperand *operator+(IOperand const &rhs) const override;

	const IOperand *operator-(IOperand const &rhs) const override;

	const IOperand *operator*(IOperand const &rhs) const override;

	const IOperand *operator/(IOperand const &rhs) const override;

	const IOperand *operator%(IOperand const &rhs) const override;

	const std::string &toString(void) const override;

private:
	Int8();
	int8_t const _number;
};


#endif //ABSTRACTVM_INT8_H
