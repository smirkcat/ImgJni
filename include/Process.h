#include <string>
#include <sstream>
using namespace std;
#ifndef _Included_Process
#define _Included_Process

class Process{
	//成员sometype pr
public:
	~Process(){
	}
	Process();
	Process(string);
	string process(char*, int);
};
#endif