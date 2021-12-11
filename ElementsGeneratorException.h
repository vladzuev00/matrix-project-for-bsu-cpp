#ifndef ELEMENTSGENERATOREXCEPTION_H
#define ELEMENTSGENERATOREXCEPTION_H

#include "Exception.h"

//******************************************************************************************
class ElementsGeneratorException : virtual public Exception 
{
public:
	ElementsGeneratorException();
	ElementsGeneratorException(const std::string &description); 
	ElementsGeneratorException(Exception * const cause);
	ElementsGeneratorException(const std::string &description,
		Exception * const cause);
public:
	virtual ~ElementsGeneratorException() override;
};
//******************************************************************************************

#endif ELEMENTSGENERATOREXCEPTION_H