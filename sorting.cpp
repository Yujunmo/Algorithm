#include "sorting.h"
#include<iostream>
#include <iostream>
using namespace std;

template<class LE>
Sorting<LE>::Sorting(LE *original) 
	:list(original), num_compare(0)	{}

template<class LE>
Sorting<LE>::~Sorting() {}

template<class LE>
int Sorting<LE>::insertion_sort(int n) {
	//n == size
	//배열 원소 하나씩 추가한다. 추가할때마다 크기순으로 정렬된다.
	//추가 후 배열 상태 출력한다.
	for (int current = 0; current < n ; current++) {
		insertion_sortSub(list, 0, current);
		print_list(0, n - 1);
	}
	return num_compare;	// 스왑이 일어난 횟수 
}

//최근에 추가된 값을 배열상에서 제 위치를 찾아 보내준다.
template<class LE>
bool Sorting<LE>::insertion_sortSub(int arr[], int start, int end) {
	bool finished = false;
	int current = end;
	bool moreToSrch = (current != start);
	

	while (moreToSrch && !finished) {
		if (arr[current] < arr[current - 1]) {
			num_compare++;
			swap(arr[current], arr[current - 1]);
			current--;
			moreToSrch = (current != start);

		}
		//제 위치를 찾았으면 스탑
		else {
			finished = true;
		}
	}
	return current == end;
}


template<class LE>
int Sorting<LE>::quick_sort(int left, int right) {
	// right == maxsize -1
	if (left < right) {
		int p = quickPartition(list, left, right); //피봇을 찾아준다.
		print_list(left, right);
		quick_sort(left, p - 1);	//피봇 왼쪽을 정리한다.
		quick_sort(p +1, right);	//피봇 오른쪽을 정리한다
		return num_compare;
	}
}

template<class LE>
int Sorting<LE>::quickPartition(LE keyList[], int left, int right) {

	//pivot - right
	/*int pivot = keyList[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; ++j) {
		if (keyList[j] <= pivot) {
			i++;
			swap(keyList[i], keyList[j]);
			num_compare++;
		}
	}
	swap(keyList[i + 1], keyList[right]);
	return i+1;
	*/
	
	//pivot - left
	int pivot = keyList[left];			//맨왼쪽 값을 기준으로 잡는다.
	int i = right + 1;
	for (int j = right; j >= left+1; --j) {
		if (keyList[j] > pivot) {	//맨왼쪽값보다 큰것을 다 오른쪽으로 민다.
			i--;
			swap(keyList[i], keyList[j]);
			num_compare++;
		}
	}
	swap(keyList[i - 1], keyList[left]);	// 맨왼쪽값의 위치를 조정해서 피봇값 기준 왼쪽은 다 작고 오른쪽은 다 크게

	//return index of pivot
	return i - 1;
}


// 소트된 두 배열 합는 함수
template<class LE>
void Sorting<LE>::merge(LE keyList[], int left, int mid, int right) {
	
	int n1 = mid - left + 1;
	int n2 = right - mid;

	//중간 왼쪽 배열 담을 배열
	LE* leftArray = new LE[n1];
	//중간 오른쪽 배열 담을 배열
	LE* rightArray = new LE[n2];

	// left ~ mid 가져오기
	for (int i = 0; i < n1; ++i) {
		leftArray[i] = keyList[left+i];
	}
	//mid+1 ~ right 가져오기
	for (int j = 0; j < n2; ++j) {
		rightArray[j] = keyList[mid + 1 + j];
	}
	
	//양쪽 배열 하나씩 비교하면서 작은거 차례로 담아오기
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftArray[i] <= rightArray[j]) {
			num_compare++;
			keyList[k] = leftArray[i];
			i++;
		}
		else {
			num_compare++;
			keyList[k] = rightArray[j];
			j++;
		}
		++k;
	}
	//남은 부분 다 가져오기 
	while (i < n1) {

		keyList[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < n2) {
		keyList[k] = rightArray[j];
		j++;
		k++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

template<class LE>
int Sorting<LE>::merge_sort(int left, int right) {

	if (left < right) {
		int middle = (left + right) / 2;		//중간위치 잡기
		merge_sort(left, middle);			//중간 왼족 소트
		merge_sort(middle + 1, right);		//중간 오른쪽 소트
		merge(list, left, middle, right);	//소트 된 위 두개 합치기

		print_list(left, right);
		return num_compare;
	}
}

template<class LE>
void Sorting<LE>::copy_list(LE newList[], int n, int compare) {
	num_compare = compare;

	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = newList[i];

}

template<class LE>
void Sorting<LE>::print_list(int left, int right) {
	for (int i = 0; i < left; i++)
		printf("    ");
	for (int i = left; i <= right; i++)
		printf("%4d", list[i]);
	printf("\n");
}

