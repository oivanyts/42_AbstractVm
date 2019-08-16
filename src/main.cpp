#include <iostream>
#include <deque>
#include <sstream>
#include <queue>
#include <Creator.h>
#include <Lexer.h>
#include <Parser.h>
#include "IOperand.h"
#include "main.h"


int main() {
	std::deque<IOperand const *> a;
	const std::string str = "12345";
	Creator           ad;
	std::cout << a.size() << " size start\n";
	{
		std::stringstream test;
		test << " push int32( 33.33 )\nadd\n assert int8(5)\n";
		Lexer	lex(test);
		Parser	parse(lex.getTokQue());
	}
//	{
//		a.push_back(ad.createOperand(eInt8, "17"));
//		a.push_back(ad.createOperand(eInt16, "1100"));
//		a.push_back(ad.createOperand(eInt32, "223344"));
//		a.push_back(ad.createOperand(eFloat, "334.25"));
//		a.push_back(ad.createOperand(eDouble, "444.54"));
//		std::cout << a.size() << " size finale " << (a.front())->toString() << std::endl;
//		for (auto dequeIterator = a.begin(); dequeIterator != a.end(); ++dequeIterator)
//		{
//			std::cout << (*dequeIterator)->toString() << std::endl;
//		}
//		std::cout << "++++++++++++++++" << std::endl;
//		a.push_back(*(a.front()) % *(a.back()));
//		for (auto dequeIterator = a.begin(); dequeIterator != a.end(); ++dequeIterator)
//		{
//			std::cout << (*dequeIterator)->toString() << std::endl;
//		}
//	}
	return 0;
}