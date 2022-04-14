// 
//############ 
#include <iostream>
#include "const_learning.h"

using namespace std;

// 
void test_const() {

	std::cout << " -------- ��ʼ���� const ������--------" << std::endl;

	const int a = 1;
	static int b = 2;
	// a = 4; // ��丳ֵ����Ǵ��
	// a = a + 1;  // ��

	b = a;
	b = b + 1;
	std::cout << a + 1 << std::endl;  // Ϊɶ����ǶԵģ� 
	std::cout << b + 1 << std::endl;
}


// const ����ָ������
void test_const_pointer() {

	const int  a = 7;
	std::cout << "��ʼֵ a = " << a << std::endl;
	int* p = (int*)&a;
	*p = 8;
	std::cout << "a = " << a << std::endl;
}


// ��ӹؼ��� volatile 
void test_const_pointer_volatile() {

	volatile const int  a = 7;
	std::cout << "��ʼֵ a = " << a << std::endl;
	int* p = (int*)&a;
	*p = 8;
	std::cout << "a = " << a << std::endl;
}


// const ����ָ�����
/********************************************************************
* const ����ָ��������������������
	A: const ����ָ��ָ������ݣ�������Ϊ���ɱ�����
	B: const ����ָ�룬��ָ��Ϊ���ɱ�����
	C: const ����ָ���ָ��ָ������ݣ���ָ���ָ��ָ������ݶ�Ϊ���ɱ�����
*********************************************************************
*/
void test_A() {

	// const int* cuode = 10; //���Ǵ��
	int a = 10;
	const int* p = &a;
	std::cout << "*p = " << *p << std::endl;
	a = 20;
	std::cout << "*p = " << *p << std::endl;

}
void test_B() {

	int a = 8;
	int* const p = &a;

	*p = 9; // ��ȷ

	std::cout << " a = " << a << std::endl;
	int  b = 7;
	// p = &b; // ����
}
void test_C() {
	int a = 8;
	const int* const  p = &a;
}


// const�������ݺͺ�������ֵ��
int test_const_value_Parameter_passing(const int a) {
	std::cout << "a = " << a << std::endl;
	// a++;  //���Ǵ����
	return a;
}

void test_const_pointer_Parameter_passing(int* const pointer) {

	std::cout << " *pointer = " << *pointer << std::endl;
	*pointer = 666;
	std::cout << " *pointer = " << *pointer << std::endl;
	// a++;  //���Ǵ����
}
