#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>

using namespace std;

class Base1
{
protected:
    string id;
    char gender;
    string name;
    int dd, mm, yyyy;
    string bloodGroup;
    string disease;

public:
    void setDOB(int dd, int mm, int yyyy);
    void getDOB();
    void validateDOB(int dd, int mm, int yyyy);

    void validateBloodGroup(string bloodGroups[8], int choice);
    void getBloodGroup();

    string getName()
    {
        return name;
    }

    string getID(){
        return id;
    }

    string getBloodGrp()
    {
        return bloodGroup;
    }

    string getDisease()
    {
        return disease;
    }

    vector<int> returnDOB()
    {
        vector<int> dob;
        dob.push_back(dd);
        dob.push_back(mm);
        dob.push_back(yyyy);

        return dob;
    }
    char getGen()
    {
        return gender;
    }
    void getBase1();
};

void Base1::getBase1()
{
    cout<<"\nEnter Patient ID: ";
    fflush(stdin);
    getline(cin, id);
    cout << "\nEnter Name of Patient: ";
    fflush(stdin);
    getline(cin, name);

    this->getDOB();
    this->getBloodGroup();
    cout << "\nEnter Disease: ";
    fflush(stdin);
    getline(cin, disease);
    cout << "\nEnter Gender of Patient(M/F): ";
    fflush(stdin);
    cin >> gender;
}

void Base1::getBloodGroup()
{
    string bloodGroups[8]{"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    fflush(stdin);
    cout << "\t1) A+\t2) A-\n\t3) B+\t4) B-\n\t5) AB+\t6) AB-\n\t7) O+\t8) O-\nEnter Serial Number of the bloodGroup: ";

    int choice;
    cin >> choice;

    this->validateBloodGroup(bloodGroups, choice);
}
void Base1::validateBloodGroup(string bloodGroups[8], int choice)
{
    if (choice < 1 || choice > 8)
    {
        cout << "\nEnter Valid Blood Group: ";
        this->getBloodGroup();
    }

    else
    {
        bloodGroup = bloodGroups[choice - 1];
    }
}

void Base1::getDOB()
{
    int dd, mm, yyyy;

    cout << "\nEnter Date of Birth(DD/MM/YYYY): ";

    cin >> dd;
    cin.get();
    cin >> mm;
    cin.get();
    cin >> yyyy;

    this->validateDOB(dd, mm, yyyy);
}

void Base1::setDOB(int dd = 1, int mm = 1, int yyyy = 2000)
{
    this->dd = dd;
    this->mm = mm;
    this->yyyy = yyyy;
}

void Base1::validateDOB(int dd = 1, int mm = 1, int yyyy = 2000)
{
    int flag = 1;

    if (yyyy < 1950 || yyyy > 2019)
    {
        flag = 0;
    }
    else if (mm < 1 && mm > 12)
    {
        flag = 0;
    }

    else if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && (dd > 31 || dd < 1))
    {
        flag = 0;
    }
    else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd > 30 || dd < 1))
    {
        flag = 0;
    }
    else
    {
        if (dd > 29 || dd < 1)
        {
            flag = 1;
        }
    }

    if (flag)
    {
        this->setDOB(dd, mm, yyyy);
    }
    else
    {
        cout << "\nInvalid Date!Enter Again....\n";
        this->getDOB();
    }
}

class Derived : public Base1
{
protected:
    unsigned long long phoneNo;
    void getNvalidatePhone();

public:
    bool show;
    Derived()
    {
        show = true;
    }
    unsigned long long getPhone()
    {
        return phoneNo;
    }
    void GetData();
    void ShowData();

};

void Derived::getNvalidatePhone()
{
    int flag = true;
    do
    {
        cout << "\nEnter Phone Number: ";
        cin >> phoneNo;

        if (phoneNo > 7000000000 && phoneNo < 10000000000)
        {
            this->phoneNo = phoneNo;
            flag = false;
        }
        else
        {
            cout << "\nInvalid Number! Try Again....";
        }
    } while (flag);
}

void Derived::GetData()
{
    this->getBase1();
    this->getNvalidatePhone();
}

