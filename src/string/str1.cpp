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
#include<ctime>
#include<cctype>
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

void testStringFun()
{
  const int NUM = 26;
  const string wordlist[NUM] = {
      "apiary","beetle","cereal","danger",
      "ensign","florid","garage","health",
      "insult","jackal","keeper","loaner",
      "manager","nonce","onset","plaid",
      "quilt","remote","stolid","train",
      "useful","valid","whence","xenon",
      "yearn","zippy"
  };

  srand(time(0));
  char play;
  cout << "Will you play a word game?<y/n>";
  cin >> play;
  play = tolower(play);
  while(play == 'y')
  {
    string target = wordlist[std::rand() % NUM];
    int length = target.length();
    string attempt(length, '-');
    string badchars;
    int guesses = 6;
    cout << "Guess my secret word. It has " << length
        << " letters, and you guess" << endl
        << "one letter at a time. You get " << guesses
        << " wrong guesses." << endl;
    cout << "Your word: " << attempt << endl;
    while(guesses > 0 && attempt != target)
    {
      char letter;
      cout << "Guess a letter: ";
      cin >> letter;
      if(badchars.find(letter) != string::npos
          || attempt.find(letter) != string::npos)
      {
        cout << "You already guessed that. Try again."
            << endl;
        continue;
      }
      int loc = target.find(letter);
      if(loc == string::npos)
      {
        cout << "Oh, bad guess!" << endl;
        --guesses;
        badchars += letter; //add to string
      }
      else
      {
        cout << "Good guess!" << endl;
        attempt[loc] = letter;
        //check if letter appears again
        loc = target.find(letter, loc+1);
        while(loc != string::npos)
        {
          attempt[loc] = letter;
          loc = target.find(letter, loc+1);
        }
      }
      cout << "Your word: " << attempt << endl;
      if(attempt != target)
      {
        if(badchars.length() > 0)
        {
          cout << "Bad choices: " << badchars << endl;
          cout << guesses << " bad guesses left" << endl;
        }
      }
      if(guesses > 0)
      {
        cout << "That's right!" << endl;
      }
      else
      {
        cout << "Sorry, the word is " << target <<"." << endl;
        cout << "Will you play another? <y/n>";
        cin >> play;
        play = tolower(play);
      }
      cout << "Bye!" << endl;
    }

  }

}





