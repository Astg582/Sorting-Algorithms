#include <iostream>

void merge(int*, int, int, int);

void mergSort(int* arr, int s, int e){
	if(s < e){
		int m = s + (e - s) /2;
		mergSort(arr, s, m);
		mergSort(arr, m + 1, e);
		merge(arr, s, m, e);
	}
}

void merge(int* arr, int s, int m, int e) {
	int* tmp = new int[(e - s) + 1];
	int i = s;
	int j = m + 1;
	int k = 0;

	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
		}
	}

	while (i <= m) {
		tmp[k++] = arr[i++];
	}

	while (j <= e) {
		tmp[k++] = arr[j++];
	}

	for (int d = 0, idx = s; idx <= e; ++idx, ++d) {
		arr[idx] = tmp[d];
	}

	delete[] tmp;
}


int main(){
	const int a = 10;
	int arr[a];
	std::cout << "enter to 10 number" << std::endl;
	for(int i = 0; i < a; ++i){
		std::cin >> arr[i];
	}

	mergSort(arr, 0, a - 1);
	std::cout << std::endl;
	for (int i = 0; i < a; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl; 
}
