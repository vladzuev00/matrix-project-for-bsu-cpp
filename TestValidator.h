#ifndef TESTVALIDATOR_H
#define TESTVALIDATOR_H

#include <iostream>

//******************************************************************
class TestValidator
{
public:
	TestValidator();
public:
	bool isValidOutputStream(std::ostream * const outputStream) const;
public:
	~TestValidator();
};
//******************************************************************

#endif TESTVALIDATOR_H