//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
  int account_number;
  string owner_name;
  double available_funds;

public:
  void setAccountNumber(int account_num);
  void setOwnerName(string name);
  void setAvailableFunds(double funds);

  int getAccountNumber() const;
  string getOwnerName() const;
  double getAvailableFunds() const;
};
