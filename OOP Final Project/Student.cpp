#include "Student.h"
#include"RegCourses.h"
#include "OldCourses.h"
#include"Day.h"
#include<iostream>
#include<fstream>
using namespace std;

Student::Student()
{
	o = new OldCourses();
	r = new RegCourses*[1];
	login = NULL;
	pin = NULL;
	name = NULL;
	age = 0;
	check = 0;
	regind = 0;
	reglen = 1;
	d[0] = new Day("Monday");
	d[0] = new Day("Tuesday");
	d[0] = new Day("Wednesday");
	d[0] = new Day("Thursday");
	d[0] = new Day("Friday");
}
void Student::_strcpy(char *&n, char *n1){
	int l1 = strlen(n1);
	int i = 0;
	for (i = 0; i < l1; i++)
	{
		n[i] = n1[i];
	}
	n[i] = { '\0' };

}
Student::Student(char *_login, char *_pin, char *_name, int _age)
{
	regind = 0;
	reglen = 1;
	r = new RegCourses*[1];
	o = new OldCourses();
	id++;
	uid = id;
	login = new char[strlen(_login) + 1];
	_strcpy(login, _login);
	pin = new char[strlen(_pin) + 1];
	_strcpy(pin, _pin);
	name = new char[strlen(_name) + 1];
	_strcpy(name, _name);
	age = _age;
	d[0] = new Day("Monday");
	d[1] = new Day("Tuesday");
	d[2] = new Day("Wednesday");
	d[3] = new Day("Thursday");
	d[4] = new Day("Friday");
}

void Student::setlogin(char *_login){
	delete[]login;
	login = new char[strlen(_login) + 1];
	_strcpy(login, _login);
}
void Student::setpin(char *_pin){
	delete[] pin;
	pin = new char[strlen(_pin) + 1];
	_strcpy(pin, _pin);
}
void Student::setname(char *_name){
	delete[] name;
	name = new char[strlen(_name) + 1];
	_strcpy(name, _name);
}
void Student::setage(int _age){
	age = _age;

}
int Student::getid(){
	return id;
}
char* Student::getlogin(){
	return login;
}
char* Student::getname(){
	return name;
}
char* Student::getpin(){
	return pin;
}
int Student::getage(){
	return age;
}

int Student::getuid()
{
	return uid;
}

Student::~Student()
{
	delete[]login;
	delete[]name;
	delete[]pin;
	delete[]r;
	delete[]o;
	delete[]d;
}

bool Student::checklogin(char *login)
{
	if (strcmp(this->login, login) == 0)
		return true;
	else
		return false;
}

bool Student::checkpin(char *pin)
{
	if (strcmp(this->pin, pin) == 0)
		return true;
	else
		return false;
}

void Student::read(char *code)
{
	o->read(code);
}

bool Student::checkpre(char *pre)
{
	return o->checkpre(pre);
}

int Student::checkDandT(char*day, char*time)
{
	int i = 0, j = 0;
	if (strcmp(day, "monday") == 0)
		i = 0;
	else if (strcmp(day, "tuesday") == 0)
		i = 1;
	else if (strcmp(day, "wednesday") == 0)
		i = 2;
	else if (strcmp(day, "thursday") == 0)
		i = 3;
	else if (strcmp(day, "friday") == 0)
		i = 4;

	if (strcmp(time, "8:00-9:40") == 0)
	{
		j=d[i]->gett1();
		d[i]->sett1(1);
		
	}
		
	else if (strcmp(time, "10:00-11:40") == 0)
	{
		j = d[i]->gett2();
		d[i]->sett2(1);
	}
	
	else if (strcmp(time, "12:00-1:40") == 0)
	{
		j = d[i]->gett3();
		d[i]->sett3(1);
	}

	return j;
}

int Student::getcheck()
{
	return check;
}

RegCourses **regrow(RegCourses **ptr, int &len)
{
	RegCourses **temp = ptr;
	ptr = new RegCourses*[len + 1];
	for (int i = 0; i < len; i++)
	{
		ptr[i] = temp[i];
	}
	delete[]temp;
	len++;
	return ptr;
}


void Student::reg(Courses*&c)
{
	check++;

	while (1)
	{
		if (regind < reglen)
		{
			r[regind] = new RegCourses(c);
			regind++;
			break;
		}
		else
		{
			r = regrow(r, reglen);
		}
	}

}

RegCourses **del(RegCourses **obj, int skip, int &len)
{
	int j = 0;
	RegCourses **temp = obj;
	obj = new RegCourses*[len - 1];
	for (int i = 0; i < len; i++)
	{
		if (i != skip)
		{
			obj[j] = temp[i];
			j++;
		}
	}
	delete[]temp;
	len--;
	return obj;
}

void Student::setDandT(char *day,char*time)
{
	int i = 0, j = 0;
	if (strcmp(day, "monday") == 0)
		i = 0;
	else if (strcmp(day, "tuesday") == 0)
		i = 1;
	else if (strcmp(day, "wednesday") == 0)
		i = 2;
	else if (strcmp(day, "thursday") == 0)
		i = 3;
	else if (strcmp(day, "friday") == 0)
		i = 4;

	if (strcmp(time, "8:00-9:40") == 0)
	{
		d[i]->sett1(0);

	}

	else if (strcmp(time, "10:00-11:40") == 0)
	{
		d[i]->sett2(0);
	}

	else if (strcmp(time, "12:00-1:40") == 0)
	{
		d[i]->sett3(0);
	}
}

void Student::delcourse()
{
	if (regind > 0)
	{
		char*day;
		char*time;
		int i = 0;
		cout << "which course you want to del.\n";
		for (i = 0; i < reglen; i++)
		{
			cout << endl;
			cout << "********************" << endl;
			cout << i + 1 << ")";
			r[i]->display();
			cout << "********************" << endl;
			cout << endl;
		}
		cin >> i;
		day = r[i-1]->getday();
		time = r[i-1]->gettime();
		setDandT(day, time);
		r = del(r, i - 1, reglen);
		check--;
		regind--;
	}

	else
		cout << "no courses.\n";

	

	
}

void Student::olddisplay()
{
	o->display();
}

void Student::timetableDisplay()
{
	if (regind > 0)
	{
		for (int i = 0; i < reglen; i++)
		{
			r[i]->timetabledidplay();
		}
	}

	else
		cout << "no courses.\n";
}

void Student::fileout(int id)
{
	o->fileout(id);
}

void Student::fileout1()
{
	ofstream fout;
	fout.open("oldcourses.txt", ios::app);

	if (regind > 0)
	{
		for (int i = 0; i < reglen; i++)
		{
			r[i]->fileout();
		}

		fout << "nill" << endl;
	}

	else
		fout << "nill" << endl;

	fout.close();
}

bool Student::checksec(char *name)
{
	int check = 0;
	if (regind > 0)
	{
		for (int i = 0; i < reglen; i++)
		{
			check=r[i]->checksec(name);
			if (check == true)
				return false;
		}
		return true;
	}

	else
		return true;
}