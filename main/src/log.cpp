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
		std::cout << "[Warning]: " << message << " | Date : " << logDate.getStringrep() << "\n";
	}
}

void Log::Error(const utility::String& message)
{
	logDate.refdate();
	if (m_LogLevel >= Level::LevelError) {
		std::cout << "[Error]: " << message << " | Date : " << logDate.getStringrep() << "\n";
	}
}

void Log::Info(const utility::String& message)
{
	logDate.refdate();
	if (m_LogLevel >= Level::LevelInfo) {
		std::cout << "[Info]: " << message << " | Date : " << logDate.getStringrep() << "\n";
	}
}

