//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include "Lexer.h"

Lexer::Lexer()
{

}

Lexer::~Lexer()
{

}

Lexer::Lexer(Lexer const &src)
{
	*this = src;
}

Lexer &Lexer::operator=(Lexer const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}

Lexer::Lexer(std::stringstream const &sorce)
{

}
