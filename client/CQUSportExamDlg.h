
// CQUSportExamDlg.h : ͷ�ļ�
//

#pragma once


// CCQUSportExamDlg �Ի���
class CCQUSportExamDlg : public CDialogEx
{
// ����
public:
	CCQUSportExamDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CQUSPORTEXAM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Keyword;
	afx_msg void OnBnClickedOk();
	CString Result_Display;
};
