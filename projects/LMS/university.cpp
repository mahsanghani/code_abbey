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

class Student : public SchoolMember {
private:
  int studentFee;

protected:
  using SchoolMember::id;

public:
  using SchoolMember::name;
  short studentClass;
  char motherName[NAME_LENGTH];
  char fatherName[NAME_LENGTH];
  char studentSection;

  Student() {
    id = 1;
    studentFee = 0;
  }

  int getId() const { SchoolMember::getId(); }

  void inputDetails();
  void updateData();
  void generateRollNumber();
  void displayData() const {
    displayNameInUpper(name, strlen(name));
    cout << "\nRoll Number: " << id << "\nClass: " << studentClass << " '"
         << char(toupper(studentSection)) << "' "
         << "\nMother's name: " << motherName
         << "\nFather's name: " << fatherName << "\nRemaining fee: Rs."
         << studentFee;
  }

  void deductFee(int amountPaid) { studentFee = studentFee - amountPaid; }

  int getStudentFee() const { return studentFee; }
};

void Student::generateRollNumber() {
  Student schoolStudentTemp;
  fstream studentFile("data/student.dat",
                      ios::in | ios::out | ios::app | ios::binary);
  short flag = 0;
  while (
      studentFile.read((char *)&schoolStudentTemp, sizeof(schoolStudentTemp))) {
    if (studentClass == schoolStudentTemp.studentClass &&
        studentSection == schoolStudentTemp.studentSection) {
      ++flag;
      sanitizeCharArray(name, NAME_LENGTH);
      sanitizeCharArray(name, NAME_LENGTH);
      if (strcmp(name, schoolStudentTemp.name) == 0) {
        id = schoolStudentTemp.id + 1;
        break;
      } else {
        for (short i = 0; i < 5; ++i) {
          if (schoolStudentTemp.name[i] > name[i]) {
            schoolStudentTemp.id++;
            id = schoolStudentTemp.id - 1;
            break;
          } else if (schoolStudentTemp.name[i] < name[i]) {
            id = schoolStudentTemp.id + 1;
            break;
          } else {
            continue;
          }
        }
      }
    }
  }
  if (flag == 0)
    id = (studentClass * 1000) + (studentSection - 96) * 100 + id;
}

void Student::inputDetails() {
  system("cls");
  cout << "Enter student name (max. 28 characters): ";
  // fixes skipping of input; this must be used when `cin` precedes `getline()`
  // or `cin.get()`
  cin.ignore();
  gets(name);
  cout << "Enter the class (1 to 12): ";
  cin >> studentClass;
  cout << "Enter the section ('A' to 'D'): ";
  cin >> studentSection;
  studentSection = tolower(studentSection);
  cout << "Enter the annual fee student needs to pay (in Rs.): ";
  cin >> studentFee;
  cout << "Enter student father's name (max. 28 characters): ";
  cin.ignore();
  gets(fatherName);
  cout << "Enter student mother's name (max. 28 characters): ";
  gets(motherName);
  generateRollNumber();
  cout
      << "\nGenerated roll number is " << getId()
      << ". Please, note it safely as it'll be asked during data modification.";
}

void receiveStudentFee() {
  system("cls");
  Student schoolStudent;
  int inputRollNumber = 0, amountPaid = 0;
  short flag = 0;
  long filePosition = 0;
  fstream studentFile("data/student.dat", ios::in | ios::out | ios::binary);
  cout << "Enter the roll number of student whose fees you want to receive: ";
  cin >> inputRollNumber;
  while (!studentFile.eof()) {
    filePosition = studentFile.tellg();
    studentFile.read((char *)&schoolStudent, sizeof(schoolStudent));
    if (inputRollNumber == schoolStudent.getId()) {
      flag++;
      break;
    }
  }
  if (flag == 0)
    cout << "Sorry, Roll number not found.";
  else if (schoolStudent.getStudentFee() == 0)
    cout << "Congratulations! All dues are clear for student "
         << schoolStudent.getId() << ".";
  else {
    cout << "Remaining fees to be paid by student " << schoolStudent.getId()
         << " is Rs." << schoolStudent.getStudentFee()
         << ". Enter fee you want to receive (in Rs.): ";
    cin >> amountPaid;
    while (amountPaid > schoolStudent.getStudentFee() || amountPaid < 0) {
      cout
          << "Sorry, we received an invalid fee. Please enter again (in Rs.): ";
      cin >> amountPaid;
    }
    schoolStudent.deductFee(amountPaid);
    studentFile.seekg(filePosition);
    studentFile.write((char *)&schoolStudent, sizeof(schoolStudent));
    cout << "We have successfully received " << amountPaid
         << ". Now remaining fee for student " << schoolStudent.getId()
         << " is: " << schoolStudent.getStudentFee();
  }
  studentFile.close();
  basicNavigation();
}

void Student::updateData() {
  char userChoice = ' ';
  cout << "Press '+' to update student name or press 'Enter' key to retain old "
          "data: ";
  cin.ignore();
  cin.get(userChoice);
  if (userChoice == '+' &&
      userChoice != 10) // 10 is ASCII value of linefeed (enter key)
  {
    cout << "Enter new name (max. 28 characters): ";
    cin.ignore();
    gets(name);
  }
  cout << "\nPress '+' to update student class or press 'Enter' key to retain "
          "old data: ";
  cin.get(userChoice);
  if (userChoice == '+' && userChoice != 10) {
    cout << "Enter new class (1 - 12): ";
    cin.ignore();
    cin >> studentClass;
    cin.ignore();
  }
  cout << "\nPress '+' to update student section or press 'Enter' key to "
          "retain old data: ";
  cin.get(userChoice);
  if (userChoice == '+' && userChoice != 10) {
    cout << "Enter new section ('A' to 'D'): ";
    cin.ignore();
    cin >> studentSection;
    cin.ignore();
  }
  cout << "\nPress '+' to update student annual fee or press 'Enter' key to "
          "retain old data: ";
  cin.get(userChoice);
  if (userChoice == '+' && userChoice != 10) {
    cout << "Enter new annual fee (in Rs.): ";
    cin.ignore();
    cin >> studentFee;
    cin.ignore();
  }
  cout << "\nPress '+' to update student father's name or press 'Enter' key to "
          "retain old data: ";
  cin.get(userChoice);
  if (userChoice == '+' && userChoice != 10) {
    cout << "Enter father's name (max. 28 characters): ";
    cin.ignore();
    gets(fatherName);
  }
  cout << "\nPress '+' to update student mother's name or press 'Enter' key to "
          "retain old data: ";
  cin.get(userChoice);
  if (userChoice == '+' && userChoice != 10) {
    cout << "Enter mother's name (max. 28 characters): ";
    cin.ignore();
    gets(motherName);
  }
  generateRollNumber();
  cout
      << "\nGenerated roll number is " << getId()
      << ". Please, note it safely as it'll be asked during data modification.";
}
