#ifndef TESTEXCEPTION_H
#define TESTEXCEPTION_H

#include "Exception.h"

//*********************************************************************
class TestException : public Exception
{
public:
	TestException();
	TestException(const string &description);
	TestException(Exception * const cause);
	TestException(const string &description, Exception * const cause);
public:
	~TestException();
};
//*********************************************************************

#endif TESTEXCEPTION_H