//
// Created by Oleh IVANYTSKYI on 2019-09-11.
//

#ifndef ERRORMNG_H
#define ERRORMNG_H

#include <exception>
#include <stdexcept>
#include <string>

class ErrorMng : public std::exception
{

public:
	ErrorMng() noexcept;
	ErrorMng(ErrorMng const &src) = default;
	ErrorMng &operator=(ErrorMng const &rhs) = default;
	virtual ~ErrorMng() = default;
	virtual const char *what() const noexcept = 0;

protected:
	std::string outLine;
};

class SyntaxErr : public ErrorMng
{

public:
	SyntaxErr() noexcept = default;
	SyntaxErr(SyntaxErr const &src) = default;
	SyntaxErr(std::string const &src);
	SyntaxErr &operator=(SyntaxErr const &rhs) = default;
	~SyntaxErr() = default;
	const char *what() const noexcept;
};

class NoExitFound : public ErrorMng
{

public:
	NoExitFound() noexcept {};
	NoExitFound(NoExitFound const &src) = default;
	NoExitFound &operator=(NoExitFound const &rhs) = default;
	~NoExitFound() = default;
	const char *what() const noexcept;
};

class RuntimeErr : public ErrorMng
{

public:
	RuntimeErr() noexcept {};
	RuntimeErr(RuntimeErr const &src) = default;
	RuntimeErr(std::string const &src);
	RuntimeErr &operator=(RuntimeErr const &rhs) = default;
	~RuntimeErr() = default;
	const char *what() const noexcept;
};

#endif //ERRORMNG_H
