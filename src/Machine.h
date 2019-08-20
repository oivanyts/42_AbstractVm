//
// Created by Oleh IVANYTSKYI on 2019-08-20.
//

#ifndef ABSTRACTVM_MACHINE_H
#define ABSTRACTVM_MACHINE_H


#include <string>
#include <main.h>
#include <IOperand.h>
#include <deque>
#include <queue>
#include <Creator.h>
#include <Command.h>

class Machine
{

public:
	Machine();
	Machine(std::queue<Command *> &com);

	~Machine();

	Machine(Machine const &src);

	Machine &operator=(Machine const &rhs);

	Machine func(int num, eOperandType type, std::string const &value);
private:
	std::deque<IOperand *> VM;
	Creator	factory;

	void initPair();
	void 	fPush(eOperandType type, std::string const &value);
	void 	fAssert(eOperandType type, std::string const &value);
	void 	fPop(eOperandType type, std::string const &value);
	void 	fDump(eOperandType type, std::string const &value);
	void 	fAdd(eOperandType type, std::string const &value);
	void	fSub(eOperandType type, std::string const &value);
	void	fMul(eOperandType type, std::string const &value);
	void	fDiv(eOperandType type, std::string const &value);
	void	fMod(eOperandType type, std::string const &value);
	void	fPrint(eOperandType type, std::string const &value);
	void	fExit(eOperandType type, std::string const &value);
};


#endif //ABSTRACTVM_MACHINE_H
