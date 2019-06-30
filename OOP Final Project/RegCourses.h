#pragma once
#include"Courses.h"
class RegCourses
{
	Courses *c;
public:
	RegCourses();
	RegCourses(Courses *&);
	~RegCourses();
	char* gettime();
	char* getday();
	void display();
	void timetabledidplay();
	void fileout();
	bool checksec(char*);
};

