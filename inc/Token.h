//
// Created by Oleh IVANYTSKYI on 2019-08-08.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "main.h"

enum eType{
	REJECT = 0,
	INST,
	OPENBR,
	CLOSEBR,
	NUMBER,
	FLOAT,
	ENDL,
	SPACE,
	COMNT,
	SIGN,
	BADINST,
	VALUE,
};



class Token
{
public:
	Token();
	Token(std::string str, int place, eType curr);
	~Token() = default;
	Token(Token const &src);

	Token &operator=(Token const &rhs);
	void printTok() const;
	eType getType() const;
	int getNumInst() const;
	const std::string &getValue() const;
	const std::string getLocation();


	static std::string	tokType[12];
private:

	eType 				_type;
	std::string	const	_value;
	int const 			col;
	int const 			row;
	int					_numInst;
	static int			endl_counter;

	void				deal_instance();
};


#endif //ABSTRACTVM_TOKEN_H
