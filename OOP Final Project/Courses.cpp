#include "Courses.h"
#include"iostream"
using namespace std;

Courses::Courses()
{
	name = NULL;
	code = NULL;
	ch = 0;
	time = NULL;
	day = NULL;
	teacher = NULL;
	pre = NULL;
	_pre = NULL;
}

void Courses::_strcpy(char *&n, char *n1){
	int l1 = strlen(n1);
	int i = 0;
	for (i = 0; i < l1; i++)
	{
		n[i] = n1[i];
	}
	n[i] = { '\0' };

}

Courses::Courses(char*name, char*code, int ch, char*time, char*day, char*teacher, char*pre,char sec)
{
	this->name = new char[strlen(name) + 1];
	_strcpy(this->name, name);
	this->code = new char[strlen(code) + 1];
	_strcpy(this->code, code);
	this->ch = ch;
	this->time = new char[strlen(time) + 1];
	_strcpy(this->time, time);
	this->day = new char[strlen(day) + 1];
	_strcpy(this->day, day);
	this->teacher = new char[strlen(teacher) + 1];
	_strcpy(this->teacher, teacher);
	this->pre = new char[strlen(pre) + 1];
	_strcpy(this->pre, pre);
	this->sec = sec;

}

Courses::Courses(char*name, char*code, int ch, char*time, char*day, char*teacher, Courses*&p,char sec)
{
	this->name = new char[strlen(name) + 1];
	_strcpy(this->name, name);
	this->code = new char[strlen(code) + 1];
	_strcpy(this->code, code);
	this->ch = ch;
	this->time = new char[strlen(time) + 1];
	_strcpy(this->time, time);
	this->day = new char[strlen(day) + 1];
	_strcpy(this->day, day);
	this->teacher = new char[strlen(teacher) + 1];
	_strcpy(this->teacher, teacher);
	_pre = p;
	this->sec = sec;
}
void Courses::setname(char*name)
{
	delete[]name;
	this->name = new char[strlen(name) + 1];
	_strcpy(this->name, name);
}
void Courses::setcode(char*code)
{
	delete[]code;
	this->code = new char[strlen(code) + 1];
	_strcpy(this->code, code);
}
void Courses::setch(int ch)
{
	this->ch = ch;
}
void Courses::settime(char*time)
{
	delete[]time;
	this->time = new char[strlen(time) + 1];
	_strcpy(this->time, time);
}
void Courses::setday(char*day)
{
	delete[]day;
	this->day = new char[strlen(day) + 1];
	_strcpy(this->day, day);
}
void Courses::setteacher(char*teacher)
{
	delete[]teacher;
	this->teacher = new char[strlen(teacher) + 1];
	_strcpy(this->teacher, teacher);
}
void Courses::setpre(char*pre)
{
	delete[]pre;
	this->pre = new char[strlen(pre) + 1];
	_strcpy(this->pre, pre);
}
char* Courses::getname()
{
	return name;
}
char* Courses::getcode()
{
	return code;
}
int Courses::getch()
{
	return ch;
}
char* Courses::gettime()
{
	return time;
}
char* Courses::getday()
{
	return day;
}
char* Courses::getteacher()
{
	return teacher;
}
char* Courses::getpre()
{
	return pre;
}

Courses::~Courses()
{
	delete[]name;
	delete[]code;
	delete[]time;
	delete[]day;
	delete[]teacher;
	delete[]pre;
	delete[]_pre;
}

void Courses::setsec(char sec)
{
	this->sec = sec;
}
char Courses::getsec()
{
	return sec;
}

void Courses::display()
{
	if (pre != NULL)
		cout << name << " " << code << " " << ch << " " << pre<<" " <<time<<" "<<day<<" "<<sec << endl;
	else
		cout << name << " " << code << " " << ch << " " << _pre->getcode() << " " << time << " " << day << " " << sec << endl;
}

char *Courses::get_pre()
{
	return _pre->getcode();
}