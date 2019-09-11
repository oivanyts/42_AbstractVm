//
// Created by Oleh IVANYTSKYI on 2019-09-11.
//

#ifndef ERRORMNG_H
#define ERRORMNG_H

#include <exception>


class ErrorMng : public std::exception
{

public:
	ErrorMng() noexcept ;
	ErrorMng(ErrorMng const &src) = default;
	ErrorMng &operator=(ErrorMng const &rhs) = default;
	virtual ~ErrorMng() = default;
	virtual const char *what() const noexcept = 0;

};



#endif //ERRORMNG_H
