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

	try
	{
		bool sorcefile = false;
		std::stringstream buffer;
		if (ac > 1)
		{
			sorcefile = true;
			std::string	filename(av[1]);
			std::ifstream fileopened(filename);
			if (fileopened)
				buffer << fileopened.rdbuf();
			else
				throw FileErr();
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

		Lexer lex(buffer, sorcefile);
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
