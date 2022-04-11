// LearingCPP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LearningConst.h"
using namespace std;

int main()
{

    std::cout << " -------- 主程序开始 -------- " << std::endl;
    test_const();
    //test_const_pointer();
    //test_const_pointer_volatile();
    //test_A();
    //test_B();
    // int a = 10;
    // test_const_pointer_Parameter_passing(&a);


    double a[3] = { 1, 2, 3 };
    double b[3][3] = { {3, 2, 1}, {3, 2, 1}, {3, 2, 1} };
}

