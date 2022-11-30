#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <time.h>
#include <chrono>


using namespace std;


//---------SUB-COMMANDS-------



//--------------ALGORITHMS------------------

//SELECTION-SORTint* duplicate(int a[], int n){
int* duplicate(int* a, int n){
    int* b = new int [n];
    for (int i = 0; i < n; i++) b[i] = a[i];
    return b;
}


void selectionSort_cmp(int* &a, int n, unsigned long long &count_cmp){
    int min;
	for (int i = 0; ++count_cmp && i < n - 1; i++){
        min = i;
        for (int j = i + 1; ++count_cmp && j < n; j++){
            if (++count_cmp && a[j] < a[min]) min = j;
        }
        swap(a[min], a[i]);
    }
}
void selectionSort_time(int* &a, int n, unsigned long long &time){
	auto start = std::chrono::high_resolution_clock::now();
	int min;
    for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min]) min = j;
        }
        swap(a[min], a[i]);
    }
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();	
}

//INSERTION SORT
void insertionSort(int* &a, int n)
{ 
    int current;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
    return;
}
void insertionSort_time(int* a, int n, unsigned long long &time)
{ 
	auto start = chrono::high_resolution_clock::now();
	insertionSort(a, n);
	auto elapsed = chrono::high_resolution_clock::now() - start;
	time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}
void insertionSort_cmp(int* a, int n, unsigned long long &comp)
{ 
	comp = 0;
	int current;
	for (int i = 1; ++comp && i < n; i++)
	{
		current = a[i];
		int j = i - 1;
		while (++comp && j >= 0 && ++comp && a[j] > current)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = current;
	}
}

//BUBBLE SORT
void bubbleSort(int*& a, int n){
    bool HoanViped;
    for(int i = 0; i < n-1; i++)
    {
        HoanViped = false;
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                HoanVi(a[j], a[j+1]);
                HoanViped = true;
            }
        }
        if(HoanViped == false)
            break;
    }
}

void bubbleSort_cmp(int*& a, int n, unsigned long long& count_compare){
    bool HoanViped;
    for(int i = 0; ++count_compare && i < n-1; i++)
    {
        HoanViped = false;
        for(int j = 0; ++count_compare && j < n-i-1; j++)
        {
            if(++count_compare && a[j] > a[j+1])
            {
                HoanVi(a[j], a[j+1]);
                HoanViped = true;
            }
        }
        if(++count_compare && HoanViped == false)
            break;
    }
}

void bubbleSort_time(int*& a, int n, unsigned long long &time){
	auto start = std::chrono::high_resolution_clock::now();
	bubbleSort(a, n);
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	time = chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();	
    return;
}


//HEAP SORT
void heapify(int arr[], int n, int i)  
{
    // for(int j = 0; j < n; j++){
    //     cout << arr[j] << " ";
    // }
    // cout << endl;
    int max = i;
    int l = i*2+1, r = i*2+2;
    if (r >= n && l < n){
        if (arr[l] > arr[i]) max = l; 
    }
    else if (l < n){
        if (arr[l] > arr[r] && arr[l] > arr[i]) max = l;
        else if (arr[r] > arr[i]) max = r;
    }
    // printf("%d\n",max);
    if (max != i){
        HoanVi(arr[max], arr[i]);
        heapify(arr, n, max);
    }
}

