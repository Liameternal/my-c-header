//
// Created by liam on 9/6/21.
//

#ifndef SINGLE_MYSELF_H
#define SINGLE_MYSELF_H

#include <stdio.h>

#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))
#define ABS(X)     ((X) > 0 ? (X) : -(X))
#define IS_SIGN(X) ((X) == '+' || (X) == '-' ? 1 : 0)

/*
 * Being familier with fgets(), but change the '\n' into '\0' while fgets()
 * read a line containing '\n', and remove remain contents until '\n' while
 * fgets() read a line without '\n'.
 * Accept the same parameters as fgets()
 * Return a pointer pointing into a stored string read from stream fp
 */
char* StrGet(char* str, int n, FILE* fp);

/*
 * As the name says, a sort function, which can sort array of int, long, or 
 * string so far.
 * Accept four parameters, first is the array to be sorted, second one is
 * the size of array type, third one is the length of the array to be 
 * sorted, the last one is a function, retuen the compare result
 */
void BubbleSort(void* ptr, size_t width, int n, int (*pfc)(void*, void*));

/*
 * A compare function for int
 * Accept two general pointers
 * Return 1,0,-1 when the first one great than,equal,less than the other
 * respectively
 */
int CompareInt(void* m, void* n);

/*
 * A compare function for ling
 * Accept two general pointers
 * Return 1,0,-1 when the first one great than,equal,less than the other
 * respectively
 */
int CompareLong(void* m, void* n);

/*
 * A compare function for string
 * Accept two general pointers
 * Retuen value is the same as strcmp()
 */
int CompareStr(void* m, void* n);

/*
 * Customized binary string type
 */
typedef char* BI_STRING;

/*
 * Transfer a BI_STRING into int
 */
int BiStrToInt(BI_STRING b, int bits);

/*
 * Transfer a int into BI_STRING 
 */
BI_STRING IntToBiString(int x);

/*
 * Show binary string
 */
void ShowBiString(BI_STRING b);

/*
 * Split file name into individual seperated by '/'
 * only works on unix-like system
 */
char** SplitFileName(char* filename, int* fields);

/*
 * Copy any kind of array form source to dest within size bytes
 */
void CopyArray(void** dest, const void* source, size_t size);

#endif// SINGLE_MYSELF_H
