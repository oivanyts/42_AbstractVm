//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef ABSTRACTVM_INT32_H
#define ABSTRACTVM_INT32_H


#include <string>
#include "IOperand.h"

class Int32 : public IOperand
{
public:
	Int32(std::string const &value);
	~Int32();
	Int32(Int32 const &src);
	Int32 &operator=(Int32 const &rhs);

	int getPrecision(void) const override;

	eOperandType getType(void) const override;

	const IOperand *operator+(IOperand const &rhs) const override;

	const IOperand *operator-(IOperand const &rhs) const override;

	const IOperand *operator*(IOperand const &rhs) const override;

	const IOperand *operator/(IOperand const &rhs) const override;

	const IOperand *operator%(IOperand const &rhs) const override;

	const std::string &toString(void) const override;

private:
	int32_t const _number;
	Int32();

};


#endif //ABSTRACTVM_INT32_H
