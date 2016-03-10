#include "stdafx.h"
#include "AnswerSearcher.h"
#include <stdio.h>
#include <afxinet.h>

AnswerSearcher::AnswerSearcher(CString AnswerSearchAPI,CString AnswerSearchSite)
{
	this->SearchAPI = AnswerSearchAPI;
	this->SearchSite = AnswerSearchSite;
}


AnswerSearcher::~AnswerSearcher(void)
{
}

CString AnswerSearcher::AnswerTranslate(int QuestionType,int AnswerCode)
{
	CString Result;
	switch (AnswerCode)
	{
	case 0:
		Result = "否";
		break;
	case 1:
		if(QuestionType == 3)
		{
			Result = "是";
		}
		else
		{
			Result = "A";
		}
		break;
	case 2:
		Result = "B";
		break;
	case 4:
		Result = "C";
		break;
	case 8:
		Result = "D";
		break;
	case 16:
		Result = "E";
		break;
	case 32:
		Result = "F";
		break;
	case 3:
		Result = "AB";
		break;
	case 5:
		Result = "AC";
		break;
	case 9:
		Result = "AD";
		break;
	case 17:
		Result = "AE";
		break;
	case 33:
		Result = "AF";
		break;
	case 6:
		Result = "BC";
		break;
	case 10:
		Result = "BD";
		break;
	case 18:
		Result = "BE";
		break;
	case 34:
		Result = "BF";
		break;
	case 12:
		Result = "CD";
		break;
	case 20:
		Result = "CE";
		break;
	case 36:
		Result = "CF";
		break;
	case 24:
		Result = "DE";
		break;
	case 40:
		Result = "DF";
		break;
	case 48:
		Result = "EF";
		break;
	case 7:
		Result = "ABC";
		break;
	case 11:
		Result = "ABD";
		break;
	case 19:
		Result = "ABE";
		break;
	case 35:
		Result = "ABF";
		break;
	case 13:
		Result = "ACD";
		break;
	case 21:
		Result = "ACE";
		break;
	case 37:
		Result = "ACF";
		break;
	case 25:
		Result = "ADE";
		break;
	case 41:
		Result = "ADF";
		break;
	case 49:
		Result = "AEF";
		break;
	case 14:
		Result = "BCD";
		break;
	case 22:
		Result = "BCE";
		break;
	case 38:
		Result = "BCF";
		break;
	case 26:
		Result = "BDE";
		break;
	case 42:
		Result = "BDF";
		break;
	case 50:
		Result = "BEF";
		break;
	case 28:
		Result = "CDE";
		break;
	case 44:
		Result = "CDF";
		break;
	case 52:
		Result = "CEF";
		break;
	case 56:
		Result = "DEF";
		break;
	case 15:
		Result = "ABCD";
		break;
	case 23:
		Result = "ABCE";
		break;
	case 39:
		Result = "ABCF";
		break;
	case 27:
		Result = "ABDE";
		break;
	case 43:
		Result = "ABDF";
		break;
	case 51:
		Result = "ABEF";
		break;
	case 29:
		Result = "ACDE";
		break;
	case 45:
		Result = "ACDF";
		break;
	case 53:
		Result = "ACEF";
		break;
	case 57:
		Result = "ADEF";
		break;
	case 30:
		Result = "BCDE";
		break;
	case 46:
		Result = "BCDF";
		break;
	case 54:
		Result = "BCEF";
		break;
	case 58:
		Result = "BDEF";
		break;
	case 60:
		Result = "CDEF";
		break;
	case 31:
		Result = "ABCDE";
		break;
	case 47:
		Result = "ABCDF";
		break;
	case 55:
		Result = "ABCEF";
		break;
	case 59:
		Result = "ABDEF";
		break;
	case 61:
		Result = "ACDEF";
		break;
	case 62:
		Result = "BCDEF";
		break;
	case 63:
		Result = "ABCDEF";
		break;
	default:
		Result = "无答案";
		break;
	}
	return Result;
}

CString AnswerSearcher::SearchAnswer(CString Keyword)
{
	CString PageRes;
	CString Answer;
	CString Question;
	CString Type;
	CString Ans;
	try
	{
	CInternetSession HttpSession;
	HttpSession.SetOption(INTERNET_OPTION_CONNECT_TIMEOUT,30000); //超时时间
	HttpSession.SetOption(INTERNET_OPTION_CONNECT_BACKOFF,500);		// 重试间隔时间	
	HttpSession.SetOption(INTERNET_OPTION_CONNECT_RETRIES,3);	//重试次数
	CHttpConnection* HttpConnection = HttpSession.GetHttpConnection(this->SearchSite,NULL,88);
	CHttpFile* HttpFile = HttpConnection->OpenRequest(CHttpConnection::HTTP_VERB_GET,this->SearchAPI+Keyword,NULL,1,NULL,NULL,INTERNET_FLAG_RELOAD|INTERNET_FLAG_NO_CACHE_WRITE);  //RELOAD表示不从缓存读取，NO_CACHE表示不写入缓存
	HttpFile->SendRequest();
	DWORD StatusCode;	//HTTP状态码
	HttpFile->QueryInfoStatusCode(StatusCode);
	if(StatusCode != 200) 
	{
		return false;
	}
	char buff[4096]={0};
	int ReadNum = 0;
	while((ReadNum = HttpFile->Read((void*)buff,4095))>0)
	{
		buff[ReadNum] = '\0';
		PageRes += buff;
		memset(buff,0,4096);
	}
	}
	catch(CInternetException* e)
	{
	}
	while(PageRes.Find('|')!=-1)
	{
		CString t1,t2;
		t1 = "题目: ";
		t2 = "答案: ";
		Question = PageRes.Mid(0,PageRes.Find('|'));
		Question +="\r\n";
		Question = t1+ Question;
		PageRes = PageRes.Mid(PageRes.Find('|')+1);
		Type = PageRes.Mid(0,PageRes.Find('|'));
		Type += "\r\n";
		PageRes = PageRes.Mid(PageRes.Find('|')+1);
		Ans = PageRes.Mid(0,PageRes.Find('|'));
		Ans = this->AnswerTranslate(_ttoi(Type),_ttoi(Ans));
		Ans += "\r\n\r\n";
		Ans = t2 + Ans;
		PageRes = PageRes.Mid(PageRes.Find('|')+1);
		Answer = Answer + Question  + Ans;
	}
	return Answer;
}