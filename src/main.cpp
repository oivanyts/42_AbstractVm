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

void runHelp()
{
	std::cout << "run\n./abstractVM test.file\n"
			  "Use following grammar:\n"
			  	"\tS := INSTR [SEP INSTR]* #\n"
				 "INSTR :=\n"
				 "\tpush VALUE\n"
				 "|\tpop\n| \tdump\n"
				 "|\tassert VALUE\n"
				 "| \tadd\n"
				 "| \tsub\n"
				 "| \tmul\n"
				 "| \tdiv\n"
				 "| \tmod\n"
				 "| \tprint\n"
				 "| \texit\n"
				 "VALUE :=\n"
				 "\tint8(N)\n"
				 "| \tint16(N)\n"
				 "| \tint32(N)\n"
				 "| \tfloat(Z)\n"
				 "| \tdouble(Z)\n"
				 "N := [-]?[0..9]+\n"
				 "Z := [-]?[0..9]+.[0..9]+\n"
				 "SEP := '\\n'+" << std::endl;
}
int main(int ac, char *av[]) {
	if (ac == 2 && (std::string(av[1]) == "-help"))
	{
		runHelp();
		return (0);
	}
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
		Lexer 		lex(buffer, sorcefile);
		Parser      parse(lex.getTokQue());
		Machine     execution(parse.getComands());
	}
	catch (ErrorMng &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
		return (2);
	}
	return 0;
}
