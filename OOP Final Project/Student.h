#pragma once
#include"RegCourses.h"
#include "OldCourses.h"
#include"Day.h"
class Student
{
	int reglen;
	int regind;
	char *login;
	char *pin;
	char *name;
	int age;
	static int id;
	int uid;
	int check;
	RegCourses **r;
	Day *d[5];
	OldCourses *o;
public:
	Student();
	Student(char*, char *, char *, int);
	void setlogin(char *);
	void setpin(char *);
	void setname(char *);
	void setage(int);
	static int getid();
	char* getlogin();
	char *getname();
	char* getpin();
	int getage();
	int getcheck();
	bool checklogin(char *);
	bool checkpin(char *);
	void read(char*);
	bool checkpre(char *);
	int checkDandT(char*, char*);
	void reg(Courses*&);
	~Student();
	void delcourse();
	void setDandT(char*,char*);
	void olddisplay();
	void timetableDisplay();
	void fileout(int);
	void _strcpy(char *&, char*);
	int getuid();
	void fileout1();
	bool checksec(char *);

};

