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
	
}