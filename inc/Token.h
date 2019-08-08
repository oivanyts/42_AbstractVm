//
// Created by Oleh IVANYTSKYI on 2019-08-08.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "main.h"

enum eType{
	COMMENT = 1,
	INST,
	OPENBR,
	CLOSEBR,
	NUMBER,
	DOT,
	ENDL,
	SPACE,
	ERROR = 0
};



class Token
{
public:
	Token();
	Token(eType const type, int size, int place, std::string const &str);
	~Token();
	Token(Token const &src);

	Token &operator=(Token const &rhs);

	const eType getType() const;
	void printTok() const;
	const int getSize() const;
	static eType stateTable[9][9];

	const int getPlace() const;

private:
	static std::string tokType[9];
	eType const _type;
	std::string	const	_value;
	int const 	_size;
	int const 	_place;


};


#endif //ABSTRACTVM_TOKEN_H
