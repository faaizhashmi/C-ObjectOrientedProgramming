#pragma once
class OldCourses
{
	char **code;
	int codeind;
	int codelen;
public:
	OldCourses();
	~OldCourses();
	void read(char*);
	bool checkpre(char*);
	void display();
	void fileout(int);
	void _strcpy(char *&, char *);
	
};

