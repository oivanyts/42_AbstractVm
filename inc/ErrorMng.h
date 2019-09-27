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
	const char *what() const noexcept;

protected:
	std::string outLine;
};

class GoodCommand : public ErrorMng
{
public:
	GoodCommand() noexcept = default;
	GoodCommand(GoodCommand  const &src) = default;
	GoodCommand  &operator=(GoodCommand  const &rhs) = default;
	virtual ~GoodCommand() = default;
};

class SyntaxErr : public ErrorMng
{

public:
	SyntaxErr() noexcept = default;
	SyntaxErr(SyntaxErr const &src) = default;
	SyntaxErr(std::string const &src);
	SyntaxErr &operator=(SyntaxErr const &rhs) = default;
	~SyntaxErr() = default;
};

class LexErr : public ErrorMng
{

public:
	LexErr() noexcept = default;
	LexErr(LexErr const &src) = default;
	LexErr(std::string const &src);
	LexErr &operator=(LexErr const &rhs) = default;
	~LexErr() = default;
};

class NoExitFound : public ErrorMng
{

public:
	NoExitFound() noexcept  = default;
	NoExitFound(NoExitFound const &src) = default;
	NoExitFound &operator=(NoExitFound const &rhs) = default;
	~NoExitFound() = default;
	const char *what() const noexcept;
};

class GotExit : public std::exception
{
public:
	GotExit() noexcept  = default;
	GotExit(GotExit const &src) = default;
	GotExit &operator=(GotExit const &rhs) = default;
	~GotExit() = default;
	const char *what() const noexcept;
};

class FileErr :  public ErrorMng
{
public:
	FileErr() noexcept;
	FileErr(FileErr const &src) = default;
	FileErr &operator=(FileErr const &rhs) = default;
	~FileErr() = default;
};

class RuntimeErr : public ErrorMng
{

public:
	RuntimeErr() noexcept {};
	RuntimeErr(RuntimeErr const &src) = default;
	RuntimeErr(std::string const &src);
	RuntimeErr &operator=(RuntimeErr const &rhs) = default;
	~RuntimeErr() = default;
};

#endif //ERRORMNG_H
