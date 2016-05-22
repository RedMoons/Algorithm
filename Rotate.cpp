#include "Rotate.h"
#include <iostream>
#define SAME_SIZE 30

using namespace std;

Inform *same[30];//중복검사허용을 위해 클래스 배열선언

int cnt = 0;

Rotate::Rotate()
{
head = new Inform("","","",-1,"","","",NULL,NULL,NULL,NULL, "", "");
z = new Inform("","","",-1,"","","",NULL,NULL,NULL,NULL, "", "");
}

Rotate::~Rotate()
{

}

void Rotate::insertNode(Inform *people)
{
Inform *h = head;
Inform *search_peo, *parent_peo;
Inform *temp = new Inform();
temp = people;

string _name = temp->get_relationName();
string _relation = temp->get_relation();

if(h->get_name() == "")
{
head = temp;
}
else
{
search_peo = SearchNode(_name, head);// Search

if(search_peo == z)
{
cout << "Error" << endl;
}
if(_relation == "배우자")// 배우자 확인
{
if(search_peo->get_partner() == NULL)
{
search_peo->partner = temp;//찾은사람의 파트너에 뉴노드를 연결
temp->partner = search_peo;//뉴노드의 파트너에 찾은사람을 연결
}
else{
cout << "Wife already existing" << endl;
}
}
else if(_relation == "자식")// 자식(막내로 저장)
{
parent_peo = search_peo;

if(search_peo->get_child() == NULL)
{
search_peo->child = temp;
temp->parent = parent_peo;//부모와 연결
}
else
{
search_peo = search_peo->get_child();

while(search_peo->get_sibling() != NULL)
{
search_peo = search_peo->get_sibling();
}
search_peo->sibling = temp;
temp->parent = parent_peo;//부모 연결
}
}
else if(_relation == "형제")// 형제(막내로 저장)
{
while(search_peo->get_sibling() != NULL)
{
search_peo = search_peo->get_sibling();
}
search_peo->sibling = temp;
temp->parent = search_peo->parent;//부모와 연결
}

else{
cout << "Unknown Realationship" << endl;
}
}
}

void Rotate::changeNode(string _name, Inform *people)
{
Inform* search_peo;
Inform *temp = new Inform();
temp = people;

search_peo = SearchNode(_name, head);

// 탐색에 성공한 경우 데이터 수정
 if(search_peo != z)
{
 search_peo->changeRotate(temp);
 }
}

Inform* Rotate::SearchNode(string _name, Inform *hd)
{
Inform *h = hd;
Inform *result = z;

while(h->get_name() != "")// 본인 탐색
{
if(h->get_name() == _name)
{
result = h;
break;
}
if(h->get_partner() != NULL)// 파트너 탐색
{
if(h->get_partner()->get_name() == _name){
result = h->get_partner();
break;
}
}
if(h->get_child() != NULL)// 자식 탐색
{
if(h->get_child()->get_name() == _name)
{
result = h->get_child();
break;
}
result = SearchNode(_name, h->get_child());
}

h = h->get_sibling();// 형제 탐색
if(h == NULL)
break;
}

return result;
}

void Rotate::SearchNode_dbl(string _name, Inform *hd)//중복허용 탐색
{
Inform *h = hd;
Inform *result = z;
while(h->get_name() != "")// 본인 탐색
{
if(h->get_name() == _name)
same[cnt++] = h;

if(h->get_partner() != NULL)// 파트너 탐색
{
if(h->get_partner()->get_name() == _name)
{
same[cnt++] = h->get_partner();
}
}
if(h->get_child() != NULL)// 자식 탐색
SearchNode_dbl(_name, h->get_child());

h = h->get_sibling();// 형제 탐색
if(h == NULL)
break;
}
}

void Rotate::printout(Inform *hd)
{
Inform *h = hd;

while(h->get_name() != "")// 본인 출력
{
cout << "( " << h->get_name() << " )" << endl;
h->print_simple();

// 파트너 출력
 if(h->get_partner() != NULL)
{
cout << "( " << h->get_name() << "의 배우자 )" << endl;
h->get_partner()->print_simple();
}
// 자식 탐색
if(h->get_child() != NULL)
{
cout << "( " << h->get_name() << "의 장손 )" << endl;
printout(h->get_child());
}
// 형제 탐색::= 제일 마지막에 하므로 종손이 먼저 출력됨.
h = h->get_sibling();
if(h == NULL)
break;
}
}

Inform* Rotate::getHead()
{
return head;
}

Inform** Rotate::getSame(){
return same;
}

void Rotate::initSame(){
int i;
for(i = 0; i < 30; i++)
same[i] = NULL;
cnt = 0;
}

int Rotate::CalculateRelation(string _name1, string _name2, Inform *hd){
Inform *p1, *p2;
Inform *h = hd;
int i, level1, level2, level_f = -1;

p1 = SearchNode_dbl(_name1, h);
if(p1->get_name() == "")
{
cout << "No Rotate!!!" << endl;
return -1;
}
p2 = SearchNode_dbl(_name2, h);
if(p2->get_name() == "")
{
cout << "데이터가 존재하지 않습니다." << endl;
return -1;
}


level1 = p1->get_level();
level2 = p2->get_level();

if(level1 == level2){
level_f = 0;
for(i = 1;; i++){
p1 = p1->get_parent();
p2 = p2->get_parent();
level_f+=2;
if(p1 == p2){
break;
}
}
}
else if(level1 < level2){
level_f = 0;
for(i = 0; i < level2 - level1; i++){
p2 = p2->get_parent();
level_f++;
}
for(i = 1;; i++)
{
if(p1 == p2)
{
break;
}
else
{
level_f+=2;
}
p1 = p1->get_parent();
p2 = p2->get_parent();
}
}
else if(level1 > level2){
level_f = 0;
for(i = 0; i < level1 - level2; i++)
{
p1 = p1->get_parent();
level_f++;
}
for(i = 1;; i++)
{
if(p1 == p2)
{
break;
}
else
{
level_f+=2;
}
p1 = p1->get_parent();
p2 = p2->get_parent();
}
}
return level_f;
}



void Rotate::saveRotates(FILE* op, Inform *hd)
{
Inform* h = hd;

while(h->get_name() != "") 
{

fprintf(op, "%s %s %s %d %s %s %s %s %s\n", &(h->get_firstName())[0], &(h->get_lastName())[0], &(h->get_gender())[0], h->get_level(), 
&(h->get_job())[0], &(h->get_birthDay())[0], &(h->get_deathDay())[0], &(h->get_relationName())[0], &(h->get_relation())[0] );

if(h->get_partner() != NULL) {
fprintf(op, "%s %s %s %d %s %s %s %s %s\n", &(h->get_partner()->get_firstName())[0], &(h->get_partner()->get_lastName())[0], &(h->get_partner()->get_gender())[0], h->get_partner()->get_level(), 
&(h->get_partner()->get_job())[0], &(h->get_partner()->get_birthDay())[0], &(h->get_partner()->get_deathDay())[0], &(h->get_partner()->get_relationName())[0], &(h->get_partner()->get_relation())[0] );
}

// 자식 탐색
if(h->get_child() != NULL)
{
saveRotates(op, h->get_child());
}

h = h->get_sibling();

if(h == NULL) 
{
break;
}
}
}