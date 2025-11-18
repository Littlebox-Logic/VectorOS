/* VectorOS
 * File name		: cstdlib/string,c
 * Creation date	: 2025/11/17 14:44 (Mon)
 */

#include <stddef.h>

char *strcpy(char *dest, const char *src)
{
	for (size_t index = 0; (dest[index] = src[index]); index ++);
	return dest;
}
