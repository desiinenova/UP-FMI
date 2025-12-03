
// Домашно 2 по "Увод в програмирането"


#include <iostream>

// Задача 1
bool isBigEndian() {

  	int num = 1;
  	unsigned char* endianness = (unsigned char*)&num;

  	if(endianness[0] == 0){
		return true;
  	}
  	return false;
}

bool isLittleEndian() {
    if (isBigEndian() == false) {
		return true;
	}
	return true;
	return !isBigEndian();
}

// Задача 2


//	a = a.a^(power-1)/2
// 	x^n => x ^2n  
// x ^ k = x * x ^ k -1;
//  a = a.a^(power/2)
int fastPow(int base, unsigned int power) {

    int result = 1;
    while (power > 0) {

        if (power % 2 == 1){
            result *= base;
            base *= base;
            power = (power - 1)/2;     
        }
        else if (power % 2 == 0) {                      
            base *= base;
            result *= base;
            power = (power - 1)/2;
        }
    }


    return result;
}

// Задача 3
void commonDigits(int a, int b) {

	a = abs(a);
	b = abs(b);
	bool arr1 [10] = {0};
	bool arr2 [10] = {0};
	bool contains = false;

	if (a == 0) {
		arr1[0] = 1;
	}
	if (b == 0) {
		arr2[0] = 1;
	}

	while (a > 0) {
		int digit = a % 10;
        arr1[digit] = 1;
        a /= 10;
	}	
	while (b > 0) {
		int digit = b % 10;
		arr2[digit] = 1;
		b /= 10;
	}	
	
	for (int i = 9; i >= 0; i--) {
		if (arr1[i] == 1 && arr2[i] == 1) {
			std :: cout << i;
			contains = true;
		}	
	}
	
	if (contains == false) {
		std :: cout << "none";
	}
	
}
	

// Задача 4
bool isSorted(int* arr, size_t size) {

    if (size == 1) {
        return true;
    }
    if (arr[0] <= arr[1]) {
        for (int i = 0; i < size-1; i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
    }
    else if (arr[0] > arr[1]) {
        for (int i = 0; i < size-1; i++) {
            if (arr[i] <= arr[i+1]) {
                return false;
            }
        }    
    }
    
    return true;
}

// Задача 5
void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int* sortedArrayAsc(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
		}
	}
	return arr;
}

bool binarySearch(int element, int* arr, size_t size) {

    int* sortedArr = sortedArrayAsc(arr, size);
	int start = 0;
	int end = size-1;
	
	while (start <= end) {

		int middle = start + (end - start)/2;
		if (element == sortedArr[middle]) {
			return true;
		}
		else if (element > sortedArr[middle]) {
			start = middle + 1;
		}
		else if (element < sortedArr[middle]) {
			end = middle - 1;
		}
	}
	return false;
}

//---------------------------------------------------------------------
// Моля, не променяйте кода от тук до края на файла (под чертата)

void printCommonDigits(int a, int b)
{
	std::cout << "\n  The common digit(s) of " << a << " and " << b << " are: ";
	commonDigits(a, b);
}

int main(int argc, char* argv[])
{
	std::cout << "\n\n# Task 1";
	std::cout << "\n  isBigEndian() returns " << isBigEndian();
	std::cout << "\n  isLittleEndian() returns " << isLittleEndian();

	std::cout << "\n\n# Task 2";
	for(int i = 0; i < 15; ++i) {
		std::cout << "\n  3^" << i << " = " << fastPow(3, i);
	}

	std::cout << "\n\n# Task 3";
	printCommonDigits(1221253, 7542111);
	printCommonDigits(1221253, -7542111);
	printCommonDigits(12340, 90);
	printCommonDigits(101, 0);
	printCommonDigits(123, 456);
	printCommonDigits(123, 0);
	printCommonDigits(-5, -5);
	printCommonDigits(5, 5);
	printCommonDigits(0, 0);

	std::cout << "\n\n# Task 4";
	int arr1[] = {1, 2, 3, 4, 5};
	std::cout << "\n  isSorted(arr1) returns " << isSorted(arr1, 5);
	int arr2[] = {5, 4, 3, 2, 1};
	std::cout << "\n  isSorted(arr2) returns " << isSorted(arr2, 5);
	int arr3[] = {1, 1, 1, 1, 1};
	std::cout << "\n  isSorted(arr3) returns " << isSorted(arr3, 5);
	int arr4[] = {0, 1, 0, 1, 1};
	std::cout << "\n  isSorted(arr4) returns " << isSorted(arr4, 5);

	std::cout << "\n\n# Task 5";
	const size_t size = 9;
	int haystack[] = {-90, -3, 0, 1, 5, 10, 10, 1'000, 3'000};
	
	for(size_t i = 0; i < size; ++i) {
		std::cout
			<< "\n  Binary search lookup for " << haystack[i] << " returns "
			<< binarySearch(haystack[i], haystack, size);
	}

	std::cout << "\n  Binary search lookup for -91 returns " << binarySearch(-91, haystack, size);
	std::cout << "\n  Binary search lookup for 2 returns " << binarySearch(2, haystack, size);
	std::cout << "\n  Binary search lookup for 3000 returns " << binarySearch(3000, haystack, size);

	std::cout << "\nDone.\n\n";
}