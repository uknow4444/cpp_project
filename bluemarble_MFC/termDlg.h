#include "Board.h"
// termDlg.h: 헤더 파일
//

#pragma once


// CtermDlg 대화 상자
class CtermDlg : public CDialogEx
{
private://변수들
	CDC m_BackDc, m_UnitDc, m_bgdc,m_pdc,m_dicedc,m_diedc;
	CBitmap m_BackBit, m_UnitBit, m_bgbit,m_pbit, m_dicebit,m_diebit;
	CRect m_BackRt, m_UnitRt, m_bgrt, m_pRect;//박스생성
	int m_turn,m_cnt;//차례
	Board b;
// 생성입니다.
public:
	CtermDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	void moveplayer(int n);//말 움직이는 함수 - move내부
	void playerpicture();//플레이어 사진추가
	void changefont();//폰트 바꾸기
	void whosland(int n);//땅주인 찾기
	void move();// 게임 진행
	void isalive();//게임오버확인
	void addstring(int n);
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit10();
	afx_msg void OnStnClickedpicture();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
