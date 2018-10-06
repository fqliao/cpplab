/*
 * stack.h
 *
 *  Created on: 2018年10月6日
 *      Author: caryliao
 */

#ifndef SRC_TEN_STACK_H_
#define SRC_TEN_STACK_H_

//typedef的好处有两点
//1 缩短类型名 2 替换类型方便
// 更进一步方便的是使用模板
typedef unsigned long Item;

class Stack
{
 public:
  Stack();
  virtual ~Stack(){};
  bool isEmpty() const;
  bool isFull() const;
  bool push(const Item & _item);
  bool pop(Item & _item);
 private:
  enum {MAX = 10};
  Item m_items[MAX];
  int m_top;
};

void testStack();

#endif /* SRC_TEN_STACK_H_ */