void Derived::ShowData()
{

    if (this->show == true)
    {
        cout << endl;
        cout<< id << "\t\t";
        cout << name << "\t\t" << dd << "/" << mm << "/" << yyyy << "\t" << bloodGroup << "\t\t\t" << gender << "\t\t" << disease << "\t\t" << phoneNo;

    }

}

void writeFile(Derived mastertable[], int i)
{
    fstream afile;
    afile.open("hospital.txt", ios ::in | ios ::out | ios ::app);

    afile << "\n";

        //int id;
        vector<int> temp = mastertable[i].returnDOB();
        int dd = temp[0];
        int mm = temp[1];
        int yyyy = temp[2];

        afile<<mastertable[i].getID()<<"\t\t"<< mastertable[i].getName() << "\t\t" << dd << "/" << mm << "/" << yyyy << "\t\t" << mastertable[i].getBloodGrp() << "\t\t" << mastertable[i].getGen() << "\t\t" << mastertable[i].getDisease() << "\t\t" << mastertable[i].getPhone();

        afile << "\n";


    afile.close();
}

void dispfile(){
    string line;

    ifstream afile("hospital.txt");

    while(getline(afile,line)){
            cout<<line<<endl;
    }


}


void searchdata(){
    ifstream afile;
	afile.open("hospital.txt");
	if(afile.fail())
	{
		cout << "Input file opening failed!\n";
		exit(1);
	}
	string searchName;
	cout << "Please enter Patient ID to Search: ";
	cin  >> searchName;
	bool isFound=0;
	while(!afile.eof())
	{
		string temp = "";
		getline(afile,temp);
		for(int i=0;i<searchName.size();i++)
		{
			if(temp[i]==searchName[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}

		if(isFound)
		{
			cout << "Record Found!\n";
			for(int i = searchName.size();i<=temp.size();i++)
            cout << temp[i];
            break;
		}

	}

	if(afile.eof()&&(!isFound))
	{
		cout << "Record Not found!\n";
	}

	afile.close();

}



int main()
{
    int login();
    login();
    int choice, i = 0, f ;
    Derived masterTable[15];
    string searchName;

    cout << "\nWELCOME TO HOSPITAL MANAGEMENT SYSTEM!\n\n";
    do
    {

        cout << "\nMenu:\n1.Accept New Patient's Data\n2.Display Data \n3.Display All Records\n4.Search Data\n5.Delete Data\n6.Exit\n\nEnter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            masterTable[i].GetData();

            writeFile(masterTable, i);
            i++;
            break;

        case 2:
            cout << "\nDisplaying  Data\n";
            cout << "ID\t\tNAME\t\tDOB\t\tBLOOD GROUP\t\tGENDER\t\tDISEASE\t\tCONTACT.NO";
            for (int j = 0; j < i; j++)
            {
                masterTable[j].ShowData();
            }

            cout << "\n\n";
            break;
        case 3:
            cout << "\nDisplaying All Records\n";
            cout << "ID\t\tNAME\t\tDOB\t\tBLOOD GROUP\t\tGENDER\t\tDISEASE\t\tCONTACT.NO";

            dispfile();
            break;
        case 4:
            fflush(stdin);
            searchdata();

            break;

        case 5:
            string line, searchName;
            cout << "Please Enter the Patient ID you want to Delete: ";
            cin >> searchName;
            ifstream afile;
            afile.open("hospital.txt");
            ofstream temp;
            temp.open("temp.txt");
            while (getline(afile, line))
                {
                        if (line.substr(0, searchName.size()) != searchName)
                        temp << line << endl;
                }
            cout <<"\nDeleted Successfully!"<<endl;
            afile.close();
            temp.close();
            remove("hospital.txt");
            rename("temp.txt", "hospital.txt");

            break;

        }
    } while (choice != 6);
    return 0;

}

int login(){
   string pass ="";
   char ch;
   cout<<"\n\n****************HOSPITAL MANAGEMENT SYSTEM****************\n";
   cout<<"\nLOGIN";
   cout <<"\nEnter Password: ";
   ch = _getch();
   while(ch != 13)
   {
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\nAccess Granted!\n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\nAccess Denied! Please Try Again....\n";
      system("PAUSE");
      system("CLS");
      login();
   }
   return 0;
}
