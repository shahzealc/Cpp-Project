#ifndef excep_flag
#define excep_flag

#include<iostream>
#include "string.h"

class MyException {
private:
	utility::String message;

public:
	MyException(utility::String str =  { "Something went wrong" } ) :message{str} {	}

	virtual void what() {
		std::cout << message;
	}

	virtual ~MyException() = default;

};

class StringException:public MyException {

public:
	StringException(utility::String str) :MyException{ str } {	}

};

class DateException :public MyException {

public:
	DateException(utility::String str) :MyException{ str } {	}
};
#endif