# string.h
Implementation of some functions of the string.h library. The library is developed in C language of C11 standard using gcc compiler.

### string.h functions
| Function | Description |
| ------ | ------ |
| void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| void *memmove(void *dest, const void *src, size_t n) | Another function to copy n characters from src to dest. |
| void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| char *strcat(char *dest, const char *src) | Appends the string pointed to, by src to the end of the string pointed to by dest. |
| char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| int strcmp(const char *str1, const char *str2) | Compares the string pointed to, by str1 to the string pointed to by str2. |
| int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| char *strcpy(char *dest, const char *src) | Copies the string pointed to, by src to dest. |
| char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives. |
| size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| size_t strspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters in str2. |
| char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |

### sprintf specifiers
| Specifier | sprintf output |
| --- | --- |
| c | Character |
| d | Signed decimal integer |
| i | Signed decimal integer |
| e | Scientific notation (mantissa/exponent) using e character (the output of the numbers must match up to e-6) |
| E | Scientific notation (mantissa/exponent) using E character |
| f | Decimal floating point |
| g | Uses the shortest representation of decimal floating point |
| G | Uses the shortest representation of decimal floating point |
| o | Unsigned octal |
| s | String of characters |
| u | Unsigned decimal integer |
| x | Unsigned hexadecimal integer |
| X | Unsigned hexadecimal integer (capital letters) |
| p | Pointer address |
| n | Number of characters printed until %n occurs |
| % | Character % |

### sprintf Flags
| Flags | Description |
| --- | --- |
| - | Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
| + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| (space) | If no sign is going to be written, a blank space is inserted before the value. |
| # | Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed. |
| 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |

### sprintf width description
|	Width | Description |
| --- | --- |
| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| * | In sprintf the * sign means, that the width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. In sscanf the * sign placed after % and before the format specifier reads data of the specified type, but suppresses their assignment. |

### sprintf precision description
|	.precision | Description |
| --- | --- |
| .number | For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers − this is the number of digits to be printed after the decimal point. For g and G specifiers − This is the maximum number of significant digits to be printed. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified for specifiers e, E, f, g and G, the default one is 6. When no precision is specified for all other kind of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| .* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf And sscanf Length Description
|	Length | Description |
| --- | --- |
| h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X). |
| l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s. |
| L | The argument is interpreted as a long double (only applies to floating point specifiers − e, E, f, g and G). |

### Special string processing functions (from the String class in C#)
| Function | Description |
| ------ | ------ |
| void *to_upper(const char *str) | Returns a copy of string (str) converted to uppercase. In case of any error, return NULL |
| void *to_lower(const char *str) | Returns a copy of string (str) converted to lowercase. In case of any error, return NULL |
| void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL |
| void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL |
