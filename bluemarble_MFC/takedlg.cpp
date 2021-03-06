// takedlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "term.h"
#include "takedlg.h"
#include "afxdialogex.h"
#include"termDlg.h"

// takedlg 대화 상자

IMPLEMENT_DYNAMIC(takedlg, CDialogEx)

takedlg::takedlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
	m_num = 0;
}

takedlg::~takedlg()
{
}

void takedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(takedlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &takedlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &takedlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// takedlg 메시지 처리기


BOOL takedlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetDlgItemText(IDC_STATIC, m_name.c_str());
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void takedlg::OnBnClickedOk()
{
	m_num = 1;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void takedlg::OnBnClickedCancel()
{
	m_num = 2;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}
