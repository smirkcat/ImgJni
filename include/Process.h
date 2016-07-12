#include <string>
#include <sstream>
using namespace std;
#ifndef _Included_Process
#define _Included_Process

class Process{
	int sign;
public:
	~Process()
	{

	}
	Process(){

	}
	std::string process(char* imagebuffer, int size);
};
#endif