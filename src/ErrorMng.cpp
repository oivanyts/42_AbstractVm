//
// Created by Oleh IVANYTSKYI on 2019-09-11.
//

#include "ErrorMng.h"

ErrorMng::ErrorMng() noexcept
{
	outLine = "ERROR";
}
const char *ErrorMng::what() const noexcept
{
	return outLine.c_str();
}

const char *SyntaxErr::what() const noexcept
{
	return outLine.c_str();
}

SyntaxErr::SyntaxErr(std::string const &src)
{
	outLine = "SYNTAX " + src;
}

const char *NoExitFound::what() const noexcept
{
	return "Exit not foud";
}

RuntimeErr::RuntimeErr(std::string const &src)
{
	outLine += " [RUNTIME]: " + src;
}
const char *RuntimeErr::what() const noexcept
{
	return outLine.c_str();
}
