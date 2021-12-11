#ifndef MATRIXSEARCHINGEXCEPTION_H
#define MATRIXSEARCHINGEXCEPTION_H

#include "MatrixException.h"

//******************************************************************
class MatrixSearchingException : public MatrixException
{
public:
	MatrixSearchingException();
	MatrixSearchingException(const string &description);
	MatrixSearchingException(Exception * const cause);
	MatrixSearchingException(const string &description,
		Exception * const cause);
public:
	virtual ~MatrixSearchingException() override;
};
//******************************************************************

#endif MATRIXSEARCHINGEXCEPTION_H