#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

class line
{


public:

	int lx, rx, y;

	line() { lx = 0; rx = 0; y = 0; };
	line(int a, int b, int c);

	void const reset(int a, int b, int c);
};

line::line(int a, int b, int c) {
	lx = a;
	rx = b;
	y = c;
}

void const line::reset(int a, int b, int c) {
	lx = a;
	rx = b;
	y = c;
}

bool operator<(line a, line b) {
	if (a.lx > b.lx) return false;
	else if (a.lx < b.lx) return true;
	else {
		if (a.y > b.y) return false;
		else return true;
	}
}

void merge(line* a, int start, int end) {

	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = 0;

	int size = end - start + 1;
	line* temp = new line[size];

	while (i <= mid && j <= end) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= end) temp[k++] = a[j++];

	//Copy all element to original arrays
	for (int i = start; i <= end; i++) a[i] = temp[i - start]; /// /// ///

}

void mergeSort(line a[], int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);
	merge(a, start, end);
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		int N;

		int RESULT_num = 0;
		int list_num = 0;

		cin >> N;

		line* lines = new line[N];

		line* list = new line[N];
		
		line* RESULT = new line[10 * N];
		 
		for (int j = 0; j < N; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			line temp(a, b, c);
			lines[j] = temp;
		}

		mergeSort(lines, 0, N - 1);

		// initial state //
		///////////////////
		///////////////////
		///////////////////
		///////////////////
        line now = lines[0];
		line comp = lines[1];
		line nowline(now.lx, now.lx, now.y);

		int next = 1; // prev의 next index
		int start = now.lx;

		while (next < N) {
			here:
			if (now.rx < comp.lx) {
				nowline.reset(start, now.rx, now.y);
				RESULT[RESULT_num] = nowline;
				RESULT_num++;
				while (list_num) {
					if(now.rx >= list[list_num-1].rx)
					{
						//list[list_num] = { 0,0,0 };
						list_num--;
					}
					else
					{
						start = now.rx;
						now = list[list_num - 1];
						//list[list_num] = { 0,0,0 };
						list_num--;
						goto here;
					}
				}
				now = comp;
				start = now.lx;
				next++;
				if (next < N)
				{
					comp = lines[next];
				}
			}
			else if (now.rx > comp.lx)
			{
				if (now.y > comp.y)
				{
					if (list_num == 0) {
						list[list_num] = comp;
						list_num++;
					}
					else
					{
						int i;
						for (i = 0; i < list_num; i++)
						{
							if (list[i].y > comp.y)
							{
								//list[i] = comp;
								//list_num++;
								// list[i] 위치에 comp를 넣고, 뒤의 원소 한칸씩 밀기
								for (int z = list_num; z > i; z--) {
									list[z] = list[z - 1];
								}
								list[i] = comp;
								list_num++;
								break;
							}
							else if (list[i].y == comp.y)
							{
								if (list[i].rx >= comp.lx && comp.rx >= list[i].lx)
								{
									list[i].reset(min(list[i].lx, comp.lx), max(list[i].rx, comp.rx), comp.y);
									break;
								}
								//list[i] = comp;
								//list_num++;
								// list[i] 위치에 comp를 넣고, 뒤의 원소 한칸씩 밀기
								for (int z = list_num; z > i; z--) {
									list[z] = list[z - 1];
								}
								list[i] = comp;
								list_num++;
								break;
							}
						}
						if (i == list_num) {
							list[list_num] = comp;
							list_num++;
						}
					}
					next++;
					if (next < N)
					{
						comp = lines[next];
					}
				}
				else if (now.y < comp.y)
				{
					nowline.reset(start, comp.lx, now.y);
					RESULT[RESULT_num] = nowline;
					RESULT_num++;
					if (list_num == 0) {
						list[list_num] = now;
						list_num++;
					}
					else
					{
						int i;
						for (i = 0; i < list_num; i++)
						{
							if (list[i].y > now.y)
							{
								//list[i] = comp;
								//list_num++;
								// list[i] 위치에 now를 넣고, 뒤의 원소 한칸씩 밀기
								for (int z = list_num; z > i; z--) {
									list[z] = list[z - 1];
								}
								list[i] = now;
								list_num++;
								break;
							}
							else if (list[i].y == now.y)
							{
								if (list[i].rx >= now.lx && list[i].lx <= now.rx)
								{
									list[i].reset(min(list[i].lx, now.lx), max(list[i].rx, now.rx), now.y);
									break;
								}
							}
						}
						if (i == list_num) {
							list[list_num] = now;
							list_num++;
						}
					}
					now = comp;
					start = now.lx;
					next++;
					if (next < N)
					{
						comp = lines[next];
					}
				}
				else
				{
					now.reset(min(now.lx, comp.lx), max(now.rx, comp.rx), now.y);
					// lines[next] 원소 지우기
					for (int q = next; q < N - 1; q++) {
						lines[q] = lines[q + 1];
					}
					N--;
					//
					if (next < N)
					{
						comp = lines[next];
					}
				}
			}
			else
			{
				if (now.y < comp.y)
				{
					nowline.reset(start, now.rx, now.y);
					RESULT[RESULT_num] = nowline;
					RESULT_num++;
					now = comp;
					start = now.lx;
					next++;
					if (next < N)
					{
						comp = lines[next];
					}
				}
				else if (now.y > comp.y)
				{
					nowline.reset(start, now.rx, now.y);
					RESULT[RESULT_num] = nowline;
					RESULT_num++;
					while (list_num)
					{
						if (comp.y > list[list_num - 1].y)
							break;
						if (now.rx < list[list_num - 1].rx)
						{
							start = now.rx;
							now = list[list_num - 1];
							//list[list_num] = { 0,0,0 };
							list_num--;
							goto here;
						}
						else
						{
							//list[list_num] = { 0,0,0 };
							list_num--;
						}
					}
					now = comp;
					start = now.lx;
					next++;
					if (next < N)
					{
						comp = lines[next];
					}
				}
				else
				{
					now.reset(min(now.lx, comp.lx), max(now.rx, comp.rx), now.y);
					// lines[next] 원소 지우기
					for (int q = next; q < N - 1; q++) {
						lines[q] = lines[q + 1];
					}
					N--;
					//
					if (next < N)
					{
						comp = lines[next];
					}
				}
			}
		}
		if (start < now.rx) {
			nowline.reset(start, now.rx, now.y);
			RESULT[RESULT_num] = nowline;
			RESULT_num++;
			start = now.rx;
		}
		while (list_num) {
			if (start >= list[list_num - 1].rx) {
				//list[list_num] = { 0,0,0 };
				list_num--;
			}
			else {
				now = list[list_num-1];
				nowline.reset(start, now.rx, now.y);
				RESULT[RESULT_num] = nowline;
				RESULT_num++;
				//list[list_num] = { 0,0,0 };
				list_num--;
				start = now.rx;
			}
		}
		mergeSort(RESULT, 0, RESULT_num -1);
		for (int i = 0; i < RESULT_num; i++)
			cout << RESULT[i].lx << " " << RESULT[i].rx << " " << RESULT[i].y << endl;
	}
	return 0;
}