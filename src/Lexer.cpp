//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include "Lexer.h"

eType Lexer::stateTable[10][10] = {
			{ REJECT,	INST,	OPENBR,	CLOSEBR,	NUMBER,	FLOAT,	REJECT,	REJECT,	COMNT,	SIGN},
/*INST*/	{ REJECT,	INST,	REJECT, REJECT, 	INST,	REJECT,	REJECT,	REJECT, REJECT, REJECT},
/*OPENBR*/	{ REJECT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	REJECT, REJECT, REJECT},
/*CLOSEBR*/	{ REJECT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	REJECT, REJECT, REJECT},
/*NUMBER*/	{ REJECT,	REJECT,	REJECT,	REJECT,		NUMBER,	FLOAT,	REJECT,	REJECT, REJECT, REJECT},
/*FLOAT*/	{ REJECT, 	REJECT,	REJECT,	REJECT,		FLOAT,	REJECT,	REJECT,	REJECT, REJECT, REJECT},
/*ENDL*/	{ REJECT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT, ENDL,	REJECT, REJECT,	REJECT},
/*SPACE*/	{ REJECT,	REJECT,	REJECT,	REJECT,		REJECT,	REJECT,	REJECT,	SPACE,	REJECT, REJECT},
/*COMNT*/	{ REJECT,	COMNT,	COMNT,	COMNT,		COMNT,	COMNT,	REJECT,	COMNT,	COMNT,	COMNT},
/*SIGN*/	{ REJECT,	REJECT,	REJECT,	REJECT,		NUMBER,	REJECT,	REJECT,	REJECT, REJECT, REJECT},
};

Lexer::~Lexer()
{ }

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

Lexer::Lexer(std::stringstream &sorce) : _raw(sorce.str()), _errors(0)
{
	runFile();
}

void Lexer::runFile()
{
	eType			old = REJECT, curr, col;
	std::string		currTok;
	int 			_location = 0;

	for (auto wrapIter = &(_raw)[0]; *wrapIter != '\0'; wrapIter++)
	{
		try
		{
			if (!(col = findType(*wrapIter)))
			{
				_errors++;
				currTok = *wrapIter;
				throw LexErr(" Bad token '" + currTok +"' at " + _tokQue.back()->getLocation());
			}
			curr = stateTable[old][col];
			if (curr == REJECT || col == REJECT)
			{
				if (old != SPACE && old != COMNT)
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
			if (currTok == ";;")
			{
				if (_errors)
					throw LexErr();
				return ;
			}
		}
		catch (LexErr &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	_tokQue.push(new Token(currTok, _location, old));
	_tokQue.push(new Token("\n", ++_location, ENDL));
	if (_errors)
		throw LexErr();
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
	else if (i == '-' || i == '+')
		return SIGN;
	else if (std::isdigit(i))
		return NUMBER;
	else if (std::isspace(i))
		return SPACE;
	else
		return REJECT;
}

const std::queue<Token *> &Lexer::getTokQue() const
{
	return _tokQue;
}
