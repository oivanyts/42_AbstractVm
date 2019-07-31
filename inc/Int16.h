//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef ABSTRACTVM_INT16_H
#define ABSTRACTVM_INT16_H


#include <cstdint>
#include <string>
#include "IOperand.h"

class Int16 : public IOperand
{

public:
	Int16(std::string const &value);
	~Int16();

	Int16();

	Int16(Int16 const &src);

	Int16 &operator=(Int16 const &rhs);

	int getPrecision(void) const override;

	eOperandType getType(void) const override;

	const IOperand *operator+(IOperand const &rhs) const override;

	const IOperand *operator-(IOperand const &rhs) const override;

	const IOperand *operator*(IOperand const &rhs) const override;

	const IOperand *operator/(IOperand const &rhs) const override;

	const IOperand *operator%(IOperand const &rhs) const override;

	const std::string &toString(void) const override;

private:
	int16_t const _number;
};


#endif //ABSTRACTVM_INT16_H
