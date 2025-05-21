#ifndef CONVENTION_H
#define CONVENTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL
typedef char* infotype;

// Boolean
#define true 1
#define false 0
typedef int boolean;

#endif