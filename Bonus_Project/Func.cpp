#include "Project.h"

void outputDate(Date x)
{
	if (x.day.length() == 1) cout << "0" << x.day << "/";
	else cout << x.day << "/";
	if (x.month.length() == 1) cout << "0" << x.month << "/";
	else cout << x.month << "/";
	cout << x.year;
}

//Function of ListID
Node_ID* createNodeID(ID_User x)
{
	Node_ID* p = new Node_ID;
	p->User = x;
	p->next = NULL;
	return p;
}

void initListID(List_ID& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputOneID(ifstream& ListID, ID_User& x)
{
	getline(ListID, x.Social_ID, ','); 
	getline(ListID, x.Password);
}

void inputListID(ifstream& ListID, List_ID& l)
{
	while (ListID.eof() == false)
	{
		ID_User x;
		inputOneID(ListID, x);
		Node_ID* q = createNodeID(x);
		if (l.head == NULL)
		{
			l.head = q;
			l.tail = q;
		}
		else
		{
			l.tail->next = q;
			l.tail = q;
		}
	}
}

void outputListID(List_ID l) //test inputListID
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		cout << p->User.Social_ID << ", " << p->User.Password << endl;
		p = p->next;
	}
}

//Function of Staff
Node_Staff* createNodeStaff(Staff x)
{
	Node_Staff* p = new Node_Staff;
	p->User = x;
	p->next = NULL;
	return p;
}

void initListStaff(List_Staff& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputOneStaff(fstream& ListStaff, Staff& x)
{
	getline(ListStaff, x.No, ',');
	getline(ListStaff, x.Staff_ID, ',');
	getline(ListStaff, x.First_Name, ',');
	getline(ListStaff, x.Last_Name, ',');
	getline(ListStaff, x.Gender, ',');
	getline(ListStaff, x.DateOfBirth.day, '/');
	getline(ListStaff, x.DateOfBirth.month, '/');
	getline(ListStaff, x.DateOfBirth.year, ',');
	getline(ListStaff, x.Social_ID);
}

void outputOneStaff(Staff x)
{
	cout << "---------------YOUR OWN PROFILE INFORMATION---------------" << endl;
	cout << "Number: " << x.No << endl;
	cout << "ID: " << x.Staff_ID << endl;
	cout << "First Name: " << x.First_Name << endl;
	cout << "Last Name: " << x.Last_Name << endl;
	cout << "Gender: " << x.Gender << endl;
	cout << "Date of Birth: ";
	outputDate(x.DateOfBirth);
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}

void inputListStaff(fstream& ListStaff, List_Staff& l)
{
	while (ListStaff.eof() == false)
	{
		Staff x;
		inputOneStaff(ListStaff, x);
		Node_Staff* q = createNodeStaff(x);
		if (l.head == NULL)
		{
			l.head = q;
			l.tail = q;
		}
		else
		{
			l.tail->next = q;
			l.tail = q;
		}
	}
}

void outputListStaff(List_Staff l) //test inputListStaff
{
	Node_Staff* p = l.head;
	while (p != NULL)
	{
		outputOneStaff(p->User);
		p = p->next;
	}
}

//Function of Student
Node_Student* createNodeStudent(Student x)
{
	Node_Student* p = new Node_Student;
	p->User = x;
	p->next = NULL;
	return p;
}

void initListStudent(List_Student& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputOneStudent(fstream& ListStudent, Student& x)
{
	getline(ListStudent, x.No, ',');
	getline(ListStudent, x.Student_ID, ',');
	getline(ListStudent, x.First_Name, ',');
	getline(ListStudent, x.Last_Name, ',');
	getline(ListStudent, x.Gender, ',');
	getline(ListStudent, x.DateOfBirth.day, '/');
	getline(ListStudent, x.DateOfBirth.month, '/');
	getline(ListStudent, x.DateOfBirth.year, ',');
	getline(ListStudent, x.Social_ID);
}

void outputOneStudent(Student x)
{
	cout << "----------------------------------------------------------" << endl;
	cout << "Number: " << x.No << endl;
	cout << "ID: " << x.Student_ID << endl;
	cout << "First Name: " << x.First_Name << endl;
	cout << "Last Name: " << x.Last_Name << endl;
	cout << "Gender: " << x.Gender << endl;
	cout << "Date of Birth: ";
	outputDate(x.DateOfBirth);
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}

void inputListStudent(fstream& ListStudent, List_Student& l)
{
	while (ListStudent.eof() == false)
	{
		Student x;
		inputOneStudent(ListStudent, x);
		Node_Student* q = createNodeStudent(x);
		if (l.head == NULL)
		{
			l.head = q;
			l.tail = q;
		}
		else
		{
			l.tail->next = q;
			l.tail = q;
		}
	}
}

void outputListStudent(List_Student l) //test inputListStudent
{
	Node_Student* p = l.head;
	while (p != NULL)
	{
		outputOneStudent(p->User);
		p = p->next;
	}
}

//A user must log in to the system
bool checkID(List_ID l, ID_User* User)
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		if ((p->User.Social_ID == User->Social_ID) && (p->User.Password == User->Password))
			return 1;
		p = p->next;
	}
	return 0;
}

