/* VectorOS
 * File name		: cstdlib/string.c
 * Creation date	: 2025/11/17 14:44 (Mon)
 */

#include "string.h"

char *strcpy(char *dest, const char *src)
{
	for (size_t index = 0; (dest[index] = src[index]); index ++);
	return dest;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1++ == *str2++ && *(const unsigned char *)(str1 - 1));
    return *(str1 - 1) - *(str2 - 1);
}

size_t strlen(const char *str)
{
	const char *target = str;
	while (*target)	target ++;
	return target - str;
}

char *strncpy(char *dest, const char *src, size_t n)
{
	size_t length = strlen(src);
	for (size_t index = 0; index < n; index ++)	dest[index] = index < length ? src[index] : '\0';
	return dest;
}

int strncmp(const char *str1, const char *str2, size_t n)
{
	size_t index = 0;
	for (index = 0; index < n && str1[index] && str1[index] == str2[index]; index ++)
	return str1[index] - str2[index];
}

void *memset(void *ptr, int value, size_t num)
{
	for (unsigned char *p = ptr; num --; *p++ = (unsigned char)value);
	return ptr;
}
