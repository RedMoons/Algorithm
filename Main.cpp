#include <iostream>
#include "Rotate.h"
#include "Inform.h"
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#define X 1
#define Y 1
using namespace std;

typedef enum 
{
BLACK,
DARK_BLUE,
DARK_GREEN,
DARK_SKY_BLUE,
DARK_RED,
DARK_VOILET,
DARK_YELLOW,
WHITE,
GRAY,
BLUE,
GREEN,
SKY_BLUE,
RED,
VOILET,
YELLOW
}COLOR_TYPE;

void SetColor(COLOR_TYPE color)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
COORD Pos = {x - 1, y - 1};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void clearSquare()
{
gotoxy(X+1,Y+1);  SetColor(YELLOW); printf("   ■■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■■   ");
gotoxy(X+1,Y+2);  SetColor(YELLOW); printf("  ■                              ■  ■                              ■  ");
gotoxy(X+1,Y+3);  SetColor(YELLOW); printf(" ■                                ■■                                ■ ");
gotoxy(X+1,Y+4);  SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+5);  SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+6);  SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+7);  SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+8);  SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+9);  SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+10); SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+11); SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+12); SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+13); SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+14); SetColor(YELLOW); printf("■                                  ■                                  ■");
gotoxy(X+1,Y+15); SetColor(YELLOW); printf("■ ■■■■■■■■■■■■■■■■ ■ ■■■■■■■■■■■■■■■■ ■");
gotoxy(X+1,Y+16); SetColor(YELLOW); printf("■■                              ■■■                              ■■");
gotoxy(X+1,Y+17); SetColor(YELLOW); printf("■  ■■■■■■■■■■■■■■■ ■■ ■■■■■■■■■■■■■■■  ■");
gotoxy(X+1,Y+18); SetColor(YELLOW); printf("■■                              ■■■                              ■■");
gotoxy(X+1,Y+19); SetColor(YELLOW); printf("■                                  ■                                  ■");

}
int main()
{
// 파일 입출력
FILE *fp;
int result;
fp = fopen("LOAD.txt", "r+");
if(fp == NULL){
fprintf(stderr, "파일 생성에 실패하였습니다.\n");
return 1;
}
//start page
gotoxy(X+2,Y+1);  SetColor(BLUE); printf("     ■■        ■        ■           ■       ■■■■■  ■■■■■■■"); Sleep(100);
gotoxy(X+2,Y+2);  SetColor(BLUE); printf("   ■    ■     ■■      ■■         ■■      ■       ■       ■"); Sleep(100);
gotoxy(X+2,Y+3);  SetColor(BLUE); printf("  ■      ■   ■  ■    ■  ■       ■  ■     ■       ■       ■"); Sleep(100);
gotoxy(X+2,Y+4);  SetColor(BLUE); printf("   ■          ■  ■    ■  ■       ■  ■     ■      ■        ■"); Sleep(100);
gotoxy(X+2,Y+5);  SetColor(BLUE); printf("    ■■■    ■    ■  ■    ■     ■    ■    ■■■■■        ■"); Sleep(100);
gotoxy(X+2,Y+6);  SetColor(BLUE); printf("         ■   ■    ■  ■    ■     ■■■■    ■       ■       ■"); Sleep(100);
gotoxy(X+2,Y+7);  SetColor(BLUE); printf("  ■      ■ ■      ■■      ■   ■      ■   ■        ■      ■"); Sleep(100);
gotoxy(X+2,Y+8);  SetColor(BLUE); printf("   ■    ■  ■      ■■      ■   ■      ■   ■        ■      ■"); Sleep(100);
gotoxy(X+2,Y+9);  SetColor(BLUE); printf("     ■■   ■        ■        ■ ■        ■  ■        ■      ■"); Sleep(100);

gotoxy(X+12,Y+13); SetColor(WHITE); printf("         ■■■■■  "); printf("                  "); Sleep(100);
gotoxy(X+12,Y+14); SetColor(WHITE); printf("             ■      "); printf("                  "); Sleep(100);
gotoxy(X+12,Y+15); SetColor(WHITE); printf("           ■  ■    "); printf("      ■      ■  "); Sleep(100);
gotoxy(X+12,Y+16); SetColor(WHITE); printf("         ■      ■  "); printf("      ■      ■  "); Sleep(100);
gotoxy(X+12,Y+17); SetColor(WHITE); printf("             ■      "); printf("      ■■■■■  "); Sleep(100);
gotoxy(X+12,Y+18); SetColor(WHITE); printf("       ■■■■■■■"); printf("      ■      ■  "); Sleep(100);
gotoxy(X+12,Y+19); SetColor(WHITE); printf("                     "); printf("      ■■■■■  "); Sleep(100);
gotoxy(X+12,Y+20); SetColor(WHITE); printf("         ■■■■■  "); printf("          ■      "); Sleep(100);
gotoxy(X+12,Y+21); SetColor(WHITE); printf("                 ■  "); printf("    ■■■■■■■"); Sleep(100);
gotoxy(X+12,Y+22); SetColor(WHITE); printf("                 ■  "); printf("                  "); Sleep(100);

gotoxy(X+28,Y+25); SetColor(WHITE); printf("  Designed by 5조"); Sleep(1000);
gotoxy(X+28,Y+26); SetColor(WHITE); printf("   김명성 양재혁 "); Sleep(1000);
gotoxy(X+28,Y+27); SetColor(WHITE); printf("   김윤석 변성진 "); Sleep(2000);
system("cls");
//end start page
// 기존 데이터 읽어오기
char firstName[30];  // 이름
char lastName[30];  // 성
char gender[30];  // 성별
int level;    // 항렬
char job[30];   // 직업
char birthDay[30]; // 탄생일
char deathDay[30]; // 사망일
char name[30];   // 누구와의
char relation[30];  // 관계인가
Rotate family;
while(1){
// 성공할 경우, fscanf 함수는 읽어들인 데이터의 수를 리턴한다. 만일 어떠한 데이터도 형식 지정자와 일치하는 것이 없다면 0 이 될 수 도 있다.
// 만일 어떠한 데이터도 성공적으로 읽어들이기 전에 입력이 실패한다면 EOF 가 리턴된다. 
result = fscanf(fp, "%s %s %s %d %s %s %s %s %s", firstName, lastName, gender, &level, job, birthDay, deathDay, name, relation);
if(result == EOF) break;
// 저장되어있는 데이터가 있으면 노드를 만들고,
Inform *temp = new Inform(firstName, lastName, gender, level, job, birthDay, deathDay, NULL, NULL, NULL, NULL, name, relation);

// Rotate에 저장한다.
family.insertNode(temp);
}
fclose(fp);
while(1)
{
string menu1;
int _menu1;
clearSquare();

// 1단계 메뉴 출력
SetColor(WHITE);
gotoxy(X+12, Y+4);cout << "* SMART 족보 *" << endl;
gotoxy(X+12, Y+5);cout << "족보  입력 1번" << endl;
gotoxy(X+12, Y+6);cout << "족보  수정 2번" << endl;
gotoxy(X+12, Y+7);cout << "족보  탐색 3번" << endl;
gotoxy(X+12, Y+8);cout << "족보  출력 4번" << endl;
gotoxy(X+12, Y+9);cout << "촌수  계산 5번" << endl;
gotoxy(X+12, Y+10);cout << "종      료 6번" << endl;
gotoxy(X+12, Y+11);cout <<"초  기  화 7번" ;
gotoxy(X+44, Y+5);SetColor(WHITE);cout << "실행할 번호를 입력하시오.";
gotoxy(X+44, Y+7);cout << "⇒ ";

/*
SetColor(WHITE);
gotoxy(X+10, Y+3);cout << "<< 전자 족보 >>" << endl;
gotoxy(X+10, Y+4);cout << "1 : 자료 입력" << endl;
gotoxy(X+10, Y+5);cout << "2 : 자료 수정" << endl;
gotoxy(X+10, Y+6);cout << "3 : 자료 탐색(인물 세부정보)" << endl;
gotoxy(X+10, Y+7);cout << "4 : 자료 출력(전체인물)" << endl;
gotoxy(X+10, Y+8);cout << "5 : 촌수 계산" << endl;
gotoxy(X+10, Y+9);cout << "6 : 종     료" << endl;
gotoxy(X+10, Y+10);cout << "7 : 화면 초기화" ;
gotoxy(X+10, Y+11);cout << "8 : 자료출력(인물 세부정보)" ;
gotoxy(X+40, Y+5);SetColor(YELLOW);cout << "메뉴를 선택하세요.";
gotoxy(X+40, Y+6);cout << ">>";
*/
cin >> menu1;
if(menu1 == "1")
_menu1 = 1;
else if(menu1 == "2")
_menu1 = 2;
else if(menu1 == "3")
_menu1 = 3;
else if(menu1 == "4")
_menu1 = 4;
else if(menu1 == "5")
_menu1 = 5;
else if(menu1 == "6")
_menu1 = 6;
else if(menu1 == "7")
_menu1 = 7;
//else if(menu1 == "8")
//_menu1 = 8;
else
_menu1 = -1;
SetColor(WHITE);
switch (_menu1)
{
case 1 :
{    
gotoxy(X+10, Y+19);
cout << endl;
// 새로운 인물 입력
Inform temp_peopleson;
Inform *new_peopleson;
new_peopleson = temp_peopleson.make_Inform();

// 족보에 추가
family.insertNode(new_peopleson);
break;
}
case 2 :
{
gotoxy(X+10, Y+19);
cout << endl;
// 수정할 이름
string changeName;

cout << "수정할 사람의 이름을 입력해 주세요." << endl;
cin >> changeName;

// 탐색에 성공한 경우
if(family.SearchNode(changeName, family.getHead())->get_name() != ""){
// 새로운 인물 입력
Inform temp_peopleson;
Inform *new_peopleson;
new_peopleson = temp_peopleson.make_Inform();

// 데이터 수정
family.changeNode(changeName, new_peopleson);
}
else{
cout << "존재하지 않습니다." << endl;
}

break;
}
case 3 :
{
gotoxy(X+10, Y+19);
cout << endl;
// 탐색할 이름
string searchName;

cout << "탐색할 이름을 입력해 주세요." << endl;
cin >> searchName;
// 데이터 위치 탐색
Inform* search_peo;
search_peo = family.SearchNode(searchName, family.getHead());

// 탐색에 실패한 경우 출력
if(search_peo->get_name() == ""){
cout << "존재하지 않습니다." << endl;
}
else{
//탐색
family.initSame();
family.SearchNode_dbl(searchName, family.getHead());
Inform **s_temp = family.getSame();
for(int i = 0; s_temp[i] != NULL; i++)
s_temp[i]->print_Inform();
}
break;
}
case 4 :
{
gotoxy(X+10, Y+19);
cout << endl;
family.printout(family.getHead());
break;
}
case 5 :
{
gotoxy(X+10, Y+19);
cout << endl;
int relation;
//* 촌수계산 구현
// 탐색할 이름
string searchName1, searchName2 ;
cout << "탐색할 첫번째 이름을 입력해 주세요." << endl;
cin >> searchName1;

cout << "탐색할 두번째 이름을 입력해 주세요." << endl;
cin >> searchName2;

// 데이터 위치 탐색
relation = family.CalculateRelation(searchName1, searchName2, family.getHead());
if(relation == -1){
cout<<"탐색오류!"<<endl;
break;
}
else{
// 탐색에 성공한 경우 출력
cout<<"해당 인물간의 촌수는 "<<relation<<"촌 입니다."<<endl;
}
break;
}
case 6 :
{
gotoxy(X+10, Y+19);
cout << endl;
// 모든 자료 저장
FILE *op;
op = fopen("family.txt", "w");
if(op == NULL){
cout << "출력 파일 개방 실패" << endl;
}
family.saveRotates(op, family.getHead());
fclose(op);
return 0;
}
/*case 7 :
{
clearSquare();
SetColor(RED);
gotoxy(X+10, Y+14);cout<<"<<추가 명령어 목록>>"<<endl;
gotoxy(X+10, Y+15);cout<<"-cls : 화면초기화"<<endl;
break;
}*/
case 7 :
{
system("cls");
break;
}
/*case 8 :
{
gotoxy(X+10, Y+14);
family.OnePrintf(family.getHead());
break;
}
*/
default:
{
gotoxy(X+30, Y+6);
SetColor(RED);
cout << ">>잘못된 입력입니다. " << endl;Sleep(200);
break;
}
}
}
}
