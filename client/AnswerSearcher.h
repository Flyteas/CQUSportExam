#pragma once
/* �𰸼����� */
class AnswerSearcher
{
public:
	AnswerSearcher(CString AnswerSearchAPI,CString AnswerSearchSite); //���췽��
	~AnswerSearcher(void);
	bool CheckVaild(CString Site,CString FilePathName,CString Salt); //�������Ƿ���Ч,ͨ������Web��������֤����������Ƿ񿪷�ʹ��
	CString SearchAnswer(CString Keyword);//������
	CString AnswerTranslate(int QuestionType,int AnswerCode); //���𰸴���ת���ɴ�ѡ��
private:
	CString SearchSite; 
	CString SearchAPI; //�𰸼���API�ӿ�
	int UploadOption; //�����ϴ�ѡ��,0Ϊ�ϴ���-1Ϊ���ϴ�
};

