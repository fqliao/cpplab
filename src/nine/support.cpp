/*
 * external.cpp
 *
 *  Created on: 2018年10月5日
 *      Author: caryliao
 */
#include<iostream>

using namespace std;
extern double warming; //use warming from another file

void update(double dt);
void local();
void testExternal();

void update(double dt) //modifies global variable
{
  warming += dt;  //uses global warming
  cout << "Updating global warming to " << warming;
  cout << " degrees." << endl;
}

void local()
{
  double warming = 0.8; // new variable hides external one
  cout << "Local warming = " << warming << " degrees." << endl;
  // Access global variable with the scope resolution operator
  cout <<"But global warming = " << ::warming;
  cout << " degrees." << endl;

}

void testExternal()
{
  cout << "Global warming is " << warming << " degrees." << endl;
  update(0.1);
  cout << "Global warming is " << warming << " degrees." << endl;
  local();
}




