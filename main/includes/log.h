
#ifndef flag
#define flag

#include<iostream>
#include<fstream>
#include "string.h"
#include "date.h"

namespace logs {

	class Log
	{

	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};

		Log()
			:m_LogLevel{ Level::LevelInfo },  fileName{ "defaultLog.txt" } , logDate{ 2,2,2024 }{}

		Log(Level l1, utility::String filePara ={ "defaultLog.txt" }, utility::Date d1 = { 2,2,2024 })
			: m_LogLevel{ l1 }, logDate{ d1 }, fileName{filePara}
		{
		}

		void SetLogLevel(Level);

		void enableFileLog();
		void disableFileLog();

		template < typename... parameters>
		void Warn( parameters &&... Args);

		template < typename... parameters>
		void Error( parameters &&... Args);

		template < typename... parameters>
		void Info(parameters &&... Args);

		void print_args() { 
			std::cout << "\n";
			writeLog << "\n";
		}

		template <typename t1, typename... args>
		void print_args(t1 first, args... rest)
		{
			std::cout << first << " ";
			writeLog << first << " ";
			Log::print_args(rest...); 
		}


	private:
		Level m_LogLevel;
		utility::Date logDate;
		std::ofstream writeLog;
		utility::String fileName;
		bool writeToFile = true;
		utility::String log;

	};

	template < typename... parameters>
	void Log::Info(parameters &&... Args)
	{
		logDate.refdate();
		if (m_LogLevel >= Level::LevelInfo) {

			log = utility::String{ "[ " } + logDate.getStringrep() + utility::String{ " ]" } + utility::String{ "[Info]: " };

			if (writeToFile) {
				writeLog.open(fileName.getCharString(), std::ios::app);
				std::cout << log;
				writeLog << log;
				Log::print_args(Args...);
				writeLog.close();
			}
			else {
				std::cout << log;
				Log::print_args(Args...);
			}
		}
	}

	template < typename... parameters>
	void Log::Warn(parameters &&... Args)
	{
		logDate.refdate();
		if (m_LogLevel >= Level::LevelWarning) {

			log = utility::String{ "[ " } + logDate.getStringrep() + utility::String{ " ]" } + utility::String{ "[Warn]: " };

			if (writeToFile) {
				writeLog.open(fileName.getCharString(), std::ios::app);
				std::cout << log;
				writeLog << log;
				Log::print_args(Args...);
				writeLog.close();
			}
			else {
				std::cout << log;
				Log::print_args(Args...);
			}
		}
	}

	template < typename... parameters>
	void Log::Error(parameters &&... Args)
	{
		logDate.refdate();
		if (m_LogLevel >= Level::LevelError) {

			log = utility::String{ "[ " } + logDate.getStringrep() + utility::String{ " ]" } + utility::String{ "[Error]: " };

			if (writeToFile) {
				writeLog.open(fileName.getCharString(), std::ios::app);
				std::cout << log;
				writeLog << log;
				Log::print_args(Args...);
				writeLog.close();
			}
			else {
				std::cout << log;
				Log::print_args(Args...);
			}
		}
	}


}

#endif