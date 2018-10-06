/*
 * twofile2.cpp
 *
 *  Created on: 2018年10月5日
 *      Author: caryliao
 */
#include <iostream>
extern int tom;
static int dick = 10;
int harry = 200;

void remote_access()
{
  using namespace std;
  cout << "remote_1111access() reports the following addresss:" << endl;
  cout << &tom << " = &tom, " << &dick << " = &dick, ";
  cout << &harry << " = &harry" << endl;
}



