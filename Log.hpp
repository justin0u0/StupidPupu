#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>

enum LogType {
	Info, Debug, Error
};

class Log {
private:
	static const char* trans(LogType type);
public:
	explicit Log(LogType type=Debug);
	~Log();
	template<class T>
	Log& operator<<(const T& msg) {
	std::cout << msg;
	return *this;
}
};
#endif

