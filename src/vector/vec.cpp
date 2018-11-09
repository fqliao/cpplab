/*
 * str1.cpp
 * string：7个传统构造函数， 2个C++11新增构造函数
 *
 *  Created on: 2018年9月16日
 *      Author: caryliao
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "vec.h"

using namespace std;

void testVector()
{

    vector<uint8_t> data;
    map<string, string> entry;
//    entry["_id_"] = "1";
//    entry["name"] = "fruit";
//    entry["item_name"] = "apple";
    entry.insert(make_pair("_id_", "1"));
    entry.insert(make_pair("name", "fruit"));
    entry.insert(make_pair("item_name", "apple"));
    for(auto it: entry)
    {
        cout << "key = " << it.first <<" value = " << it.second << endl;
    }
    map<string, string>::iterator iter;
    for(auto iter: entry)
    {
        data.insert(data.end(), iter.first.begin(), iter.first.end());
        data.insert(data.end(), iter.second.begin(), iter.second.end());
    }
    cout << data.size();
    cout << "aaa";
    for(auto it = data.begin(); it != data.end(); it ++)
    {
        cout << *it << " ";
    }
}


void testVectorData() {
    vector<string> vec;

    vec.push_back("C++");
    vec.push_back("Java");
    vec.push_back("PHP");

    string* pStr = vec.data(); //返回指向vector中第一个数据的指针或空vector之后的位置
    for (size_t n = 0;n < vec.size(); n++, pStr++)
    {
        cout << "vec.data() = " << *pStr << endl;
     }

}



