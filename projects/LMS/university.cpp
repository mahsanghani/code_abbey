//
// Created by Ahsan Ghani on 2022-09-13.
//
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utils/utilities.h>

using namespace std;

const short NAME_LENGTH = 29;

class SchoolMember {
protected:
  char name[NAME_LENGTH];
  int id;

private:
public:
  SchoolMember() { id = 0; }

  int getId() const { return id; }
};

template <typename T>
void removeMember(const string filePath, const string tempFilePath,
                  const T schoolMember) {
  system("cls");
  int inputId = 0;
  short flag = 0;
  ifstream fileToRead(filePath, ios::binary);
  ofstream fileToWrite(tempFilePath, ios::binary | ios::app);
  fileToRead.seekg(0);
  cout << "Enter ID of person whose data has to be removed: " << endl;
  cin >> inputId;

  while (fileToRead.read((char *)&schoolMember, sizeof(schoolMember))) {
    if (inputId == schoolMember.getId()) {
      flag++;
    } else {
      fileToWrite((char *)&schoolMember, sizeof(schoolMember));
    }
  }

  if (flag == 0) {
    cout << "Sorry, no match found." << endl;
  } else {
    cout << "Data of ID " << inputId << " has been removed from file.";
  }

  fileToRead.close();
  fileToWrite.close();
  remove(filePath.c_str());
  rename(tempFilePath.c_str(), filePath.c_str());
  basicNavigation();
}

template <typename T> void addMember(const string filePath, T schoolMember) {
  fstream file(filePath, ios::in | ios::out | ios::app | ios::binary);
  schoolMember.inputDetails();
  file.write((char *)&schoolMember, sizeof(schoolMember));
  file.close();
  basicNavigation();
}

template <typename T>
void viewData(const string filePath, const T schoolMember) {
  system("cls");
  ifstream fileToRead(filePath, ios::binary);
  fileToRead.seekg(0);
  int inputId = 0;
  short flag = 0;

  cout << "Enter ID of person whose data records you want to see: " << endl;
  cin >> inputId;

  while (fileToRead.read((char *)&schoolMember, sizeof(schoolMember))) {
    if (inputId == schoolMember.getId()) {
      ++flag;
      break;
    }
  }
  if (flag > 0) {
    schoolMember.displayData();
  } else {
    cout << "Sorry, no match found." << endl;
  }
  basicNavigation();
}

template <typename T>
void updateMemberData(const string filePath, T schoolMember) {
  system("cls");
  int inputId = 0;
  short flag = 0;
  long filePosition = 0;
  fstream file(filePath, ios::in | ios::out | ios::binary);

  if (file) {
    file.seekg(0);
    cout << "Enter ID or roll number of person whose data has to be updated: ";
    cin >> inputId;

    while (!file.eof()) {
      filePosition = file.tellg();
      file.read((char *)&schoolMember, sizeof(schoolMember));

      if (inputId == schoolMember.getId()) {
        ++flag;
        break;
      }
    }

    if (flag > 0) {
      schoolMember.updateData();
      file.seekg(filePosition);
      file.write((char *)&schoolMember, sizeof(schoolMember));
      cout << "\nFile has been successfully updated." << endl;
    } else {
      cout << "Sorry, no match found." << endl;
    }
  } else {
    cout << "\nOops! There is something wrong with this file " << filePath
         << ". Please make sure it is in the right directory." << endl;
  }

  basicNavigation();
}

template <typename T>
void paySalaryToMember(const string filePath, T schoolMember) {
  system("cls");
  int inputId = 0;
  int salaryPaid = 0;
  long filePosition = 0;
  short flag = 0;
  fstream file(filePath, ios::in | ios::out | ios::binary);
  file.seekg(0);
  cout << "Enter ID to pay salary: " << endl;
  cin >> inputId;

  while (!file.eof()) {
    filePosition = file.tellg();
    file.read((char *)&schoolMember, sizeof(schoolMember));

    if (inputId == schoolMember.getId()) {
      ++flag;
      break;
    }
  }

  if (flag == 0) {
    cout << "Sorry, ID " << inputId << " not found.";
  } else if (schoolMember.getSalary() == 0) {
    cout << "Congratulations! Total annual salary has been paid to "
         << schoolMember.getId() << ".";
  } else {
    cout << "Remaining salary to be paid to " << schoolMember.getId()
         << " is $ " << schoolMember.getSalary()
         << ". Enter the salary to be paid ($): ";
    cin >> salaryPaid;

    while (salaryPaid > schoolMember.getSalary() || salaryPaid < 0) {
      cout << "You have entered invalid salary. Please enter a valid salary "
              "($): "
           << endl;
      cin >> salaryPaid;
    }

    schoolMember.deductSalary(salaryPaid);
    file.seekg(filePosition);
    file.write((char *)&schoolMember, sizeof(schoolMember));
    cout << "You have successfully paid " << salaryPaid
         << ". Now remaining salary for " << schoolMember.getId() << " is: $ "
         << schoolMember.getSalary();
  }

  file.close();
  basicNavigation();
}
