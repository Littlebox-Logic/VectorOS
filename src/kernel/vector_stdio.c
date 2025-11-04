/* VectorOS
 * File name		: kernel/vector_stdio.c
 * Creation date	: 2025/11/14 00:30 (Tues)
 */

#include "vector_stdio.h"
#include "vector_errno.h"

int printf(const char *fmt, ...)
{
	return VECTOR_EXIT_SUCCESS;
}

int printk(const char *fmt, ...)
{
	return VECTOR_EXIT_SUCCESS;
}

int puts(const char *string)
{
	return VECTOR_EXIT_SUCCESS;
}