void buildHeap(int arr[], int n)  
{ 
    for (int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
}

void heapSort_time(int* arr, int n, unsigned long long &time)
{
    //code here
    auto start = std::chrono::high_resolution_clock::now();

    buildHeap(arr, n);
    HoanVi(arr[0], arr[n - 1]);
    for (int i = n-1; i > 0; i--){
        heapify(arr, i, 0);
        HoanVi(arr[0], arr[i - 1]);
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
	time = chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();	
	return;
}

void heapify_cmp(int arr[], int n, int i, unsigned long long &cmp)  
{
    // for(int j = 0; j < n; j++){
    //     cout << arr[j] << " ";
    // }
    // cout << endl;
    int max = i;
    int l = i*2+1, r = i*2+2;
    if ((++cmp && r >= n) && (++cmp && l < n)){
        if (++cmp && arr[l] > arr[i]) max = l; 
    }
    else if (++cmp && l < n){
        if ((++cmp && arr[l] > arr[r]) && (++cmp && arr[l] > arr[i])) max = l;
        else if (++cmp && arr[r] > arr[i]) max = r;
    }
    // printf("%d\n",max);
    if (++cmp && max != i){
        HoanVi(arr[max], arr[i]);
        heapify_cmp(arr, n, max, cmp);
    }
}

void buildHeap_cmp(int arr[], int n, unsigned long long &cmp)  
{ 
    for (int i = n/2-1; i >= 0; i--){
    	cmp++;
        heapify_cmp(arr, n, i, cmp);
    }
}

void heapSort_cmp(int* arr, int n, unsigned long long &cmp)
{
    //code here
    buildHeap_cmp(arr, n, cmp);
    int temp;
    HoanVi(arr[0], arr[n - 1]);
    for (int i = n-1; i > 0; i--){
    	cmp++;
        heapify_cmp(arr, i, 0, cmp);
        HoanVi(arr[0], arr[i - 1]);
    }
}

//MERGE SORT
void merge(int*& a, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int [n1];
    int* R = new int [n2];
    for(i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int* &a, int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge_cmp(int* &a, int l, int m, int r, unsigned long long& count_compare)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int [n1];
    int* R = new int [n2];
    for(i = 0; ++count_compare && i < n1; i++)
        L[i] = a[l + i];
    for(j = 0; ++count_compare && j < n2; j++)
        R[j] = a[m + 1 + j];
    i = 0;
    j= 0;
    k = l;
    while((++count_compare && i < n1) && (++count_compare &&j < n2))
    {
        if(++count_compare && L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(++count_compare && i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(++count_compare && j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_cmp(int* &a, int left, int right, unsigned long long& count_compare)
{
    int mid;
    if(++count_compare && left < right)
    {
        mid = left + (right - left) / 2;
        mergeSort_cmp(a, left, mid, count_compare);
        mergeSort_cmp(a, mid + 1, right, count_compare);
        merge_cmp(a, left, mid, right, count_compare);
    }
}

void mergeSort_time(int a[], int n, unsigned long long &time)
{
    //Execution Time measuring codes are retrieved from: How to Measure C++ Time Intervals | Pluralsight. (2020, February 5). Pluralsight. https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
    auto start = chrono::high_resolution_clock::now();
    mergeSort(a, 0, n - 1);
    auto elapsed = chrono::high_resolution_clock::now() - start;
    time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}

//RADIX
void radixSort_time(int* a, int n, unsigned long long &time)
{
	// Find max value
	auto start = chrono::high_resolution_clock::now();
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	// 
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		int* output = new int[n];
		int* count = new int[10];

		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			count[(a[i] / exp) % 10]++;
		}
		// 
		for (int i = 1; i < 10; i++)///////////////////////
		{
			count[i] += count[i - 1];
		}

		// 
		for (int i = n - 1; i >= 0; i--)
		{
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}
		// copy
		for (int i = 0; i < n; i++)
		{
			a[i] = output[i];
		}
	}
	auto elapsed = chrono::high_resolution_clock::now() - start;
	time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}

void radixSort_cmp(int* a, int n, unsigned long long &comp)
{
	comp = 0;
	// Find max value
	int max = a[0];
	for (int i = 0;++comp && i < n; i++)
	{
		if (++comp && max < a[i])
		{
			max = a[i];
		}
	}
	// 
	for (int exp = 1; ++comp && max / exp > 0; exp *= 10)
	{
		int* output = new int[n];
		int* count = new int[10];

		for (int i = 0; ++comp && i < 10; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; ++comp && i < n; i++)
		{
			count[(a[i] / exp) % 10]++;
		}
		// 
		for (int i = 1; ++comp && i < 10; i++)///////////////////////
		{
			count[i] += count[i - 1];
		}

		// 
		for (int i = n - 1; ++comp && i >= 0; i--)
		{
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}
		// copy
		for (int i = 0; ++comp && i < n; i++)
		{
			a[i] = output[i];
		}
	}
}

//COUNTING SORT
void countingSort(int* &a, int n){
    int min = a[0], max = a[0];
    int* ad = duplicate(a, n);
    for (int i = 0; i < n; i++){
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    int nt = max - min + 1; int at[nt];
    for (int i = 0; i < nt; i++){
        at[i] = 0;
    }
    for (int i = 0; i < n; i++){
        at[ad[i] - min]++;
    }
    for (int i = 1; i < nt; i++){
        at[i] += at[i - 1];
    }
    for (int i = 0; i < n; i++){
        a[at[ad[i] - min] - 1] = ad[i];
        at[ad[i] - min]--;
    }
    return;
}
void countingSort_cmp(int* &a, int n, unsigned long long &cmp){
    int min = a[0], max = a[0];
    int* ad = new int [n];
    for (int i = 0; ++cmp && i < n; i++) ad[i] = a[i];
    for (int i = 0; ++cmp && i < n; i++){
        if (++cmp && a[i] > max) max = a[i];
        if (++cmp && a[i] < min) min = a[i];
    }
    int nt = max - min + 1; int at[nt];
    for (int i = 0; ++cmp && i < nt; i++){
        at[i] = 0;
    }
    for (int i = 0; ++cmp && i < n; i++){
        at[ad[i] - min]++;
    }
    for (int i = 1; ++cmp && i < nt; i++){
        at[i] += at[i - 1];
    }
    for (int i = 0; ++cmp && i < n; i++){
        a[at[ad[i] - min] - 1] = ad[i];
        at[ad[i] - min]--;
    }
    return;
}
void countingSort_time(int* &a, int n, unsigned long long &time){
    auto start = chrono::high_resolution_clock::now();
    countingSort(a, n);
    auto elapsed = chrono::high_resolution_clock::now() - start;
    time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}

//SHAKER SORT
void shakerSort(int a[], int start, int end){
    //first forward pass
    bool flag = true;
    if (start >= end) return;
    for (int i = start; i < end; i++){
        if (a[i + 1] < a[i]){
            HoanVi(a[i + 1], a[i]);
            flag = false;
        }
    }
    if (flag) return;
    flag = true;
    for (int i = end - 1; i > start; i--){
        if (a[i] < a[i - 1]){
            HoanVi(a[i], a[i - 1]);
            flag = false;
        }
    }
    if (flag) return;
    shakerSort(a, start + 1, end - 1);
}

void shakerSort_cmp(int a[], int start, int end, unsigned long long &cmp){
    //first forward pass
    bool flag = true;
    if (++cmp && start >= end) return;
    for (int i = start; ++cmp && i < end; i++){
        if (++cmp && a[i + 1] < a[i]){
            HoanVi(a[i + 1], a[i]);
            flag = false;
        }
    }
    if (flag) return;
    flag = true;
    for (int i = end - 1; ++cmp && i > start; i--){
        if (++cmp && a[i] < a[i - 1]){
            HoanVi(a[i], a[i - 1]);
            flag = false;
        }
    }
    if (flag) return;
    shakerSort_cmp(a, start + 1, end - 1, cmp);
}
void shakerSort_time(int a[], int start, int end, unsigned long long &time){
    auto starttime = chrono::high_resolution_clock::now();
    shakerSort(a, start, end);
    auto elapsed = chrono::high_resolution_clock::now() - starttime;
    time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}
void shellSort_cmp(int*& a, int n, unsigned long long &count_compare)
{
    for (int in = n / 2; ++count_compare && in > 0; in /= 2) 
    {
        for (int i = in; ++count_compare && i < n; i += 1) 
        {
            int t = a[i];
            int j;
            for (j = i; ++count_compare && j >= in && ++count_compare && a[j - in] > t; j -= in) 
                a[j] = a[j - in];
            a[j] = t;
        }
    }
}
void shellSort_time(int*& a, int n, unsigned long long &time)
{
    auto start = chrono::high_resolution_clock::now();
    for (int in = n / 2; in > 0; in /= 2) 
    {
        for (int i = in; i < n; i += 1) 
        {
            int t = a[i];
            int j;
            for (j = i; j >= in && a[j - in] > t; j -= in) 
                a[j] = a[j - in];
            a[j] = t;
        }
    }
    auto elapsed = chrono::high_resolution_clock::now() - start;
    time = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}
void flashSort(int* &a, int n){
    int m = int(n * 0.45);
    int min = a[0], maxp = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > a[maxp]) maxp = i;
        if (a[i] < min) min = a[i];
    }
    int* l = new int [m]; //last
    for (int i = 0; i < m; i++) l[i] = 0;
    int k;
    for (int i = 0; i < n; i++){
        k = int((m - 1) * (a[i] - min) / (a[maxp] - min));
        l[k]++;
    }
    const double c = double(m - 1) / double(a[maxp] - min);

    for (int i = 1; i < m; i++) l[i] += l[i - 1];
    
    //swap
    HoanVi(a[0], a[maxp]);

    int j = 0, nmove = 0;
    k = 0;

    if (m - 1 < 0 || a[maxp] - min < 0) return;

    while (nmove < n - 1){
        while (j > l[k] - 1){
            j++;
            k = int(c * (a[j] - min));
        }
        while (j != l[k]){
            k = int(c * (a[j] - min));

            HoanVi(a[j], a[l[k] - 1]);
            l[k]--;
            nmove++;
        }
    }
    insertionSort(a, n);
    return;
}
void flashSort_cmp(int* &a, int n, unsigned long long &time){
    int m = int(n * 0.45);
    int min = a[0], maxp = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > a[maxp]) maxp = i;
        if (a[i] < min) min = a[i];
    }
    int* l = new int [m]; //last
    for (int i = 0; i < m; i++) l[i] = 0;
    int k;
    for (int i = 0; i < n; i++){
        k = int((m - 1) * (a[i] - min) / (a[maxp] - min));
        l[k]++;
    }
    const double c = double(m - 1) / double(a[maxp] - min);

    for (int i = 1; i < m; i++) l[i] += l[i - 1];
    
    //swap
    HoanVi(a[0], a[maxp]);

    int j = 0, nmove = 0;
    k = 0;

    if (m - 1 < 0 || a[maxp] - min < 0) return;

    while (nmove < n - 1){
        while (j > l[k] - 1){
            j++;
            k = int(c * (a[j] - min));
        }
        while (j != l[k]){
            k = int(c * (a[j] - min));

            HoanVi(a[j], a[l[k] - 1]);
            l[k]--;
            nmove++;
        }
    }
    insertionSort(a, n);
    return;
}