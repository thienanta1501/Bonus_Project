#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

struct Course;
struct List_Course;

struct ID_User {
	string Social_ID;
	string Password;
};

struct Node_ID {
	ID_User User;
	Node_ID* next;
};

struct List_ID {
	Node_ID* head;
	Node_ID* tail;
};

Node_ID* createNodeID(ID_User x);
void initListID(List_ID& l);
void inputOneID(ifstream& ListID, ID_User& x);
void inputListID(ifstream& ListID, List_ID& l);
void outputListID(List_ID l);
bool checkID(List_ID l, ID_User* User);

struct Staff {
	string No;
	string Staff_ID;
	string First_Name;
	string Last_Name;
	string Gender;
	string DateOfBirth;
	string Social_ID;
};

struct Node_Staff {
	Staff User;
	Node_Staff* next;
};

struct List_Staff {
	Node_Staff* head;
	Node_Staff* tail;
};

Node_Staff* createNodeStaff(Staff x);
void initListStaff(List_Staff& l);
void inputOneStaff(fstream& ListStaff, Staff& x);
void outputOneStaff(Staff x);
void inputListStaff(fstream& ListStaff, List_Staff& l);
void outputListStaff(List_Staff l);

struct Student {
	string No;
	string Student_ID;
	string First_Name;
	string Last_Name;
	string Gender;
	string DateOfBirth;
	string Social_ID;
	//List_Course lCOfStudent;
};

struct Node_Student {
	Student User;
	Node_Student* next;
};

struct List_Student {
	string ClassName;
	Node_Student* head;
	Node_Student* tail;
};

Node_Student* createNodeStudent(Student x);
void initListStudent(List_Student& l);
void inputOneStudent(fstream& ListStudent, Student& x);
void outputOneStudent(Student x);
void inputListStudent(fstream& ListStudent, List_Student& l);
void outputListStudent(List_Student l);

void viewInfo(List_Staff lS, List_Student l, ID_User* User);

Node_ID* checkListID(List_ID l, ID_User* User);
void changePassword(ID_User* User, List_ID& l, string newPassword);
void outputFileListID(ofstream& ListID, List_ID l);

struct StudentMark {
	string No;
	string Student_ID;
	string StudentFullName;
	float TotalMark;
	float FinalMark;
	float MidtermMark;
	float OtherMark;
};

struct Node_StudentMark {
	StudentMark a;
	Node_StudentMark* next;
};

struct Scoreboard {
	Node_Student* head;
	Node_Student* tail;
};

struct Course {
	string CourseID;
	string CourseName;
	string ClassName;
	string TeacherName;
	int Credits_num;
	int Max_Student = 50;
	string DayOfWeek; //string Day[6] = {MON, TUE, WED, THU, FRI, SAT};
	string Session; //string Session[4] = { S1 (07:30), S2 (09:30), S3 (13:30), S4 (15:30)}; 
	List_Student ListOfStudent;
	Scoreboard MarksOfClass;
};

struct Node_Course {
	Course course;
	Node_Course* next;
};

struct List_Course {
	Node_Course* head;
	Node_Course* tail;
};

struct Semester {
	int Name;
	string SchoolYear;
	string Start;
	string End;
	List_Course lC;
};


struct Node_School_Year {
	List_Student a;
	Node_School_Year* next;
};

struct List_School_Year {
	string Name;
	Semester semester[3];
	Node_School_Year* head;
	Node_School_Year* tail;
};

struct Node_Year {
	List_School_Year a;
	Node_Year* next;
};

struct List_Year {
	Node_Year* head;
	Node_Year* tail;
};

Node_School_Year* createNodeSchoolYear(List_Student x);
void initListSchoolYear(List_School_Year& l);
void inputOneSchoolYear(fstream& ListStudent, List_Student& x);
void inputListSchoolYear(List_School_Year& l, List_Student x);
void outputListSchoolYear(List_School_Year l);

Node_Year* createNodeYear(List_School_Year x);
void initListYear(List_Year& l);
void inputListYear(List_Year& l, List_School_Year x);
void outputListYear(List_Year l);

static List_Year lAll;

