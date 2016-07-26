# include "Process.h"
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
	this->sign = size;
	std::stringstream ss;
	std::string str;
	ss << size;
	ss >> str;
	std::string result = "result,图片byte长度为" + str;
	return result;
}

Process::Process(){
	//一些预处理
}

Process::Process(string path){
	///   Process(); 是否调用默认构造函数
	//path是模型文件的根目录绝对路径，使用/分割,方式如下
	//成员初始化 pr ，加载一些模型文件; 
	//pr.LoadANN(path + "/ann.xml");
	//pr.LoadChineseANN(path + "/ann_chinese.xml");
	//pr.LoadSVM(path + "/svm.xml");
}