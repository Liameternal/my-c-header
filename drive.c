//
// Created by liam on 9/6/21.
//
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "myself.h"

int main(int argc, char** argv) {
  puts("kind of char * example:");
  char str[] = "this is a string";
  size_t len = strlen(str);
  char* cp_str;
  CopyArray((void*) &cp_str, (void*) str, len * sizeof(char));
  puts(str);
  puts(cp_str);

  puts("kind of int example:");
  int guess[len];
  int* cp_guess;
  for (int i = 0; i < len; ++i) {
    guess[i] = i + 1;
  }
  CopyArray((void*) &cp_guess, (void*) guess, len * sizeof(int));
  printf("guess: ");
  for (int i = 0; i < len; ++i) {
    printf("%d ", guess[i]);
    if ((i + 1) % len == 0)
      putchar('\n');
  }
  printf("cp_guess: ");
  for (int i = 0; i < len; ++i) {
    printf("%d ", cp_guess[i]);
    if ((i + 1) % len == 0)
      putchar('\n');
  }

  return 0;
}