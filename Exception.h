#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using std::string;

//*************************************************
class Exception
{
private:
	string *description;
	Exception *cause;
public:
	Exception();
	Exception(const string &description);
	Exception(Exception * const cause);
	Exception(const string &description,
		Exception * const cause);
public:
	const string& getDescription() const;
	Exception& getCause() const;
public:
	virtual ~Exception();
};
//*************************************************

#endif EXCEPTION_H
