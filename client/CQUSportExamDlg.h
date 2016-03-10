
// CQUSportExamDlg.h : 头文件
//

#pragma once


// CCQUSportExamDlg 对话框
class CCQUSportExamDlg : public CDialogEx
{
// 构造
public:
	CCQUSportExamDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CQUSPORTEXAM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
