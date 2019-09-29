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
	buffer[20] = 20;
	cout << endl;
}

void init_data(gsl::span<int> buffer)
{
	cout << "size=" << buffer.size() << endl;
	int value = 0;
	for (auto it = buffer.begin(); it != buffer.end(); it++) {
		*it = value++;
	}
	buffer[4] = 10;
	//buffer[20] = 20;
	cout << endl;
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
	int dummy[100];
	for (auto it = begin(data); it != end(data); it++) {
		*it = 0;
	}
	init_data(data, 4);
	show_data(data);
}
