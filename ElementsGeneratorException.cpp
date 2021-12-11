#include "stdafx.h"
#include "ElementsGeneratorException.h"

//******************************************************************************************
ElementsGeneratorException::ElementsGeneratorException() : Exception::Exception()
{

}
//******************************************************************************************
ElementsGeneratorException::ElementsGeneratorException(const std::string &description)
	: Exception::Exception(description)
{

}
//******************************************************************************************
ElementsGeneratorException::ElementsGeneratorException(Exception * const cause) 
	: Exception::Exception(cause)
{

}
//******************************************************************************************
ElementsGeneratorException::ElementsGeneratorException(
	const std::string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//******************************************************************************************
ElementsGeneratorException::~ElementsGeneratorException()
{

}
//******************************************************************************************