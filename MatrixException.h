#ifndef MATRIXEXCEPTION_H
#define MATRIXEXCEPTION_H

#include "Exception.h"
//************************************************************************
class MatrixException : virtual public Exception
{
public:
	MatrixException();
	MatrixException(const string &description);
	MatrixException(Exception * const cause);
	MatrixException(const string &description, Exception * const cause);
public:
	virtual ~MatrixException() override;
};
//************************************************************************
#endif MATRIXEXCEPTION_H