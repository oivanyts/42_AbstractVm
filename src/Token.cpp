#include <utility>

//
// Created by Oleh IVANYTSKYI on 2019-08-08.
//

#include <Token.h>
#include <iostream>

#include "Token.h"

eType Token::stateTable[9][9] = {
		{ REJECT,	COMMENT,	INST,	OPENBR,	CLOSEBR,	NUMBER,	FLOAT,	ENDL,	SPACE},
		{ COMMENT,	COMMENT,	COMMENT,COMMENT,COMMENT,	COMMENT,COMMENT,REJECT,	COMMENT},
		{ INST,		COMMENT,	INST,	REJECT, REJECT, 	INST,	REJECT,	REJECT,	REJECT},
		{ OPENBR,	COMMENT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	REJECT},
		{ CLOSEBR,	COMMENT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	REJECT},
		{ NUMBER,	COMMENT,	REJECT,	REJECT,	REJECT,		NUMBER,	FLOAT,	REJECT,	REJECT},
		{ FLOAT, 	REJECT,		REJECT,	REJECT,	REJECT,		FLOAT,	REJECT,	REJECT,	REJECT},
		{ ENDL, 	COMMENT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT, ENDL,	REJECT},
		{ SPACE,	COMMENT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	SPACE}
};

std::string Token::tokType[9] = {
		"REJECT",
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

Token::Token(eType const type, int size, int place, std::string str)
		: _type(type), _value(std::move(str)), _size(size), _place(place)
{}

void Token::printTok() const
{
	std::cout << "[\033[1;31m" << Token::tokType[_type]  << "\033[0m] = {" << _value << "} > " <<
	_place << std::endl;
}

const int Token::getPlace() const
{
	return _place;
}

Token::Token(std::string str, int place, eType curr) : _type(curr), _value(str), _size(str.size()), _place(place)
{

}
