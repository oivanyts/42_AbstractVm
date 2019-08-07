//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include "Parser.h"

Parser::Parser()
{

}

Parser::~Parser()
{

}

Parser::Parser(Parser const &src)
{
	*this = src;
}

Parser &Parser::operator=(Parser const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}