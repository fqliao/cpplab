/*
 * twofile1.cpp
 *
 *  Created on: 2018年10月5日
 *      Author: caryliao
 */
#include <iostream>
int tom = 3; //external variable definition
int dick = 30; //external variable definition
static int harry = 300; //static interanl linkage

void remote_access();
void testTwofile1();

void testTwofile1()
{
  using namespace std;
  cout << "main() reports the following addresses:" << endl;
  cout << &tom << " = &tom, " << &dick << " = &dick, ";
  cout << & harry << " = &harry" << endl;
  remote_access();
}





