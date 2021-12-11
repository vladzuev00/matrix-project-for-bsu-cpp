#include "stdafx.h"
#include "RunningTestException.h"

//********************************************************************
RunningTestException::RunningTestException() 
	: TestException::TestException()
{

}
//********************************************************************
RunningTestException::RunningTestException(const string &description)
	: TestException::TestException(description)
{

}
//********************************************************************
RunningTestException::RunningTestException(Exception * const cause)
	: TestException::TestException(cause)
{

}
//********************************************************************
RunningTestException::RunningTestException(const string &description,
	Exception * const cause) 
	: TestException::TestException(description, cause)
{

}
//********************************************************************
RunningTestException::~RunningTestException()
{

}
//********************************************************************