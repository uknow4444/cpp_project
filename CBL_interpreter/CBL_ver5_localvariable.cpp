#include<iostream>
#include<fstream> // 파일 입출력 헤더파일 추가
#include<vector> // 토큰들을 저장하고 각 변수타입 등을 저장할 변수.
#include<string>
#include<Windows.h>

using namespace std;




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
#define PRINT 18 // 출력함수 구현

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
bool assign_expr();
bool boolo_expr();
bool booln_expr();
bool or_expr();
bool xor_expr();
bool and_expr();
bool equals_expr();
bool term();
bool factor();
bool var_ident();
bool def_ident(); // 정의함수
bool def_params(); // 함수 매개변수





/*****************************************

				  해석기
				 (선언부)

******************************************/

int depth; // 현재 수준을 확인해줄 변수
int main_pos; // main 함수의 위치를 확인할 변수
int main_size; // main 함수의 토큰 개수 확인.
int inter_pos; // 인터프리터용 현재 확인중인 pos
int callf; // 호출중인 함수개수
int callf_pos; // 호출중인 함수 위치
tokens inter_token; // 인터프리터용 서브토큰
tokens ident_token; // 식별자 토큰을 임시저장하는 토큰
tokens func_token; // 실행중인 함수의 토큰을 임시저장.
//변수를 저장하는 클래스
class var {
public:
	string name; // 변수의 이름을 저장
	bool binary[8]; // 2진 데이터를 저장할 참조변수
};

class callf_vec {
public:
	int depth; // 이 함수 실행의 깊이
	int call_pos; // 이 함수에서 실행된 토큰의 개수
	vector<tokens> tovec; // 함수의 토큰을 복사 저장.
};

vector<vector<var>> memory; // 메모리공간
vector<callf_vec> callfvec; // 실행중인 함수.
void interpreter(); // 인터프리터
void search_main(); // main 함수 찾기
void inter_next(); // 다음 토큰
void memory_alloc(); // 변수 할당
void var_assign(); // 변수에 값 할당.
void var_print(); // 메인에서의 출력함수.
void call_func(); // 함수호출
void search_func(); // 함수찾기
void func_next(); // 실행함수에서의 다음 토큰
void func_alloc(); // 함수 변수 할당
void func_assign(); // 함수 변수 값 할당
void call_print(); // 함수에서의 출력함수.












