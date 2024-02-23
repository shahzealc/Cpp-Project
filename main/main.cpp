#include <iostream>
#include "includes/log.h"
#include "includes/date.h"


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

	//utility::Date d1{ 11_month,12_day,2024_year };
	//utility::Date d2{ 2024_year,11_month,12_day };
	//d1.getDate();
}
