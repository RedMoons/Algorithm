#ifndef __ROTATE_H__
#define __ROTATE_H__
#include "Inform.h"
#include <string>

using namespace std;

class Rotate{
public:
Rotate();
~Rotate();

void insertNode(Inform *people);// 삽입
void changeNode(string _name, Inform* people);// 삭제
void SearchNode_dbl(string _name, Inform *hd);
void printout(Inform *hd);// 출력

Inform* SearchNode(string _name, Inform *hd);// 탐색
Inform* getHead();                                 
Inform** getSame();                                             //동명이인 탐색
void initSame();                                                //동명이인 탐색에 필요한 초기화 메소드
int CalculateRelation(string _name1, string _name2, Inform *hd);              //촌수계산
void saveRotates(FILE *op, Inform *hd);//데이터 저장.


private:
Inform *head, *z;

};

#endif