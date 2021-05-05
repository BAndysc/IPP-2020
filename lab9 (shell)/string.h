#ifndef IPPSHELLTEST_STRING_H
#define IPPSHELLTEST_STRING_H

#include <stdbool.h>

typedef struct String String;

/**
 * Dokleja znak do napisu. Rozszerza wewnętrzny bufor w razie potrzeby.
 * @param string Napis, do którego doklejamy znak
 * @param chr Znak do doklejenia
 */

void stringAppendChar(String* string, char chr);

/**
 * Zwalnia napis zaalokowany za pomocą funkcji newString.
 * @param string Napis do zwolnienia
 */
void freeString(String* string);

/**
 * Alokuje nowy pusty napis. Należy go zwolnić funkcją `freeString`.
 * @return Nowy pusty napis
 */
String* newString();

/**
 * Zwraca znak pod podanym indeksem. Jeśli indeks jest spoza zakresu, zwraca -1.
 * @param string napis
 * @param index indeks znaku
 * @return Znak pod indeksem lub -1 gdy indeks poza zakresem
 */
int charAt(String* string, size_t index);

/**
 * Alokuje nowy napis na podstawie przekazanego parametru. Należy go zwolnić funkcją `freeString`.
 * @param str tablica znaków, na podstawie którego tworzymy nowy napis
 * @return nowo zaalokowany napis
 */
String* newStringFromCString(char* str);

/**
 * Zwraca ciąg znaków jako C-string.
 * @param string Napis
 */
char* stringRaw(String* string);

/**
 * Zwraca długość napisu (koszt stały).
 * @param string Napis
 */
size_t stringLength(String* string);

/**
 * Zwraa true jeśli napisy są dokładnie takie same.
 * @param string Pierwszy napis do porównania
 * @param str Drugi napis do porównania
 * @return true jeśli napisy są takie same, false wpp.
 */
bool stringEquals(String* string, const char* str);

#endif //IPPSHELLTEST_STRING_H
