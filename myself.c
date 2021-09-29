//
// Created by liam on 9/6/21.
//

#include "myself.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <errno.h>


char* StrGet(char* str, int n, FILE* fp) {
  char* ret_val;
  char* find;
  ret_val = fgets(str, n, fp);
  if (ret_val) {
    find = strchr(str, '\n');
    if (find)
      *find = '\0';
    else {
      while (fgetc(fp) != '\n')
        continue;
    }
  }

  return ret_val;
}

const int MAX_BUF = 256;
void BubbleSort(void* ptr, size_t width, int n, int (*pfc)(void*, void*)) {
  unsigned char buf[MAX_BUF];
  unsigned char* ptl = ptr;
  int compare;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= i; ++j) {
      compare = pfc((void*) (ptl + (j - 1) * width), (void*) (ptl + j * width));
      if (compare > 0) {
        memcpy(buf, ptl + (j - 1) * width, width);
        memcpy(ptl + (j - 1) * width, ptl + j * width, width);
        memcpy(ptl + j * width, buf, width);
      }
    }
  }
}

int CompareInt(void* m, void* n) {
  int *m1, *n1;
  m1 = (int*) m;
  n1 = (int*) n;
  return *m1 > *n1;
}

int CompareLong(void* m, void* n) {
  long *m1, *n1;
  m1 = (long*) m;
  n1 = (long*) n;
  return *m1 > *n1;
}

int CompareStr(void* str1, void* str2) {
  char* str11 = str1;
  char* str21 = str2;
  return strcmp(str11, str21);
}

int BiStrToInt(BI_STRING b, int bits) {
  int num[bits];
  int total = 0;
  for (int i = 0; i < bits; ++i) {
    num[i] = b[i] - '0';
  }
  int i = bits - 1;
  int j = 0;
  for (; i >= 0; --i, ++j) {
    total += num[i] * pow(2, j);
  }
  return total;
}

BI_STRING IntToBiString(int x) {
  const static int size = sizeof(int) * CHAR_BIT;
  BI_STRING b = (BI_STRING) malloc((size + 1) * sizeof(char));
  if (!b)
    fprintf(stderr, "Malloc failed!\n");
  for (int i = size - 1; i >= 0; --i) {
    b[i] = (x & 01) + '0';
    x >>= 1;
  }
  b[size] = '\0';
  return b;
}

void ShowBiString(BI_STRING b) {
  printf("%s\n", b);
}
char** SplitFileName(char* filename, int* fields) {
  extern int errno;
  int arr_num = 0;
  char* p = filename;
  char* q = filename;
  while (*p) {
    if (*p == '/')
      ++arr_num;
    ++p;
  }
  *fields = arr_num;

  char** split_name = calloc(sizeof(char*), arr_num);
  if (!split_name) {
    error(0, errno, NULL);
    return NULL;
  }
  for (int i = 0; i < arr_num; ++i) {
    split_name[i] = strchr(q, '/') + 1;
    q = split_name[i];
  }
  for (int i = 1; i < arr_num; ++i) {
    *(split_name[i] - 1) = '\0';
  }

  return split_name;
}
void CopyArray(void** dest, const void* source, size_t size) {
  void* to = malloc(size);
  if (!to) {
    perror("malloc");
    *dest = NULL;
    return;
  }
  memmove(to, source, size);

  *dest = to;
}
