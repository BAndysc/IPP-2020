#ifndef IPPSHELLTEST_INPUT_H
#define IPPSHELLTEST_INPUT_H

#include "string.h"

/**
 * Czyta jedną linię (do znaku \ n) ze standardowego wejścia i zwraca jako String.
 * Jeśli linia jest pusta, zwraca pusty string (nie NULL).
 * Jeśli nie ma więcej danych na wejściu (EOF) zwraca NULL.
 * Zwrócony string należy zwolnić gdy nie jest potrzebny.
 * @return wskaźnik do wczytanej lini lub NULL jeśli nie ma więcej danych na wejściu
 */
String* readLine();

#endif //IPPSHELLTEST_INPUT_H
