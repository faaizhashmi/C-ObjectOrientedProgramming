#include "Day.h"
#include"iostream"
using namespace std;

Day::Day()
{
	name = NULL;
	t1 = 0;
	t2 = 0;
	t3 = 0;
}


Day::~Day()
{
	delete[]name;
}


void Day::_strcpy(char *&n, char *n1){
	int l1 = strlen(n1);
	n = new char(l1);
	int i = 0;
	for (i = 0; i < l1; i++)
	{
		n[i] = n1[i];
	}
	n[i] = { '\0' };

}

Day::Day(char *name)
{
	this->name = new char[strlen(name) + 1];
	_strcpy(this->name, name);
	t1 = 0;
	t2 = 0;
	t3 = 0;
}

void Day::setname(char*name)
{
	delete[]name;
	this->name = new char[strlen(name) + 1];
	_strcpy(this->name, name);
}
char *Day::getname()
{
	return 0;
}
void Day::sett1(int t1)
{
	this->t1 = t1;
}
void Day::sett2(int t2)
{
	this->t2 = t2;
}
void Day::sett3(int t3)
{
	this->t3 = t3;
}
int Day::gett1()
{
	return t1;
}
int Day::gett2()
{
	return t2;
}

int Day::gett3()
{
	return t3;
}