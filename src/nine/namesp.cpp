/*
 * namesp.cpp
 *
 *  Created on: 2018年10月6日
 *      Author: caryliao
 */
#include <iostream>
#include "namesp.h"

namespace pers
{
  using std::cout;
  using std::cin;
  void getPerson(Person & rp)
  {
    cout << "Enter first name: ";
    cin >> rp.fname;
    cout << "Enter last name: ";
    cin >> rp.lname;
  }
  void showPerson(const Person & rp)
  {
    cout << rp.lname << ", " << rp.fname;
  }
}

namespace debts
{
  void getDebt(Debt & rd)
  {
    getPerson(rd.name);
    std::cout << "Enter debt: ";
    std::cin >> rd.amount;
  }
  void showDebt(const Debt & rd)
  {
    showPerson(rd.name);
    std::cout << ": $" << rd.amount << std::endl;
  }
  double sumDebts(const Debt ar[], int n)
  {
    double total = 0;
    for(int i = 0; i < n; i++)
    {
      total += ar[i].amount;
    }
    return total;
  }
}

void testNameSpace()
{
  using debts::Debt;
  using debts::showDebt;

  Debt golf = {{"Benny", "Goatsniff"}, 120.0};
  showDebt(golf);
  other();
  another();

}
void other()
{
  using std::cout;
  using std::endl;
  using namespace debts;
  Person dg = {"Doodles", "Glister"};
  showPerson(dg);
  cout << endl;
  Debt zippy[3];
  int i;
  for(i = 0; i < 3; i++)
  {
    getDebt(zippy[i]);
  }
  for(i = 0; i < 3; i++)
  {
    showDebt(zippy[i]);
  }
  cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
}
void another()
{
  using pers::Person;
  Person collector = {"Milo", "Rightshift"};
  pers::showPerson(collector);
  std::cout << std::endl;
}


