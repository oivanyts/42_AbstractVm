#include <utility>
#include <vector>
//
// Created by Oleh IVANYTSKYI on 2019-08-08.
//

#include <Token.h>
#include <iostream>

#include "Token.h"

int Token::endl_counter = 0;



 std::string Token::tokType[12] = {
		"REJECT", "INST", "OPENBR", "CLOSEBR", "INT", "FLOAT", "ENDL",
		"SPACE","COMNT", "SIGN", "BAD", "VALUE"
};

std::vector<std::string> commandTok = {
		"push", "assert", "pop", "dump", "add", "sub", "mul",
		"div", "mod", "print","pow","sqrt", "exit", "bad instance"};

std::vector<std::string> valueTok = {
		"int8", "int16", "int32", "float", "double"
};

Token::Token() : _type(SPACE), _value(" "), col(0), row(0)
{ }


Token::Token(Token const &src) : _type(src._type), _value(src._value), col(src.col), row(src.row), _numInst(src._numInst)
{
	*this = src;
}

Token &Token::operator=(Token const &rhs)
{
	if (&rhs != this)
	{
		_numInst = rhs._numInst;
	}
	return *this;
}

void Token::printTok() const
{
	std::cout << "[\033[1;31m" << Token::tokType[_type]  << "\033[0m]\t\t= {" << _value << "} > " <<
	row << ":" << col << std::endl;
}

Token::Token(std::string str, int place, eType curr) : _type(curr), _value(str),  col(place - str.size() + 1), row(Token::endl_counter + 1)
{
	deal_instance();
	if (_type == ENDL)
	{
		Token::endl_counter++;
	}
}

void Token::deal_instance()
{
	if (_type == INST)
	{
		auto found = std::find(valueTok.begin(), valueTok.end(), _value);
		if (found != valueTok.end())
		{
			_numInst = found - valueTok.begin();
			_type = VALUE;
			return ;
		}
		auto found2 = std::find(commandTok.begin(), commandTok.end(), _value);
		if (found2 == commandTok.end())
			_type = BADINST;
		else
			_numInst = found2 - commandTok.begin();
	}
}

eType Token::getType() const
{
	return _type;
}

const std::string &Token::getValue() const
{
	return _value;
}

int Token::getNumInst() const
{
	return _numInst;
}

const std::string Token::getLocation()
{
	return "[" + std::to_string(row) + ":" + std::to_string(col) + "]";
}
