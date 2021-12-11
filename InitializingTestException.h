#ifndef INITIALIZINGTESTEXCEPTION_H
#define INITIALIZINGTESTEXCEPTION_H

#include "TestException.h"

//********************************************************************
class InitializingTestException : public TestException
{
public:
	InitializingTestException();
	InitializingTestException(const string &description);
	InitializingTestException(Exception * const cause);
	InitializingTestException(const string &description,
		Exception * const cause);
public:
	virtual ~InitializingTestException() override;
};
//********************************************************************

#endif INITIALIZINGTESTEXCEPTION_H