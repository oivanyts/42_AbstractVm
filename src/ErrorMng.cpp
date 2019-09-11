//
// Created by Oleh IVANYTSKYI on 2019-09-11.
//

#include "ErrorMng.h"

ErrorMng::ErrorMng()
{

}

ErrorMng::~ErrorMng()
{

}

ErrorMng::ErrorMng(ErrorMng const &src)
{
	*this = src;
}

ErrorMng &ErrorMng::operator=(ErrorMng const &rhs)
{
	if (&rhs != this)
	{}
	return *this;
}