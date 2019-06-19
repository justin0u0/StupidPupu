#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>

enum LogType {
	Info, Verbose, Debug, Error
};

class Log {
private:
	const char* trans(LogType type);
	bool VerboseMode = false;
public:
	LogType type;
	explicit Log(LogType type=Debug);
	~Log();
	template<class T>
	Log& operator<<(const T& msg) {
		if (type != Verbose || (type == Verbose && VerboseMode))
			std::cout << msg;
		return *this;
	}
};
#endif

