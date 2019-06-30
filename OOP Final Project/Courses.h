#pragma once
class Courses
{
	char *name;
	char *code;
	int ch;
	Courses *_pre;
	char *time;
	char *day;
	char *teacher;
	char *pre;
	char sec;
	
public:
	Courses();
	~Courses();
	Courses(char*, char*, int, char*, char*, char*, char*,char);
	Courses(char*, char*, int, char*, char*, char*, Courses*&,char);
	void setname(char*);
	void setcode(char*);
	void setch(int);
	void settime(char*);
	void setday(char*);
	void setteacher(char*);
	void setpre(char*);
	char* getname();
	char* getcode();
	int getch();
	char* gettime();
	char* getday();
	char* getteacher();
	char* getpre();
	void setsec(char);
	char getsec();
	void display();
	char* get_pre();
	void _strcpy(char *&, char *);
};

