#pragma once
#include<iostream>
using namespace std;
// butdlg 대화 상자

class butdlg : public CDialogEx
{
	DECLARE_DYNAMIC(butdlg)

public:
	butdlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~butdlg();
	int m_buy;//산지 안산지 체크
	string m_name;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual INT_PTR DoModal();
	afx_msg void OnStnClickedpicture();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
