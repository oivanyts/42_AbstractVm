//
// Created by Oleh IVANYTSKYI on 2019-08-06.
//

#ifndef ABSTRACTVM_LEXER_H
#define ABSTRACTVM_LEXER_H


#include <iostream>
#include <sstream>
//#include ""

enum eType{
	COMMENT = 1,
	SEMICOL,
	INST,
	OPENBR,
	CLOSEBR,
	NUMBER,
	FLOAT,
	ENDL,
	SPACE,
	ERROR = 0
};

int stateTable[10][10] = {
	{ ERROR,	SEMICOL,	COMMENT, INST,	OPENBR,	CLOSEBR,	NUMBER,	FLOAT,	ENDL,	SPACE},
	{ SEMICOL,	ENDL},
	{ COMMENT,		COMMENT,COMMENT,COMMENT,	COMMENT,COMMENT,ENDL,	COMMENT},
	{ INST,			INST,	0,		0, 			0,		0, 		ENDL,	SPACE},
	{ OPENBR,		0,		0,		0,			NUMBER,	0, 		0, 		SPACE},
	{ CLOSEBR,		0, 		0,		0,			0,		0,		ENDL,	SPACE},
	{ NUMBER,		0,		0,		0,			NUMBER,	FLOAT,	0,		SPACE},
	{ FLOAT, 		0, 		0,		CLOSEBR,	NUMBER,	0,		0,		SPACE},
	{ ENDL, 		INST,	0,		0,			0,		0,		ENDL,	SPACE},
	{ SPACE,		INST,	OPENBR,	CLOSEBR,	NUMBER,	FLOAT,	ENDL,	SPACE}
};

class Lexer
{

public:
	Lexer();
	~Lexer();
	Lexer(Lexer const &src);
	Lexer(std::stringstream const &sorce);
	Lexer &operator=(Lexer const &rhs);

private:
	std::stringstream const _raw;
};


#endif //ABSTRACTVM_LEXER_H
