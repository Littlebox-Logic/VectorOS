/* VectorOS
 * File name		: cstdlib/string,c
 * Creation date	: 2025/11/17 14:46 (Mon)
 */

#ifndef C_STRING_H
#define C_STRING_H

#include <stddef.h>

char	*strcpy(char *, const char *);
int 	strcmp(const char *, const char *);
size_t	strlen(const char *);
char	*strncpy(char *, const char *, size_t);
int		strcmp(const char *, const char *, size_t);

#endif
