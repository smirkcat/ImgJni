# include "process.h"
# include <sstream>
string Process::process(char* imagebuffer, int size){
	/* //通用函数 opencv环境
	Mat src = imdecode(Mat(1, size, CV_8U, imagebuffer), IMREAD_COLOR);
	if (!src.data)
	return NULL;

	//在这里做相关处理
	string result=somefunc(src)
	*/
	//下面是测试
	std::stringstream ss;
	std::string str;
	ss << size;
	ss >> str;
	std::string result = "result,图片byte长度为" + str;
	return result;
}

Process::Process(){
	
}

Process::Process(string path){
	//new (this) Process(); 是否调用默认构造函数
}