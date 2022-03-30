#include "Lesson2.h"
#include <iostream>
#include <string.h>
#include <random>
#define Size_Inbuf 5
//3
void UseOparators() {
	int num = 10;
	int* numPtr = &num;
	std::cout << "before:	" << num << "\n";
	*numPtr = num * 2;
	std::cout << "after:	" << num << "\n";
}
//8
void Swap(char* x, char* y) {
	char temp=*x;
	*x = *y;
	*y = temp;
}
void PrintPermutations(char* str, int start, int end) {
	if (start == end){
		std::cout << "\t" << str << "\n";
		return;
	}
	for (int i = start; i <= end; i++)
	{		
		Swap(str+start,str+i);
		PrintPermutations(str,start+1,end);
		Swap(str + start, str + i);
	}
}
//14
int FindMin(int *arr,int n) {
	if (n == 1) {
		return 0;
	}
	int min = arr[0],imin=0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			imin = i;
		}
	}
	return imin;
}
void Swap(int *a1,int *a2) {
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void SortArray(int* arr,int n) {
	if (n == NULL)return;
	int minIndex;
	for (int i = 0; i < n; i++)
	{
		minIndex = FindMin(arr, n-i);
		Swap(arr + minIndex, arr);
		arr++;
	}
}
//17
int compare(const void* a, const void* b)
{
	return (*(int*)b - *(int*)a);
}
void SortArrayReverse(int *arr,int n) {

	qsort(arr, n, sizeof(int), compare);
	for (int i = 0; i <n; i++){ std::cout << arr[i] << "\n"; }
		
}

//תרגיל מרכזי
//1
double getProb() {
	return (double)rand() / RAND_MAX;
}
//2
int* generData(int*& inbuf, int& count) {
	int* buff = inbuf;
	if (count == Size_Inbuf)//אם נגמר המקום
	{
		inbuf = (int*)malloc(sizeof(int));
		count = 1;
		inbuf[0] = rand() % 9 + 1;
		return buff;
	}
	count++;
	//if(inbuf==NULL)
	//	inbuf = (int*)malloc(sizeof(int));
	//else
	inbuf = (int*)realloc(inbuf, sizeof(int) * (count));
	if (inbuf == NULL) {
		std::cout << "alocation failed\n";
		exit(1);
	}
	inbuf[count - 1] = rand() % 9 + 1;
	return NULL;
}
//3
void processData(int*& outbuf, int& count, int& total) {
	if (outbuf == NULL)return;
	for (int i = 0; i < Size_Inbuf; i++)
		total += outbuf[i];
	free(outbuf);
	count = 1;
	outbuf = NULL;
}
//4
void simulation() {
	int count = 0, total = 0;
	int* buffer = NULL, * oldBuff = NULL;
	std::cout << "start--------->>>>>>>>>>\n";
	for (int i = 0; i < 20; i++)
	{
		oldBuff = generData(buffer, count);
		if(!oldBuff)
			std::cout << "generate a new data:" << buffer[count - 1] << "	count:" << count << "\n";
		else
		{
			std::cout << "buffer is full!!\n";
			std::cout << "sending to process data.........\n";
			processData(oldBuff, count, total);
			std::cout << "the total is:	" << total << "\n";
			std::cout << "process data is finish.\n";
			std::cout << "generate a new data:" << buffer[count - 1] << "	count:" << count << "\n";
		}
	}
	std::cout << "end--------->>>>>>>>>>\n";
}
