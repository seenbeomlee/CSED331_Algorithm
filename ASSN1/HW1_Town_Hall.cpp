#include <iostream>
using namespace std;

int main()
{
	int times;
	int num;
	int middle;
	long long result;
	cin >> times;
	for (int i = 0; i < times; i++) {
		result = 0;
		cin >> num;
		long long* list = new long long[num];
		for (int j = 0; j < num; j++) {
			cin >> list[j];
		}
			middle = list[num / 2];
			for (int j = 0; j < num; j++) {
				if (list[j] <= middle) result += (middle - list[j]);
				else result += (list[j] - middle);
			}
		cout << result << endl;
		delete[] list;
	}
	return 0;
}