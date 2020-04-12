#include <iostream>
using namespace std;

int N_array[531441];

int main(void) {
	int t, N;
	int result;
	int R, G, B;
	int result_R, result_G, result_B;
	int RGB;
	int check = 0;

	cin >> dec >> t;

	for (int i = 0; i < t; i++) {

		cin >> dec >> N;
		for (int j = 0; j < N; j++) cin >> hex >> N_array[j];
		
		while (N > 1) {
			for (int j = 0; j < N; j += 3) {
				//
				B = N_array[j] % 16;
				N_array[j] /= 16;
				G = N_array[j] % 16;
				N_array[j] /= 16;
				R = N_array[j] % 16;
				N_array[j] /= 16;
				if (R == G && G == B) {
					result_R = R;
					check++;
				}
				else result_R = (R + G + B) % 16;
				//
				B = N_array[j+1] % 16;
				N_array[j+1] /= 16;
				G = N_array[j+1] % 16;
				N_array[j+1] /= 16;
				R = N_array[j+1] % 16;
				N_array[j+1] /= 16;
				if (R == G && G == B) {
					result_G = G;
					check++;
				}
				else result_G = (R + G + B) % 16;
				//
				B = N_array[j+2] % 16;
				N_array[j+2] /= 16;
				G = N_array[j+2] % 16;
				N_array[j+2] /= 16;
				R = N_array[j+2] % 16;
				N_array[j+2] /= 16;
				if (R == G && G == B) {
					result_B = B;
					check++;
				}
				else result_B = (R + G + B) % 16;
				//
				if (check == 3) result_G = 15;
				RGB = result_R * 16 * 16 + result_G * 16 + result_B;

				check = 0;
				N_array[j / 3] = RGB;
			}
			N /= 3;
		}

		/*
		B = N_array[0] % 16;
		N_array[0] /= 16;
		G = N_array[0] % 16;
		N_array[0] /= 16;
		R = N_array[0] % 16;
		N_array[0] /= 16;

		if (R == G && G == B) result_R = R;
		else result_R = (R + G + B) % 16;

		cout << hex << result_R << endl;
		*/

		result = N_array[0];

		if (result == 0) {
			cout.setf(ios::uppercase);
			cout << 0 << 0 << 0 << endl;
			continue;
		}

		else if (result < 16) {
			cout.setf(ios::uppercase);
			cout << 0 << 0 << hex << result << endl;
			continue;
		}

		else if (result < 16 * 16) {
			cout.setf(ios::uppercase);
			cout << 0 << hex << result << endl;
			continue;
		}


		else {
			cout.setf(ios::uppercase);
			cout << hex << result << endl;
			continue;
		}
	}
	
	

	/*
		if (A == 0xABC) cout << "AAA" <<  endl;

	cout.setf(ios::uppercase);
	cout << "A°ªÀº :"<< hex << A << endl;

	*/

	return 0;

}