/*
 * tabtenn0.cpp
 *
 *  Created on: 2018年10月7日
 *      Author: caryliao
 */

#include "tabtenn0.h"
#include <iostream>

//构造函数使用的是成员初始化列表（这种方式只能用于构造函数）语法
//相比传统的构造函数初始化复制语句写法，初始化列表的方法好处有2点
//1 简洁，直观，代码量少
//2 效率高，会直接调用string的复制构造函数初始化，而不用调用复制运算符，而且是在创建对象时完成，而不是创建对象后再赋值完成的，
// 换句话说，初始化列表在构造函数体前面执行
//3 类的常量，引用类型强制必须使用初始化列表初始化
// 注意: 初始化列表中的排列顺序与初始化数据成员顺序无关，初始化数据成员的顺序与在类中的声明顺序一致

TableTennisPlayer::TableTennisPlayer(const string & _firstname, const string & _lastname, bool _hasTable):
m_firstname(_firstname), m_lastname(_lastname), m_hasTable(_hasTable){}

void TableTennisPlayer::Name() const
{
    std::cout << m_lastname << ", " << m_firstname;
}

RatedPlayer::RatedPlayer(unsigned int _rating , const string & _firstname,
                   const string & _lastname, bool _hasTable):TableTennisPlayer(_firstname,_lastname,_hasTable), m_rating(_rating){}
RatedPlayer::RatedPlayer(unsigned int _rating, const TableTennisPlayer & tp):TableTennisPlayer(tp), m_rating(_rating){}

void testTabtenn0()
{
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if(player1.HasTable())
    {
        cout << ": has a table" << std::endl;
    }
    else
    {
        cout << ": hasn't a table" << std::endl;
    }
    player2.Name();
    if(player2.HasTable())
    {
        cout << ": has a table" << std::endl;
    }
    else
    {
        cout << ": hasn't a table" << std::endl;
    }
}

void testTabtenn1()
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();
    if(rplayer1.HasTable())
        cout << ": has a table." << endl;
    else
        cout << ": hasn't a table." << endl;
    player1.Name();
    if(player1.HasTable())
        cout << ": has a table." << endl;
    else
        cout << ": hasn't a table." << endl;
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;
    //initialize RatedPlayer using TableTennisPlayer Object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
}
