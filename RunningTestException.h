#ifndef RUNNINGTESTEXCEPTION_H
#define RUNNINGTESTEXCEPTION_H

#include "TestException.h"

//********************************************************************
class RunningTestException : public TestException
{
public:
	RunningTestException();
	RunningTestException(const string &description);
	RunningTestException(Exception * const cause);
	RunningTestException(const string &description,
		Exception * const cause);
public:
	virtual ~RunningTestException() override;
};
//********************************************************************

#endif RUNNINGTESTEXCEPTION_H