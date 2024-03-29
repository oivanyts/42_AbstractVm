//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef IOPERAND_H
#define IOPERAND_H

#include <iostream>
#include "main.h"

class IOperand {
public:
	virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
	virtual eOperandType getType( void ) const = 0; // Type of the instance
	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
	virtual inline bool operator==(IOperand const & rhs) const = 0;
	virtual inline bool operator!=(IOperand const & rhs) const = 0;
	virtual IOperand const *fpow(IOperand const &second) const = 0;
	virtual IOperand const *fsqrt() const = 0;
	virtual std::string const & toString( void ) const = 0; // String representation of the instance

	virtual ~IOperand( void ) {}

};



#endif //IOPERAND_H
