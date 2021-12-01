#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include "definition.h"

// 遍历过程中对访问到的元素执行的操作
void Visit(ValueType val) {
  std::cout << val << std::endl;
}

#endif // UTILS_H_