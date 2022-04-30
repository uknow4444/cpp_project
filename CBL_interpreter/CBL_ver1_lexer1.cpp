#include<iostream>
#include<fstream> // 파일 입출력 헤더파일 추가
#include<vector> // 토큰들을 저장하고 각 변수타입 등을 저장할 변수.
#include<string>

using namespace std;

int depth; // 현재 수준을 확인해줄 변수


//변수를 저장하는 클래스
class var {
public:
	int depth; // 변수의 참조 수준 저장
	string name; // 변수의 이름을 저장
	bool binary[]; // 2진 데이터를 저장할 참조변수
	var(int depth, string s); // 생성자, 데이터 토큰을 받아와 값을 대입한다.
};





ifstream file_in; // 파일 입력 객체
ofstream file_out; // 파일 출력 객체



void fileopen(); // 파일을 여는 함수
void fileclose(); // 파일을 닫는 함수
void result_print(); // 결과 출력함수



/*****************************************

				어휘 분석기
				 (선언부)

******************************************/

// 첫글자 판단
#define LETTER 0 // 글자
#define DIGIT 1 // 숫자
#define OTHER 2 // 그 외

// 함수 및 변수
#define VAR 10 // 변수선언임을 표시
#define DEF 11 // 함수선언임을 표시
#define IDENT 12 // 함수 변수들의 이름이자 식별자.
#define COLON 13 // 콜론
#define MAIN 14 // MAIN 함수
#define BINARY 15 // 2진수의 상수

//연산자 타입 정의
#define ADD 40 // 더하기 +
#define SUB 41 // 빼기 -
#define MULT 42 // 곱하기 *
#define DIV 43 // 나누기 /
#define PAR_IN 44 // 괄호 (
#define PAR_OUT 45 // 괄호 )
#define ASSIGN 46 //  대입연산자 =
#define COMMA 47 // 콤마 ,
#define HT 48 // \t, 탭
#define LF 49 // \n, 개행문자.
// + 비트연산자 추가해야함.
// + 비교연산자 추가해야함.

#define ERROR 4444; //ERROR 발생 코드
string error_s; // 에러발생 코드를 저장할 변수


//토큰을 저장하는 클래스
class tokens {
public:
	int type;
	string token;
};
//어휘분석기 변수
vector<tokens> lexer; // 토큰을 저장해둘 변수.
char nextc; // 파일에서 글자를 읽어와 임시 저장할 변수
int chartype; // 파일에서 읽어온 글자를 판단해주는 함수.
string store; // 토큰을 생성하기 전에 임시로 토큰을 저장할 변수.

//어휘분석기 함수
void Lexer(); // 어휘분석기를 실행하는 함수.
int lex(); // 어휘분석기
void nextchar(); // 다음 문자 유형을 결정하는 함수.
void check_mean(); // 의미를 확인하는 함수, 공백문자만을 제거하고, 줄이 바뀐것을 확인한다.
int lookup(); // 연산자와 괄호를 조사하여 그 토큰을 반환하는 함수.










/*****************************************

				MAIN 함수

******************************************/
int main() {
	fileopen(); // 파일열기
	Lexer();
	fileclose(); // 파일닫기
}



//파일입출력 조절 함수들

void fileopen() {
	file_in.open("sourcecode.txt");
	file_out.open("result.txt");
}

void fileclose() {
	file_in.close();
	file_out.close();
}
void result_print() {

}


/*****************************************

				어휘 분석기
				 (정의부)

*******************************************/
// 어휘분석기를 실행하여 나온 토큰에 대해 타입 확인 및 저장하는 함수.
void Lexer() {
	//lex가 EOF를 반환하기 전까지 수행.
	int type_check;
	nextchar();
	while ((type_check = lex()) != EOF) {
		tokens n_token;
		n_token.type = type_check;
		n_token.token = store;
		lexer.push_back(n_token);
		store = ""; // store 초기화
	}
	for (tokens t : lexer) {
		cout << "Next token is : " << t.type;
		cout << " Next lexeme is : " << t.token << endl;
	}
	cout << "END LEXER" << endl;
}
// 어휘분석기
int lex() {
	check_mean();
	switch (chartype) {
	case LETTER:
		store += nextc; // 현재 문자 저장.
		nextchar(); // 다음문자 받아오기
		while (chartype == LETTER || chartype == DIGIT) {
			store += nextc;
			nextchar(); // 다음문자 받아오기
		}
		if (store == "def") // 함수라면
			return DEF;
		else if (store == "var") // 변수라면
			return VAR;
		else if (store == "main") // main이라는 예약어라면
			return MAIN;
		else // 그외 문자라면
			return IDENT; // 식별자로 구분
		break;
	case DIGIT:
		store += nextc; // 0이 불러와진다.
		nextchar(); // 다음문자 받아오기
		// 정해진 변수 타입 확인
		if (nextc == 'b');
		//else if(nextc != 'x')  *** 나중에 구현하기 ***
		else
			return ERROR;
		//정해진 변수타입인 경우에만
		while (chartype == LETTER || chartype == DIGIT) {
			store += nextc;
			nextchar(); // 다음문자 받아오기
		}
		return BINARY; // 상수 임을 반환.
		break;
	case OTHER :
		store += nextc; // 현재 문자 추가.
		return lookup();
		break;
	case EOF: // EOF반환.
		return EOF;
		break;
	}
}
// 다음 문자 유형을 결정하는 함수.
void nextchar() {
	nextc = file_in.get(); // 한글자 읽기
	if (nextc != EOF) {//파일 끝이 아니라면
		if (isalpha(nextc)) // 알파벳일 경우
			chartype = LETTER; // 글자 타입 지정
		else if (isdigit(nextc)) // 숫자일 경우
			chartype = DIGIT; // 숫자 타입 지정
		else // 그외
			chartype = OTHER; // 그 외 타입으로 지정
	}
	else
		chartype = EOF;
}
//의미를 찾을 때까지 반복하는 함수. 의미가 없는 공백문자(0)만을 제거한다.
void check_mean(){
	//공백문자가 아닐 때까지 다음 글자를 부른다.
	while (nextc == 32) nextchar();
}
// 연산자와 괄호를 조사하여 그 토큰을 반환하는 함수.
int lookup() {
	char sub_c = nextc;
	nextchar();
	switch (sub_c) {
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MULT;
	case '/':
		return DIV;
	case '(':
		return PAR_IN;
	case ')':
		return PAR_OUT;
	case '=':
		return ASSIGN;
	case ',':
		return COMMA;
	case '\t':
		return HT;
	case '\n':
		return LF;
	case ':':
		return COLON;
	}
}
