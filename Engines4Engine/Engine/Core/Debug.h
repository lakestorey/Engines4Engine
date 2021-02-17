#ifndef DEBUG_H
#define DEBUG_H

#include<iostream>
#include<string>
#include<fstream>

class Debug {
public:
	enum class MessageType : unsigned short {
		//starts at 0, so could leave that out
		TYPE_NONE = 0,
		TYPE_FATAL_ERROR,
		TYPE_ERROR,
		TYPE_WARNING,
		TYPE_TRACE,
		TYPE_INFO
	};

	Debug() = delete;
	Debug(const Debug&) = delete;
	Debug(Debug&&) = delete;
	Debug& operator=(const Debug&) = delete;
	Debug& operator=(Debug&&) = delete;
	
	static void OnCreate(const std::string& name_ = "Game258EngineLog"); //gives the name a default value
	static void SetSeverity(MessageType type_);

	//seperate functions for each type so it doesn't slow the program down
	static void Info(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void Trace(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void Warning(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void Error(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void FatalError(const std::string& message_, const std::string& fileName,
		const int line_);

private:
	static void Log(const MessageType type_, const std::string& message_,
		const std::string& fileName, const int line_);
	static MessageType currentSev;
	static std::string outputName;
};
#endif //!DEBUG_H