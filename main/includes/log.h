
#ifndef flag
#define flag

#include<iostream>
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


		template < typename... parameters>
		void Warn( parameters &&... Args);

		template < typename... parameters>
		void Error( parameters &&... Args);

		template < typename... parameters>
		void Info(parameters &&... Args);


		void print_args() { std::cout << "\n"; }

		template <typename t1, typename... args>
		void print_args(t1 first, args... rest)
		{
			std::cout << first << " ";
			Log::print_args(rest...); 
		}
	};

	template < typename... parameters>
	void Log::Info(parameters &&... Args)
	{
		logDate.refdate();
		if (m_LogLevel >= Level::LevelInfo) {
			std::cout << "[ " << logDate.getStringrep() << " ]" << "[Info]: ";
			Log::print_args(Args...);

		}
	}

	template < typename... parameters>
	void Log::Warn(parameters &&... Args)
	{
		logDate.refdate();
		if (m_LogLevel >= Level::LevelWarning) {
			std::cout << "[ " << logDate.getStringrep() << " ]" << "[Warn]: ";
			Log::print_args(Args...);
		}
	}

	template < typename... parameters>
	void Log::Error(parameters &&... Args)
	{
		logDate.refdate();
		if (m_LogLevel >= Level::LevelError) {
			std::cout << "[ " << logDate.getStringrep() << " ]" << "[Error]: ";
			Log::print_args(Args...);
		}
	}

}

#endif