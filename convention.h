#ifndef CONVENTION_H
#define CONVENTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>	// Untuk kebutuhan mkdir di fileio
#include <errno.h>		// Untuk kebutuhan errno di fileio
#include <math.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL
typedef char* infotype;

// Boolean
#define true 1
#define false 0
typedef int boolean;

#endif