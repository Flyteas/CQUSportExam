#pragma once
/* �𰸼����� */
class AnswerSearcher
{
public:
	AnswerSearcher(CString AnswerSearchAPI,CString AnswerSearchSite); //���췽��
	~AnswerSearcher(void);
	CString SearchAnswer(CString Keyword);//������
	CString AnswerTranslate(int QuestionType,int AnswerCode); //���𰸴���ת���ɴ�ѡ��
private:
	CString SearchSite; 
	CString SearchAPI; //�𰸼���API�ӿ�
};

