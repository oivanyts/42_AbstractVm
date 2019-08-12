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

Lexer::Lexer(Lexer const &src) : _raw(src.getRaw())
{
	*this = src;
}

Lexer &Lexer::operator=(Lexer const &rhs)
{
	if (&rhs != this)
	{
	}
	return *this;
}

Lexer::Lexer(std::stringstream &sorce) : _raw(sorce)
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
	a  = _raw.get();
	_tokQue.push(new Token(type, _location - _startTok, _location, a));
}

void Lexer::runFile()
{
	eType	old = SPACE, curr;
	std::string	tmp;
	_location = 0;
	std::cout << _raw.str();
	for (auto wrapIter = &(_raw.str())[0]; *wrapIter != '\0'; ++wrapIter)
	{
		std::cout << *wrapIter << std::endl;
		curr = findType(*wrapIter);
		tmp += *wrapIter;
		if (curr != old)
		{
			saveToken(Token::stateTable[old][curr]);
			old = Token::stateTable[old][curr];
			_startTok = _location;
			tmp = "";
		}
		else
		{
			_tokQue.front()
		}

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
		return DOT;
	else if (std::isalpha(i))
		return INST;
	else if (std::isdigit(i))
		return NUMBER;
	else if (std::isspace(i))
		return SPACE;
	return ERROR;
}

void Lexer::printAllTok()
{
	while (!_tokQue.empty())
	{
		_tokQue.front()->printTok();
		_tokQue.pop();
	}
}

std::stringstream & Lexer::getRaw() const
{
	return _raw;
}
