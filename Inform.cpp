#include "Inform.h"
#include <iostream>

using namespace std;

Inform::Inform()
{
firstName = "";// 이름
lastName = "";// 성
gender = "";// 성별
level = -1;// 항렬
job = "";// 직업
birthDay = "";// 탄생일
deathDay = "";// 사망일
partner = NULL;// 배우자
child = NULL;// 자식
sibling = NULL;// 형제
parent = NULL;  //부
name = "";
relation = "";
}

Inform::Inform(string _name, string _relation)
{
firstName = "";// 이름
lastName = "";// 성
gender = "";// 성별
level = -1;// 항렬
job = "";// 직업
birthDay = "";// 탄생일
deathDay = "";// 사망일
partner = NULL;// 배우자
child = NULL;// 자식
sibling = NULL;// 형제
parent = NULL;  //부
name = _name;
relation = _relation;
}

Inform::Inform(string _firstName, string _lastName, string _gender, int _level,string _job, string _birthDay, string _deathDay, Inform *_partner, Inform *_child, Inform *_sibling, Inform *_parent, string _name, string _relation)
{
firstName = _firstName;
lastName = _lastName;
gender = _gender;
level = _level;
job = _job;
birthDay = _birthDay;
deathDay = _deathDay;
partner = _partner;
child = _child;
sibling = _sibling;
parent = _parent;
name = _name;
relation = _relation;
}

Inform::~Inform()
{

}

Inform* Inform::make_Inform()
{
cout << "성 : ";
cin >> lastName;
cout << "이름 : ";
cin >> firstName;
cout << "성별 : ";
cin >> gender;
cout << "항렬 : ";
cin >> level;
cout << "직업 : ";
cin >> job;
cout << "탄생일 : ";
cin >> birthDay;
cout << "사망일 : ";
cin >> deathDay;
partner = NULL;
child = NULL;
sibling = NULL;
parent = NULL;

cout << "저장될 위치와 관계를 입력해 주세요." << endl;
cout << "이름 : ";
cin >> name;
cout << "관계(배우자, 자식, 형제) : ";
cin >> relation;

Inform *tmp = new Inform(firstName, lastName, gender, level, job, birthDay, deathDay, partner, child, sibling, parent, name, relation);
return tmp;
}

void Inform::changeRotate(Inform *obj)
{
lastName = obj->lastName;
firstName = obj->firstName;
gender = obj->gender;
level = obj->level;
job = obj->job;
birthDay = obj->birthDay;
deathDay = obj->deathDay;
}

Inform* Inform::get_partner()
{
return partner;
}

Inform* Inform::get_child()
{
return child;
}

Inform* Inform::get_sibling()
{
return sibling;
}

Inform* Inform::get_parent()
{
return parent;
}

string Inform::get_name()
{
return lastName + firstName;
}

string Inform::get_firstName()
{
return firstName;
}

string Inform::get_lastName()
{
return lastName;
}

string Inform::get_gender()
{
return gender;
}

string Inform::get_job()
{
return job;
}

string Inform::get_birthDay()
{
return birthDay;
}

string Inform::get_deathDay()
{
return deathDay;
}

string Inform::get_relationName()
{
return name;
}

string Inform::get_relation()
{
return relation;
}


int Inform::get_level()
{
return level;
}


void Inform::print_Inform()
{
cout << "============ 인물 정보 =============" << endl;
cout << "성 : " << lastName << endl;
cout << "이름 : " << firstName << endl;
cout << "성별 : " << gender << endl;
cout << "항렬 : " << level << endl;
cout << "직업 : " << job << endl;
cout << "탄생일 : " << birthDay << endl;
cout << "사망일 : " << deathDay << endl;
cout << "관계 : " << name<<"과 "<<relation <<endl;
cout << "====================================" << endl;
}
void Inform::print_simple()
{
cout<<"========== 간단한 인물 정보 =========="<<endl;
cout<<"성+이름 : "<<lastName<<firstName<<endl;
cout<<"관계 : "<<name<<"과(와) "<<relation<<endl;

}