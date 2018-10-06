/*
 * stack.cpp
 *
 *  Created on: 2018年10月6日
 *      Author: caryliao
 */
#include <iostream>
#include <cctype>
#include "stack.h"

Stack::Stack() {
    m_top = 0;
}

bool Stack::isEmpty() const {
    return m_top == 0;
}

bool Stack::isFull() const {
    return m_top == MAX;
}

bool Stack::push(const Item & _item) {
    if (!isFull()) {
        m_items[m_top++] = _item;
        return true;
    } else {
        return false;
    }
}

bool Stack::pop(Item & item)  //获得的弹出值放入形参了，返回值用于表示弹出是否成功
        {
    if (!isEmpty()) {
        item = m_items[--m_top];  //注意这里需要--m_top，与push中的m_top++对应
        return true;
    } else {
        return false;
    }
}

void testStack() {
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order," << endl
         << "P to proccess a PO, or Q to quit." << endl;
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isFull())
                    cout << "stack already full" << endl;
                else
                    st.push(po);
                break;
            case 'p':
            case 'P':
                if (st.isEmpty())
                    cout << "stack already empty" << endl;
                else {
                    st.pop(po);
                    cout << "PO #" << po << " poped" << endl;
                }
                break;
        }
        cout << "Please enter A to add a purchase order," << endl
             << "P to proccess a PO, or Q to quit." << endl;

    }
    cout << "Bye" << endl;

}
