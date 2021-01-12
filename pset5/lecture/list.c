#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL; //the linked list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1; //means n didn't get any memory and returned null
    }
    n->number = 1;
    n->next = NULL; //always make this null for safety
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    while(list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}