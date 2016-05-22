#ifndef __INFORM_H__
#define __INFORM_H__
#include <string>
using namespace std;

class Inform{
public:
Inform();// 생성자
Inform(string _name, string _relation);
Inform(string _firstName, string _lastName, string _gender, int _level,string _job, string _birthDay, string _deathDay, Inform *_partner, Inform *_child, Inform *_sibling, Inform *_parent, string _name, string _relation);
~Inform();// 소멸자

Inform* make_Inform();// 인물 생성
void print_Inform();// 인물 출력
void print_simple();

void changeRotate(Inform *d);// 인물 수정

Inform* get_partner();
Inform* get_child();
Inform* get_sibling();
Inform* get_parent();
string get_name();
string get_firstName();
string get_lastName();
string get_gender();
string get_job();
string get_birthDay();
string get_deathDay();
string get_relation();
string get_relationName();
int get_level();

// link
Inform *partner;// 배우자
Inform *child;// 자식
Inform *sibling;// 형제
Inform *parent;     //부
private:
// data
string firstName;// 이름
string lastName;// 성
string gender;// 성별
int level;// 항렬
string job;// 직업
string birthDay;// 탄생일
string deathDay;// 사망일
string relation;// 관계
string name;
};

#endif
