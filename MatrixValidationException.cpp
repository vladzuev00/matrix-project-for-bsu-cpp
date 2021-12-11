#include "stdafx.h"
#include "MatrixValidationException.h"

//***************************************************************************************
MatrixValidationException::MatrixValidationException() 
	: MatrixException::MatrixException()
{

}
//***************************************************************************************
MatrixValidationException::MatrixValidationException(const string &description)
	: MatrixException::MatrixException(description)
{

}
//***************************************************************************************
MatrixValidationException::MatrixValidationException(Exception * const cause)
	: MatrixException::MatrixException(cause)
{

}
//***************************************************************************************
MatrixValidationException::MatrixValidationException(
	const string &description, Exception * const cause)
	: MatrixException::MatrixException(description, cause)
{

}
//***************************************************************************************
MatrixValidationException::~MatrixValidationException()
{

}
//***************************************************************************************