//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef ABSTRACTVM_FLOAT_H
#define ABSTRACTVM_FLOAT_H


#include <string>
#include "IOperand.h"

class Float : public IOperand
{

public:
	Float();
	Float(std::string const &value);

	~Float();

	Float(Float const &src);

	Float &operator=(Float const &rhs);

	int getPrecision(void) const override;

	eOperandType getType(void) const override;

	const IOperand *operator+(IOperand const &rhs) const override;

	const IOperand *operator-(IOperand const &rhs) const override;

	const IOperand *operator*(IOperand const &rhs) const override;

	const IOperand *operator/(IOperand const &rhs) const override;

	const IOperand *operator%(IOperand const &rhs) const override;

	const std::string &toString(void) const override;

private:
	float const _number;
};


#endif //ABSTRACTVM_FLOAT_H
