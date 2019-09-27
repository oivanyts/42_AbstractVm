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
			tmpTok = a.front();
			if (a.front()->getType() != ENDL)
				comands.push(new Command);
			else
			{
				a.pop();
				delete(tmpTok);
				continue ;
			}
			while (!a.empty())
			{
				tmpTok = a.front();
				comands.back()->setFunc(*tmpTok);
				a.pop();
				delete(tmpTok);
			}
		}
		catch (GoodCommand &)
		{
			skipTokens(&a);
		}
		catch (ErrorMng &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << ">> " << a.front()->getValue() << std::endl;
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
	while (queue->front()->getType() != ENDL)
	{
//		Token	*tmp = queue->front() ;
		queue->pop();
//		delete(tmp);
	}
	queue->pop();
}
