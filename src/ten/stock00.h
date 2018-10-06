/*
 * stock00.h
 *
 *  Created on: 2018年10月6日
 *      Author: caryliao
 */

#ifndef SRC_TEN_STOCK00_H_
#define SRC_TEN_STOCK00_H_

#include <string>

class Stock
{

 public://类的成员函数形参以_开头
  //默认构造函数 无返回类型 有参数 可重载
  Stock(const std::string & _company = "WeBank", long _shares = 0, double _shares_val = 0.0);
  //析构函数 无返回类型 无参数 不可重载 尽量使用virtual关键字
  virtual ~Stock(){std::cout << "调用析构函数:  " << m_company << std::endl;};
  void buy(long _shares, double _shares_val);
  void sell(long _shares, double _shares_val);
  void update(double _shares_val);
  void show() const; //只要方法不修复对象数据，将应该添加关键字const,限制不能修改对象
  const Stock & topVal(const Stock & s) const; //传入其他对象，进行比较

 private: //类数据成员变量以m_开头
  std::string m_company;
  long m_shares;
  double m_shares_val;
  double m_total_val;
  //inline function definition in class declaration by default
  void set_tot(){m_total_val = m_shares * m_shares_val;}

};


//global test function
void testStock00();
void testStock01();
void testStock02();


#endif /* SRC_TEN_STOCK00_H_ */
