#pragma once
/* 答案检索类 */
class AnswerSearcher
{
public:
	AnswerSearcher(CString AnswerSearchAPI,CString AnswerSearchSite); //构造方法
	~AnswerSearcher(void);
	CString SearchAnswer(CString Keyword);//检索答案
	CString AnswerTranslate(int QuestionType,int AnswerCode); //将答案代码转换成答案选项
private:
	CString SearchSite; 
	CString SearchAPI; //答案检索API接口
};

