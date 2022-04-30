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
#define CONST 17 //  일반 변수

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

// BIT 연산자 및 논리연산자
#define BOOLO 50 // 논리 OR ||
#define BOOLN 51 // 논리 AND &&
#define EQUALS 52 // 논리 EQUALS ==
#define NEQUALS 53 // 논리 NOT-EQUALS !=
#define OR 54 // BIT OR |
#define AND 55 // BIT AND &
#define XOR 56 // BIT Exclusive-OR ^
#define NOT 57 // BIT NOT !

#define ERROR 4444 //ERROR 발생 코드
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

				구문 분석기
				 (선언부)

******************************************/
int token_pos; // 현재 확인 중인 토큰의 위치 파악
int func_size; // 현재 생성된 함수의 개수
tokens sub_tokens; // 토큰 임시 저장
class def_fun{
public:
	string name; // 함수의 이름
	vector<tokens> tovec; // 토큰이 저장됨.
};
vector<def_fun> defvec; // 함수들이 나뉘어 저장.
void pasing(); // 구문 분석기 실행 함수
void nexttoken(); // 다음 토큰을 받는 함수
void addfunctoken(); // 토큰을 현재 구문 분석중인 함수에 추가하기.
bool func_def(); // 함수
bool def_main(); // 메인함수
bool stmt_line(); // 문장 한줄
bool stmt();
bool expr();
bool or_expr();
bool xor_expr();
bool and_expr();
bool assign_expr();
bool term();
bool factor();
bool var_ident();
bool def_ident(); // 정의함수
bool def_params(); // 함수 매개변수





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
		if (type_check == ERROR) {
			cout << error_s << endl;
			break;
		}
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
		store += nextc; // 상수가 불러와진다.
		nextchar(); // 다음문자 받아오기
		// 정해진 변수 타입 확인
		if (nextc == 'b'); //  2진수.
		//else if(nextc != 'x')  *** 16진수 나중에 구현하기 ***
		else if (nextc == '\n') return CONST; // 일반 상수 반환
		else {
			error_s = "상수 선언 에러";
			return ERROR;
		}
		//BINARY 상수 구분
		store += nextc;
		nextchar();
		//정해진 변수타입인 경우에만
		while (chartype == DIGIT) {
			if (nextc == '0' || nextc == '1') { // 0과 1만 입력받기.
				store += nextc;
				nextchar(); // 다음문자 받아오기
			}
			else {
				error_s = "상수 선언 에러";
				return ERROR;
			}
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
		if (nextc == '=') {
			store += nextc;
			nextchar(); // 다음 글자
			return EQUALS;
		}
		else
			return ASSIGN;
	case ',':
		return COMMA;
	case '\t':
		return HT;
	case '\n':
		return LF;
	case ':':
		return COLON;
	case '|':
		if (nextc == '|') {
			store += nextc;
			nextchar(); // 다음 글자
			return BOOLO;
		}
		else
			return OR;
	case '&':
		if (nextc == '&') {
			store += nextc;
			nextchar(); // 다음 글자
			return BOOLN;
		}
		else
			return AND;
	case '!':
		if (nextc == '=') {
			store += nextc;
			nextchar(); // 다음 글자
			return NEQUALS;
		}
		else
			return NOT;
	case '^':
		return XOR;
	default :
		error_s = "사용하지 않는 토큰";
		return ERROR;
	}
}


/*****************************************

				구문 분석기
				 (정의부)

*******************************************/
// 구문 분석기 실행 함수
void pasing() {
	token_pos = 0; // 토큰 확인 초기 위치 초기화
	func_size = -1; // 생성된 함수 개수 초기화
	// 토큰을 전부 확인할 때까지 반복
	while (lexer.size() <= token_pos) {
		if (!func_def()) { // 구문 오류 발생 시
			cout << "구문 오류 발생" << endl;
			break;
		}
	}
}
// 다음 토큰을 받는 함수
void nexttoken() {
	sub_tokens = lexer.at(token_pos++);
}
// 토큰을 현재 구문 분석중인 함수에 추가하기.
void addfunctoken() {
	defvec.at(func_size).tovec.push_back(sub_tokens);
}
// 함수
bool func_def() {
	/*
			EBNF :
			func_def	->		'def' ('main'|<def_name>)
			main과 정의된 함수를 구분지어 호출.
	*/
	func_size++; // 생성된 함수 추가
	def_fun df;
	defvec.push_back(df); // 함수 모음집에 함수 객체 추가
	vector<tokens> sub_def;
	nexttoken(); // 다음 토큰
	if (sub_tokens.type == DEF) { // 첫 토큰이 함수 정의를 의미 함
		addfunctoken(); // 현재 def 토큰 추가
		nexttoken(); // 다음 토큰
		if (sub_tokens.type == MAIN)  //  두번째 토큰이 MAIN임
			return def_main(); // main 추가 파서로
		else if (sub_tokens.type == IDENT)  // 두번째 토큰이 식별자임
			return def_ident(); // 함수 추가 파서로
		else
			return false;
	}
	else
		return false;
}


