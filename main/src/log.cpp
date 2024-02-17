#include <iostream>
#include "../includes/log.h"
#include "../includes/string.h"

using logs::Log;

// Log Class implementation of all function definations
void Log::SetLogLevel(Level level)
{
	m_LogLevel = level;
}

void Log::Warn(const utility::String& message)
{
	logDate.refdate(); 
	if (m_LogLevel >= Level::LevelWarning) {
		std::cout << "[ " << logDate.getStringrep() <<" ]" << "[Warn]: " << message << "\n";
	}
}

void Log::Error(const utility::String& message)
{
	logDate.refdate();
	if (m_LogLevel >= Level::LevelError) {
		std::cout << "[ " << logDate.getStringrep() << " ]" << "[Error]: " << message << "\n";
	}
}

void Log::Info(const utility::String& message)
{
	logDate.refdate();
	if (m_LogLevel >= Level::LevelInfo) {
		std::cout << "[ " << logDate.getStringrep() << " ]" << "[Info]: " << message << "\n";
	}
}

