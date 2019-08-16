//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#include <iostream>
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

Parser::Parser(std::queue<Token *> a)
{
	Token *tmp;
	while (!a.empty())
	{
		try
		{
			int i;
			while (a.front()->getType() == commandLine[i])
			{
				tmp = a.front();
				a.pop();
				if (tmp->getNumInst() < 2)
				{
					dealLong(a);
				}
				else
				{
					dealShort(a);
				}
			}
//			throw std::invalid_argument("BAD COMMAND");
		}
		catch (std::exception&)
		{
			std::cout << "SYNTAX ERROR : " << __LINE__ << std::endl;
			while (a.front()->getType() != ENDL)
				a.pop();
			a.pop();
		}
	}
}

void Parser::dealLong(std::queue<Token *> queue)
{
	if (queue.front()->getType() == VALUE)
	{
		std::cout << queue.front()->getValue();
		queue.pop();
	}
	else
	{
		throw std::invalid_argument("BAD VALUE TYPE");
	}
}

void Parser::dealShort(std::queue<Token *> queue)
{
	if (queue.front()->getType() == ENDL)
	{
		queue.pop();
	}
	else
	{
		throw std::invalid_argument("BAD VALUE TYPE");
	}

}
