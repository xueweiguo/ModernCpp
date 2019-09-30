// Span.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdexcept>
#include <gsl>

using namespace std;

void init_data(int buffer[], size_t size)
{
	cout << "size=" << size << endl;
	for (gsl::index i = 0; i < size; ++i) {
		buffer[i] = i;
	}
	buffer[4] = 40;
	buffer[20] = 20;  //越界访问
}

void init_data(gsl::span<int> buffer)
{
	cout << "size=" << buffer.size() << endl;
	int value = 0;
	for (auto it = buffer.begin(); it != buffer.end(); it++) {
		*it = 10 + value++;
	}
	buffer[4] = 10;
	//buffer[20] = 20;  //越界访问
}

void show_data(gsl::span<int> buffer)
{
	for (auto v : buffer) {
		std::cout << v << ',';
	}
	std::cout << std::endl;
}

int main()
{
	int data[10];
	for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
		data[i] = 0;
	}
	//使用数组传递参数
	init_data(data, 5);
	//使用span传递参数
	show_data(data);
	init_data(data);
	show_data(data);
	return 0;
}
