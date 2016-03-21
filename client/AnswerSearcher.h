#pragma once
/* 答案检索类 */
class AnswerSearcher
{
public:
	AnswerSearcher(CString AnswerSearchAPI,CString AnswerSearchSite); //构造方法
	~AnswerSearcher(void);
	bool CheckVaild(CString Site,CString FilePathName,CString Salt); //检查软件是否有效,通过增加Web服务器验证开控制软件是否开放使用
	CString SearchAnswer(CString Keyword);//检索答案
	CString AnswerTranslate(int QuestionType,int AnswerCode); //将答案代码转换成答案选项
private:
	CString SearchSite; 
	CString SearchAPI; //答案检索API接口
	int UploadOption; //数据上传选项,0为上传，-1为不上传
};

