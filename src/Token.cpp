//
// Created by Oleh IVANYTSKYI on 2019-08-08.
//

#include <Token.h>
#include <iostream>

#include "Token.h"

eType Token::stateTable[9][9] = {
		{ ERROR,	COMMENT,	INST,	OPENBR,	CLOSEBR,	NUMBER,	DOT,	ENDL,	SPACE},
		{ COMMENT,	COMMENT,	COMMENT,COMMENT,COMMENT,	COMMENT,COMMENT,ENDL,	COMMENT},
		{ INST,		COMMENT,	INST,	ERROR, 	ERROR,		ERROR, 	ERROR,	ENDL,	SPACE},
		{ OPENBR,	COMMENT,	ERROR,	ERROR,	ERROR,		NUMBER,	ERROR, 	ERROR,	SPACE},
		{ CLOSEBR,	COMMENT,	ERROR,	ERROR,	ERROR,		ERROR,	ERROR,	ENDL,	SPACE},
		{ NUMBER,	COMMENT,	ERROR,	ERROR,	CLOSEBR,	NUMBER,	DOT,	ERROR,	SPACE},
		{ DOT, 		ERROR,		ERROR,	ERROR,	ERROR,		NUMBER,	ERROR,	ERROR,	SPACE},
		{ ENDL, 	COMMENT,	INST,	ERROR,	ERROR,		ERROR,	ERROR,	ENDL,	SPACE},
		{ SPACE,	COMMENT,	INST,	OPENBR,	CLOSEBR,	NUMBER,	DOT,	ENDL,	SPACE}
};

std::string Token::tokType[9] = {
		"ERROR",
		"COMMENT",
		"INST",
		"OPENBR",
		"CLOSEBR",
		"NUMBER",
		"DOT",
		"ENDL",
		"SPACE"
};

Token::Token() : _type(SPACE), _value(" "), _size(1), _place(0)
{ }

Token::~Token()
{ }

Token::Token(Token const &src) : _type(src.getType()), _size(src.getSize()), _place(src.getPlace())
{
	*this = src;
}

Token &Token::operator=(Token const &rhs)
{
	if (&rhs != this)
	{

	}
	return *this;
}

const eType Token::getType() const
{
	return _type;
}

const int Token::getSize() const
{
	return _size;
}

Token::Token(eType const type, int size, int place, std::string const &str)
		: _type(type), _value(str), _size(size), _place(place)
{}

void Token::printTok() const
{
	std::cout << "[" << Token::tokType[_type]  << "]" << _value << std::endl;
}

const int Token::getPlace() const
{
	return _place;
}
