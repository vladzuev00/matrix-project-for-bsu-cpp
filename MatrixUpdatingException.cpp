#include "stdafx.h"
#include "MatrixUpdatingException.h"

//************************************************************************
MatrixUpdatingException::MatrixUpdatingException()
	: MatrixException::MatrixException()
{

}
//************************************************************************
MatrixUpdatingException::MatrixUpdatingException(const string &description)
	: MatrixException::MatrixException(description)
{

}
//************************************************************************
MatrixUpdatingException::MatrixUpdatingException(Exception * const cause)
	: MatrixException::MatrixException(cause)
{

}
//************************************************************************
MatrixUpdatingException::MatrixUpdatingException(const string &description,
	Exception * const cause)
	: MatrixException::MatrixException(description, cause)
{

}
//************************************************************************
MatrixUpdatingException::~MatrixUpdatingException()
{

}
//************************************************************************
