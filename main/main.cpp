#include <iostream>
#include "includes/log.h"

using logs::Log;


int main()
{
	Log log;
	log.SetLogLevel(Log::Level::LevelInfo);

	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");

	Log logTemplate;
	logTemplate.SetLogLevel(Log::Level::LevelInfo);

	logTemplate.Info("Info Log",1,'i');
	logTemplate.Warn( "Warning Log" , 2.1f, 'w');
	logTemplate.Error(1.1 + 1.9, "Error Log",  "e" );
}
