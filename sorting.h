#pragma once

#define MAX_SIZE 10


template <class LE>
class Sorting {
public:

	Sorting(LE *original); //Constructor
	~Sorting(); 

	int insertion_sort(int n); 
	bool insertion_sortSub(int arr[],int start, int end);

	int quick_sort(int left, int right); 
	int merge_sort(int left, int right); 

	void copy_list(LE newList[], int n, int compare); 
	void print_list(int left, int right); 

private:
	void merge(LE keyList[], int left, int mid, int right); //merge
	int quickPartition(LE keyList[], int left, int right); //quick sort partition

	LE *list;
	int num_compare; 
};



