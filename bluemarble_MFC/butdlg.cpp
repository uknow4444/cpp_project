// butdlg.cpp: 구현 파일
//
#include "termDlg.h"
#include "stdafx.h"
#include "term.h"
#include "butdlg.h"
#include "afxdialogex.h"


// butdlg 대화 상자

IMPLEMENT_DYNAMIC(butdlg, CDialogEx)

butdlg::butdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_buy = 0;
}

butdlg::~butdlg()
{
}

void butdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(butdlg, CDialogEx)
	ON_STN_CLICKED(IDC_picture, &butdlg::OnStnClickedpicture)
	ON_BN_CLICKED(IDC_BUTTON2, &butdlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &butdlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// butdlg 메시지 처리기


INT_PTR butdlg::DoModal()
{
	


	return CDialogEx::DoModal();
}


void butdlg::OnStnClickedpicture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void butdlg::OnBnClickedButton2()
{
	m_buy = 2;
	
	SendMessage(WM_CLOSE, 0, 0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void butdlg::OnBnClickedButton1()
{
	m_buy = 1;
	SendMessage(WM_CLOSE, 0, 0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL butdlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemText(IDC_STATIC, m_name.c_str());
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
