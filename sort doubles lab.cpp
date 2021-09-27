#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Print the doubles out in sorted order. (small to big)
//Print out all unique values in sorted order. (small to big)
//Print out the unique values in reverse sorted order. (big to small)

bool IsBigger(double a,double b)
{
	return a>b;
}

int main(void)
{
	double d;
	vector<double> vec;

	while (std::cin >> d)
	{
		vec.push_back(d);
	}

	sort(vec.begin(), vec.end());
	for (auto a : vec) {
		cout << a << " ";
	}
	cout << endl;

	d = vec[0] - 1;
	for (auto a : vec) {
		if (d != a) {
			cout << a << " ";
			d = a;
		}
	}
	cout << endl;

	sort(vec.begin(), vec.end(),&IsBigger);
	d = vec[0] - 1;
	for (auto a : vec) {
		if (d != a) {
			cout << a << " ";
			d = a;
		}
	}
	cout << endl;

	return 0;
}
