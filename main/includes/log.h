
#ifndef flag
#define flag

#include "string.h"
#include "date.h"

namespace logs {

	class Log
	{

	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};

	private:
		Level m_LogLevel;
		utility::Date logDate;

	public:
		Log()
			:m_LogLevel{ Level::LevelInfo }, logDate{ 2,2,2024 } {	}

		Log(Level l1, utility::Date d1 = { 2,2,2024 })
			: m_LogLevel{ l1 }, logDate{ d1 }
		{	}

		void SetLogLevel(Level);
		void Warn(const utility::String&);
		void Error(const  utility::String&);
		void Info(const  utility::String&);
	};

}

#endif