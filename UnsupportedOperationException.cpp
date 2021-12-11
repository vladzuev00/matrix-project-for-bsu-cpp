#include "stdafx.h"
#include "UnsupportedOperationException.h"

//*******************************************************************
UnsupportedOperationException::UnsupportedOperationException()
{

}
//*******************************************************************
UnsupportedOperationException::UnsupportedOperationException(
	const string &description) : Exception::Exception(description)
{

}
//*******************************************************************
UnsupportedOperationException::UnsupportedOperationException(
	Exception * const cause) : Exception::Exception(cause)
{

}
//*******************************************************************
UnsupportedOperationException::UnsupportedOperationException(
	const string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//*******************************************************************
UnsupportedOperationException::~UnsupportedOperationException()
{

}
//*******************************************************************