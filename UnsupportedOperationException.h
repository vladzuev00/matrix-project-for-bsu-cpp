#ifndef UNSUPPORTEDOPERATIONEXCEPTION_H
#define UNSUPPORTEDOPERATIONEXCEPTION_H

#include "Exception.h"

//*******************************************************************
class UnsupportedOperationException : public Exception
{
public:
	UnsupportedOperationException();
	UnsupportedOperationException(const string &description);
	UnsupportedOperationException(Exception * const cause);
	UnsupportedOperationException(const string &description,
		Exception * const cause);
public:
	~UnsupportedOperationException();
};
//*******************************************************************

#endif UNSUPPORTEDOPERATIONEXCEPTION_H