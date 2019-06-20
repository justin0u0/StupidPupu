#include "LOG.hpp"
#include <stdexcept>

const char* Log::trans(LogType type) {
	switch(type) {
	case Info: return "Info";
	case Verbose: return "Verbose";
	case Debug: return "Debug";
	case Error: return "Error";
	}
	return "Unknown";
}

Log::Log(LogType type) {
	this->type = type;
	if (type != Verbose || (type == Verbose && VerboseMode))
		std::cout << "[" << trans(type) << "]: ";
}

Log::~Log() {
	if (type != Verbose || (type == Verbose && VerboseMode))
		std::cout << std::endl;
	if (type == Error)
		throw std::runtime_error("Terminate on error");
}

