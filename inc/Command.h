//
// Created by Oleh IVANYTSKYI on 2019-08-16.
//

#ifndef ABSTRACTVM_COMMAND_H
#define ABSTRACTVM_COMMAND_H


class Command
{

public:
	Command();
//	Command();
	~Command();

	Command(Command const &src);

	Command &operator=(Command const &rhs);

private:
	bool commandlong;
};


#endif //ABSTRACTVM_COMMAND_H
