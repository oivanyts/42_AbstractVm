//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include <iostream>
#include <ErrorMng.h>
#include "Parser.h"

eType commandLine[] = {VALUE, OPENBR, NUMBER, CLOSEBR, ENDL};

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
	{
		
	}
	return *this;
}

Parser::Parser(std::queue<Token *> a) : errFound(false)
{
	Token *tmpTok;
	while (!a.empty())
	{
		try
		{
			if (a.front()->getType() != ENDL)
				comands.push(new Command);
			while (!a.empty() && a.front()->getType() != ENDL)
			{
				tmpTok = a.front();
				comands.back()->setFunc(*tmpTok);
				a.pop();
			}
			if (!a.empty())
				a.pop();
		}
		catch (SyntaxErr &e)
		{
			std::cout << e.what() << std::endl;
			errFound = true;
			if (!a.empty())
				a.pop();
		}
	}
}

void Parser::prQue()
{
	while (!comands.empty())
	{
		std::cout << comands.front()->getInts() << " inst " <<
		comands.front()->getValue() << " value " <<
		comands.front()->getNum() << " num\n";
		comands.pop();
	}
}

std::queue<Command *> & Parser::getComands()
{
	return comands;
}