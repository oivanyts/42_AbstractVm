//
// Created by Oleh IVANYTSKYI on 2019-08-20.
//

#include <ErrorMng.h>
#include <sstream>
#include <iomanip>
#include "Machine.h"

Machine::Machine()
{
}

Machine::~Machine()
{
	for (auto dequeIterator = VM.begin(); dequeIterator != VM.end(); ++dequeIterator)
	{
		delete(*dequeIterator);
	}
}

Machine::Machine(Machine const &src)
{
	*this = src;
}

Machine &Machine::operator=(Machine const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}

void Machine::fPush(eOperandType type, std::string const &value)
{
	VM.push_back(factory.createOperand(type, value));
}

void Machine::fAssert(eOperandType type, std::string const &value)
{
	if (VM.empty())
		throw RuntimeErr(" assert on empty stack");
	IOperand const *first = factory.createOperand(type, value);
	if (*(VM.back()) != *(first))
	{
		delete(first);
		throw RuntimeErr(" Assert fails '" + VM.back()->toString() + "'");
	}
	delete(first);
}

void Machine::fPop(eOperandType , std::string const &)
{
	if (VM.empty())
		throw RuntimeErr(" pop on empty stack");
	IOperand const *first = VM.back();
	VM.pop_back();
	delete(first);
}

void Machine::fDump(eOperandType, std::string const &)
{
	if (VM.empty())
		std::cout << " dumped empty stack" << std::endl;
	for (auto iter = VM.rbegin(); iter != VM.rend(); ++iter)
	{
		std::cout << std::fixed << (*iter)->toString() << std::endl;
	}
}

void Machine::fAdd(eOperandType , std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *second = VM.back();
		VM.pop_back();
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(*first + *second);
		delete(first);
		delete(second);
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::fSub(eOperandType , std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *second = VM.back();
		VM.pop_back();
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(*first - *second);
		delete(first);
		delete(second);
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::fMul(eOperandType , std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *second = VM.back();
		VM.pop_back();
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(*first * *second);
		delete(first);
		delete(second);
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::fDiv(eOperandType, std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *second = VM.back();
		VM.pop_back();
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(*first / *second);
		delete(first);
		delete(second);
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::fMod(eOperandType, std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *second = VM.back();
		VM.pop_back();
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(*first % *second);
		delete(first);
		delete(second);
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::fPrint(eOperandType, std::string const &)
{
	if (VM.size() < 1)
	{
		throw RuntimeErr(" too few arguments");
	}
	if (VM.back()->getType() == eInt8)
	{
		std::cout << static_cast<int8_t>(std::stoi((VM.back()->toString())))
		<< std::endl;
	}
	else
		throw RuntimeErr("trying to print non printable type");
}

void Machine::fExit(eOperandType, std::string const &)
{
	exitFound = true;
}

void Machine::func(int num, eOperandType type, std::string const &value)
{
	typedef void (Machine::*ftab)(eOperandType type, std::string const &value);
	ftab tmp[] = {
			&Machine::fPush,
			&Machine::fAssert,
			&Machine::fPop,
			&Machine::fDump,
			&Machine::fAdd,
			&Machine::fSub,
			&Machine::fMul,
			&Machine::fDiv,
			&Machine::fMod,
			&Machine::fPrint,
			&Machine::fPow,
			&Machine::fSqrt,
			&Machine::fExit};

	(this->*(tmp[num]))(type, value);
}

Machine::Machine(std::queue<Command *> &com) : exitFound(false)
{
	try
	{
		while (!com.empty() && !exitFound)
		{
			Command *tmp = com.front();
			func(com.front()->getInts(),
					static_cast<eOperandType>(com.front()->getValue()),
					com.front()->getNum());
			com.pop();
			delete(tmp);
		}
		if (!exitFound)
		{
			clearIt();
			throw NoExitFound();
		}
	}
	catch (ErrorMng &e)
	{
		clearIt();
		throw ;
	}
}

void Machine::fSqrt(eOperandType , std::string const &)
{
	if (!VM.empty())
	{
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(first->fsqrt());
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::fPow(eOperandType , std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *second = VM.back();
		VM.pop_back();
		IOperand const *first = VM.back();
		VM.pop_back();
		VM.push_back(first->fpow(*second));
	}
	else
	{
		throw RuntimeErr(" too few arguments");
	}
}

void Machine::clearIt()
{
	for (auto dequeIterator = VM.begin(); dequeIterator != VM.end(); ++dequeIterator)
	{
		delete(*dequeIterator);
	}
}