/*****************************************

				MAIN 함수

******************************************/
int main() {
	fileopen(); // 파일열기
	Lexer();
	pasing();
	interpreter();
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
		else if (store == "print") // print라는 출력함수라면
			return PRINT;
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
	while (lexer.size() > token_pos) {
		if (!func_def()) { // 구문 오류 발생 시
			cout << "구문 오류 발생" << endl;
			break;
		}
	}
	cout << endl << endl << endl;
	for (def_fun dfs : defvec) {
		cout << dfs.name << endl;
		for (tokens t : dfs.tovec) {
			cout << "Next token is : " << t.type;
			cout << " Next lexeme is : " << t.token << endl;
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
	while(sub_tokens.type != DEF) // 현재 토큰이 개행문자라면
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
			if (sub_tokens.type == LF) { //다음 토큰이 개행문자라면
				addfunctoken(); // \n 토큰을 추가
				if (lexer.size() == token_pos) break; // 모든 토큰을 다 돌았다면 반복 종료.
				nexttoken(); // 다음 토큰
			}
		}
		if (lexer.size() == token_pos) break; // 모든 토큰을 다 돌았다면 반복 종료.
	}
	return true;
}
bool stmt() {
	/*
			EBNF :
			stmt		->		(<not_op><assign_expr>  | <assign_expr>)
	*/
	if (sub_tokens.type == NOT) {
		addfunctoken(); // 부정연산자 토큰 추가
		nexttoken(); //  다음 토큰
	}
	if (!assign_expr())
		return false;
}
bool assign_expr() {
	/*
			EBNF :
			assign		->		<boolo_expr> {<assign_op> <boolo_expr>}
	*/
	if (!boolo_expr())
		return false;
	if (sub_tokens.type == ASSIGN) {// ASSIGN연산자가 다음 토큰이라면
		addfunctoken(); // = 토큰 추가
		nexttoken();// 다음 토큰
		if (!boolo_expr()) // boolo_expr 호출
			return false;
	}
	return true;
}
bool boolo_expr() {
	/*
			EBNF :
			boolo_expr	->		<booln_expr> {<boolo_op> <booln_expr>}
	*/
	if (!booln_expr())
		return false;
	if (sub_tokens.type == BOOLO) {// BOOLO연산자가 다음 토큰이라면
		addfunctoken(); // || 토큰 추가
		nexttoken();// 다음 토큰
		if (!booln_expr()) // booln_expr 호출
			return false;
	}
	return true;
}
bool booln_expr() {
	/*
		EBNF :
		booln_expr	->		<or_expr> {<booln_op> <or_expr>}
*/
	if (!or_expr())
		return false;
	if (sub_tokens.type == BOOLN) {// BOOLN연산자가 다음 토큰이라면
		addfunctoken(); // && 토큰 추가
		nexttoken();// 다음 토큰
		if (!or_expr()) // or_expr 호출
			return false;
	}
	return true;
}
bool or_expr() {
	/*
			EBNF :
			or_expr		->		<xor_expr>{<or_op> <xor_expr>}
	*/
	if (!xor_expr())
		return false;
	if (sub_tokens.type == OR) {// OR연산자가 다음 토큰이라면
		addfunctoken(); // = 토큰 추가
		nexttoken();// 다음 토큰
		if (!xor_expr()) // xor_expr 호출
			return false;
	}
	return true;
}
bool xor_expr() {
	/*
			EBNF :
			xor_expr		->		<and_expr>{<xor_op><and_expr>}
	*/
	if (!and_expr())
		return false;
	if (sub_tokens.type == XOR) {// OR연산자가 다음 토큰이라면
		addfunctoken(); // = 토큰 추가
		nexttoken();// 다음 토큰
		if (!and_expr()) // and_expr 호출
			return false;
	}
	return true;
}
bool and_expr() {
	/*
			EBNF :
			and_expr		->		<equals_expr>{<and_op><equals_expr>}
	*/
	if (!equals_expr())
		return false;
	if (sub_tokens.type == AND) {// AND연산자가 다음 토큰이라면
		addfunctoken(); // & 토큰 추가
		nexttoken();// 다음 토큰
		if (!equals_expr()) // equals_expr 호출
			return false;
	}
	return true;
}
bool equals_expr() {
	/*
			EBNF :
			equals_expr		->		<term>{<equals_op><stmt>}
	*/
	if (!term())
		return false;
	nexttoken();// 다음 토큰
	if (sub_tokens.type == EQUALS || sub_tokens.type == NEQUALS) {// 관계연산자가 다음 토큰이라면
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
	else if (sub_tokens.type == IDENT || sub_tokens.type == BINARY || sub_tokens.type == CONST) // 변수 또는 상수인가
		re = factor();
	else if (sub_tokens.type == PRINT) { // 출력함수라면
		re = true;
		addfunctoken();
		nexttoken();// par_in
		if (sub_tokens.type == PAR_IN) {
			addfunctoken();
			nexttoken(); // ident
			if (sub_tokens.type == IDENT) {
				addfunctoken();
				nexttoken();
				if (sub_tokens.type == PAR_OUT) {
					addfunctoken();
				}
				else false;
			}
			else false;
		}
		else false;
	}
	else
		return false;
	return re;
}
bool factor() {
	/*
			EBNF :
			factor			->		<ident> | const
	*/
	addfunctoken(); // 현재 토큰을 추가
	if (sub_tokens.type == IDENT) { // 함수호출이 옳은지 확인.
		nexttoken();
		if (sub_tokens.type == PAR_IN) {
			addfunctoken();
			nexttoken();
			if (sub_tokens.type == PAR_OUT) {
				addfunctoken();
			}
		}
		else {
			token_pos--;
		}
	}
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
	defvec.at(func_size).name = sub_tokens.token; // 함수명 main 지정
	addfunctoken(); // defname 추가.
	nexttoken(); // 다음 토큰
	if (sub_tokens.type == COLON) { // def_name 다음 토큰이 ':'이 맞다면
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
bool def_params() {
	return true;
}





/*****************************************

				  해석기
				 (정의부)

******************************************/
//인터프리터
void interpreter() {
	depth = 0;
	main_pos = 0;
	inter_pos = 0;
	callf = 0;
	search_main(); // 메인함수가 저장된 곳 확인
	main_size = defvec.at(main_pos).tovec.size(); // main 함수 token개수 저장
	cout << "main 함수 실행" << endl << endl;
	inter_next();// 다음 토큰
	if (inter_token.type == DEF) inter_next(); // def 토큰일 경우 다음
	if (inter_token.type == MAIN) inter_next(); // MAIN 토큰일 경우 다음
	if (inter_token.type == COLON) inter_next(); // COLON 토큰일 경우 다음 -> 개행문자
	while (main_size != inter_pos) {
		inter_next(); // 다음토큰
		if (inter_token.type == VAR) // VAR를 발견하엿을 경우.
			memory_alloc(); // 변수 메모리영역 할당.
		else if (inter_token.type == ASSIGN)// 대입문일 경우.
			var_assign(); // 변수에 값 할당.
		else if (inter_token.type == IDENT) {// LHS가 식별자라면
			sub_tokens = inter_token;
			inter_next(); // 다음 토큰
			if (inter_token.type == PAR_IN) {
				call_func();
			}
			else
				inter_pos--; // 전에 토큰으로.
		}
		else if (inter_token.type == PRINT) // 출력함수라면
			var_print();
	}
	cout << endl << endl;
	cout << "main 함수 종료" << endl;
}
// 메인함수 찾기
void search_main() {
	for (def_fun dfs : defvec) {
		if (dfs.name == "main")
			break;
		main_pos++;
	}
}
// 인터프리터 다음 토큰
void inter_next() {
	inter_token = defvec.at(main_pos).tovec.at(inter_pos++);
}
// 변수 할당
void memory_alloc() {
	inter_next(); //var를 발견시 다음 항목 불러오기
	if (memory.size() != depth + 1) { // 현재 깊이의 메모리영역이 없다면
		memory.push_back(*(new vector<var>())); // 메모리 영역 추가
	}
	ident_token = inter_token; // 현재 변수이름 임시보관.
	memory.at(depth).push_back(*(new var()));
	memory.at(depth).at(memory.at(depth).size() - 1).name = inter_token.token;
	cout << "\n변수할당 깊이 : " <<depth<<endl;
	cout << inter_token.token + " 변수의 공간이 할당됨." << endl;
}
// 변수에 값 할당.
void var_assign() {
	inter_next(); // assign 대입문 발견 시 다음 토큰.
	if (inter_token.type == BINARY) { // 다음 토큰이 2진상수일 경우.
		int ident_pos = 0;
		for (var v : memory.at(depth)) {
			if (v.name == ident_token.token)
				break;
			ident_pos++;
		}
		
		if (inter_token.token.at(9) == '1')
			memory.at(depth).at(ident_pos).binary[0] = true;
		else
			memory.at(depth).at(ident_pos).binary[0] = false;
		if (inter_token.token.at(8) == '1')
			memory.at(depth).at(ident_pos).binary[1] = true;
		else
			memory.at(depth).at(ident_pos).binary[1] = false;
		if (inter_token.token.at(7) == '1')
			memory.at(depth).at(ident_pos).binary[2] = true;
		else
			memory.at(depth).at(ident_pos).binary[2] = false;
		if (inter_token.token.at(6) == '1')
			memory.at(depth).at(ident_pos).binary[3] = true;
		else
			memory.at(depth).at(ident_pos).binary[3] = false;
		if (inter_token.token.at(5) == '1')
			memory.at(depth).at(ident_pos).binary[4] = true;
		else
			memory.at(depth).at(ident_pos).binary[4] = false;
		if (inter_token.token.at(4) == '1')
			memory.at(depth).at(ident_pos).binary[5] = true;
		else
			memory.at(depth).at(ident_pos).binary[5] = false;
		if (inter_token.token.at(3) == '1')
			memory.at(depth).at(ident_pos).binary[6] = true;
		else
			memory.at(depth).at(ident_pos).binary[6] = false;
		if (inter_token.token.at(2) == '1')
			memory.at(depth).at(ident_pos).binary[7] = true;
		else
			memory.at(depth).at(ident_pos).binary[7] = false;

		cout << memory.at(depth).at(ident_pos).name + " : ";
		for (int i = 7; i > -1; i--) {
			if (memory.at(depth).at(ident_pos).binary[i])
				cout << 1;
			else
				cout << 0;
		}
		cout << "  의 값이 대입됨." << endl;
	}
	else if (inter_token.type = IDENT) { // 다음 토큰이 IDENT라면
		int subt_pos = 0;
		int intt_pos = 0;
		for (var v : memory.at(depth)) {
			if (sub_tokens.token == v.name)
				break;
			subt_pos++;
		}
		for (var v : memory.at(depth)) {
			if (inter_token.token == v.name)
				break;
			intt_pos++;
		}

		for (int i = 0; i < 8; i++) {
			memory.at(depth).at(subt_pos).binary[i] =
				memory.at(depth).at(intt_pos).binary[i];
		}

		cout << "\n값 변경"<<endl;
		cout << memory.at(depth).at(subt_pos).name + " : ";
		for (int i = 7; i > -1; i--) {
			if (memory.at(depth).at(subt_pos).binary[i])
				cout << 1;
			else
				cout << 0;
		}
		cout << "  의 값이 대입됨." << endl;
	}
}
// 메인에서의 출력함수.
void var_print() {
	cout << "출력함수 실행" << endl;
	inter_next(); // par_in
	inter_next(); // ident
	int print_pos = 0;
	for (var v : memory.at(depth)) {
		if (v.name == inter_token.token)
			break;
		print_pos++;
	}
	cout << "깊이 : " << depth << "  , 값 : ";
	file_out << "깊이 : " << depth << "  , 값 : ";
	for (int i = 7; i > -1; i--) {
		file_out << memory.at(depth).at(print_pos).binary[i];
		cout << memory.at(depth).at(print_pos).binary[i];
	}
	file_out << endl;
	cout << endl;
	inter_next(); // par_out
}

//함수호출
void call_func() {
	search_func();// 함수 찾기
	depth++;//깊이 추가
	string sub_name = sub_tokens.token;
	cout << endl << endl;
	cout << sub_name << " 함수 실행" << endl;
	callfvec.push_back(*(new callf_vec)); // 실행 함수 정보 추가
	callfvec.at(callfvec.size() - 1).depth = depth;
	callfvec.at(callfvec.size() - 1).call_pos = 0;
	callfvec.at(callfvec.size() - 1).tovec = defvec.at(callf_pos).tovec;
	int callf_size = callfvec.at(callfvec.size() - 1).tovec.size();
	func_next();
	if (func_token.type == DEF) func_next(); // def 토큰일 경우 다음
	if (func_token.type == IDENT) func_next(); // ident 토큰일 경우 다음
	if (func_token.type == COLON) func_next(); // COLON 토큰일 경우 다음 -> 개행문자
	while (callf_size != callfvec.at(callfvec.size() - 1).call_pos) {
		func_next(); // 다음토큰
		if (func_token.type == VAR) // VAR를 발견하엿을 경우.
			func_alloc(); // 변수 메모리영역 할당.
		else if (func_token.type == ASSIGN)// 대입문일 경우.
			func_assign(); // 변수에 값 할당.
		else if (func_token.type == IDENT) {// LHS가 식별자라면
			sub_tokens = func_token;
			func_next(); // 다음 토큰
			if (func_token.type == PAR_IN) {
				call_func(); // 재귀호출
			}
			else
				callfvec.at(callfvec.size() - 1).call_pos--; // 전에 토큰으로.
		}
		else if (func_token.type == PRINT) // 출력함수라면
			call_print();

	}
	callfvec.pop_back(); // 마지막 함수 제거 - 이로써 재귀함수가 실행 가능.
	depth--;
	cout << endl << endl;
	cout << sub_name << " 함수 종료" << endl << endl;;
}
// 함수찾기
void search_func() {
	callf_pos = 0;
	for (def_fun dfs : defvec) {
		if (dfs.name == sub_tokens.token)
			break;
		callf_pos++;
	}
}

// 호출 함수에서 다음 토큰 찾기
void func_next() {
	func_token = callfvec.at(callfvec.size() - 1).tovec.at(callfvec.at(callfvec.size() - 1).call_pos++);
}

// 함수 변수 할당
void func_alloc() {
	func_next(); //var를 발견시 다음 항목 불러오기
	if (memory.size() != depth + 1) { // 현재 깊이의 메모리영역이 없다면
		memory.push_back(*(new vector<var>())); // 메모리 영역 추가
	}
	ident_token = func_token; // 현재 변수이름 임시보관.
	memory.at(depth).push_back(*(new var()));
	memory.at(depth).at(memory.at(depth).size() - 1).name = func_token.token;
	cout << "\n변수할당 깊이 : "<< depth << endl;
	cout << func_token.token + " 변수의 공간이 할당됨." << endl;
}
// 함수 변수 값 할당
void func_assign() {
	func_next(); // assign 대입문 발견 시 다음 토큰.
	if (func_token.type == BINARY) { // 다음 토큰이 2진상수일 경우.
		int ident_pos = 0;
		for (var v : memory.at(depth)) {
			if (v.name == ident_token.token)
				break;
			ident_pos++;
		}

		if (func_token.token.at(9) == '1')
			memory.at(depth).at(ident_pos).binary[0] = true;
		else
			memory.at(depth).at(ident_pos).binary[0] = false;
		if (func_token.token.at(8) == '1')
			memory.at(depth).at(ident_pos).binary[1] = true;
		else
			memory.at(depth).at(ident_pos).binary[1] = false;
		if (func_token.token.at(7) == '1')
			memory.at(depth).at(ident_pos).binary[2] = true;
		else
			memory.at(depth).at(ident_pos).binary[2] = false;
		if (func_token.token.at(6) == '1')
			memory.at(depth).at(ident_pos).binary[3] = true;
		else
			memory.at(depth).at(ident_pos).binary[3] = false;
		if (func_token.token.at(5) == '1')
			memory.at(depth).at(ident_pos).binary[4] = true;
		else
			memory.at(depth).at(ident_pos).binary[4] = false;
		if (func_token.token.at(4) == '1')
			memory.at(depth).at(ident_pos).binary[5] = true;
		else
			memory.at(depth).at(ident_pos).binary[5] = false;
		if (func_token.token.at(3) == '1')
			memory.at(depth).at(ident_pos).binary[6] = true;
		else
			memory.at(depth).at(ident_pos).binary[6] = false;
		if (func_token.token.at(2) == '1')
			memory.at(depth).at(ident_pos).binary[7] = true;
		else
			memory.at(depth).at(ident_pos).binary[7] = false;

		cout << memory.at(depth).at(ident_pos).name + " : ";
		for (int i = 7; i > -1; i--) {
			if (memory.at(depth).at(ident_pos).binary[i])
				cout << 1;
			else
				cout << 0;
		}
		cout << "  의 값이 대입됨." << endl;
	}
	else if (func_token.type = IDENT) { // 다음 토큰이 IDENT라면
		int subt_pos = 0;
		int intt_pos = 0;
		for (var v : memory.at(depth)) {
			if (sub_tokens.token == v.name)
				break;
			subt_pos++;
		}
		for (var v : memory.at(depth)) {
			if (func_token.token == v.name)
				break;
			intt_pos++;
		}

		for (int i = 0; i < 8; i++) {
			memory.at(depth).at(subt_pos).binary[i] =
				memory.at(depth).at(intt_pos).binary[i];
		}

		cout << "\n값 변경" << endl;
		cout << memory.at(depth).at(subt_pos).name + " : ";
		for (int i = 7; i > -1; i--) {
			if (memory.at(depth).at(subt_pos).binary[i])
				cout << 1;
			else
				cout << 0;
		}
		cout << "  의 값이 대입됨." << endl;
	}
}
void call_print() {
	cout << "출력함수 실행" << endl;
	func_next(); // par_in
	func_next(); // ident
	int print_pos = 0;
	for (var v : memory.at(depth)) {
		if (v.name == func_token.token)
			break;
		print_pos++;
	}
	cout << "깊이 : " << depth << "  , 값 : ";
	file_out << "깊이 : " << depth << "  , 값 : ";
	for (int i = 7; i > -1; i--) {
		file_out << memory.at(depth).at(print_pos).binary[i];
		cout << memory.at(depth).at(print_pos).binary[i];
	}
	file_out << endl;
	cout << endl;
	func_next(); // par_out
}
