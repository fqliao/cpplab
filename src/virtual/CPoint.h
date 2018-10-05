
/**
 * 1.父类要实现多态性，则父类的成员函数必须virtual关键字声明，Java中可以无该关键字，默认直接支持多态
 * 2.子类的virtual关键字可以省略，但是还是虚函数
 * 3.父类与子类函数签名一致才可以实现多态，否则还是直接调用父类方法
 * 4.虚函数实现不要加virtural关键字
 * 5.只有成员函数才能声明为虚函数，普通函数不能声明为虚函数
 * 6.构造函数、静态成员函数、内联函数不能是虚函数
 * 7.析构函数通常声明为虚函数,其他成员函数尽量声明为虚函数，增了点开销，没有其他坏处，可支持多态
 * 定义父类的指针指向子类的对象时，先调用父类的构造函数再调用子类的构造函数，delete释放父类指针对象内存时，
 * 若父类的析构函数不是虚析构函数，则只释放调用父类的析构函数而不调用子类的析构函数，从
 * 而造成内存泄漏。当然如果直接释放子类的指针对象，先调用子类的析构函数，再调用父类的析构函数。
 * 因此，析构函数最好用户virtual关键字声明，这样即使调用父类的析构函数时也可以调用到子类的析构函数
 */

#pragma once
#include <iostream>

class CPoint
{
 public:
  CPoint(float w, float h);
  virtual ~CPoint(){std::cout << "CPoint析构函数被调用" << std::endl;};
  virtual float getArea();

 private:
  float m_w, m_h;
};
