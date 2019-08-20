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
	factory.createOperand(type, value);
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
	IOperand *first = VM.front();
	VM.pop_back();

//	VM.back() =
}

void Machine::fSub(eOperandType , std::string const &)
{

}

void Machine::fMul(eOperandType , std::string const &)
{

}

void Machine::fDiv(eOperandType, std::string const &)
{

}

void Machine::fMod(eOperandType, std::string const &)
{

	IOperand const *first = VM.back();

}

void Machine::fPrint(eOperandType, std::string const &)
{
	for (auto dequeIterator = VM.begin(); dequeIterator != VM.end(); ++dequeIterator)
	{
		std::cout << (*dequeIterator)->toString();
	}
}

void Machine::fExit(eOperandType, std::string const &)
{

}

void Machine::initPair()
{

}

Machine Machine::func(int num, eOperandType type, std::string const &value)
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

Machine::Machine(std::queue<Command *> &com)
{
	while (!com.empty() || com.front()->getInts() == 10)
	{
		func(com.front()->getInts(), static_cast<eOperandType>(com.front()->getValue()), com.front()->getNum());
		com.pop();
	}
}
