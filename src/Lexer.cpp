//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include "Lexer.h"

eType Lexer::stateTable[9][9] = {
		{ REJECT,	INST,	OPENBR,	CLOSEBR,	NUMBER,	FLOAT,	ENDL,	SPACE, COMNT},
		{ INST,		INST,	REJECT, REJECT, 	INST,	REJECT,	REJECT,	REJECT, REJECT},
		{ OPENBR,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	REJECT, REJECT },
		{ CLOSEBR,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	REJECT, REJECT},
		{ NUMBER,	REJECT,	REJECT,	REJECT,		NUMBER,	FLOAT,	REJECT,	REJECT, REJECT },
		{ FLOAT, 	REJECT,	REJECT,	REJECT,		FLOAT,	REJECT,	REJECT,	REJECT, REJECT },
		{ ENDL,		REJECT,	REJECT,	REJECT,		REJECT,	REJECT, ENDL,	REJECT, REJECT },
		{ SPACE,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	SPACE, REJECT },
		{ COMNT,	COMNT,	COMNT,	COMNT,	COMNT,		COMNT,	COMNT,	REJECT,	COMNT}
};

//Lexer::Lexer() : _raw()
//{
//
//}

Lexer::~Lexer()
{
	//delete tokens;
}

Lexer::Lexer(Lexer const &src) : _raw(src._raw)
{
	*this = src;
}

Lexer &Lexer::operator=(Lexer const &rhs)
{
	if (&rhs != this)
	{
		std::copy(rhs._tokQue.front(), rhs._tokQue.back(), _tokQue.front());
	}
	return *this;
}

Lexer::Lexer(std::stringstream &sorce) : _raw(sorce.str())
{
	runFile();
}

void Lexer::runFile()
{
	eType			old = REJECT, curr, col;
	std::string		currTok;
	int 			_location = 0;

	std::cout << _raw;
	for (auto wrapIter = &(_raw)[0]; *wrapIter != '\0'; wrapIter++)
	{
		col = findType(*wrapIter);
		curr = stateTable[old][col];
		if (curr == REJECT)
		{
			if (old != SPACE)
			{
				_tokQue.push(new Token(currTok, _location, old));
			}
			currTok = *wrapIter;
			if (old == ENDL)
			{
				_location = 0;
			}
			_location++;
			old = col;
			continue ;
		}
		else
		{
			currTok += *wrapIter;
			old = curr;
			_location++;
		}
	}
	printAllTok();
}

eType Lexer::findType(const char &i) const
{
	if (i == '\n')
		return ENDL;
	else if (i == ';')
		return COMNT;
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

const std::queue<Token *> &Lexer::getTokQue() const
{
	return _tokQue;
}
