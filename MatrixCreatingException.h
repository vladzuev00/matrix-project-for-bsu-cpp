#ifndef MATRIXCREATINGEXCEPTION_H
#define MATRIXCREATINGEXCEPTION_H

#include "MatrixException.h"

//***************************************************************************
class MatrixCreatingException : public MatrixException
{
public:
	MatrixCreatingException();
	MatrixCreatingException(const string &description);
	MatrixCreatingException(Exception * const cause);
	MatrixCreatingException(const string &description,
		Exception * const cause);
public:
	virtual ~MatrixCreatingException() override;
};
//***************************************************************************

#endif MATRIXCREATINGEXCEPTION_H