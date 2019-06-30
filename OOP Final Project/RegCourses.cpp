#include "RegCourses.h"
#include<iostream>
#include<fstream>
using namespace std;


RegCourses::RegCourses()
{

}

RegCourses::RegCourses(Courses *&c)
{
	this->c = c;
}


RegCourses::~RegCourses()
{
}

void RegCourses::display()
{
	cout << c->getname() << endl;
}

char* RegCourses::gettime()
{
	return c->gettime();
}
char* RegCourses::getday()
{
	return c->getday();
}

void RegCourses::timetabledidplay()
{
	cout << endl;
	cout << "*********************" << endl;
	cout << c->getday() << endl;
	cout << c->gettime() << endl;
	cout << c->getname()<<"("<<c->getsec()<<")" << endl;
	cout << c->getteacher() << endl;
	cout << endl;
	cout << "*********************" << endl;
	
}

void RegCourses::fileout()
{
	ofstream fout;
	fout.open("oldcourses.txt", ios::app);

	fout << c->getcode()<<" ";

	fout.close();

}

bool RegCourses::checksec(char*name)
{
	if (strcmp(c->getname(), name) == 0)
		return true;
	else
		return false;
}