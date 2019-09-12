//
// Created by Oleh IVANYTSKYI on 2019-09-11.
//

#include "ErrorMng.h"

ErrorMng::ErrorMng() noexcept
{
	outLine = "ERROR OCCURRED ";
}

const char *SyntaxErr::what() const noexcept
{
	return outLine.c_str();
}

SyntaxErr::SyntaxErr(std::string const &src)
{
	outLine += src;
}

const char *NoExitFound::what() const noexcept
{
	return "Exit not foud";
}
