#include "stdafx.h"
#include "ElementsGeneratorUpdatingException.h"

//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException() 
	: ElementsGeneratorException::ElementsGeneratorException()
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException(const std::string &description)
	: ElementsGeneratorException::ElementsGeneratorException(description)
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException(Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(cause)
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::ElementsGeneratorUpdatingException(
	const std::string &description, Exception * const cause)
	: ElementsGeneratorException::ElementsGeneratorException(description, cause)
{

}
//***********************************************************************
ElementsGeneratorUpdatingException::~ElementsGeneratorUpdatingException()
{

}
//***********************************************************************