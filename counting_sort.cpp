#include <iostream>
#include <climits>

const int s = 10;
void counting_S(int*, int);

void print(int*, int);
void fill(int*, int);
int max1(int*, int);
int min1(int*, int);

int main(){
	int arr[s];
	fill(arr, s);
	counting_S(arr, s);
	print(arr, s);
}

void fill(int* arr, int s){
	std::cout << " Enter array " << std::endl;

	for(int i = 0; i < s; ++i){
		std::cin >> arr[i];
	}

	std::cout << " Array is full " << std::endl;
}

void print(int* arr, int s){
	std::cout << "\nThe array is printed " << std::endl;

	for(int i = 0; i < s; ++i){
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int min1(int* arr, int s){
	int min = INT_MAX;
	
	for(int i = 0; i < s; ++i){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	return min;
}

int max1(int* arr, int s){
	int max = INT_MIN;
	
	for(int i = 0; i < s; ++i){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

void counting_S(int* arr, int s){
	if ( s <= 0){
		return;
	}

	int max = max1(arr, s);
	int min = min1(arr, s);
	int range = max - min + 1;

	int* tmp = new int[range]();
	int* res = new int[s];
		
	for(int i = 0; i < s; ++i){
		++tmp[arr[i] - min];
	}
	
	for(int i = 1; i <= range; ++i){
		tmp[i] += tmp[i - 1];
	}	

	for(int i = s - 1; i >= 0; --i){
		res[tmp[arr[i] - min] - 1] = arr[i];
		--tmp[arr[i] - min];
	}

	for(int i = 0; i < s; ++i){
		arr[i] = res[i];
	}
	delete[] tmp;
	delete[] res;
}
