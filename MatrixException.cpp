#include "stdafx.h"
#include "MatrixException.h"

//************************************************************************
MatrixException::MatrixException() : Exception::Exception()
{

}
//************************************************************************
MatrixException::MatrixException(const string &description)
	: Exception::Exception(description)
{

}
//************************************************************************
MatrixException::MatrixException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//************************************************************************
MatrixException::MatrixException(const string &description,
	Exception * const cause) : Exception::Exception(description, cause)
{

}
//************************************************************************
MatrixException::~MatrixException()
{

}
//************************************************************************