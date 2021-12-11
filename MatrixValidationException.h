#ifndef MATRIXVALIDATIONEXCEPTION_H
#define MATRIXVALIDATIONEXCEPTION_H

#include "MatrixException.h"

//***************************************************************************************
class MatrixValidationException : public MatrixException
{
public:
	MatrixValidationException();
	MatrixValidationException(const string &description);
	MatrixValidationException(Exception * const cause);
	MatrixValidationException(const string &description,
		Exception * const cause);
public:
	virtual ~MatrixValidationException() override;
};
//***************************************************************************************

#endif MATRIXVALIDATIONEXCEPTION_H