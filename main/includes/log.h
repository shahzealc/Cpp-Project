
#ifndef flag
#define flag

#include<iostream>
#include<fstream>
#include "string.h"
#include "date.h"
#include <vector>
#include<string>

namespace logs {

	class Log
	{

	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};

		Log()
			:m_LogLevel{ Level::LevelInfo }, fileName{ "defaultLog.txt" }, logDate{ 2,2,2024 } {}

		Log(Level l1, utility::String filePara = { "defaultLog.txt" }, utility::Date d1 = { 2,2,2024 })
			: m_LogLevel{ l1 }, logDate{ d1 }, fileName{ filePara }
		{
		}

		//~Log() { writeBuffer_File(); }

		void SetLogLevel(Level);

		void enableFileLog();
		void disableFileLog();
		void writeBuffer_File();

		template <typename... parameters>
		void generalLogger(parameters... Args);

		template < typename... parameters>
		void Warn(parameters &&... Args);

		template < typename... parameters>
		void Error(parameters &&... Args);

		template < typename... parameters>
		void Info(parameters &&... Args);

		void print_args() {

			if (writeToFile) {

				writeLog << "\n";
			}

			std::cout << "\n";

		}

		template <typename t1, typename... args>
		void print_args(t1 first, args... rest)
		{
			if (writeToFile) {
				writeLog << first<<" ";
			}
			std::cout << first << " ";
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
		if (m_LogLevel >= Level::LevelInfo) {
			logDate.refdate();
			log = utility::String{ "[ " } + logDate.getStringrep() + utility::String{ " ]" } + utility::String{ "[Info]: " };

			generalLogger(Args...);
		}
	}

	template < typename... parameters>
	void Log::Warn(parameters &&... Args)
	{
		if (m_LogLevel >= Level::LevelWarning) {
			logDate.refdate();
			log = utility::String{ "[ " } + logDate.getStringrep() + utility::String{ " ]" } + utility::String{ "[Warn]: " };

			generalLogger(Args...);
		}
	}

	template < typename... parameters>
	void Log::Error(parameters &&... Args)
	{
		if (m_LogLevel >= Level::LevelError) {
			logDate.refdate();
			log = utility::String{ "[ " } + logDate.getStringrep() + utility::String{ " ]" } + utility::String{ "[Error]: " };

			generalLogger(Args...);
		}
	}

	template<typename ...parameters>
	void Log::generalLogger(parameters ...Args)
	{
		
		if (writeToFile) {

			writeLog.open(fileName.getCharString(), std::ios::app);
			try {
				if (!writeLog.is_open()) {
					writeToFile = false;
					throw FileException("Error: Failed to open file for writing\n");
				}
			}
			catch (FileException e) {
				e.what();
			}

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

#endif