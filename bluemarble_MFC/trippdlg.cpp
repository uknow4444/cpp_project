// trippdlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "term.h"
#include "trippdlg.h"
#include "afxdialogex.h"
#include "termDlg.h"

// trippdlg 대화 상자

IMPLEMENT_DYNAMIC(trippdlg, CDialogEx)

trippdlg::trippdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	m_radio = -1;
}

trippdlg::~trippdlg()
{
}

void trippdlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Radio(pDX, IDC_RADIO7, m_radio);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(trippdlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &trippdlg::OnBnClickedOk)
	
END_MESSAGE_MAP()


// trippdlg 메시지 처리기


void trippdlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
