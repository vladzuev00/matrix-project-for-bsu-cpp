#include "stdafx.h"
#include "Test.h"
#include "UnsupportedOperationException.h"
#include "RunningTestException.h"
#include "InitializingTestException.h"

//************************************************
const TestValidator Test::TEST_VALIDATOR = TestValidator();
//************************************************
Test::Test(const Test &other)
{
	this->reactToRequestCopyTestObject();
}
//************************************************
void Test::reactToRequestCopyTestObject() const 
{
	throw new UnsupportedOperationException("Impossible to copy test-object.");
}
//************************************************
void Test::operator=(const Test &other)
{
	this->reactToRequestCopyTestObject();
}
//************************************************
void Test::incrementCorrespondingAmountTests(const bool isTestSuccessed) 
{
	this->testWasRanOrThrowException();
	if (isTestSuccessed)
	{
		this->amountSuccessedTests++;
	}
	else 
	{
		this->reportAboutCurrentFailedTest();
		this->amountFailedTests++;
	}
}
//************************************************
void Test::testWasRanOrThrowException() const
{
	if (!this->isTestWasRan) 
	{
		const string exceptionDescription 
			= typeid(*this).name() + string(" wasn't ran yet.");
		throw new RunningTestException(exceptionDescription);
	}
}
//************************************************
void Test::reportAboutCurrentFailedTest() const 
{
	*this->outputStream << "Test failed in : "
		                << typeid(*this).name() 
		                << ".\n";
}
//************************************************
Test::Test(ostream * const outputStream)
{
	if (!Test::TEST_VALIDATOR.isValidOutputStream(outputStream)) 
	{
		throw new InitializingTestException("Given pointer of output "
			"stream to initialize test-object isn't valid.");
	}
	this->outputStream = outputStream;
	this->amountSuccessedTests = 0;
	this->amountFailedTests = 0;
	this->isTestWasRan = false;
}
//************************************************
void Test::runTests() 
{
	this->testWasNotRanOrThrowException();
	this->isTestWasRan = true;
}
//************************************************
void Test::testWasNotRanOrThrowException() const
{
	if (this->isTestWasRan) 
	{
		const string exceptionDescription
			= typeid(*this).name() + string(" was ran already.");
		throw new RunningTestException(exceptionDescription);
	}
}
//************************************************
void Test::setOutputStream(ostream * const outputStream)
{
	if (!Test::TEST_VALIDATOR.isValidOutputStream(outputStream)) 
	{
		throw new InitializingTestException(
			"Given pointer of output stream isn't valid.");
	}
	this->outputStream->flush();
	this->outputStream = outputStream;
}
//************************************************
const ostream& Test::getOutputStream() const
{
	return *this->outputStream;
}
//************************************************
long Test::getAmountSuccessedTests() const
{
	this->testWasRanOrThrowException();
	return this->amountSuccessedTests;
}
//************************************************
long Test::getAmountFailedTests() const
{
	this->testWasRanOrThrowException();
	return this->amountFailedTests;
}
//************************************************
void Test::reportAboutSuccessedAndFailedTests() const 
{
	this->testWasRanOrThrowException();
	*this->outputStream << "Test \"" << typeid(*this).name() << "\"\n"
		                << "\tAmount of successed tests : " << this->amountSuccessedTests << "\n"
		                << "\tAmount of failed tests : " << this->amountFailedTests << "\n";
}
//************************************************
Test::~Test() 
{
	this->outputStream->flush();    
}
//************************************************