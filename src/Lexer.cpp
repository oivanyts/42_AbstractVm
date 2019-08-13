//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include "Lexer.h"

//Lexer::Lexer() : _raw()
//{
//
//}

Lexer::~Lexer()
{
	//delete tokens;
}

//Lexer::Lexer(Lexer const &src) : _raw(src.getRaw())
//{
//	*this = src;
//}

Lexer &Lexer::operator=(Lexer const &rhs)
{
	if (&rhs != this)
	{
	}
	return *this;
}

Lexer::Lexer(std::stringstream &sorce) : _raw(sorce.str())
{
	runFile();
}

void Lexer::saveToken(eType type)
{
	std::string a;
//	if (type == INST || type == NUMBER)
//	{
//		_raw >> a;
//	}
//	else
//		a  = _raw.get();
	_tokQue.push(new Token(type, _location - _startTok, _location, a));
}

void Lexer::runFile()
{
	eType	old = REJECT, curr, col;
	std::string	currTok = "";
	char 		cuurChar = 0;
	_location = 0;
//	std::cout << ;
	for (auto wrapIter = &(_raw)[0]; *wrapIter != '\0'; ++wrapIter)
	{
		std::cout << *wrapIter << std::endl;
		col = findType(*wrapIter);
		curr = Token::stateTable[old][col];
		if (curr == REJECT)
		{
			if (old != SPACE)
				_tokQue.push(new Token(currTok, _location, col));
				currTok = *wrapIter;
				_startTok = _location;
//			currTok = "";
		}
		else
		{
			currTok += *wrapIter;
		}
		old = col;
		_location++;
	}
	printAllTok();
}

eType Lexer::findType(char &i)
{
	if (i == '\n')
		return ENDL;
	else if (i == ';')
		return COMMENT;
	else if (i == '(')
		return OPENBR;
	else if (i == ')')
		return CLOSEBR;
	else if (i == '.')
		return FLOAT;
	else if (std::isalpha(i))
		return INST;
	else if (std::isdigit(i))
		return NUMBER;
	else if (std::isspace(i))
		return SPACE;
	return REJECT;
}

void Lexer::printAllTok()
{
	while (!_tokQue.empty())
	{
		_tokQue.front()->printTok();
		_tokQue.pop();
	}
}

//std::stringstream & Lexer::getRaw() const
//{
//	return _raw;
//}
