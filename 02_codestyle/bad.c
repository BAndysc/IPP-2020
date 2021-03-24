#include <stdio.h>
 #include <stdlib.h>
#include <stdbool.h>

struct employee {
    char* name;
    int age;
    int flags;
};

struct list 
{
struct employee* employee;
struct list*next,*prev;
};


// creates a list
struct list* cr() {
return NULL;
}

// insert
void inst(struct list** lista,struct employee* employee)
{
    int empty = *lista == NULL ? 1 : 0;
while (*lista != NULL && (**lista).next) lista = &((*(*lista)).next);
    struct list* node = malloc(20);
	node->employee = employee;     node->next = NULL;
    node->prev = *lista;
	if (*lista)
	    (*(*lista)).next = node;
    if (empty) *lista = node;
}
void printList(struct list* lista){
while (lista != NULL) {
    printf("name: %s, age: %d, traits: ", (*(lista)).employee->name, (*(lista)).employee->age);
    if (((*(lista)).employee->flags & 1))
        printf("intern, ");
    if (((*(lista)).employee->flags & 2))
        printf("fulltime, ");
    if (((*(lista)).employee->flags & 4))
        printf("manager, ");
	lista = lista->next;
printf("\n");
}
}
void remove_no_full_holiday(struct list** list)
{
    while (list && (*list != NULL) == true)
    {
    bool bShouldDelete = true;
    // if age below 20 or is not full time employee, then is not
    // eligible for full holidays
	if ((*list)->employee->age <= 20 || ((*list)->employee->flags & 2) == 0)
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
struct employee* e1 = malloc(sizeof(struct employee));
e1->name = "Lindsay";
e1->flags = 6;
e1->age = 32;
struct employee* e2 = malloc(sizeof(struct employee));
e2->name = "Justin";
e2->flags = 1;
e2->age = 19;
struct employee* e3 = malloc(sizeof(struct employee));
e3->name = "Brian";
e3->flags = 2;
e3->age = 28;
struct list* list = cr();
printList(list);
inst(&list, e1);
inst(&list, e2);
inst(&list, e3);
printList(list);
remove_no_full_holiday(&list);
printList(list);
list = release(list);
return 0;
}