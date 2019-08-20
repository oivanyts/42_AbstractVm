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
	void prQue();
	std::queue<Command *> & getComands();

private:
	std::queue<Command *> comands;

};


#endif //ABSTRACTVM_PARSER_H
