#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <time.h>
#include <chrono>
#include "DataGenerator.cpp"
#include "Algorithm.cpp"

using namespace std;

void print(int a[], int n){
	int i = 0;
	while (i < n){
		cout << a[i] << " ";
		i++;
	}
	cout << endl;
	return;
}

bool isNumber(char number[]){
	int i = 0;
	for(; number[i] != 0; i++){
		if (!isdigit(number[i])) return false;
	}
	return true;
} //only used in cmdline


//------------------------------------------

int cmdline(int argc, char** argv){
	//COMMAND LINE
	//https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
	//argc is the number of arguments given to main

	if (strcmp(argv[1], "-a") == 0){
		if (argc == 5){
			if (!isNumber(argv[3])) return 1;
			else return 3;
		}
		if (argc == 6) return 2;
		else return 0;
	}
	else if (strcmp(argv[1], "-c") == 0){
		if (argc == 5) return 4;
		else if (argc == 6) return 5;
		else return 0;
	}
	else{
		return 0;
	}
} //return mode


//STRUCT ALGORITHM
struct ALGR{
	char* name;
	char* para;
	long long unsigned cmp = 0;
	long long unsigned time;
public:
	void printresult(){
		if (strcmp(para, "-comp") == 0) printf("Comparisons: %llu\n", cmp);
		if (strcmp(para, "-time") == 0) printf("Time: %llu\n", time);
		else if (strcmp(para, "-both") == 0){
			printf("Comparisons: %llu\nTime: %llu\n", cmp, time);
		}
	}

	void algorithm_run(int a[], int n){
		if (strcmp(name, "selection-sort") == 0){
			if (strcmp(para, "-comp") == 0) selectionSort_cmp(a, n, cmp);
			else if (strcmp(para, "-time") == 0) selectionSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				selectionSort_cmp(a, n, cmp);
				selectionSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "bubble-sort") == 0){
			if (strcmp(para, "-comp") == 0) bubbleSort_cmp(a, n, cmp);
			if (strcmp(para, "-time") == 0) bubbleSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				bubbleSort_cmp(a, n, cmp);
				bubbleSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "binary-insertion-sort") == 0){
			if (strcmp(para, "-comp") == 0) insertionSort_cmp(a, n, cmp);
			if (strcmp(para, "-time") == 0) insertionSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				insertionSort_cmp(a, n, cmp);
				insertionSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "heap-sort") == 0){
			if (strcmp(para, "-comp") == 0) heapSort_cmp(a, n, cmp);
			if (strcmp(para, "-time") == 0) heapSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				heapSort_cmp(a, n, cmp);
				heapSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "merge-sort") == 0){
			if (strcmp(para, "-comp") == 0) mergeSort_cmp(a, 0, n - 1, cmp);
			if (strcmp(para, "-time") == 0) mergeSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				mergeSort_cmp(a, 0, n - 1, cmp);
				mergeSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "radix-sort") == 0){
			if (strcmp(para, "-comp") == 0) radixSort_cmp(a, n, cmp);
			if (strcmp(para, "-time") == 0) radixSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				radixSort_cmp(a, n, cmp);
				radixSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "counting-sort") == 0){
			if (strcmp(para, "-comp") == 0) countingSort_cmp(a, n, cmp);
			if (strcmp(para, "-time") == 0) countingSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				countingSort_cmp(a, n, cmp);
				countingSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "shaker-sort") == 0){
			if (strcmp(para, "-comp") == 0) shakerSort_cmp(a, 0, n - 1, cmp);
			if (strcmp(para, "-time") == 0) shakerSort_time(a, 0, n - 1, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				shakerSort_cmp(a, 0, n - 1, cmp);
				shakerSort_time(b, 0, n - 1, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "shell-sort") == 0){
			if (strcmp(para, "-comp") == 0) shellSort_cmp(a, n, cmp);
			if (strcmp(para, "-time") == 0) shellSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				shellSort_cmp(a, n, cmp);
				shellSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
		if (strcmp(name, "quick-sort") == 0){
			if (strcmp(para, "-comp") == 0) quickSort_cmp(a, 0, n - 1, cmp);
			else if (strcmp(para, "-time") == 0) quickSort_time(a, n, time);
			else if (strcmp(para, "-both") == 0){
				int* b = duplicate(a, n);
				quickSort_cmp(a, 0, n - 1, cmp);
				quickSort_time(b, n, time);
				delete[] b;
			}
			else return;
		}
	}	
};

void printCresult(ALGR a1, ALGR a2){
			printf("Comparisions: %llu | %llu\nTime: %llu | %llu\n", a1.cmp, a2.cmp, a1.time, a2.time);
}

bool fread(char* filename, int* &a, int &n){
//READ FILE OR GENERATE ARRAY OF NUMBER
	ifstream fin;
	fin.open(filename);

	fin >> n;

	a = new int [n];
	for (int i = 0; i < n; i++){
		fin >> a[i];
	}
	return true;
}

//------------------------------

