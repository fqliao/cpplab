#include <iostream>
#include <stdlib.h>
//自定义的头文件路径用“”，系统库的用<>.如果自定义的文件夹名与系统的同名，
//而且用<>,则找系统的，但找不到对于头文件，报错
#include "math/Power.h"
#include "virtual/CRect.h"
#include "string/str1.h"
#include "polar/coordin.h"
#include "nine/support.cpp"
#include "nine/twofile1.cpp"
#include "nine/static.cpp"
#include "nine/namesp.h"
#include "ten/stock00.h"
#include "ten/stack.h"

using namespace std;


void virtualTest() {
  CRect *rt = new CRect(6.0, 9.0);
  rt->disp(rt);
//  delete rt;
}

int main(int argc, char *argv[])
{

  testStack();
  return 0;
}
