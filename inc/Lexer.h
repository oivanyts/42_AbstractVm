//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#ifndef LEXER_H
#define LEXER_H


#include <iostream>
#include <sstream>
#include <queue>
#include "Token.h"

class Lexer
{

public:
	Lexer() = default;
	~Lexer();
	Lexer(Lexer const &src);
	Lexer(std::stringstream &sorce);
	Lexer &operator=(Lexer const &rhs);

//	std::stringstream & getRaw() const;

private:
	void runFile();
	void saveToken(eType type);
	std::string 			_raw;

private:
	std::queue<Token *>			_tokQue;
	int 						_location;
	int 						_startTok;

	eType findType(char &i);

	void printAllTok();
};


#endif //ABSTRACTVM_LEXER_H
