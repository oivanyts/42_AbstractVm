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
	outLine = "Syntax error: " + src;
}

const char *NoExitFound::what() const noexcept
{
	return "Exit not foud";
}

RuntimeErr::RuntimeErr(std::string const &src)
{
	outLine += "Runtime error:" + src;
}
const char *RuntimeErr::what() const noexcept
{
	return outLine.c_str();
}

LexErr::LexErr(std::string const &src)
{
	outLine = "Lexical error:" + src;
}