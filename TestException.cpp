#include "stdafx.h"
#include "TestException.h"

//*********************************************************************
TestException::TestException() : Exception::Exception()
{

}
//*********************************************************************
TestException::TestException(const string &description) 
	: Exception::Exception(description)
{

}
//*********************************************************************
TestException::TestException(Exception * const cause) 
	: Exception::Exception(cause)
{

}
//*********************************************************************
TestException::TestException(const string &description,
	Exception * const cause) : Exception::Exception(description, cause)
{

}
//*********************************************************************
TestException::~TestException()
{

}
//*********************************************************************