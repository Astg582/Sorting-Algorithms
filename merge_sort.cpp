#include <iostream>
void merge(int*, int, int, int);

void merge_S(int* arr, int f, int e){
	if(e > f){
		int m = f + (e - f) / 2;
		merge_S(arr, f, m);
		merge_S(arr, m + 1, e);

		merge(arr, f, m, e);
	}
}

void merge(int* arr, int f, int m, int e){
	int f1 = f;
	int e1 = m;
	int f2 = m + 1;
	int e2 = e;

	int s = (e - f) + 1;
	int* tmp = new int[s];
	int ind = 0;

	while (f1 <= e1 && f2 <= e2){
		if (arr[f1] <= arr[f2]){
			tmp[ind] = arr[f1];
			++f1;
		} else {
			tmp[ind] = arr[f2];
			++f2;
		}
		++ind;
	}

	while(f1 <= e1){
		tmp[ind] = arr[f1];
		++f1;
		++ind;
	}

	while(f2 <= e2){
		tmp[ind] = arr[f2];
		++f2;
		++ind;
	}

	for(int  i = 0; i < s; ++i){
		arr[f + i] = tmp[i];
	}

	delete[] tmp;
}

void print(int arr[], int s){
    std::cout << std::endl;

    for(int i = 0; i < s; ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void fill(int arr[], int s){
    std::cout << "fill arr" << std::endl;

    for(int i = 0; i < s; ++i){
        std::cin >> arr[i];
    }
}



const int s = 10;
int main(){
    int arr[s];
    fill(arr, s);
    merge_S(arr, 0, s - 1);
    print(arr, s);
}

