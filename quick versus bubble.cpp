#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stack>
#include<Windows.h>

 //2014111629
 //경영학부
 //유준모

using namespace std;
#define ARR_SIZE 1000

void randomArray(int arr0[],int arr1[],int arr2[],int arr3[], int num) {
	for (int i = 0; i < num; ++i) {
		int num = (rand() % 10000) + 1;
		arr0[i] = num;
		arr1[i] = num;
		arr2[i] = num;
		arr3[i] = num;
	}
}

void printArr(int arr[], int num) {
	for (int i = 0; i < num; ++i) {
		cout << arr[i] << " ";
	}
	puts("");
	return;
}


// 버블 소트 ( 재귀x )
void nonRecursiveBubble(int arr[], int start, int end) {
	bool sorted = true;
	for (int i = end; i >= 0; --i) {
		if (i!=end&&sorted == true) {
			break;
		}
		for (int j = 0; j < i ; ++j) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				if (sorted == true) {
					sorted = false;
				}
			}
		}
	}
}


void recursiveBubble_sub(int arr[], int num, bool sorted) {
	if (num != ARR_SIZE) {
		if (sorted == true) return;
	}
	if (num == 1) return;

	for (int i = 0; i < num; ++i) {
		if (arr[i] < arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			if (sorted == true) {
				sorted = false;
			}
		}
	}
	recursiveBubble_sub(arr, num - 1, sorted);
}

// 버블소트(재귀)
void recursiveBubble(int arr[], int num) {
	recursiveBubble_sub(arr, num, true);
}

int quickPartition(int keyList[], int left, int right) {
	//pivot - right
	int pivot = keyList[right];		//맨 오른쪽 값을 기준으로 잡는다
	int i = left - 1;
	for (int j = left; j <= right - 1; ++j) {
		if (keyList[j] > pivot) {		//맨 오른쪽 값보다 큰것을 다 왼쪽으로 민다.
			i++;
			swap(keyList[i], keyList[j]);
		}
	}
	swap(keyList[i + 1], keyList[right]);	//맨 오른쪽 값의 위치를 조정해서 피봇값 기준 왼쪽은 다 크고 오른쪽은 다 작게
	return i+1;
}

// 퀵소트 (재귀)
void RecursiveQuick(int arr[],int left, int right) {
	// right == maxsize -1
	if (left < right) {
		int p = quickPartition(arr, left, right); //피봇을 찾아준다.
		RecursiveQuick(arr,left, p - 1);	//피봇 왼쪽을 정리한다.
		RecursiveQuick(arr,p + 1, right);	//피봇 오른쪽을 정리한다
		return;
	}
}

// 퀵소트(재귀x)
void nonRecursiveQuick(int arr[], int start, int end) {
	stack<int> stack;
	stack.push(end);
	stack.push(start);
	int left, right, pivot;

	//파티션 함수에 넣어줄 매개변수 값들만 스택에 쌓아놓고 
	//순서대로 가져와서 파티션해주면 된다.
	while (!stack.empty()) {
		left = stack.top(); stack.pop();
		right = stack.top(); stack.pop();
		pivot = quickPartition(arr, left, right);
		 
		if (pivot - 1 > left) {
			stack.push(pivot - 1);
			stack.push(left);
		}

		if (pivot + 1 < right) {
			stack.push(right);
			stack.push(pivot + 1);
		}
	}

}

int main()
{
	time_t start1, end1;
	srand((unsigned int)time(NULL));
	int arr0[ARR_SIZE];
	int arr1[ARR_SIZE];
	int arr2[ARR_SIZE];
	int arr3[ARR_SIZE];

	randomArray(arr0,arr1,arr2, arr3,ARR_SIZE);

	//버블 (재귀x)
	cout << "bubble sort : (non recursive)";
	start1 = clock();
	nonRecursiveBubble(arr0, 0,ARR_SIZE-1);
	end1 = clock();; puts("");
	printf("time cost : %f\n", (double)(end1 - start1));
//	cout << "bubble" << endl;printArr(arr0, ARR_SIZE);

	puts("");

	//버블 (재귀)
	cout << "bubble sort : (recursive)";
	start1 = clock();
	recursiveBubble(arr1, ARR_SIZE);
	end1 = clock();; puts("");
	printf("time cost : %f\n", (double)(end1 - start1));
	//cout << "bubble" << endl;printArr(arr1, ARR_SIZE);
	
	puts("");

	//퀵 (재귀)
	cout << "quick sort : (recursive)";
	start1 = clock();
	RecursiveQuick(arr1, 0, ARR_SIZE-1);
	end1 = clock(); puts("");
	printf("time cost : %f\n", (double)(end1 - start1));
	//cout << "quick" << endl; printArr(arr1, ARR_SIZE);

	puts("");

	//퀵 (재귀X)
	cout << "quick sort : (non recursive)";
	start1 = clock();
	nonRecursiveQuick(arr3, 0, ARR_SIZE - 1);
	end1 = clock(); puts("");
	printf("time cost : %f\n", (double)(end1 - start1));
	//cout << "quick" << endl; printArr(arr3, ARR_SIZE);

	system("pause");
	return 0;
}