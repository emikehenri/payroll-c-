#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

struct information {
	int id;
	string fname;
	string lname;
	string department;
	double workhr;
	double salary;
};

struct decuction{
	int tax;
	int sss;
	int pagibig;
};

void displaychoice(int options);
void addEmployee();
void exportinfo(information &info);
void displayinfo();

int main(){
	
	int choice;
	
	do{
	cout<<"\n";
	cout<<"============================================="<<endl;
	cout<<"=========== Payroll System =================="<<endl;
	cout<<"===== submitted By: Mike Henri S Edralin ===="<<endl;
	cout<<"========== Subject: IT - 122 ================"<<endl;
	cout<<"\n";
	cout<<"================ Main Menu ==================\n"<<endl;
	cout<<"[1]. Add Employee Information: "<<endl;
	cout<<"============================================="<<endl;
	cout<<"[2]. View Employee Information: "<<endl;
	cout<<"============================================="<<endl;
	cout<<"[3]. Calculate Total Salary: "<<endl;
	cout<<"============================================="<<endl;
	cout<<"[4]. Print Salary Information: "<<endl;
	cout<<"============================================="<<endl;
	cout<<"[5]. Exit Menu: "<<endl;
	cout<<"============================================="<<endl;
	
	cout<<"Select from the menu: ";
	cin>>choice;
	displaychoice(choice);
	
}while(choice != 5);

	return 0;
}

void displaychoice(int options){
	
	switch(options){
		case 1:
			addEmployee();
			break;
		case 2: 
			displayinfo();
			break;
		case 3: 
			cout<<"calculate"<<endl;
			break;
		case 4:
			cout<<"print check"<<endl;
			break;
		case 5:
			cout<<"exited"<<endl;
			break;
			
		default:
			cout<<"failed to select"<<endl;
			
			}
}

void addEmployee() {
    information info;

    cout << "Add Employee Id: ";
    cin >> info.id;

    cout << "Add Employee First Name: ";
    cin >> info.fname;

    cout << "Add Employee Last Name: ";
    cin >> info.lname;

    cout << "Add your Department: ";
    cin >> info.department;

    cout << "Add How many Working Hours: ";
    cin >> info.workhr;

    cout << "Add Salary Per Hour: ";
    cin >> info.salary;
    
    exportinfo(info);
	}

	
void exportinfo(information &info) {
  ofstream outFile("employeeinfo.dat", ios::app);
  if (outFile.is_open()) {
    outFile << info.id << " " << info.fname << " " << info.lname << " "
            << " " << info.department << " " << fixed << setprecision(2)
            << info.workhr << " " << fixed << setprecision(2) << info.salary << endl;
    outFile.close();
    cout << "Successfully added employee." << endl;
  } else {
    cout << "Error: Could not open file for export." << endl;
  }
}

void displayinfo() {
  ifstream infile("employeeinfo.dat");
  if (infile.is_open()) {
    cout << "| ID | 	First Name |	 Last Name | 	Department | 	Work Hours | 	Salary |" << endl;

    string id, fname, lname, department, workhour, salary;
    while (infile >> id >> fname >> lname >> department >> workhour >> salary) {
      cout << "| " << setw(2) << id << " | " << setw(6) << fname << " | "
           << setw(15) << lname << " | " << setw(3) << " | "
           << setw(12) << department << " | " << setw(10) << workhour << " | "
           << setw(8) << salary << " |" << endl;
    }
    infile.close();
  } else {
    cout << "Error: Could not open file for viewing." << endl;
  }
}
