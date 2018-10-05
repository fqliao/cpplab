/*
 *
 *  Created on: 2018年9月16日
 *      Author: caryliao
 */
#include<iostream>
#include<cmath>
#include "coordin.h"

using namespace std;

polar rect_to_polar(rect xypos)
{
  polar answer;

  answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
  answer.angle = atan2(xypos.y, xypos.x);
  return answer;
}

void show_polar(polar dapos)
{
  const double Rad_to_deg = 57.29577951;

  cout << "distance = " << dapos.distance;
  cout << ", angle = " << dapos.angle * Rad_to_deg;
  cout << " degrees" << endl;
}

void testPolar()
{
  rect rplace;
  polar pplace;

  cout << "Enter the x and y values: ";
  while(cin >> rplace.x >> rplace.y) //input is two number, cin return true ,otherwise, return false
  {
    pplace = rect_to_polar(rplace);
    show_polar(pplace);
    cout << "Next two numbers (q to quit): ";
  }
  cout << "Bye!" << endl;
}





