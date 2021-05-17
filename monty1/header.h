#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define UNUSED __attribute__((unused))
#define BUFFERSIZE 128

char *lines[BUFFERSIZE];

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instructions
{
	char *oper;
	void (*function)(/*stack_t **stack,*/char *dolor);
} operations;

void match(void);

void op_nop(/*stack_t **stack,*/char *dolor);

#endif
