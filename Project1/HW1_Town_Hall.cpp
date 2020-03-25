#include <iostream>
using namespace std;

int main()
{
	int times;
	int num;
	double middle;
	double result, f_result, s_result;
	cin >> times;
	for (int i = 0; i < times; i++) {
		result = 0; f_result = 0; s_result = 0;
		cin >> num;
		int* list = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> list[j];
		}
		if (num % 2 == 1) {
			middle = list[num / 2];
			for (int j = 0; j < num; j++) {
				if (list[j] <= middle) result += (middle - list[j]);
				else result += (list[j] - middle);
			}
		}
		else {
			double first = list[num / 2 - 1];
			double second = list[num / 2];
			for (int j = 0; j < num; j++) {
				if (list[j] <= first) f_result += (first - list[j]);
				else f_result += (list[j] - first);
			}
			for (int j = 0; j < num; j++) {
				if (list[j] <= second) s_result += (second - list[j]);
				else s_result += (list[j] - second);
			}
			if (f_result >= s_result) result = s_result;
			else result = f_result;
		}
		delete[] list;
		cout << result << endl;
	}
}