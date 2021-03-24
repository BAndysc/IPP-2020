#include <stdio.h>
 #include <stdlib.h>
#include <stdbool.h>

struct list 
{
struct list*next,*prev;
int data;
};


// creates a list
struct list* cr() {
return NULL;
}

// insert
void inst(struct list** lista,int i)
{
    int empty = *lista == NULL ? 1 : 0;
while (*lista != NULL && (**lista).next) lista = &((*(*lista)).next);
    struct list* node = malloc(sizeof(struct list));
	node->data = i;     node->next = NULL;
    node->prev = *lista;
	if (*lista)
	    (*(*lista)).next = node;
    if (empty) *lista = node;
}
void print(struct list* lista){
printf("list: ");
while (lista != NULL) {
    printf("%d, ", (*(lista)).data);
	lista = lista->next;
}
printf("\n");
}
void sum_o(struct list* lista, int* r){
    int sum;
while (lista != NULL) {
    if ((*(lista)).data % 2 == 1)
		sum += (*lista).data;
	lista = lista->next;
    }
    *r = sum;
}
void removeOdd(struct list** list)
{
    while (list && (*list != NULL) == true)
    {
    bool bShouldDelete = true;
	if ((*list)->data % 2 == 1)
			bShouldDelete = true;
	else    bShouldDelete = false;
    if (bShouldDelete)
    {
    	if (((*list)->next) != NULL) ((*list)->next)->prev = ((*list)->prev);

        if (((*list)->prev) != NULL) {
    	    ((*list)->prev)->next = ((*list)->next);
    	    list = &(*list)->next; }
        else *list = ((*list)->next);  }
	else
		list = &(*list)->next;
	}
}

void removeEven(struct list** list)
{
	while (list && (*list != NULL) == true)
	{
	bool bShouldDelete = true;
    if ((*list)->data % 2 == 0)
            bShouldDelete = true;
    else	bShouldDelete = false;
    if (bShouldDelete)
    {
    	if (((*list)->next) != NULL) ((*list)->next)->prev = ((*list)->prev);

        if (((*list)->prev) != NULL) {
		    ((*list)->prev)->next = ((*list)->next);
            list = &(*list)->next;  }
    	else *list = ((*list)->next);  }
    else
        list = &(*list)->next;
    }
}

struct list* release(struct list* l)
{
    while (l != NULL) {
        struct list* nxt = l->next;
	    free(l);
        l = nxt;
    }    
    return 0;
}

int main()
{
struct list* list = cr();
print(list);
inst(&list, 3);
inst(&list, 2);
inst(&list, 7);
print(list);
int sum;
sum_o(list, &sum);
printf("suma nieparystych: %d\n", sum);
removeOdd(&list);
print(list);
removeEven(&list);
print(list);
list = release(list);
return 0;
}