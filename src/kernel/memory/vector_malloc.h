/* VectorOS
 * File name		: kernel/memory/vector_malloc.h
 * Creation date	: 2025/11/05 20:43 (Tues)
 */

#ifndef VECTOR_MALLOC_H
#define VECTOR_MALLOC_H

#include <stddef.h>

void *kernel_malloc(size_t);
int	 kernel_free(void *);

#endif
