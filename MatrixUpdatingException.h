#ifndef MATRIXUPDATINGEXCEPTION_H
#define MATRIXUPDATINGEXCEPTION_H

#include "MatrixException.h"

//***************************************************************************
class MatrixUpdatingException : public MatrixException
{
public:
	MatrixUpdatingException();
	MatrixUpdatingException(const string &description);
	MatrixUpdatingException(Exception * const cause);
	MatrixUpdatingException(const string &description,
		Exception * const cause);
public:
	virtual ~MatrixUpdatingException() override;
};
//***************************************************************************

#endif MATRIXUPDATINGEXCEPTION_H