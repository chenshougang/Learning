// 
//############ 
#include <iostream>
#include "const_learning.h"

using namespace std;

// 
void test_const() {

	std::cout << " -------- 开始测试 const 的内容--------" << std::endl;

	const int a = 1;
	static int b = 2;
	// a = 4; // 这句赋值语句是错的
	// a = a + 1;  // 错

	b = a;
	b = b + 1;
	std::cout << a + 1 << std::endl;  // 为啥这句是对的？ 
	std::cout << b + 1 << std::endl;
}


// const 修饰指针的情况
void test_const_pointer() {

	const int  a = 7;
	std::cout << "初始值 a = " << a << std::endl;
	int* p = (int*)&a;
	*p = 8;
	std::cout << "a = " << a << std::endl;
}


// 添加关键字 volatile 
void test_const_pointer_volatile() {

	volatile const int  a = 7;
	std::cout << "初始值 a = " << a << std::endl;
	int* p = (int*)&a;
	*p = 8;
	std::cout << "a = " << a << std::endl;
}


// const 修饰指针变量
/********************************************************************
* const 修饰指针变量有以下三种情况。
	A: const 修饰指针指向的内容，则内容为不可变量。
	B: const 修饰指针，则指针为不可变量。
	C: const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。
*********************************************************************
*/
void test_A() {

	// const int* cuode = 10; //这是错的
	int a = 10;
	const int* p = &a;
	std::cout << "*p = " << *p << std::endl;
	a = 20;
	std::cout << "*p = " << *p << std::endl;

}
void test_B() {

	int a = 8;
	int* const p = &a;

	*p = 9; // 正确

	std::cout << " a = " << a << std::endl;
	int  b = 7;
	// p = &b; // 错误
}
void test_C() {
	int a = 8;
	const int* const  p = &a;
}


// const参数传递和函数返回值。
int test_const_value_Parameter_passing(const int a) {
	std::cout << "a = " << a << std::endl;
	// a++;  //这是错误的
	return a;
}

void test_const_pointer_Parameter_passing(int* const pointer) {

	std::cout << " *pointer = " << *pointer << std::endl;
	*pointer = 666;
	std::cout << " *pointer = " << *pointer << std::endl;
	// a++;  //这是错误的
}
