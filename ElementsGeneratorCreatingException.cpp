#include "stdafx.h"
#include "ElementsGeneratorCreatingException.h"

//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException() 
	: ElementsGeneratorException::ElementsGeneratorException()
{

}
//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException(
	const std::string &description)
	: ElementsGeneratorException::ElementsGeneratorException(description)
{

}
//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException(
	Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(cause)
{

}
//************************************************************************
ElementsGeneratorCreatingException::ElementsGeneratorCreatingException(
	const std::string &description, Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(description, cause)
{

}
//************************************************************************
ElementsGeneratorCreatingException::~ElementsGeneratorCreatingException()
{

}
//************************************************************************