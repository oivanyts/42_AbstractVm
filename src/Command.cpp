//
// Created by Oleh IVANYTSKYI on 2019-08-16.
//

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
		status = statCom::BR;
		this->num = number;
	}
	else
	{
		status = statCom::BR;
		throw std::invalid_argument("bad number");
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
		status = statCom::BROP;
		throw std::invalid_argument("bad value");
	}
}

void Command::setStatusBr(bool open)
{
	if (open && status == statCom::BROP && this->ints < 2)
		status = statCom::NUM;
	else if (!open && status == statCom::BR && this->ints < 2)
		status = statCom::ENDLINE;
	else
		throw std::invalid_argument("BRACKET PROBLEM");
}

void Command::setInts(int instance)
{
	if (status == statCom::ERROR)
	{
		this->ints = instance;
		status = (ints) < 2 ? statCom::VALUE : statCom::ENDLINE;
	}
	else
		throw std::invalid_argument("Bad instance");
}

void Command::setFunc(Token tok)
{
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
			throw std::invalid_argument("Token fail");

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
