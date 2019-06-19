#include "LOG.hpp"
#include <stdexcept>

const char* Log::trans(LogType type) {
	switch(type) {
	case Info: return "Info";
	case Debug: return "Debug";
	case Error: return "Error";
	}
	return "Unknown";
}

Log::Log(LogType type) {
	std::cout << "[" << trans(type) << "]: ";
}

template <class T>
Log& Log::operator<<(const T& msg){
	std::cout << msg;
	return *this;
}

Log::~Log() {
	std::cout << std::endl;
}

