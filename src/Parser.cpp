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
				delete(tmpTok);
			}
			if (!a.empty())
			{
				a.pop();
			}
		}
		catch (ErrorMng &e)
		{
			std::cout << e.what() << std::endl;
			errFound = true;
			skipTokens(&a);
		}
	}
	if (errFound)
		throw SyntaxErr();
}

std::queue<Command *> & Parser::getComands()
{
	return comands;
}

void Parser::skipTokens(std::queue<Token *> *queue)
{
	std::cout << ">> " << queue->front()->getValue() ;
	while (!queue->empty() && queue->front()->getType() != ENDL)
	{
//		Token	*tmp = queue->front() ;
		queue->pop();
//		delete(tmp);
	}
	std::cout << std::endl;
}
