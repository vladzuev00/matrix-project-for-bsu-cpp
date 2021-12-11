#include "stdafx.h"
#include "MatrixSearchingException.h"

//************************************************************************
MatrixSearchingException::MatrixSearchingException()
	: MatrixException::MatrixException()
{

}
//************************************************************************
MatrixSearchingException::MatrixSearchingException(const string &description)
	: MatrixException::MatrixException(description)
{

}
//************************************************************************
MatrixSearchingException::MatrixSearchingException(Exception * const cause)
	: MatrixException::MatrixException(cause)
{

}
//************************************************************************
MatrixSearchingException::MatrixSearchingException(const string &description,
	Exception * const cause) 
	: MatrixException::MatrixException(description, cause)
{

}
//************************************************************************
MatrixSearchingException::~MatrixSearchingException()
{

}
//************************************************************************