void command1(char** argv){

	//INIT
	ALGR al1;
	char* filename; //array
	char both[10];
	strcpy(both, "-both");
	char* in_order;

	int* a;
	int size;

	ofstream fout;
	fout.open("output.txt");

	al1 = {argv[2], argv[4], 0, 0};
	filename = argv[3];

	//READ FILE
	bool state = fread(filename, a, size);
	if (!state){
		cout << "Read file failed!\n";
		return;
	}

	al1.algorithm_run(a, size); //to call an algorithm

	//WRITE FILE
	fout << size << endl;
	for (int i = 0; i < size; i++){
		fout << a[i] << " ";
	}

	al1.printresult();
	return;
}

void command2(char** argv){
	//huy
	//INIT
	ALGR al1;
	char both[10];
	strcpy(both, "-both");
	char* in_order; //input order
	
	int* a;
	int size;

	ofstream fout;
	fout.open("output.txt");

	al1 = {argv[2], argv[5], 0, 0};
	size = atoi(argv[3]);
	in_order = argv[4];
	//remember to create duplicate before running algorithms

	//generate input

	//write input in file

	//algorithm

	//write output in file

	//cout time - comparisons
	al1.printresult();
	return;
}

void fwrite(string filename, int a[], int n) {
	ofstream fout;
	fout.open(filename);

	fout << n << endl;

	for (int i = 0; i < n; i++) {
		fout << a[i] << " ";
	}

	fout.close();
}

void command3(char** argv){
	//mchau
	//INIT
	ALGR al1;
	char both[10];
	strcpy(both, "-both");
	
	int* a;
	int size;

	ofstream fout;
	fout.open("output.txt");

	al1 = {argv[2], argv[4], 0, 0};
	size = atoi(argv[3]);
	a = new int [size];

	//tao array random data
	cout << "Input order: Ramdomize\n";
	GenerateRandomData(a, size);
	//tao array moi de chay thuat toan tren do, k dung array goc
	fwrite("input_1.txt", a, size);
	al1.algorithm_run(a, size);
	al1.printresult();

	//tao array nearly sorted data
	al1.time = 0; al1.cmp = 0;
	cout << "Input order: Nearly Sort\n";
	GenerateNearlySortedData(a, size);
	fwrite("input_2.txt", a, size);
	al1.algorithm_run(a, size);
	al1.printresult();
	
	//tao array sorted
	al1.time = 0; al1.cmp = 0;
	cout << "Input order: Sorted\n";
	GenerateSortedData(a, size);
	fwrite("input_3.txt", a, size);
	al1.algorithm_run(a, size);
	al1.printresult();

	//tao array reversed sorted
	al1.time = 0; al1.cmp = 0;
	cout << "Input order: Reversed\n";
	GenerateReverseData(a, size);
	fwrite("input_4.txt", a, size);
	al1.algorithm_run(a, size);
	al1.printresult();
	//ghi array moi tao vao file
}


/*
– "input_1.txt": random order data
– "input_2.txt": nearly sorted data
– "input_3.txt": sorted data
– "input_4.txt": reversed data

Input order:
• -rand: randomized data
• -nsorted: nearly sorted data
• -sorted: sorted data
• -rev: reverse sorted data
*/
//Run two sorting algorithms on the given input.
//– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
//– Ex: a.exe -c heap-sort merge-sort input.txt
void command4(char** argv){
	//yen
	//INIT
	ALGR al1, al2;
	char* filename;
	char both[10];
	strcpy(both, "-both");
	char* in_order; //input order
	
	int* a;
	int size;

	ofstream fout;
	fout.open("output.txt");

	al1 = {argv[2], both, 0, 0};
	al2 = {argv[3], both, 0, 0};
	filename = argv[4];

	//mo file
	bool state = fread(filename, a, size);
	if (!state){
		cout << "Read file failed!\n";
		return;
	}

	//nho tao array moi de chay thuat toan tren do, k dung array goc
	int* temp1;
	temp1 = duplicate(a, size);
	// fwrite("input_1.txt", a, size);
	al1.algorithm_run(temp1, size);
	al1.printresult();
	//chay thuat toan al1 va al2 
	al2.algorithm_run(temp1, size);
	al2.printresult();
	//cout time + comparisons
	
	// al1.printresult();	
}

//Run two sorting algorithms on the data generated automatically.
//– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size][Input order]
//– Ex: a.exe -c quick-sort merge-sort 100000 -nsorted
void command5(char** argv){
	//yen
	//INIT
	ALGR al1, al2;
	char both[10];
	strcpy(both, "-both");
	char* in_order; //input order
	
	int* a;
	int size;

	ofstream fout;
	fout.open("output.txt");

	al1 = {argv[2], both, 0, 0};
	al2 = {argv[3], both, 0, 0};
	size = atoi(argv[4]);
	in_order = argv[5];

	//generate data dung function tu file cua thay

	//ghi data moi tao vao file input

	//chay thuat toan

	//cout

}

int main(int argc, char** argv){
	//INITIALIZE
	int mode = cmdline(argc, argv);
	cout << "Command: " << mode << endl;

	//EXECUTION
	switch(mode){
		case 1:
			command1(argv);
			break;
		case 2:
			command2(argv);
			break;
		case 3:
			command3(argv);
			break;
		case 4:
			command4(argv);
			break;
		case 5:
			command5(argv);
			break;
		default:
			break;
	}
	return 0;
}