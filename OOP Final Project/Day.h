#pragma once
class Day
{
	char *name;
	int t1;
	int t2;
	int t3;
public:

	Day();
	Day(char*);
	~Day();
	void setname(char*);
	char *getname();
	void sett1(int);
	void sett2(int);
	void sett3(int);
	int gett1();
	int gett2();
	int gett3();
	void _strcpy(char *&, char *);
};

