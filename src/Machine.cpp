//
// Created by Oleh IVANYTSKYI on 2019-08-20.
//

#include "Machine.h"

Machine::Machine()
{
}

Machine::~Machine()
{

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

}

void Machine::fPop(eOperandType , std::string const &)
{

}

void Machine::fDump(eOperandType, std::string const &)
{

}

void Machine::fAdd(eOperandType , std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *first = VM.back();
		VM.pop_back();
		IOperand const *second = VM.back();
		VM.pop_back();
		VM.push_front(*first + *second);
	}
	else
	{
		throw std::invalid_argument(" to few arg");
	}
}

void Machine::fSub(eOperandType , std::string const &)
{
	if (VM.size() > 1)
	{
		IOperand const *first = VM.back();
		VM.pop_back();
		IOperand const *second = VM.back();
		VM.pop_back();
		VM.push_front(*first - *second);
	}

}

void Machine::fMul(eOperandType , std::string const &)
{
	IOperand const *first = VM.back();
	VM.pop_back();
	IOperand const *second = VM.back();
	VM.pop_back();
	VM.push_front(*first * *second);
}

void Machine::fDiv(eOperandType, std::string const &)
{
	IOperand const *first = VM.back();
	VM.pop_back();
	IOperand const *second = VM.back();
	VM.pop_back();
	VM.push_front(*first / *second);
}

void Machine::fMod(eOperandType, std::string const &)
{
	IOperand const *first = VM.back();
	VM.pop_back();
	IOperand const *second = VM.back();
	VM.pop_back();
	VM.push_front(*first % *second);
}

void Machine::fPrint(eOperandType, std::string const &)
{
	for (auto dequeIterator = VM.begin(); dequeIterator != VM.end(); ++dequeIterator)
	{
		std::cout << (*dequeIterator)->toString() << std::endl;
	}
}

void Machine::fExit(eOperandType, std::string const &)
{
	exitFound = true;
}

void Machine::func(int num, eOperandType type, std::string const &value)
{
	typedef void (Machine::*funcptr)(eOperandType type, std::string const &value);
	funcptr tmp[] = {
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
			&Machine::fExit
	};
	(this->*(tmp[num]))(type, value);
}

Machine::Machine(std::queue<Command *> &com) : exitFound(false)
{
	try
	{
		while (!com.empty() && !exitFound)
		{
			func(com.front()->getInts(), static_cast<eOperandType>(com.front()->getValue()), com.front()->getNum());
			com.pop();
		}
		if (!exitFound)
		{
			throw std::invalid_argument("EXIT NOT FOUND");
		}
		fPrint(eInt16, "");
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "ERROR OP " << e.what();
	}
}