//He/she can view his/her own profile info, change the password, or log out the system.

//View his/her own profile info
Node_Staff* checkInfoInListStaff(List_Staff lS, ID_User* User)
{
	Node_Staff* p = lS.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

Node_Student* checkInfoInListStudent(List_Student l, ID_User* User)
{
	Node_Student* p = l.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

void viewInfo(List_Staff lS, List_Student l, ID_User* User)
{
	if (checkInfoInListStaff(lS, User) != 0)
	{
		outputOneStaff(checkInfoInListStaff(lS, User)->User);
		return;
	}
	if (checkInfoInListStudent(l, User) != 0)
	{
		outputOneStudent(checkInfoInListStudent(l, User)->User);
		return;
	}
}

//Change the password
Node_ID* checkListID(List_ID l, ID_User* User)
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

void changePassword(ID_User* User, List_ID& l, string newPassword)
{
	Node_ID* p = checkListID(l, User);
	p->User.Password = newPassword;
}

void outputFileListID(ofstream& ListID, List_ID l)
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		ListID << p->User.Social_ID << ", " << p->User.Password << endl;
		p = p->next;
	}
}

//At the beginning of the school year (often in September), an academic staff member will
//Create a school year (2021-2022...)

//Function of School Year
Node_School_Year* createNodeSchoolYear(List_Student x)
{
	Node_School_Year* p = new Node_School_Year;
	p->a = x;
	p->next = NULL;
	return p;
}

