#include "stdafx.h"
#include "InitializingTestException.h"

//********************************************************************
InitializingTestException::InitializingTestException() 
	: TestException::TestException()
{
	
}
//********************************************************************
InitializingTestException::InitializingTestException(
	const string &description)
	: TestException::TestException(description)
{

}
//********************************************************************
InitializingTestException::InitializingTestException(Exception * const cause)
	: TestException::TestException(cause)
{

}
//********************************************************************
InitializingTestException::InitializingTestException(
	const string &description, Exception * const cause)
	: TestException::TestException(description, cause)
{

}
//********************************************************************
InitializingTestException::~InitializingTestException()
{

}
//********************************************************************