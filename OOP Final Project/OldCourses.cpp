#include "OldCourses.h"
#include<fstream>
#include<iostream>
using namespace std;

OldCourses::OldCourses()
{
	code = new char*[1];
	codeind = 0;
	codelen = 1;
}


OldCourses::~OldCourses()
{
	delete[]code;
}

void OldCourses::_strcpy(char *&n, char *n1){
	int l1 = strlen(n1);
	int i = 0;
	for (i = 0; i < l1; i++)
	{
		n[i] = n1[i];
	}
	n[i] = { '\0' };

}

char **regrow(char **ptr, int &len)
{
	char **temp = ptr;
	ptr = new char*[len + 1];
	for (int i = 0; i < len; i++)
	{
		ptr[i] = temp[i];
	}
	delete[]temp;
	len++;
	return ptr;
}

void OldCourses::read(char*code)
{
	while (1)
	{
		if (codeind < codelen)
		{
			this->code[codeind] = new char[7];
			_strcpy(this->code[codeind], code);
			codeind++;
			break;
		}
		else
		{
			this->code = regrow(this->code, codelen);
		}
	}
}

bool OldCourses::checkpre(char*pre)
{
	if (codeind == 0)
		return false;
	else
	{
		for (int i = 0; i < codelen; i++)
		{
			if (strcmp(code[i], pre) == 0)
				return true;
		}
		return false;
	}
}

void OldCourses::display()
{
	if (codeind > 0)
	{
		cout << endl;
		cout << "*********************" << endl;
		for (int i = 0; i < codelen; i++)
		{
			
			cout << code[i] << endl;
		}
		cout << endl;
		cout << "*********************" << endl;
		
			
	}
	else
	{
		cout << "No course is cleared.\n";
	}
}

void OldCourses::fileout(int id)
{
	ofstream fout;
	fout.open("oldcourses.txt", ios::app);

	fout << id << " ";
	if (codeind > 0)
	{
		
		for (int i = 0; i < codelen; i++)
		{
			fout << code[i] << " ";
		}
			
	}
	/*else
	{
		fout << "nill" << endl;
	}*/

	fout.close();

}