void initListSchoolYear(List_School_Year& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputOneSchoolYear(fstream& ListStudent, List_Student& x)
{
	initListStudent(x);
	inputListStudent(ListStudent, x);
	//outputListStudent(x); //test inputListStudent
}

void inputListSchoolYear(List_School_Year& l, List_Student x)
{
	Node_School_Year* p = createNodeSchoolYear(x);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void outputListSchoolYear(List_School_Year l) //test inputListSchoolYear
{
	Node_School_Year* p = l.head;
	while (p != NULL)
	{
		cout << "-----------------------Class-----------------------" << endl;
		outputListStudent(p->a);
		p = p->next;
	}
}

//Function of Year
Node_Year* createNodeYear(List_School_Year x)
{
	Node_Year* p = new Node_Year;
	p->a = x;
	p->next = NULL;
	return p;
}

void initListYear(List_Year& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputListYear(List_Year& l, List_School_Year x)
{
	Node_Year* p = createNodeYear(x);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void outputListYear(List_Year l) //test inputListYear
{
	Node_Year* p = l.head;
	while (p != NULL)
	{
		cout << "-----------------------School Year-----------------------" << endl;
		outputListSchoolYear(p->a);
		p = p->next;
	}
}

//Create a school year
Student enterOneStudent()
{
	Student x;
	cout << "ENTER HIS/HER PROFILE INFORMATION!" << endl;
	cout << "No: ";
	cin >> x.No;
	cout << "Student ID: ";
	cin >> x.Student_ID;
	cout << "First Name: ";
	cin >> x.First_Name;
	cout << "Last Name: ";
	cin >> x.Last_Name;
	cout << "Date of Birth: ";
	cin >> x.DateOfBirth.day;
	cin >> x.DateOfBirth.month;
	cin >> x.DateOfBirth.year;
	cout << "Social ID: ";
	cin >> x.Social_ID;
	return x;
}

void add1stStudent(List_Student& l, Student x)
{
	Node_Student* p = createNodeStudent(x);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void SCHOOLYEAR(List_Year& lAll)
{
	int course_num = 3; //Bien dem cac nam hoc t�nh 2018-2019 la 0
	//SEPTEMBER
	//An academic staff member will
	//if user is staff will
	cout << "At the beginning of a school year (often in September), you can: " << endl;
	cout << "1. Create a school year." << endl;
	course_num++;
	List_School_Year _2022_2023;
	initListSchoolYear(_2022_2023);
	//inputListYear(lAll, _2022_2023);
	cout << "2. Create several classes for 1st-year	students." << endl;
	fstream Class22CTT2, Class22CTT3, Class22CTT4;
	List_Student l22CTT2, l22CTT3, l22CTT4;
	inputOneSchoolYear(Class22CTT2, l22CTT2);
	inputOneSchoolYear(Class22CTT3, l22CTT3);
	inputOneSchoolYear(Class22CTT4, l22CTT4);
	cout << "3. Add new 1st year students to 1st-year classes." << endl;
	add1stStudent(l22CTT2, enterOneStudent());
	cout << "4. Import a CSV file." << endl;
	Class22CTT2.open("22CTT2.csv", ios_base::in);
	Class22CTT3.open("22CTT3.csv", ios_base::in);
	Class22CTT4.open("22CTT4.csv", ios_base::in);
	//Create 2022 - 2023
	initListSchoolYear(_2022_2023);
	inputListSchoolYear(_2022_2023, l22CTT2);
	inputListSchoolYear(_2022_2023, l22CTT3);
	inputListSchoolYear(_2022_2023, l22CTT4);
	//outputListSchoolYear(_2022_2023);
	cout << "5. Not need to add 2nd-year, 3rd-year, or 4th-year students." << endl;
	Class22CTT2.close();
	Class22CTT3.close();
	Class22CTT4.close();
}
//Semester
void inputSemester(Semester& a, List_Year lAll)
{
	cout << "ENTER SEMESTER'S INFORMATION!" << endl;
	cout << "NUMBER OF SEMESTER: " << endl;
	cout << "1. Fall." << endl;
	cout << "2. Summer." << endl;
	cout << "3. Autumn." << endl;
	cin >> a.Name;
	cin.ignore();
	lAll.tail->a.semester[a.Name - 1] = a;
	a.SchoolYear = lAll.tail->a.Name;
	cout << "START DATE: " << endl;
	cin >> a.Start;
	cout << "END DATE: " << endl;
	cin >> a.End;
}

void inputCourse(Course& a)
{
	cout << "ENTER COURSE'S INFORMATION!" << endl;
	cout << "COURSE ID: " << endl;
	cin >> a.CourseID;
	cout << "COURSE NAME: " << endl;
	cin >> a.CourseName;
	cout << "CLASS NAME: " << endl;
	cin >> a.ClassName;
	cout << "TEACHER NAME: " << endl;
	cin >> a.TeacherName;
	cout << "NUMBER OF CREDITS: " << endl;
	cin >> a.Credits_num;
	cin.ignore();
	//cout << "THE MAXIMUM NUMBER OF STUDENTS IN THE COURSE: " << endl; DEFAULT: 50
	cout << "DAY OF WEEK: " << endl;
	cin >> a.DayOfWeek;
	cout << "THE SESSION:  " << endl;
	cin >> a.Session;
}

//Function of ListCourse
Node_Course* createNodeCourse(Course x)
{
	Node_Course* p = new Node_Course;
	p->course = x;
	p->next = NULL;
	return p;
}

void initListCourse(List_Course& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void outputOneCourse(Course x)
{
	cout << "Course ID: " << x.CourseID << endl;
	cout << "Course name: " << x.CourseName << endl;
	cout << "Class name: " << x.ClassName << endl;
	cout << "Teacher name: " << x.TeacherName << endl;
	cout << "Number of credits: " << x.Credits_num << endl;
	cout << "The maximum number of students in the course: " << x.Max_Student << endl;
	cout << "Day of the week: " << x.DayOfWeek << endl;
	cout << "The session: " << x.Session << endl;
}

void inputListCourse(List_Course& l)
{
	Course x;
	inputCourse(x);
	Node_Course* q = createNodeCourse(x);
	if (l.head == NULL)
	{
		l.head = q;
		l.tail = q;
	}
	else
	{
		l.tail->next = q;
		l.tail = q;
	}
}

void outputListCourse(Semester a)
{
	cout << "-----------------------LIST OF COURSES-----------------------" << endl;
	Node_Course* p = a.lC.head;
	int temp = 0;
	while (p != NULL)
	{
		temp++;
		cout << temp << ". " << endl;
		outputOneCourse(p->course);
		p = p->next;
	}
}

void updateCourse(Semester& a, string name)
{
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseName == name) {
			inputCourse(p->course);
			return;
		}
		p = p->next;
	}
}

//void inputStudent(Student& a)
//{
//	cout << "ENTER THIS STUDENT'S INFORMATTION"
//	getline(ListStudent, x.No, ',');
//	getline(ListStudent, x.Student_ID, ',');
//	getline(ListStudent, x.First_Name, ',');
//	getline(ListStudent, x.Last_Name, ',');
//	getline(ListStudent, x.Gender, ',');
//	getline(ListStudent, x.DateOfBirth.day, '/');
//	getline(ListStudent, x.DateOfBirth.month, '/');
//	getline(ListStudent, x.DateOfBirth.year, ',');
//	getline(ListStudent, x.Social_ID);
//}

void SEMESTER(List_Year& lAll)
{
	cout << "6. Create a semester. " << endl;
	Semester Sdemo;
	inputSemester(Sdemo, lAll);
	cout << "7. Add a course to this semester. " << endl;
	initListCourse(Sdemo.lC);
	inputListCourse(Sdemo.lC);
	cout << "8. Upload a CSV file containing a list of student enrolled in the course." << endl;
	fstream Class22CTT2;
	List_Student lSOfCourse;
	Class22CTT2.open("22CTT2.csv", ios_base::in);
	initListStudent(lSOfCourse);
	inputListStudent(Class22CTT2, lSOfCourse);
	Sdemo.lC.tail->course.ListOfStudent = lSOfCourse;
	Class22CTT2.close();
	cout << "9. View the list of courses." << endl;
	outputListCourse(Sdemo);
	cout << "10. Update course information." << endl; //Update full information
	string updatingname;
	cout << "ENTER NAME OF THE COURSE THAT YOU WANT TO UPDATE: ";
	cin >> updatingname;
	updateCourse(Sdemo, updatingname);
	cout << "11. Add a student to the course." << endl;
	string StudentIDextra;
	cout << "ENTER STUDENT ID OF STUDENT THAT YOU WANT TO ADD: ";
	cin >> updatingname;

	cout << "12. Remove a student from the course." << endl;

	cout << "13. Delete a course." << endl;






}

//In a semester, a student still can:


