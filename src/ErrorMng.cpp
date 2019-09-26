//
// Created by Oleh IVANYTSKYI on 2019-09-11.
//

#include "ErrorMng.h"

ErrorMng::ErrorMng() noexcept
{
	
}
const char *ErrorMng::what() const noexcept
{
	return outLine.c_str();
}

SyntaxErr::SyntaxErr(std::string const &src)
{
	outLine = "\033[1;31m Syntax error: \033[0m" + src;
}

const char *NoExitFound::what() const noexcept
{
	return "\033[1;31m Runtime error: \033[0m Exit not foud";
}

RuntimeErr::RuntimeErr(std::string const &src)
{
	outLine += "\033[1;31m Runtime error: \033[0m" + src;
}

LexErr::LexErr(std::string const &src)
{
	outLine = "\033[1;31m Lexical error: \033[0m" + src;
}

const char *GotExit::what() const noexcept
{
	return "";
}
