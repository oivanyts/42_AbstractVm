//
// Created by Oleh IVANYTSKYI on 2019-08-16.
//

#ifndef ABSTRACTVM_COMMAND_H
#define ABSTRACTVM_COMMAND_H


#include <string>
#include "Token.h"

enum class statCom{
	ERROR = 0,
	COMMAND,
	VALUE,
	BROP,
	NUM,
	BR,
	ENDLINE
};

class Command
{

public:
	Command();
	~Command();

	Command(Command const &src);

	Command &operator=(Command const &rhs);

	void setFunc(Token tok);
	void setStatusBr(bool open);
	void setValue(int val);
	void setNum(const std::string &number);
	void setInts(int instance);

	int getInts() const;

	int getValue() const;

	const std::string &getNum() const;

	statCom getStatus() const;

private:
	Token			*curr;
	int				ints;
	int 			value;
	std::string 	num;
	statCom			status;

};


#endif //ABSTRACTVM_COMMAND_H
