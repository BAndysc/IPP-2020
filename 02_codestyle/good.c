#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// można też użyć makr, ale enum jest ładniejszy, bo można używać typu
// EmployeeFlags (mimo że nie zapewnia dodatkowego bezpieczeństwa)
typedef enum {
    EMPLOYEE_INTERN = 1,
    EMPLOYEE_FULLTIME = 2,
    EMPLOYEE_MANAGER = 4
} EmployeeFlags;

typedef struct {
    char* name;
    int age;
    EmployeeFlags flags; // używamy lepszego typu - zamiast int, nasz enum
} Employee;

/*
 *
 * Rozdzielenie struktury Listy na Węzeł listy (node) i samą listę (List)
 * znacznie ułatwia pisanie kodu oraz jego czytelność
 * Dzięki temu unikamy przekazywania wskażnika do wskaźnika w funkcjach
 * modyfikujących listę bo lista zawsze jest taka sama, a tylko w środku
 * zmieniają się węzły
 *
 * ponadto, czytelne jest czy funkcje jako argument biorą Listę czy jeden węzeł
 *
 */

typedef struct employeeNode {
    struct employeeNode* next;
    struct employeeNode* prev;
    Employee employee;
} EmployeeNode;

typedef struct {
    EmployeeNode* first;
    EmployeeNode* last;
} EmployeeList;

// czytelna nazwa funkcji nie wymaga dodatkowego komentarza
EmployeeList createEmployeeList() {
    static EmployeeList empty = {.first = NULL, .last = NULL};
    return empty;
}

void fatalError() {
    exit(1);
}

// dzięki tej dodatkowej funkcji, nie musimy sprawdzać
// za każdym razem wyniku funkcji alokujących
void* safeCalloc(size_t num, size_t size) {
    void* ptr = calloc(num, size);

    if (!ptr)
        fatalError();

    return ptr;
}

// małe funkcje pomocnicze pozwalają zmniejszyć inne funkcje,
// operujące na "wyższym poziomie abstrakcji"
EmployeeNode* employeeNodeAlloc(Employee employee) {
    EmployeeNode* node = safeCalloc(1, sizeof(EmployeeNode));
    node->employee = employee;
    return node;
}

// dzięki zastosowaniu dodatkowej struktury na listę
// nie musimy przekazywać "wskaźnika do wskaźnika", kod jest prostszy
void addEmployeeToList(EmployeeList* list, Employee employee) {
    EmployeeNode* newNode = employeeNodeAlloc(employee);

    newNode->prev = list->last;

    if (list->last)
        list->last->next = newNode;

    list->last = newNode;

    if (!list->first)
        list->first = newNode;
}

bool employeeHasFlag(Employee* employee, EmployeeFlags flag) {
    return (employee->flags & flag) == flag;
}

void employeeListPrint(EmployeeList* list) {
    EmployeeNode* node = list->first;

    while (node) {
        printf("name: %s, age: %d, traits: ", node->employee.name, node->employee.age);
        if (employeeHasFlag(&node->employee, EMPLOYEE_INTERN))
            printf("intern, ");
        if (employeeHasFlag(&node->employee, EMPLOYEE_FULLTIME))
            printf("fulltime, ");
        if (employeeHasFlag(&node->employee, EMPLOYEE_MANAGER))
            printf("manager, ");
        node = node->next;
        printf("\n");
    }

    printf("\n");
}

/*
 * mimo że ta funkcja teraz tylko uruchamia funkcję free
 * to "logicznie" zwalnianie struktury jest na wyższym poziomie abstrakcji niż
 * zwalnianie pamięci za pomocą `free`, dlatego warto to wydzielić do osobnej funkcji
 */
void freeNode(EmployeeNode* node) {
    free(node);
}

/*
 *
 * nie jest oczywiste co ta funkcja zwraca
 * stąd komentarz jest całkiem dobrym pomysłem
 *
 */

/// removes a `node` from given `list`
/// it won't work correctly if given node is not inside given list
///
/// returns next node or NULL if it was the last element of the list
EmployeeNode* employeeListRemoveNode(EmployeeList* list, EmployeeNode* node) {
    if (node->next)
        node->next->prev = node->prev;

    if (node->prev)
        node->prev->next = node->next;

    if (list->last == node)
        list->last = node->prev;

    if (list->first == node)
        list->first = node->next;

    EmployeeNode* next = node->next;
    freeNode(node);
    return next;
}

/*
 * Wskaźnik do funkcji to może być lekki overkill, ale w ładny sposób pozwolił
 * pozbyć się kilku dodatkowych linijek i przede wszsytkim powtarzania kodu
 */

/*
 *  Dzięki zastosowanie funkcji removeNode oraz argumentu `condition`, funkcja removeIf jest bardzo
 *  prosta i czytelna
 */
void employeeListRemoveIf(EmployeeList* list, bool (*condition)(Employee* )) {
    EmployeeNode* node = list->first;

    while (node) {
        if (condition(&node->employee))
            node = employeeListRemoveNode(list, node);
        else
            node = node->next;
    }
}

bool isEligibleForFulllHoliday(Employee* employee) {
    return employee->age > 20 && employeeHasFlag(employee, EMPLOYEE_FULLTIME);
}

bool isNotEligibleForFullHoliday(Employee* employee) {
    return !isEligibleForFulllHoliday(employee);
}

void employeeListRemoveNoFullHoliday(EmployeeList* list) {
    employeeListRemoveIf(list, isNotEligibleForFullHoliday);
}

void freeEmployeeList(EmployeeList* list) {
    EmployeeNode* node = list->first;
    while (node) {
        EmployeeNode* next = node->next;
        free(node);
        node = next;
    }
    list->first = NULL;
    list->last = NULL;
}

int main() {
    // jeśli nie ma potrzeby dynamicznej alokacji pamięci - nie ma co tego robić
    Employee e1 = {.name = "Lindsay",
                                 .age = 32,
                                 .flags = EMPLOYEE_FULLTIME | EMPLOYEE_MANAGER};
    Employee e2 = {.name = "Justin", .age = 19, .flags = EMPLOYEE_INTERN};
    Employee e3 = {.name = "Brian", .age = 28, .flags = EMPLOYEE_FULLTIME};

    // odstępy pionowe pozwalają łatwiej zrozumieć co się dzieje
    // nazwa zmiennej "employees" jest lepsza niż "employeeList", ponieważ
    // nie zawiera w sobie szczegołu implementacyjnego - nazwy kontenera w ktorym trzymamy
    // (jak zmienimy kiedyś na tablicę, nazwa "employess" nadal będzie dobra)
    EmployeeList employees = createEmployeeList();
    employeeListPrint(&employees);

    addEmployeeToList(&employees, e1);
    addEmployeeToList(&employees, e2);
    addEmployeeToList(&employees, e3);
    employeeListPrint(&employees);
    
    employeeListRemoveNoFullHoliday(&employees);
    employeeListPrint(&employees);
    
    freeEmployeeList(&employees);
    return 0;
}