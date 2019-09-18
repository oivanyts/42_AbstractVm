#include <iostream>
#include <deque>
#include <sstream>
#include <queue>
#include <Creator.h>
#include <Lexer.h>
#include <Parser.h>
#include <fstream>
#include "IOperand.h"
#include "main.h"
#include "Machine.h"


int main(int ac, char *av[]) {

	std::stringstream buffer;
	if (ac > 1)
	{
		std::string	filename(av[1]);
		std::ifstream fileopened(filename);
		buffer << fileopened.rdbuf();
	}
	else
	{
		std::string line;
		while (line != ";;" && !std::cin.eof())
		{

			std::getline(std::cin, line, '\n');
			buffer << line << '\n';
		}
	}
	try
	{
		Lexer         lex(buffer);
		Parser        parse(lex.getTokQue());
		Machine       main(parse.getComands());
	}
	catch (ErrorMng &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}

	return 0;
}
