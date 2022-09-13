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
    cout << "Sorry, No Math Found." << endl;
  } else {
    cout << "Data of ID " << inputId << " has been removed from file.";
  }

  fileToRead.close();
  fileToWrite.close();
  remove(filePath.c_str());
  rename(tempFilePath.c_str(), filePath.c_str());
  basicNavigation();
}
