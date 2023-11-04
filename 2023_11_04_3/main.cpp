#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SWAP(a,b)        {int t; t = a; a=b; b=t;}
#define LEFT_CHILD(x)    (2*x + 1)
#define RIGHT_CHILD(x)   (2*x + 2)
#define PARENT(x)        ((x-1)/2)

int *origin;
int on;

void MergeSort(int *base, int n);
void HeapSort(int *base, int n);

void ViewArr(int* arr, int n);

void SequenceSort(int* base, int n);
void BubbleSort(int *base, int n);
void SelectionSort(int *base, int n);
void InsertionSort(int *base, int n);
void ShellSort(int *base, int n);
void QuickSort(int *base, int n);

int main(void){
    int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };

    SequenceSort(arr, 10);
	BubbleSort(arr, 10);
	SelectionSort(arr, 10);
	InsertionSort(arr, 10);
	
	origin = arr;
	on = 10;

	ShellSort(arr, 10);

	origin = arr;
	on = 10;

	ViewArr(arr, 10);
	QuickSort(arr, 10);
	ViewArr(arr, 10);
	
	origin = arr;
	on = 10;

	ViewArr(origin, on);
	MergeSort(arr, 10);
	ViewArr(origin, on);

	ViewArr(arr, 10);
	HeapSort(arr, 10);
	ViewArr(arr, 10);

    return 0;
}

void InsertionSort2(int *base, int size, int step);

void SequenceSort(int* base, int n){
    int i, j;

    ViewArr(base, n);

    for (i = 0; i < n; i++){
        for (j = i; j < n; j++){
            if (base[i] > base[j]){
                SWAP(base[i], base[j]);
                ViewArr(base, n);
            }
        }
    }
}

void BubbleSort(int *base, int n){
	int i, j;
	ViewArr(base, n);
	for (i = n; i>1; i--){
		for (j = 1; j<i; j++){
			if (base[j - 1]>base[j]){
				SWAP(base[j - 1], base[j]);
				ViewArr(base, n);
			}
		}
	}
}

void SelectionSort(int *base, int n){

	int i, j;

	int maxi;

	ViewArr(base, n);
	for (i = n; i>1; i--){
		maxi = 0;
		for (j = 1; j<i; j++){
			if (base[maxi]<base[j]){
				maxi = j;
			}
		}
		SWAP(base[maxi], base[i - 1]);
		ViewArr(base, n);
	}
}

void InsertionSort(int *base, int n){
	int i, j;

	ViewArr(base, n);

	for (i = 1; i<n; i++){
		for (j = i; j>0; j--){
			if (base[j - 1]>base[j]){
				SWAP(base[j - 1], base[j]);
				ViewArr(base, n);
			}
			else{
				break;
			}
		}
	}
}

void ShellSort(int *base, int size){
	int i, step;

	for (step = size / 2; step>0; step /= 2){
		printf("step:%d\n", step);

		for (i = 0; i<step; i++){
			InsertionSort2(base + i, size - i, step);
		}
	}
}

void InsertionSort2(int *base, int size, int step){
	int i, j;

	for (i = step; i<size; i += step){
		for (j = i; j>0; j -= step){
			if (base[j - step]>base[j]){
				SWAP(base[j - step], base[j]);

				ViewArr(origin, on);
			}
			else{
				break;
			}
		}
	}
}

void PrintSpace(int n);

void QuickSort(int *base, int n){
	int pivot = 0;
	int left = 0, right = 0;

	if (n <= 1)
	{
		return;
	}
	left = 0;

	right = n;

	while (1){
		for (left++; (left<n) && (base[0] >= base[left]); left++);

		for (right--; (right>0) && (base[0]<base[right]); right--);

		if (left<right){
			SWAP(base[left], base[right]);

			PrintSpace(base - origin);

			ViewArr(base, n);
		}

		else{
			break;
		}
	}

	SWAP(base[0], base[right]);

	PrintSpace(base - origin);

	ViewArr(base, n);

	QuickSort(base, right);

	QuickSort(base + left, n - left);
}

void PrintSpace(int n){
	int i = 0;

	for (i = 0; i<n; i++){
		printf("   ");
	}
}

void PrintSpace(int n);

void MergeSort(int *base, int n){
	int ahalf = n / 2;
	int bhalf = n - ahalf;
	int ai = 0, bi = ahalf;
	int i = 0;
	int *tbase = 0;

	if (n <= 1){
		return;
	}

	MergeSort(base, ahalf);

	PrintSpace(base - origin);

	ViewArr(base, ahalf);

	MergeSort(base + ahalf, bhalf);

	PrintSpace(base + ahalf - origin);

	ViewArr(base + ahalf, bhalf);

	tbase = (int *)malloc(sizeof(int)*n);

	memcpy(tbase, base, sizeof(int)*n);

	while ((ai<ahalf) && (bi<n)){
		if (tbase[ai] <= tbase[bi]){
			base[i] = tbase[ai];
			ai++;
		}
		else{
			base[i] = tbase[bi];
			bi++;
		}
		i++;
	}

	while (ai<ahalf){
		base[i] = tbase[ai];
		i++;
		ai++;
	}
	while (bi<n){
		base[i] = tbase[bi];
		i++;
		bi++;
	}
	free(tbase);       

}

void PrintSpace(int n){
	int i = 0;

	for (i = 0; i<n; i++){
		printf("   ");
	}
}

void InitHeap(int *base, int n);

void MakeHeap(int *base, int n);

void HeapSort(int *base, int n){

	int on = n;

	printf("초기 힙 생성 과정\n");

	InitHeap(base, n);

	n--;

	SWAP(base[0], base[n]);

	printf("정렬 과정\n");

	while (n>1){
		MakeHeap(base, n);

		ViewArr(base, n + 1);

		n--;

		SWAP(base[0], base[n]);

	}

	ViewArr(base, n + 1);

}

void InitHeap(int *base, int n){
	int pa = 0;
	int now;
	int i;

	for (i = 1; i<n; i++){
		now = i;

		while (now>0){
			pa = PARENT(now);

			if (base[now]>base[pa]){
				SWAP(base[now], base[pa]);

				now = pa;
			}
			else{
				break;
			}
		}
		ViewArr(base, i + 1);
	}
}

int FindMaxIndex(int *base, int n, int now);

void MakeHeap(int *base, int n){
	int now = 0;

	int mp = 0;

	while (LEFT_CHILD(now) < n){
		int mp = FindMaxIndex(base, n, now);

		if (mp == now){
			break;
		}
		if (base[mp] > base[now]){
			SWAP(base[mp], base[now]);
		}
		now = mp;
	}
}

int FindMaxIndex(int *base, int n, int now){

	int lc = LEFT_CHILD(now);

	int rc = RIGHT_CHILD(now);

	if (rc >= n){
		if (base[now]<base[lc]){
			return lc;
		}
		return now;
	}

	if (base[lc]<base[rc]){
		return rc;
	}
	return lc;
}

void ViewArr(int* arr, int n){
    int i = 0;
    for (i = 0; i < n; i++){
        printf("%2d ", arr[i]);
    }
    printf("\n");

}