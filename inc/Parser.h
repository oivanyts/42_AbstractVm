//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#ifndef ABSTRACTVM_PARSER_H
#define ABSTRACTVM_PARSER_H


#include <queue>
#include "Token.h"
#include "Command.h"
#include "main.h"
class Parser
{

public:
	Parser();
	Parser(std::queue<Token *>);
	~Parser();

	Parser(Parser const &src);

	Parser &operator=(Parser const &rhs);

private:
	std::queue<Command *> comands;

	void dealLong(std::queue<Token *> queue);

	void dealShort(std::queue<Token *> queue);
};


#endif //ABSTRACTVM_PARSER_H
