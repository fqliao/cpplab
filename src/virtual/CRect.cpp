#include "CRect.h"

#include<iostream>
//如果包含就报错！重复包含就重复定义类,因为CRect.h以及包含了。
//解决办法：
// 1 不包含，但是前提是要查找到CRect.h已经包含了CPoint.h
// 2 创建的每个头文件都包含#pragma once就ok，保证同一个头文件只会被包含一次，最省事！！！
#include "CPoint.h"

CRect::CRect(float w, float h):CPoint(w,h)
{
  m_w = w;
  m_h = h;
}
float CRect::getArea()
{
  return m_w * m_h;
}

void CRect::disp(CPoint *cp)
{
  std::cout << "面积为：" << cp->getArea() << std::endl;
  delete cp;
}

void virtualTest() {
  CRect *rt = new CRect(6.0, 9.0);
  rt->disp(rt);
//  delete rt;
}
