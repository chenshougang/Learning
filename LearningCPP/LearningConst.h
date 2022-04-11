#pragma once


void test_const();

void test_const_pointer();

void test_const_pointer_volatile();

void test_A();

void test_B();

void test_C();

int test_const_value_Parameter_passing(const int a);

void test_const_pointer_Parameter_passing(int* const pointer);


class Test {
public:
	Test(int val) :_val(val) {}

	int get_val_const() const {
		// _val++; //´íÎó
		return _val;
		// return _val++; //´íÎó
	}

	int get_val() {
		_val++;
		return _val;
	}

private:
	int _val;

};