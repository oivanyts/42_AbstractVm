//
// Created by Oleh IVANYTSKYI on 2019-08-16.
//

#include <ErrorMng.h>
#include "Command.h"



Command::Command() : ints(-1), status(statCom::ERROR)
{ }

Command::~Command()
{ }

Command::Command(Command const &src)
{
	*this = src;
}

Command &Command::operator=(Command const &rhs)
{
	if (&rhs != this)
	{
		this->status = rhs.status;
		this->ints = rhs.ints;
		this->num = rhs.num;
		this->value = rhs.value;
	}
	return *this;
}

void Command::setNum(const std::string &number)
{
	if (this->ints < 2 && status == statCom::NUM)
	{
		if ((value < 3 && curr->getType() == FLOAT) || (value >= 3 && curr->getType() == NUMBER))
		{
			std::string ret("BAD NUMBER TYPE at "  + curr->getLocation());
			throw SyntaxErr(ret);
		}
		status = statCom::BR;
		this->num = number;
	}
	else if (status != statCom::NUM)
	{
		std::string ret("TOKEN BAD at "  + curr->getLocation());
		throw SyntaxErr(ret);
	}
	else
	{
		throw LexErr("");
	}
}

void Command::setValue(int val)
{
	if (status == statCom::VALUE && this->ints < 2)
	{
		status = statCom::BROP;
		this->value = val;
	}
	else
	{
		throw SyntaxErr("bad place for value");
	}
}

void Command::setStatusBr(bool open)
{
	if (open && status == statCom::BROP && this->ints < 2)
		status = statCom::NUM;
	else if (!open && status == statCom::BR && this->ints < 2)
		status = statCom::ENDLINE;
	else
	{
		throw SyntaxErr(open ? "open bracket expected" : "closed bracket expected");
	}
}

void Command::setInts(int instance)
{
	if (status == statCom::ERROR)
	{
		this->ints = instance;
		status = (ints) < 2 ? statCom::VALUE : statCom::ENDLINE;
	}
	else
	{
		throw SyntaxErr("bad place for instance");
	}
}

void Command::setFunc(Token tok)
{
	curr = &tok;
	tok.printTok();
	switch (tok.getType())
	{
		case INST :
		{
			setInts(tok.getNumInst());
			break ;
		}
		case VALUE :
		{
			setValue(tok.getNumInst());
			break;
		}
		case OPENBR:
		{
			setStatusBr(true);
			break ;
		}
		case CLOSEBR:
		{
			setStatusBr(false);
			break ;
		}
		case NUMBER :
		{
			setNum(tok.getValue());
			break ;
		}
		case FLOAT :
		{
			setNum(tok.getValue());
			break ;
		}
		case ENDL :
		{
			break ;
		}
		case COMNT:
		{
			break ;
		}
		default :
		{
			throw LexErr(" Unknown token at " + curr->getLocation());
		}
	}
}

int Command::getInts() const
{
	return ints;
}

int Command::getValue() const
{
	return value;
}

const std::string &Command::getNum() const
{
	return num;
}

statCom Command::getStatus() const
{
	return status;
}
