#pragma once

#include "../virtual/CPoint.h"

class CRect:public CPoint
{
 public:
  CRect(float w, float h);
  virtual ~CRect(){std::cout << "CRect析构函数被调用" << std::endl;};
  float getArea();
  void disp(CPoint *cp); //virtual 函数，子类的virtual关键词可以省略

 private:
  float m_w,m_h;
};

void virtualTest();
