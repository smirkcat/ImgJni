# include "process.h"
# include <sstream>
string Process::process(char* imagebuffer, int size){
	/* //ͨ�ú��� opencv����
	Mat src = imdecode(Mat(1, size, CV_8U, imagebuffer), IMREAD_COLOR);
	if (!src.data)
	return NULL;

	//����������ش���
	string result=somefunc(src)
	*/
	//�����ǲ���
	std::stringstream ss;
	std::string str;
	ss << size;
	ss >> str;
	std::string result = "result,ͼƬbyte����Ϊ" + str;
	return result;
}

Process::Process(){
	
}

Process::Process(string path){
	//new (this) Process(); �Ƿ����Ĭ�Ϲ��캯��
}