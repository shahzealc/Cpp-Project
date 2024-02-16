#include <iostream>
#include "includes/log.h"
#include "includes/date.h"
#include "includes/string.h"
#include "includes/complex.h"
#include "includes/myexception.h"

using logs::Log;
using utility::Date;
using utility::String;
using utility::Complex;

int main()
{
	Log log;
	log.SetLogLevel(Log::Level::LevelInfo);

	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");
	
	Date d1{ 10,30,2024 };
	String s{ "helloo" };
	std::cout << s[10];
	s.subStr(10,2);
}