//
// Created by Oleh IVANYTSKYI on 2019-08-16.
//

#include "Command.h"

Command::Command()
{

}

Command::~Command()
{

}

Command::Command(Command const &src)
{
	*this = src;
}

Command &Command::operator=(Command const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}