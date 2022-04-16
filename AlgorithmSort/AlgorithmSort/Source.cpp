#include <iostream>
#include <chrono>
using namespace std;

void shake_sort(int arr[], int size){

	int left_index = 0;
	int right_index = size;

	bool control = false;

	auto startall = chrono::steady_clock::now();

	while (right_index != left_index) {
		for (int j = 0; j < right_index - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				control = true;
				arr[j] = arr[j + 1];
			}
		}

		if (control == false) {
			cout << "Выполненно условие Айверсона, сортировка принудительно прекращена." << endl;;
			break;
		}

		right_index = right_index - 1;

		for (int i = right_index; i > left_index + 1; i--) {
			if (arr[i] > arr[i - 1])
				arr[i] = arr[i - 1];
		}
	}
	auto endall = chrono::steady_clock::now();

	cout << endl << "Время сортировки: " << (endall - startall).count() / 1'000'000'000.0
		<< " seconds" << endl;;
}

int main(){

	srand(time(NULL));
	system("chcp 1251");

	int n1_sorted[2200];
	int n1_random[2200];
	int n1_reverse[2200];

	int n2_sorted[3400];
	int n2_random[3400];
	int n2_reverse[3400];

	int n3_sorted[7300];
	int n3_random[7300];
	int n3_reverse[7300];

	//Random values for arrays

	for (int i = 0; i < 2200; i++){
		n1_sorted[i] = i;
	}

	for (int i = 0; i < 3400; i++) {
		n2_sorted[i] = i;
	}

	for (int i = 0; i < 7300; i++) {
		n3_sorted[i] = rand() % 10000 + 0;
	}

	for (int i = 0; i < 2200; i++) {
		n1_random[i] = rand() % 10000 + 0;
	}

	for (int i = 0; i < 3400; i++) {
		n2_random[i] = rand() % 10000 + 0;
	}

	for (int i = 0; i < 7300; i++) {
		n3_random[i] = rand() % 10000 + 0;
	}

	for (int i = 0; i < 2200; i++) {
		n1_reverse[i] = 2200-i;
	}

	for (int i = 0; i < 3400; i++) {
		n2_reverse[i] = 3400-i;
	}

	for (int i = 0; i < 7300; i++) {
		n3_reverse[i] = 7300-i;
	}

	//Sorting sorted arrays(Aiverson condition)

	cout << "Время сортировок сортированных массивов" << endl;

	shake_sort(n1_sorted, 2200);
	shake_sort(n2_sorted, 3400);
	shake_sort(n3_sorted, 7300);

	//Sorting random arrays(Aiverson condition)

	cout << "Время сортировок рандомных массивов" << endl;

	shake_sort(n1_random, 2200);
	shake_sort(n2_random, 3400);
	shake_sort(n3_random, 7300);

	//Sorting reverse arrays(Aiverson condition)

	cout << "Время сортировок реверсированных массивов" << endl;

	shake_sort(n1_reverse, 2200);
	shake_sort(n2_reverse, 3400);
	shake_sort(n3_reverse, 7300);


	return 0;
}