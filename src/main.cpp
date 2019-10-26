//自定义的头文件路径用“”，系统库的用<>.如果自定义的文件夹名与系统的同名，
//而且用<>,则找系统的，但找不到对于头文件，报错
#include "libextern/externdemo1.h"
#include "math/Power.h"
#include "nine/namesp.h"
#include "nine/static.cpp"
#include "nine/support.cpp"
#include "nine/twofile1.cpp"
#include "polar/coordin.h"
#include "string/str1.h"
#include "ten/stack.h"
#include "ten/stock00.h"
#include "thirteen/tabtenn0.h"
#include "vector/vec.h"
#include "virtual/CRect.h"

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char* argv[])
{
    int a = 3, b = 6;
    swap(&a, &b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    return 0;
}
