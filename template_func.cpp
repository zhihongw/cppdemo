#include <iostream>

using namespace std;

template <class T>

inline T square(T x) {
	T result = x * x;
	return result;
}

int main() {
	int i=2;
	cout<<i<<":"<<square<int>(i)<<endl;
	double d=2.2;
	cout<<d<<":"<<square(d)<<endl;
	return 0;
}