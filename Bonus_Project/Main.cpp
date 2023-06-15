#include "Project.h"

int main()
{
	ifstream ListIDin;
	static fstream ListStaff, Class18CTT2, Class18CTT3, Class18CTT4, Class19CTT2, Class19CTT3, Class19CTT4, Class20CTT2, Class20CTT3, Class20CTT4, Class21CTT2, Class21CTT3, Class21CTT4;
	ListIDin.open("ListID.csv", ios::in);
	List_ID lID;
	initListID(lID);
	inputListID(ListIDin, lID);
	outputListID(lID); //test inputListID
	ListStaff.open("ListStaff.csv", ios_base::in);
	List_Staff lS;
	initListStaff(lS);
	inputListStaff(ListStaff, lS);
	//outputListStaff(lS); //test inputListStaff
	Class18CTT2.open("18CTT2.csv", ios_base::in);
	Class18CTT3.open("18CTT3.csv", ios_base::in);
	Class18CTT4.open("18CTT4.csv", ios_base::in);
	Class19CTT2.open("19CTT2.csv", ios_base::in);
	Class19CTT3.open("19CTT3.csv", ios_base::in);
	Class19CTT4.open("19CTT4.csv", ios_base::in);
	Class20CTT2.open("20CTT2.csv", ios_base::in);
	Class20CTT3.open("20CTT3.csv", ios_base::in);
	Class20CTT4.open("20CTT4.csv", ios_base::in);
	Class21CTT2.open("21CTT2.csv", ios_base::in);
	Class21CTT3.open("21CTT3.csv", ios_base::in);
	Class21CTT4.open("21CTT4.csv", ios_base::in);
	List_Student l18CTT2, l18CTT3, l18CTT4, l19CTT2, l19CTT3, l19CTT4, l20CTT2, l20CTT3, l20CTT4, l21CTT2, l21CTT3, l21CTT4;
	List_School_Year _2018_2019, _2019_2020, _2020_2021, _2021_2022;
	List_Year lAll;
	initListYear(lAll);
	//Create 2018 - 2019
	initListSchoolYear(_2018_2019);
	inputOneSchoolYear(Class18CTT2, l18CTT2);
	inputOneSchoolYear(Class18CTT3, l18CTT3);
	inputOneSchoolYear(Class18CTT4, l18CTT4);
	inputListSchoolYear(_2018_2019, l18CTT2);
	inputListSchoolYear(_2018_2019, l18CTT3);
	inputListSchoolYear(_2018_2019, l18CTT4);
	//outputListSchoolYear(_2018_2019);
	//Create 2019 - 2020
	initListSchoolYear(_2019_2020);
	inputOneSchoolYear(Class19CTT2, l19CTT2);
	inputOneSchoolYear(Class19CTT3, l19CTT3);
	inputOneSchoolYear(Class19CTT4, l19CTT4);
	inputListSchoolYear(_2019_2020, l19CTT2);
	inputListSchoolYear(_2019_2020, l19CTT3);
	inputListSchoolYear(_2019_2020, l19CTT4);
	//outputListSchoolYear(_2019_2020);
	//Create 2020 - 2021
	initListSchoolYear(_2020_2021);
	inputOneSchoolYear(Class20CTT2, l20CTT2);
	inputOneSchoolYear(Class20CTT3, l20CTT3);
	inputOneSchoolYear(Class20CTT4, l20CTT4);
	inputListSchoolYear(_2020_2021, l20CTT2);
	inputListSchoolYear(_2020_2021, l20CTT3);
	inputListSchoolYear(_2020_2021, l20CTT4);
	//outputListSchoolYear(_2020_2021);
	//Create 2021 - 2022
	initListSchoolYear(_2021_2022);
	inputOneSchoolYear(Class21CTT2, l21CTT2);
	inputOneSchoolYear(Class21CTT3, l21CTT3);
	inputOneSchoolYear(Class21CTT4, l21CTT4);
	inputListSchoolYear(_2021_2022, l21CTT2);
	inputListSchoolYear(_2021_2022, l21CTT3);
	inputListSchoolYear(_2021_2022, l21CTT4);
	//outputListSchoolYear(_2021_2022);
	inputListYear(lAll, _2018_2019);
	inputListYear(lAll, _2019_2020);
	inputListYear(lAll, _2020_2021);
	inputListYear(lAll, _2021_2022);
	//outputListYear(lAll);  

	ID_User* User = new ID_User;
	cout << "YOU MUST LOG IN TO THE SYSTEM!" << endl;
	cout << "Enter your ID: " << endl;
	cin >> User->Social_ID;
	cout << "Enter your password: " << endl;
	cin >> User->Password;
	if (!checkID(lID, User)) {
		do
		{
			cout << "YOUR ID OR PASSWORD IS WRONG!" << endl;
			cout << "Enter your ID: " << endl;
			cin >> User->Social_ID;
			cout << "Enter your password: " << endl;
			cin >> User->Password;
		} while (!checkID(lID, User));
	}
	cout << "LOG IN SUCCESSFULLY!" << endl;
	int select;
	do {
		cout << "-----------------------MENU-----------------------" << endl;
		cout << "1. View your profile info." << endl;
		cout << "2. Change your password." << endl;
		cout << "3. Log out of the system." << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "CHOOSE YOUR ACTION!" << endl;
		cin >> select;
	} while (select != 1 && select != 2 && select != 3);
	switch (select)
	{
	case 1: {
		viewInfo(lS, l18CTT2, User);
		viewInfo(lS, l18CTT3, User);
		viewInfo(lS, l18CTT4, User);
		viewInfo(lS, l19CTT2, User);
		viewInfo(lS, l19CTT3, User);
		viewInfo(lS, l19CTT4, User);
		viewInfo(lS, l20CTT2, User);
		viewInfo(lS, l20CTT3, User);
		viewInfo(lS, l20CTT4, User);
		viewInfo(lS, l21CTT2, User);
		viewInfo(lS, l21CTT3, User);
		viewInfo(lS, l21CTT4, User);
		break;
	}
	case 2: {
		string newPassword;
		cout << "ENTER YOUR PASSWORD THAT YOU WANT TO CHANGE INTO: ";
		cin >> newPassword;
		changePassword(User, lID, newPassword);
		//outputListID(lID);
		ofstream ListIDout;
		ListIDout.open("ListID.csv", ios::out);
		outputFileListID(ListIDout, lID);
		ListIDout.close();
		inputListID(ListIDin, lID);
		break;
	}
	case 3: {
		delete User;
		User = NULL;
		cout << "LOGGING OUT OF THE SYSTEM!" << endl;
		main();
		break;
	}
	}

	


	



























	ListIDin.close();
	ListStaff.close();
	system("pause");
	return 0;
}