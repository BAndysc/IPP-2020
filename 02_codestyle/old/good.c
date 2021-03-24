#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *
 * Rozdzielenie struktury Listy na Węzeł listy (node) i samą listę (List)
 * znacznie ułatwia pisanie kodu oraz jego czytelność
 * Dzięki temu unikamy przekazywania wskażnika do wskaźnika w funkcjach modyfikujących listę
 * bo lista zawsze jest taka sama, a tylko w środku zmieniają się węzły
 *
 * ponadto, czytelne jest czy funkcje jako argument biorą Listę czy jeden węzeł
 *
 */

typedef struct node
{
    struct node* next;
    struct node* prev;
    int data;
} Node;


typedef struct list
{
    Node* first;
    Node* last;
} List;

List createList()
{
    List empty = { .first = NULL, .last = NULL };
    return empty;
}

void fatalError()
{
    exit(-1);
}

void* safeCalloc(size_t num, size_t size)
{
    void* ptr = calloc(num, size);

    if (!ptr)
        fatalError();

    return ptr;
}

Node* nodeAlloc(int value)
{
    Node* node = calloc(1, sizeof (Node));
    node->data = value;
    return node;
}

void listInsert(List* list, int element)
{
    Node* newNode = nodeAlloc(element);

    newNode->prev = list->last;

    if (list->last)
        list->last->next = newNode;

    list->last = newNode;

    if (!list->first)
        list->first = newNode;
}

void listPrint(List* list)
{
    printf("list: ");
    Node* node = list->first;

    while (node)
    {
        printf("%d, ", node->data);
        node = node->next;
    }

    printf("\n");
}

bool isOdd(int val)
{
    return val % 2 == 1;
}

bool isEven(int val)
{
    return val % 2 == 0;
}

int listSumOfOdds(List* list)
{
    int sum = 0;
    Node* node = list->first;

    while (node)
    {
        if (isOdd(node->data))
            sum += node->data;

        node = node->next;
    }

    return sum;
}

void freeNode(Node* node)
{
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
Node* removeNode(List* list, Node* node)
{
    if (node->next)
        node->next->prev = node->prev;

    if (node->prev)
        node->prev->next = node->next;

    if (list->last == node)
        list->last = node->prev;

    if (list->first == node)
        list->first = node->next;

    Node* next = node->next;

    freeNode(node);

    return next;
}

void removeIf(List* list, bool (*condition)(int))
{
    Node* node = list->first;

    while (node)
    {
        if (condition(node->data))
            node = removeNode(list, node);
        else
            node = node->next;
    }
}

/*
 * Wskaźnik do funkcji to może być lekki overkill, ale w ładny sposób pozwolił pozbyć
 * się kilku dodatkowych linijek i przede wszsytkim powtarzania kodu
 */

void listRemoveOdd(List* list)
{
    removeIf(list, isOdd);
}

void listRemoveEven(List* list)
{
    removeIf(list, isEven);
}

void listFree(List* list)
{
    Node* node = list->first;

    while (node)
    {
        Node* next = node->next;

        freeNode(node);

        node = next;
    }

    list->first = list->last = NULL;
}

int main()
{
    List list = createList();

    listPrint(&list);
    listInsert(&list, 3);
    listInsert(&list, 2);
    listInsert(&list, 7);
    listPrint(&list);

    printf("suma nieparystych: %d\n", listSumOfOdds(&list));

    listRemoveOdd(&list);
    listPrint(&list);

    listRemoveEven(&list);
    listPrint(&list);

    listFree(&list);

    return 0;
}