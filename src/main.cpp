#include <iostream>
#include <deque>
#include <sstream>
#include <queue>
#include <Creator.h>
#include <Lexer.h>
#include "IOperand.h"
#include "main.h"


std::string	TokenTypes[] = {
		"bad instance",
		"good instance",
		"brace open",
		"brace close",
		"int",
		"dot",
		"delimiter"
};

int main() {
	std::deque<IOperand const *> a;
	const std::string str = "12345";
	Creator           ad;
	std::cout << a.size() << " size start\n";
	{
		std::stringstream test;
		test << " push int8(123) \n";
		Lexer	god(test);

		int i = test.str().find(';');
		std::string			command;
		std::string			value;
		std::stringstream 	num;
		int					token = -1;
		std::queue<std::pair<int,char>>	qqqq;
		qqqq.push(std::make_pair(3, 's'));
		test >> command >> value;
		std::cout << "i = "<< i << "\ncommand {" << command << "}\nvalue{" << value << "}" << std::endl;
		std::cout << qqqq.back().first << qqqq.back().second;
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