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

void BankAccount::setAccountNumber(int account_num) {
  this->account_number = account_num;
}

void BankAccount::setOwnerName(std::string name) { this->owner_name = name; }

void BankAccount::setAvailableFunds(double funds) {
  this->available_funds = funds;
}

int BankAccount::getAccountNumber() const { return account_number; }

std::string BankAccount::getOwnerName() const { return owner_name; }

double BankAccount::getAvailableFunds() const { return available_funds; }

int main() {
  BankAccount bank_account;
  bank_account.setAccountNumber(12);
  bank_account.setOwnerName("Jacky Chan");
  bank_account.setAvailableFunds(123.34);

  std::cout << "this bank account has account number: "
            << bank_account.getAccountNumber() << std::endl
            << "which belongs to : " << bank_account.getOwnerName() << std::endl
            << "and it contains available funds: "
            << bank_account.getAvailableFunds() << std::endl;
}