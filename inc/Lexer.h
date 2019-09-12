//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <sstream>
#include <queue>
#include "Token.h"
#include "ErrorMng.h"

class Lexer
{

public:
	Lexer() = default;
	~Lexer();
	Lexer(Lexer const &src);
	Lexer(std::stringstream &sorce);
	Lexer &operator=(Lexer const &rhs);
	const std::queue<Token *> &getTokQue() const;

private:
	void runFile();
	const std::string 			_raw;
	std::queue<Token *>			_tokQue;
	static eType stateTable[10][10];

	eType findType(const char &i) const;
};


#endif //ABSTRACTVM_LEXER_H
