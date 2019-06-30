#include<iostream>
#include<fstream>
#include "Day.h"
#include "Student.h"
#include "RegCourses.h"
#include "Courses.h"
using namespace std;

Student **regrow(Student **ptr, int &len)
{
	Student **temp = ptr;
	ptr = new Student*[len + 1];
	for (int i = 0; i < len; i++)
	{
		ptr[i] = temp[i];
	}
	delete[]temp;
	len++;
	return ptr;
}

int Student::id = 0;
int main()
{
	Courses *c[40];
	Student **s = new Student*[1];
	int stulen = 1, stuind = 0, i = 0, ch = 0, id = 0, age = 0, j = 0, check = 0, count = 0, k = 0, l = 0, check1 = 0, flag = 0;
	char sec = '\0';
	char name[20] = { '\0' };
	char code[20] = { '\0' };
	char pre[20] = { '\0' };
	char login[20] = { '\0' };
	char pin[20] = { '\0' };
	char time[20] = { '\0' };
	char day[20] = { '\0' };
	char tname[20] = { '\0' };

	ifstream fin;
	fin.open("courses.txt", ios::in);

	
	for (i = 0; i < 40; i++)
	{
		fin >> name >> code >> ch;
		fin.ignore();
		fin >> pre >> time >> day >> tname >> sec;

		if (strcmp(pre, "nill") == 0)
		{
			c[i]=new Courses(name, code, ch, time, day, tname, pre, sec);
		}
		else
		{
			for (j = 0; j < i-1; j++)
			{
				if (strcmp(c[j]->getname(), pre) == 0)
					break;
			}
			c[i] = new Courses(name, code, ch, time, day, tname, c[j], sec);
		}
	}

	fin.close();

	fin.open("student.txt", ios::in);

	fin >> id;
	while (!fin.eof())
	{
		fin.ignore();
		fin >> login >> pin >> name >> age;

		while (1)
		{
			if (stuind < stulen)
			{
				s[stuind] = new Student(login,pin,name,age);
				stuind++;
				break;
			}
			else
			{
				s = regrow(s, stulen);
			}
		}

		fin >> id;
	}

	fin.close();
	id=s[0]->getid();

	fin.open("oldcourses.txt", ios::in);
	
	for (i = 0; i < id; i++)
	{
		fin >> ch;
		fin.ignore();
		while (1)
		{
			fin >> code;
			if (strcmp(code, "nill") != 0)
				s[i]->read(code);
			else
				break;
		}
		
	}

	while (1)
	{
		cout << "1)User Login.\n";
		cout << "2)New Id.\n";
		cout << "3)Exit.\n";
		cin >> i;

		if (i == 1)
		{
			while (1)
			{
				char login1[20] = { '\0' };
				cout << "Enter login : ";
				cin >> login1;

				for (j = 0; j < stulen; j++)
				{
					check = s[j]->checklogin(login1);
					if (check == true)
						break;
				}

				if (check == true)
				{
					while (1)
					{
						char pin1[20] = { '\0' };
						cout << "Enter pin : ";
						cin >> pin1;

						check = s[j]->checkpin(pin1);
						if (check == true)
							break;
						else
						{
							cout << "wrong pin.\n";
							count++;
							if (count == 4)
								break;
						}
							
					}
				}

				if (check == true)
					break;
				else
					cout << "many attemptes.\n";

			}

			while (1)
			{

				cout << "Welcome.\n";
				cout << "1)Show courses.\n";
				cout << "2)Register for course.\n";
				cout << "3)withdraw from couese.\n";
				cout << "4)View cleared courses.\n";
				cout << "5)Show timetable.\n";
				cout << "6)Logout\n";
				cin >> i;

				if (i == 1)
				{
					for (k = 0; k < 40; k++)
					{
						cout << k + 1 << ")";
						c[k]->display();
					}
				}

				else if (i == 2)
				{
					check1 = s[j]->getcheck();

					if (check1 < 5)
					{
						cout << "which coures you want to register.\n";
						for (k = 0; k < 40; k++)
						{
							cout << k + 1 << ")";
							c[k]->display();
						}

						while (1)
						{
							char *day1;
							char *time1;
							char *pre1;
							cout << "selecet option : ";
							cin >> k;
							check = s[j]->checksec(c[k - 1]->getname());
							if (check == true)
							{
								if (c[k - 1]->getpre() == NULL)
								{
									pre1 = c[k - 1]->get_pre();
									check = s[j]->checkpre(pre1);
									if (check == true)
									{
										day1 = c[k - 1]->getday();
										time1 = c[k - 1]->gettime();
										check = s[j]->checkDandT(day1, time1);
										if (check == 0)
										{
											s[j]->reg(c[k - 1]);
											break;
										}
										else
										{
											cout << "Clash.\n";
										}
									}
									else
										cout << "sorry you can't!.\n";
								}
								else
								{
									char*day2;
									char*time2;

									day2 = c[k - 1]->getday();
									time2 = c[k - 1]->gettime();
									check = s[j]->checkDandT(day2, time2);
									if (check == 0)
									{
										s[j]->reg(c[k - 1]);
										break;
									}
									else
									{
										cout << "Clash.\n";
									}

								}
							}
							
							else
							{
								cout << "you are already registered to this course.\n";
							}
						//
						}

					}
					else
						cout << "no more courses.\n";

				}

				else if (i == 3)
				{
					s[j]->delcourse();
				}

				else if (i == 4)
				{
					s[j]->olddisplay();
				}

				else if (i == 5)
				{
					s[j]->timetableDisplay();
				}

				else if (i == 6)
				{
					break;
				}

				else if (i > 6 || i <= 0)
					cout << "select right option.\n";


			} //login while


		}//if 1 userlogin

		else if (i == 2)
		{
			char login3[20] = { '\0' };
			char pin3[20] = { '\0' };
			char name3[20] = { '\0' };
			int age2 = 0;

			cout << "enter name : ";
			cin >> name3;
			cout << "enter age : ";
			cin >> age2;
			cin.ignore();
			cout << "enter login : ";
			cin >> login3;
			cout << "enter pin : ";
			cin >> pin3;

			while (1)
			{
				if (stuind < stulen)
				{
					s[stuind] = new Student(login3, pin3, name3, age2);
					stuind++;
					break;
				}
				else
				{
					s = regrow(s, stulen);
				}
			}
			id++;
			cout << "Your account has been created (LaLaLaaaaa)" << endl;
		}

		else if (i == 3)
		{
			break;
		}

		else if (i>3 || i<=0)
			cout << "select right option.\n";

		

	}//main while

	ofstream fout;
	ofstream fout1;
	fout1.open("oldcourses.txt", ios::out);
	fout.open("student.txt", ios::out);

	for (i = 0; i < stulen; i++)
	{
		fout << s[i]->getuid() << " " << s[i]->getlogin() << " " << s[i]->getpin() << " " << s[i]->getname() << " " << s[i]->getage() << endl;

		s[i]->fileout(s[i]->getuid());
		s[i]->fileout1();
	}
	fout.close();
	fout1.close();



	system("pause");

}//main