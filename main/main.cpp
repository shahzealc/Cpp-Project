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

	Log logTemplate;
	logTemplate.SetLogLevel(Log::Level::LevelInfo);

	logTemplate.Info(String{ "Info Log" }, 1, 'i');
	logTemplate.Warn(String{ "Warning Log" }, 2.1, 'w');
	logTemplate.Error(1.1 + 1.9, "Error Log", String{ "e" });

}
