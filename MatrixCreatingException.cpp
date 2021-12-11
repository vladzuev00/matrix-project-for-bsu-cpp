#include "stdafx.h"
#include "MatrixCreatingException.h"

//************************************************************************
MatrixCreatingException::MatrixCreatingException() 
	: MatrixException::MatrixException()
{

}
//************************************************************************
MatrixCreatingException::MatrixCreatingException(const string &description)
	: MatrixException::MatrixException(description)
{

}
//************************************************************************
MatrixCreatingException::MatrixCreatingException(Exception * const cause)
	: MatrixException::MatrixException(cause)
{

}
//************************************************************************
MatrixCreatingException::MatrixCreatingException(const string &description,
	Exception * const cause)
	: MatrixException::MatrixException(description, cause)
{

}
//************************************************************************
MatrixCreatingException::~MatrixCreatingException()
{

}
//************************************************************************