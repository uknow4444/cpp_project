
// termDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "term.h"
#include "termDlg.h"
#include "afxdialogex.h"
#include "Board.h"
#include "butdlg.h"
#include "trippdlg.h"
#include"takedlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


template <typename T>
T add(T a, T b) {
	return a + b;
}

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtermDlg 대화 상자



CtermDlg::CtermDlg(CWnd* pParent /*=nullptr*/)//변수 초기화
	: CDialogEx(IDD_TERM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pRect= CRect(0, 0, 800, 800);
	m_BackRt= CRect(0, 0, 910, 800); 
	srand(time(NULL));
	m_turn = 0;
	m_cnt = 0;
}

void CtermDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtermDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_STN_CLICKED(IDC_picture, &CtermDlg::OnStnClickedpicture)
	ON_BN_CLICKED(IDC_BUTTON1, &CtermDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtermDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

void CtermDlg::changefont() {//글자 바꾸기
	CFont ex;
	ex.CreateFont(40, 10, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, _T("Arial"));
	GetDlgItem(IDC_STATIC1)->SetFont(&ex);
//	GetDlgItem(IDC_STATIC_2)->SetFont(&ex);
}

void CtermDlg::playerpicture() {//플레이어 그림그리기
	CWindowDC wc(NULL);
	
	m_BackBit.CreateCompatibleBitmap(&wc, m_BackRt.Width(), m_BackRt.Height());
	m_BackDc.CreateCompatibleDC(&wc);
	m_BackDc.SelectObject(&m_BackBit);
	m_diebit.CreateCompatibleBitmap(&wc, 185, 341);
	m_diedc.CreateCompatibleDC(&wc);
	m_diedc.SelectObject(&m_diebit);
	m_pbit.CreateCompatibleBitmap(&wc, p_width*4, p_height);
	m_pdc.CreateCompatibleDC(&wc);
	m_pdc.SelectObject(&m_pbit);
	m_dicebit.CreateCompatibleBitmap(&wc, d_size * 6, d_size);
	m_dicedc.CreateCompatibleDC(&wc);
	m_dicedc.SelectObject(&m_dicebit);
	CBitmap bit;
	bit.LoadBitmap(IDB_ply1);
	CDC memdc;
	memdc.CreateCompatibleDC(&wc);
	memdc.SelectObject(&bit);

	BITMAP bm;
	bit.GetBitmap(&bm);
	m_pdc.StretchBlt(0, 0, p_width , p_height, &memdc, 0, 0, p_width, p_height, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_ply2);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_pdc.StretchBlt(p_width, 0, p_width, p_height, &memdc, 0, 0, p_width, p_height, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_ply3);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_pdc.StretchBlt(p_width*2, 0, p_width, p_height, &memdc, 0, 0, p_width, p_height, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_ply4);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_pdc.StretchBlt(p_width*3, 0, p_width, p_height, &memdc, 0, 0, p_width, p_height, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_dice1);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_dicedc.StretchBlt(0, 0, d_size, d_size, &memdc, 0, 0, d_size, d_size, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_dice2);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_dicedc.StretchBlt(d_size, 0, d_size, d_size, &memdc, 0, 0, d_size, d_size, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_dice3);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_dicedc.StretchBlt(d_size * 2, 0, d_size, d_size, &memdc, 0, 0, d_size, d_size, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_dice4);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_dicedc.StretchBlt(d_size * 3, 0, d_size, d_size, &memdc, 0, 0, d_size, d_size, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_dice5);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_dicedc.StretchBlt(d_size * 4, 0, d_size, d_size, &memdc, 0, 0, d_size, d_size, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_dice6);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_dicedc.StretchBlt(d_size * 5, 0, d_size, d_size, &memdc, 0, 0, d_size, d_size, SRCCOPY);
	
	bit.Detach();
	bit.LoadBitmap(IDB_background);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_BackDc.BitBlt(0, 0, m_BackRt.Width(), m_BackRt.Height(), &memdc, 0, 0, SRCCOPY);

	bit.Detach();
	bit.LoadBitmap(IDB_die);
	memdc.SelectObject(&bit);
	bit.GetBitmap(&bm);
	m_diedc.StretchBlt(0, 0, 185, 341, &memdc, 0, 0, 185, 341, SRCCOPY);



	m_BackDc.BitBlt(450, 470, d_size, d_size, &m_dicedc, 0, 0, SRCCOPY);//backdc 화면에 그림그려줌
	m_BackDc.BitBlt(540, 470, d_size, d_size, &m_dicedc, 0, 0, SRCCOPY);//backdc 화면에 그림그려줌
	/*m_BackDc.TransparentBlt(600, 0, p_width, p_height, &m_pdc, 0, 0, p_width, p_height, RGB(255, 255, 255));//킬때 화면에 그림그려줌
	m_BackDc.TransparentBlt(650, 0, p_width, p_height, &m_pdc, p_width, 0, p_width, p_height, RGB(255, 255, 255));//킬때 화면에 그림그려줌
	m_BackDc.BitBlt(450, 470, d_size, d_size, &m_dicedc, 0, 0, SRCCOPY);//킬때 화면에 그림그려줌
	m_BackDc.BitBlt(540, 470, d_size, d_size, &m_dicedc, 0, 0, SRCCOPY);
	Invalidate(FALSE);*/
}

// CtermDlg 메시지 처리기

BOOL CtermDlg::OnInitDialog()//시작할 때 자동실행
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	string s;
	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	SetDlgItemInt(IDC_STATIC1, b.player[0].getMoney());
	SetDlgItemInt(IDC_STATIC2, b.player[1].getMoney());
	SetDlgItemInt(IDC_STATIC3, b.player[2].getMoney());
	SetDlgItemInt(IDC_STATIC4, b.player[3].getMoney());

	playerpicture();
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CtermDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CtermDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
		

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else//여기서 비트맵을 그려줘야함
	{
		
		dc.BitBlt(160, 0, m_BackRt.Width(), m_BackRt.Height(), &m_BackDc, 160, 0, SRCCOPY);//킬때 화면에 그림그려줌
	
	
		if (m_cnt != 0) {
			for (int j = 0; j < 4; j++) {
				dc.TransparentBlt(b.player[j].getPosx(), b.player[j].getPosy(), p_width, p_height, &m_pdc, p_width*j, 0, p_width, p_height, RGB(255, 255, 255));//그림에 하얀색있으면 투명화(말찍는거)
			}
		}
		
//		dc.TransparentBlt(790, 10, p_width, p_height, &m_pdc, p_width, 0, p_width, p_height, RGB(255, 255, 255));//그림에 하얀색있으면 투명화

		CDialogEx::OnPaint();
	}
	
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CtermDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtermDlg::OnEnChangeEdit10()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CtermDlg::OnStnClickedpicture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CtermDlg::move() {

	int d1 = b.dice[0].getNum(); // 주사위 1번 값
	int d2 = b.dice[1].getNum(); // 주사위 2번 값
	int sum = add(d1, d2);// 주사위 합산 값 - 템플릿 사용
	int p_num = b.turn % 4;
	

	if (b.player[p_num].getposition() == 10 && b.player[p_num].getprisoncnt() > -1) { //플레이어가 감옥이라면
		// 감옥은 총 3턴 간 못움직임.
		if (b.player[p_num].getprisoncnt() > 0) {//감옥 트라이 켓치?
			if (d1 == d2) {
				MessageBox(_T("탈출 성공(다음턴에 나올수 있습니다.)"), _T("감옥"));
				b.player[p_num].setprisoncnt(-1);
				return;
			}
			b.player[p_num].setprisoncnt((b.player[p_num].getprisoncnt())-1);
			MessageBox(_T("탈출 실패"), _T("감옥"));
			return;
		}
		else { // 감옥에서 카운트가 0이 될 경우
			MessageBox(_T("탈출 성공"), _T("감옥"));
			b.player[p_num].setprisoncnt(-1);
			return;
		}
	}
	b.player[p_num].setMovecount(sum); // 현재 플레이어의 이동거리 설정
	moveplayer(p_num); // 이동 시작
	whosland(b.turn % 4); // 현재 땅에 대한 함수 체킹
	SetDlgItemInt(IDC_STATIC1, b.player[0].getMoney());//돈보여주기
	SetDlgItemInt(IDC_STATIC2, b.player[1].getMoney());
	SetDlgItemInt(IDC_STATIC3, b.player[2].getMoney());
	SetDlgItemInt(IDC_STATIC4, b.player[3].getMoney());
}

void CtermDlg::moveplayer(int n) {//플레이어 움직이기
	CClientDC dc(this);
	int sum = b.player[n].getMovecount(); // 이동거리 확인.
	for (int i = 0; i < sum; i++) {
		b.moveif(n);
		dc.BitBlt(160, 0, m_BackRt.Width(), m_BackRt.Height(), &m_BackDc, 160, 0, SRCCOPY);//말때문에 화면 다시찍는거
	
		Sleep(100);
		for (int j = 0; j < 4; j++) {//사람수만큼 루프돌림
			dc.TransparentBlt(b.player[j].getPosx(), b.player[j].getPosy(), p_width, p_height, &m_pdc, p_width*j, 0, p_width, p_height, RGB(255, 255, 255));//그림에 하얀색있으면 투명화(말찍는거)
		}
		dc.TransparentBlt(b.player[n].getx(), b.player[n].gety(), p_width, p_height, &m_pdc, p_width*n, 0, p_width, p_height, RGB(255, 255, 255));
		Sleep(100);
		
		//처음 위치 지날 때마다 월급받기
		int who_pos = b.player[n].getposition(); // 사용자의 위치 받아오기
		if (who_pos == 0) { //사용자의 현재 배열상의 위치 중 시작일 경우
			b.zone[0]->func(b,n); // 월급받는다.
		}
	}
	b.player[n].setMovecount(0); // 움직이는 수 초기화
}

//도착한 땅에 대한 함수 수행
void CtermDlg::whosland(int n) {
	CClientDC dc(this);
	int who = b.zone[b.player[n].getposition()]->getOwner();
	Zone *sub_z = b.zone[b.player[n].getposition()];
	if (who == 0) { // 주인 없는 땅 구매
		if (b.player[n].getMoney() < sub_z->getCost()) {
			MessageBox(_T("땅 구매 불가"), _T("땅 구매"));
			return;
		}
		butdlg dlg;
		dlg.m_name = sub_z->getName() + "을 " + to_string(sub_z->getCost()) + "원에 구매하시겠습니까?";
	
		dlg.DoModal();
		
		 // 현재의 땅을 체크
		if (dlg.m_buy == 1) { // 구매하겠다고 한다면
			sub_z->setOwner(n + 1); // 현재 땅의 주인 변경
			b.player[n].addZone(*sub_z); // 플레이어의 소유땅 추가
			b.player[n].setMoney(b.player[n].getMoney() - sub_z->getCost()); // 플레이어의 소지금 변경 - *************함수 설정 필요할 듯
			addstring(n); // 문자열을 추가하는 함수
		}
	}
	else if(who == 5){ // 보드 자체적 땅일 경우   // 스타트인경우는 움직일 때 해주기 때문 여기서는 안해줌.
		sub_z->func(b, n);// 각자 고유함수 실행
		if (sub_z->getName() == "Goldkey") { // 카드 실행
			/***********************예외처리기 사용*******************/
			try {
				int x = b.player[n].getMycard().getType();
				if (x > 4) // 이동형 카드 실행시
					throw x; // 투척
				if (x == 1) // 1번 카드
					MessageBox(_T("꽝이에요 ㄲㅂ"), _T("황금카드"));
				else if (x == 2) // 2번 카드
					MessageBox(_T("주사위를 한 번 더 굴리세요!"), _T("황금카드"));
				else if (x == 3) // 3번 카드
					MessageBox(_T("운수가 좋은걸요?\n돈을 주웠습니다."), _T("황금카드"));
				else if (x == 4) { // 4번 카드
					MessageBox(_T("운수가 안좋네요.\n강도를 당해 돈을 잃었습니다."), _T("황금카드"));

				}
				b.player[n].mycardexe(b,n); // 함수 실행
				b.isalive(n);
				if (b.player[n].getAlive() == false) {
					b.zoneclear(n);
					SetDlgItemInt(IDC_STATIC1, b.player[0].getMoney());//돈보여주기
					SetDlgItemInt(IDC_STATIC2, b.player[1].getMoney());
					SetDlgItemInt(IDC_STATIC3, b.player[2].getMoney());
					SetDlgItemInt(IDC_STATIC4, b.player[3].getMoney());
					string str = "플레이어 " + to_string(n) + "님 탈락하셨습니다.";
					MessageBox(_T(str.c_str()), _T("안내"));
					dc.BitBlt(b.player[n].getdiex(), b.player[n].getdiey(), 175,341, &m_diedc, 0, 0, SRCCOPY);//죽은사람표시
					return;
				}
			}
			catch (int x) { // 이동형 카드 처리기
				if (x == 5)
					MessageBox(_T("무법지대로 가세요!"), _T("황금카드"));
				else if (x == 6)
					MessageBox(_T("경찰서로 가세요!"), _T("황금카드"));
				else if (x == 7)
					MessageBox(_T("신창으로 가세요!"), _T("황금카드"));
				else if (x == 8)
					MessageBox(_T("감옥으로 가세요!"), _T("황금카드"));
				else if (x == 9)
					MessageBox(_T("시작점으로 가세요!"), _T("황금카드"));
				else if (x == 10)
					MessageBox(_T("여행을 떠나세요!"), _T("황금카드"));
				b.player[n].mycardexe(b, n);//함수 실행
				moveplayer(n); // 이동 시작
				whosland(n); // 현재 땅에 대한 함수 체킹 
			}
		}
		else if (sub_z->getName()=="Prison") {// 감옥일 때
			MessageBox(_T("투옥되어 버렸어요"), _T("감옥"));
			return;
		}
		else if (sub_z->getName() == "TAX_O") {
			string str="경찰서에 오셨네요 "+to_string(sub_z->getPrice())+"원획득";
			
			MessageBox(_T(str.c_str()), _T("꽁 돈"));
		}
		else if (sub_z->getName() == "TAX_I") {
			b.isalive(n);
			if (b.player[n].getAlive() == false) {
				b.zoneclear(n);
				SetDlgItemInt(IDC_STATIC1, b.player[0].getMoney());//돈보여주기
				SetDlgItemInt(IDC_STATIC2, b.player[1].getMoney());
				SetDlgItemInt(IDC_STATIC3, b.player[2].getMoney());
				SetDlgItemInt(IDC_STATIC4, b.player[3].getMoney());
				string str = "플레이어 " + to_string(n+1) + "님 탈락하셨습니다.";
				MessageBox(_T(str.c_str()), _T("안내"));
				dc.BitBlt(b.player[n].getdiex(), b.player[n].getdiey(), 175, 341, &m_diedc, 0, 0, SRCCOPY);//죽은사람표시
				return;
			}

			MessageBox(_T("강도를 만났습니다.(300원 강탈당함) "), _T("스 틸"));
		}
		else if (sub_z->getName() == "Trip") {//여행
			MessageBox(_T("여행을 떠나볼까요?"), _T("여 행"));
			trippdlg dlg;
			dlg.DoModal();//여행 다이얼로그
			int r = dlg.m_radio;
			int sum;
			if (r > 30) {
				sum=r - 30;
			}
			else {
				sum = 10 + r;
			}
			b.player[n].setMovecount(sum);
			moveplayer(n); // 이동 시작
			whosland(n); // 현재 땅에 대한 함수 체킹 

		}
	}
	else { // 누군가 소유중인 땅인 경우
		if (who == (n + 1)) { // 플레이어와 땅주인이 같다면
		}
		else { // 플레이어와 땅주인이 다르다면
			MessageBox(_T("입장료 내세요"), _T("안내"));
			b.player[n].setMoney(b.player[n].getMoney() - sub_z->getCost());
			b.player[who - 1].setMoney(b.player[n].getMoney() + sub_z->getCost());
			b.isalive(n);
			if (b.player[n].getAlive()==false) {
				SetDlgItemInt(IDC_STATIC1, b.player[0].getMoney());//돈보여주기
				SetDlgItemInt(IDC_STATIC2, b.player[1].getMoney());
				SetDlgItemInt(IDC_STATIC3, b.player[2].getMoney());
				SetDlgItemInt(IDC_STATIC4, b.player[3].getMoney());
				b.zoneclear(n);
				string str = "플레이어 " + to_string(n+1) + "님 탈락하셨습니다.";
				MessageBox(_T(str.c_str()), _T("안내"));
				dc.BitBlt(b.player[n].getdiex(), b.player[n].getdiey(), 175, 341, &m_diedc, 0, 0, SRCCOPY);//죽은사람표시
				return;
			}
			if (b.player[n].getMoney() < sub_z->getCost()) {//인수 할돈이 없을 때
				MessageBox(_T("땅 인수 불가"), _T("땅 인수"));
				return;
			}
			takedlg dlg;
			dlg.m_name = sub_z->getName();
			dlg.DoModal();
			if (dlg.m_num == 1) {
				b.take(sub_z->getName(), (who - 1), n);
				sub_z->setOwner(n + 1);
				b.player[n].setMoney(b.player[n].getMoney() -sub_z->getCost());
				b.player[who - 1].setMoney(b.player[n].getMoney() + sub_z->getCost());
				addstring(n);
				addstring((who - 1));
			}
			
		}
	}
}

//소유땅의 이름을 통합하여 저장하는 함수
void CtermDlg::addstring(int n) {
	string sub_s = ""; // 문자열을 통합할 변수
	string sub_s2;
	int sub_size = b.player[n].getMylandlength(); // 소유 땅의 개수를 확인
	//소유땅들의 목록을 합친다.
	for (int i = 0; i < sub_size; i++) {
		sub_s2 = sub_s;
		sub_s = sub_s2 + b.player[n].getMyland(i).getName() + "\r\n";
	}
	CString a = _T(sub_s.c_str());
	if(n == 0)
		SetDlgItemText(IDC_EDIT2, a);
	else if (n == 1)
		SetDlgItemText(IDC_EDIT8, a);
	else if (n == 2)
		SetDlgItemText(IDC_EDIT5, a);
	else if (n == 3)
		SetDlgItemText(IDC_EDIT11, a);
}

void CtermDlg::isalive() {
	int sum = 0;
	int n = 0 ;
	for (int i = 0; i < 4; i++) {
		if (b.player[i].getAlive() == false) {
			sum++;
		}
		else {
			n = i;
		}
	}
	if (sum >= 3) {
		string str = "플레이어  " + to_string(n) + "승리";

		MessageBox(_T(str.c_str()), _T("게임 끝"));
		SendMessage(WM_CLOSE, 0, 0);
	}
}

void CtermDlg::OnBnClickedButton1()//주사위 굴리기
{
	if (m_cnt == 0)return;
	CClientDC dc(this);
	int n = b.turn % 4;
	int m = (b.turn + 1) % 4;//플레이어 차례때문에 해줌
	while (b.player[n].getAlive() == false) {//죽으면 그턴은 넘겨야해서만듬
		b.turn++;
		n = b.turn % 4;
	}
	
	
	/*dc.BitBlt(b.player[m].getx(), b.player[m].gety(), p_width, p_height, &m_BackDc, b.player[m].getx(), b.player[m].gety(), SRCCOPY);
	dc.TransparentBlt(b.player[n].getx(), b.player[n].gety(), p_width, p_height, &m_pdc, p_width*n, 0, p_width, p_height, RGB(255, 255, 255));
	Sleep(500);*/
	//int j = 0,k=0;
	for (int i = 0; i < 6; i++) {
		//j = rand() % 6;

		b.dice[0].Roll();
		dc.BitBlt(450, 470, d_size, d_size, &m_dicedc, (b.dice[0].getNum()-1) *d_size,0, SRCCOPY);
		
		//k = rand() % 6;
		b.dice[1].Roll();
		dc.BitBlt(540, 470, d_size, d_size, &m_dicedc,( b.dice[1].getNum()-1) *d_size, 0, SRCCOPY);
		m_BackDc.BitBlt(450, 470, d_size, d_size, &m_dicedc, (b.dice[0].getNum() - 1) *d_size, 0, SRCCOPY);
		m_BackDc.BitBlt(540, 470, d_size, d_size, &m_dicedc, (b.dice[1].getNum() - 1) *d_size, 0, SRCCOPY);

		Sleep(300);

	}
	
	move(); // 실행함수
	if (b.dice[0].getNum() == b.dice[1].getNum() && b.player[b.turn%4].getposition() != 10) {//더블이면 다시하기 + 감옥이면 빼기
		MessageBox(_T("더블!! 주사위를 한 번 더 굴리세요."), _T("행운!"));
		return;
	}
	dc.BitBlt(b.player[n].getx(), b.player[n].gety(), p_width, p_height, &m_BackDc, b.player[n].getx(), b.player[n].gety(), SRCCOPY);//차례를 알려주기위한 것(말초기화
	dc.TransparentBlt(b.player[m].getx(), b.player[m].gety(), p_width, p_height, &m_pdc, p_width*m, 0, p_width, p_height, RGB(255, 255, 255));// 차례를 알려주기위한 것(플레이어차례
	isalive();
	b.turn++;
	//	Invalidate(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void CtermDlg::OnBnClickedButton2()//시작버튼
{
	
	if (m_cnt != 0) {//처음 판모양 저장
		return;
	}

	CClientDC dc(this);
	m_BackDc.BitBlt(0, 0, m_BackRt.Width(), m_BackRt.Height(), &dc, 0, 0, SRCCOPY);
	m_cnt++;
	dc.TransparentBlt(b.player[0].getx(), b.player[0].gety(), p_width, p_height, &m_pdc,0, 0, p_width, p_height, RGB(255, 255, 255));// 차례를 알려주기위한 것(플레이어차례
	for (int i = 0; i < 4; i++) {
		dc.TransparentBlt(790+(i*6), 620+(i*6), p_width, p_height, &m_pdc, p_width*i, 0, p_width, p_height, RGB(255, 255, 255));//그림에 하얀색있으면 투명화
	}
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
