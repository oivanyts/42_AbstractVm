//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef ABSTRACTVM_DOUBLE_H
#define ABSTRACTVM_DOUBLE_H


#include <string>
#include "IOperand.h"

class Double : public IOperand
{

public:
	Double();
	Double(std::string const &value);

	~Double();

	int getPrecision(void) const override;

	eOperandType getType(void) const override;

	const IOperand *operator+(IOperand const &rhs) const override;

	const IOperand *operator-(IOperand const &rhs) const override;

	const IOperand *operator*(IOperand const &rhs) const override;

	const IOperand *operator/(IOperand const &rhs) const override;

	const IOperand *operator%(IOperand const &rhs) const override;

	const std::string &toString(void) const override;

	Double(Double const &src);

	Double &operator=(Double const &rhs);

private:
	double const _number;
};


#endif //ABSTRACTVM_DOUBLE_H
