// 函数指针和指针函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// 求最大值，返回值是int类型，返回两个整数中较大的一个
int max(int a, int b) {
	return a > b ? a : b;
}
// 求最小值，返回值是int类型，返回两个整数中较小的一个
int min(int a, int b) {
	return a < b ? a : b;
}

int(*f)(int, int); // 声明函数指针，指向返回值类型为int，有两个参数类型都是int的函数


//------------------------------- 主程序开始 --------------------------------//
int main()
{
	printf("------------------------------ Start ------------------------------\n");

	f = max; // 函数指针f指向求最大值的函数max(将max函数的首地址赋给指针f)
	int c = (*f)(1, 2);

	printf("The max value is %d \n", c);

	f = min; // 函数指针f指向求最小值的函数min(将min函数的首地址赋给指针f)
	c = (*f)(1, 2);

	printf("The min value is %d \n", c);

	printf("------------------------------ End ------------------------------\n");
	return 0;
}


// ----------------------------------------------------------------------------
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
void func(int e, int d, int(*f)(int a, int b)) { // 这里才是我想说的，
// 传入了一个int型，双参数，返回值为int的函数
	std::cout << f(e, d) << std::endl;
}
int main()
{
	func(2, 3, add);
	func(2, 3, sub);

	return 0;
}
// ----------------------------------------------------------------------------
