#pragma once
#include <string>
class Log
{
public:
	Log();
	~Log();

	void WriteTraceLog(std::string trace);
	void WriteErrorLog(std::string error);

};

