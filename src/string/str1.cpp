/*
 * str1.cpp
 * string：7个传统构造函数， 2个C++11新增构造函数
 *
 *  Created on: 2018年9月16日
 *      Author: caryliao
 */
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include "str1.h"

using namespace std;

void testStringCtor()
{
  //#1 string(const char * s)
  string one("Lottery Winner!");
  cout << one << endl;

  //#2 string(size_type n, char c)
  string two(20, '$');
  cout << two << endl;

  //#3 string(const string & str)
  string three(one);
  cout << three << endl;
  one += " Oops!";
  cout << one << endl;
  two = "Sorry! That was ";
  three[0] = 'P';

  //#4 string()
  string four;
  four = two + three;
  cout << four << endl;
  char alls[] = "All's well that ends well";

  //#5 string(const char * s, size_type n)
  string five(alls, 20);
  cout << five << endl;

  //template<class Iter>
  //#6 string(Iter begin, Iter end)
  string six1(alls+6, alls+10);
  cout << six1 << endl;
  string six2(&five[6], &five[10]);
  cout << six2 << endl;

  //#7 string(string & str, size_type pos = 0, size_type = npos)
  string seven(four, 7, 16);
  cout << seven << endl;

  //==== C++11 新增的2个构造方法 ====
  //#8 string(string && str)

  //#9 string(initializer_list<char> il) 用c风格字符串赋值更加方便
  string nine1 = {'H','i'};
  string nine2 {'H','i'};
  cout << nine1 << endl;
  cout << nine2 << endl;
}

void testStringInput()
{
  ifstream fin;
  fin.open("/mnt/d/data/eclipse/cpplab/src/string/tobuy.txt");
  if(fin.is_open() == false)
  {
    cerr << "Can't open file. Bye!" << endl;
    exit(EXIT_FAILURE);
  }
  string item;
  getline(fin, item, ':');
  while(fin)
  {
    cout << item << endl;
    getline(fin, item, ':');
  }
  fin.close();

}



