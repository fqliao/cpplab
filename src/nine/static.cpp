/*
 * static.cpp
 *
 *  Created on: 2018年10月5日
 *      Author: caryliao
 */
#include <iostream>
//constants
const int ArSize = 10;

void strcount(const char * str);
void testStatic();

void testStatic()
{
  using namespace std;
  char input[ArSize];
  char next;

  cout << "Enter a line:" << endl;
  cin.get(input, ArSize);
  while(cin)
  {
    cin.get(next); //获取输入后面的字符
    while(next != '\n') //如果不是换行符，则丢弃剩余输入的字符
    {
      cin.get(next);
    }
    strcount(input);
    cout << "Enter next line(empty line to quit):" << endl;
    cin.get(input, ArSize);
  }
  cout << "Bye" << endl;
}

void strcount(const char * str)
{
  using namespace std;
  static int total = 0; // static local variable
  int count = 0; //automatic local variable

  cout << "\"" << str << "\" contains ";
  while(*str++)
    count++;
  total += count;
  cout << count << " characters" << endl;
  cout << total << " characters total" << endl;
}



