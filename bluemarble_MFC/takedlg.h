#pragma once
#include<iostream>
using namespace std;

// takedlg 대화 상자

class takedlg : public CDialogEx
{
	DECLARE_DYNAMIC(takedlg)

public:
	takedlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~takedlg();
	int m_num;
	string m_name;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
