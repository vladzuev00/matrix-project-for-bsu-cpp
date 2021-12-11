#ifndef TEST_H
#define TEST_H
      
#include <iostream>
#include "TestValidator.h"

using std::ostream;
using std::cout;

//********************************************************
class Test
{
private:
	ostream *outputStream;
	long amountSuccessedTests;
	long amountFailedTests;
	bool isTestWasRan;
private:
	static const TestValidator TEST_VALIDATOR;
private:
	Test(const Test &other);
private:
	void operator=(const Test &other);
	void reportAboutCurrentFailedTest() const;
	void testWasRanOrThrowException() const;
	void testWasNotRanOrThrowException() const;
protected:
	void reactToRequestCopyTestObject() const;
	void incrementCorrespondingAmountTests(const bool isTestSuccessed);
public:
	Test(ostream * const outputStream = &cout);
public:
	virtual void runTests();
	void setOutputStream(ostream * const outputStream);
	const ostream& getOutputStream() const;
	long getAmountSuccessedTests() const;
	long getAmountFailedTests() const;
	void reportAboutSuccessedAndFailedTests() const;
public:
	virtual ~Test() = 0;
};
//********************************************************
#endif TEST_H