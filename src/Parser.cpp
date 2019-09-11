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
		catch (std::invalid_argument &e)
		{
			std::cout << "Syntax ERROR: " << e.what() << std::endl;
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

//void Parser::dealLong(std::queue<Token *> queue)
//{
//	if (queue.front()->getType() == VALUE)
//	{
//		std::cout << queue.front()->getValue();
//		queue.pop();
//	}
//	else
//	{
//		throw std::invalid_argument("BAD VALUE TYPE");
//	}
//}

//void Parser::dealShort(std::queue<Token *> queue)
//{
//	if (queue.front()->getType() == ENDL)
//	{
//		queue.pop();
//	}
//	else
//	{
//		throw std::invalid_argument("BAD VALUE TYPE");
//	}
//
//}
