#include <iostream>
#include <deque>
#include <sstream>
#include <queue>
#include <Creator.h>
#include <Lexer.h>
#include <Parser.h>
#include "IOperand.h"
#include "main.h"
#include "Machine.h"


int main(int ac, char *av[]) {
	std::stringstream test;
//	test << " push int32(33)\n push float(2.2)\nadd\n\n";
	test << av[1];
	Lexer	lex(test);
	Parser	parse(lex.getTokQue());
	Machine	main(parse.getComands());
	return 0;
}