bool def_main() {
	/*
			EBNF :
			def_main	->		':' '\n'  {'\t' <stmt> '\n'}+
			콜론과 뉴라인 검사 후 stmt_line 호출.
	*/
	defvec.at(func_size).name = "main"; // 함수명 main 지정
	addfunctoken(); // main 추가.
	nexttoken(); // 다음 토큰
	if (sub_tokens.type == COLON) { // main 다음 토큰이 ':'이 맞다면
		addfunctoken(); // 토큰 추가
		nexttoken(); // 다음 토큰
		if (sub_tokens.type == LF) { // 다음이 개행문자가 맞다면
			addfunctoken(); // 토큰 추가
			nexttoken(); // 다음 토큰
			return stmt_line(); // stmt_line 호출
		}
		else
			return false;
	}
	else
		return false;
	return true;
}
// 문장 한줄
bool stmt_line() {
	/*
			EBNF :
			stmt_line	->		{\t<stmt>\n}+
	*/
	while (sub_tokens.type == HT) { // 다음토큰이 탭이라면 반복하라.
		addfunctoken(); // \t 토큰을 추가
		nexttoken(); // 다음 토큰
		if (sub_tokens.type == LF) {  //다음 토큰이 개행문자라면
			addfunctoken(); // \n 토큰을 추가
			nexttoken(); // 다음 토큰
		}
		else if(!stmt()) // 아니라면 stmt 실행
			return false;
		else {// stmt 실행 후 문제가 없다면
			nexttoken(); //다음 토큰
			if (sub_tokens.type == LF) { //다음 토큰이 개행문자라면
				addfunctoken(); // \n 토큰을 추가
				nexttoken(); // 다음 토큰
			}
		}
	}
	return true;
}
bool stmt() {
	/*
			EBNF :
			stmt_line	->		<expr> {<boolo_op> <expr>}
	*/
	if (!expr())
		return false;
}
bool expr() {
	/*
			EBNF :
			expr		->		<or_expr> {<booln_op> <or_expr>}
	*/
	if (!or_expr())
		return false;
}
bool or_expr() {
	/*
			EBNF :
			or_expr		->		<xor_expr>{<or_op> <xor_expr>}
	*/
	if (!xor_expr())
		return false;
}
bool xor_expr() {
	/*
			EBNF :
			xor_expr		->		<and_expr>{<xor_op><and_expr>}
	*/
	if (!and_expr())
		return false;
}
bool and_expr() {
	/*
			EBNF :
			and_expr		->		<assign_expr>{<and_op><assign_expr>}
	*/
	if (!assign_expr())
		return false;
	nexttoken(); // 다음 토큰
	//if (sub_tokens.type == );
}
bool assign_expr() {
	/*
			EBNF :
			assign_expr		->		<term>{<assign_op><stmt>}
	*/
	if (!term())
		return false;
	nexttoken();// 다음 토큰
	if (sub_tokens.type == ASSIGN) {// 대입연산자가 다음 토큰이라면
		addfunctoken(); // = 토큰 추가
		nexttoken();// 다음 토큰
		if (!stmt()) // stmt 호출
			return false;
	}
	return true;
}
bool term() {
	/*
			EBNF :
			term			->		(<factor> | var_ident | function)
	*/
	bool re; //에러확인, 반환용 변수
	if (sub_tokens.type == VAR) // 변수 선언부인가
		re = var_ident();
	else if (sub_tokens.type == IDENT || sub_tokens.type == BINARY) // 변수 또는 상수인가
		re = factor();
	return re;
}
bool factor() {
	/*
			EBNF :
			factor			->		<ident> | const
	*/
	addfunctoken(); // 현재 토큰을 추가
	return true;
}
bool var_ident() {
	/*
			EBNF :
			var_ident			->		var <ident>
	*/
	addfunctoken(); // var 토큰을 추가
	nexttoken(); // 다음 토큰
	if (sub_tokens.type == IDENT) { // 다음토큰이 식별자라면
		addfunctoken(); //현재 토큰을 추가
		return true; // 문제없음 반환
	}
	else
		return false; // 오류
}
bool def_ident() {
	return true;
}
bool def_params() {
	return true;
}
