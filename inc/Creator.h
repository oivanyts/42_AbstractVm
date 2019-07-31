//
// Created by Oleh IVANYTSKYI on 2019-07-31.
//

#ifndef OPERATORMEMB_H
#define OPERATORMEMB_H

#include <IOperand.h>
#include <string>
#include "main.h"

class Creator : private IOperand
{
public:
	~Creator();
	Creator	&operator=(Creator const &rhs);
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
private:
	Creator();
	Creator(Creator const &src);
	IOperand const	*createInt8(std::string const &value) const;
	IOperand const	*createInt16(std::string const &value) const;
	IOperand const	*createInt32(std::string const &value) const;
	IOperand const	*createFloat(std::string const &value) const;
	IOperand const	*createDouble(std::string const &value) const;
};

#endif //OPERATORMEMB_H
