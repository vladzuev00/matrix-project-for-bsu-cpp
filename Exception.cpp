#include "stdafx.h"
#include "Exception.h"

//*************************************************
Exception::Exception()
	: description(new string()),
	  cause(0)
{

}
//*************************************************

//*************************************************
Exception::Exception(const string &description)
	: description(new string(description)),
	  cause(0)
{

}
//*************************************************
Exception::Exception(Exception * const cause)
	: description(new string()),
	  cause(cause)
{

}
//*************************************************
Exception::Exception(const string &description,
	Exception * const cause)
	: description(new string(description)),
	  cause(cause)
{

}
//*************************************************
const string& Exception::getDescription() const
{
	return *this->description;
}
//*************************************************
Exception& Exception::getCause() const
{
	return *this->cause;
}
//*************************************************
Exception::~Exception()
{
	delete this->description;
	delete this->cause;
}
//*************************************************