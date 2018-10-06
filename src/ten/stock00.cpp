/*
 * stock00.cpp
 *
 *  Created on: 2018年10月6日
 *      Author: caryliao
 */
#include <iostream>
#include "stock00.h"
#include <memory> //使用智能指针
#include <typeinfo>

Stock::Stock(const std::string & _company, long _shares, double _shares_val)
{
  m_company = _company;
  if(_shares < 0)
  {
    std::cout << "Number of shares can't be negative;"
        << m_company << " shares set to 0." << std::endl;
    m_shares = 0;
  }
  else
  {
    m_shares = _shares;
  }
  m_shares_val = _shares_val;
  set_tot();
}

void Stock::buy(long _shares, double _shares_val)
{
  if(_shares < 0)
  {
    std::cout << "Number of shares purchased can't be negative. "
        << "Transaction is aborted." << std::endl;
  }
  else
  {
    m_shares += _shares;
    m_shares_val = _shares_val;
    set_tot();
  }
}

void Stock::sell(long _shares, double _shares_val)
{
  using std::cout;
  if(_shares < 0)
  {
    cout << "Number of shares sold can't be negative."
        << "Transaction is aborted." << std::endl;
  }
  else if(_shares > m_shares)
  {
    cout << "You can't sell more than you have! "
        << "Transaction is aborted." << std::endl;
  }
  else
  {
    m_shares -= _shares;
    m_shares_val = _shares_val;
    set_tot();
  }
}

void Stock::update(double _shares_val)
{
  m_shares_val = _shares_val;
  set_tot();
}

void Stock::show() const
{
  //定点表示法，而不是科学表示法
  auto orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  //显示三位小数
  auto prec = std::cout.precision(3);
  std::cout << "Company: " << m_company
      << " Shares: " << m_shares << std::endl
      << " Shares Price: $" << m_shares_val
      << " Total Worth: $" << m_total_val << std::endl;
  //显示完后，恢复之前的输出格式
  std::cout.setf(orig, std::ios_base::floatfield);
  std::cout.precision(prec);
}

const Stock & Stock::topVal(const Stock & s) const
{
  if(s.m_total_val > m_total_val)
  {
    return s;
  }
  else
  {
    return *this;
  }
}


//这是全局函数，与类无关
void testStock00()
{
  //栈对象
  Stock cat;//调用默认构造函数
  cat.show();
  cat.buy(15, 18.125);
  cat.show();
  cat.sell(400, 20.00);
  cat.show();
  cat.buy(300000, 40.125);
  cat.show();
  cat.sell(300000, 0.125);
  cat.show();

  //栈对象
  Stock penguin("WeBank1", 12, 100);// 等价 Stock penguin = Stock("WeBank", 12, 100);
  penguin.show();

  //shared ptr利用默认参数创建对象 动态对象
  std::shared_ptr<Stock> pig = std::make_shared<Stock>();
  pig->show();

  //shared ptr利用带参构造函数创建对象 动态对象
  std::shared_ptr<Stock> dolphin = std::make_shared<Stock>("DolphinBank", 50, 100);
  dolphin->show();

}

void testStock01()
{
  std::shared_ptr<Stock> stock1 = std::make_shared<Stock>("Stock1", 30, 100);
  std::shared_ptr<Stock> stock2 = std::make_shared<Stock>("Stock2", 20, 100);
  auto stock = stock1->topVal(*stock2.get());
  std::cout << "stock类型：" << typeid(stock).name()<< std::endl;
  stock.show();
}

void testStock02()
{
  const int STKS = 4;
  //创建对象数组
  Stock stocks[STKS] = {
      Stock("Na", 12, 20.0),
      Stock("Bo", 200, 2.0),
      Stock("Mo", 130, 3.25),
      Stock("Fl", 60, 6.5),
  };
  std::cout << "Stock holdings:" << std::endl;
  int st;
  for(st = 0; st < STKS; st ++)
  {
    stocks[st].show();
  }
  const Stock * top = &stocks[0];
  for(st = 1; st < STKS; st++)
  {
    top = &top->topVal(stocks[st]);
  }
  std::cout << std::endl << "Most valuable holding:" << std::endl;
  top->show();
}

