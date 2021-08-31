#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main(void)
{
    srand(time);

    printf("enter the size and range from 0 of the list\n");

    size_t size, range;

    scanf_s("%d %d", &size, &range);

    List* list = CreateList();
    if (!CheckForError(ErrorCode))
    {

    }

    if (!list)
    {
        printf("ERROR: insufficient memory\n");
    }

    size_t new_value = rand() % range + 1;

    Node* head = (Node*)malloc(sizeof(Node));
    head->key = new_value;
    head->prev = NULL;
    head->next = NULL;
    list->head = head;
    Node* current = list->head;

    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t new_value = rand() % range + 1;
        
        current = Insert(current, new_value);
    }

    return 0;
}


List* CreateList(void)
{
    List* list = (List *)malloc(sizeof(List*));
    if (!list)
    {
        ErrorCode = 1;
        return NULL;
    }
    ErrorCode = 0;

    list->head = NULL;
    return list;
}

void FreeList(List* list)
{
    if (!list)
    {
        ErrorCode = 2;
        return;
    }
    ErrorCode = 0;
    
    if (list->head)
    {
        Node* current = list->head;
        while (current)
        {
            Node* next = current->next;
            free(current);
            current = next;
        }
        free(list);
    }
}

size_t GetListSize(List* list)
{
    if (!list)
    {
        ErrorCode = 2;
        return 0;
    }
    ErrorCode = 0;
    
    size_t count = 0;
    Node* head_pointer = list->head;
    while (head_pointer->next)
    {
        ++count;
    }
    ++count;
    return count;
}

Node* GetListHead(List* list)
{
    if (!list)
    {
        ErrorCode = 2;
        return NULL;
    }
    else 
    {
        ErrorCode = 0;
        return list->head;
    }
}

Node* GetNextNode(Node* currentNode)
{
    if (!currentNode)
    {
        ErrorCode = 3;
        return NULL;
    }
    else 
    {
        ErrorCode = 0;
        return currentNode->next;
    }
}

ListDataType GetValue(Node* node)
{
    if (!node)
    {
        ErrorCode = 3;
        return 0;
    }
    ErrorCode = 0;
    return node->key;
}

Node* Insert(Node* after, ListDataType newValue)
{
    if (!after)
    {
        ErrorCode = 3;
        return NULL;
    }
    ErrorCode = 0;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        ErrorCode = 1;
        return NULL;
    }
    ErrorCode = 0;

    new_node->key = newValue;

    if (after->next)
    {
        new_node->next = after->next;
        new_node->next->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    after->next = new_node;
    new_node->prev = after;
    return new_node;
}

Node* PushFront(List* list, ListDataType newValue)
{
    if (!list)
    {
        ErrorCode = 2;
        return NULL;
    }
    ErrorCode = 0;
    
    Node* new_head = (Node*)malloc(sizeof(Node*));
    if (!new_head)
    {
        ErrorCode = 1;
        return NULL;
    }
    ErrorCode = 0;

    new_head->key = newValue;

    new_head->next = list->head;
    new_head->prev = list->head->prev;
    list->head->prev = new_head;
    list->head = new_head;
    return new_head;
}

Node* PushBack(List* list, ListDataType newValue)
{
    if (!list)
    {
        ErrorCode = 2;
        return NULL;
    }
    ErrorCode = 0;
    
    Node* iterator = list->head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        ErrorCode = 1;
        return NULL;
    }
    ErrorCode = 0;

    new_node->key = newValue;

    new_node->next = NULL;
    new_node->prev = iterator;
    iterator->next = new_node;
    return new_node;   
}

ListDataType PopFront(List* list)
{
    if (!list)
    {
        ErrorCode = 2;
        return 0;
    }
    ErrorCode = 0;

    ListDataType value = list->head->key;

    Node* new_head = list->head->next;
    free(list->head);
    list->head = new_head;
    list->head->prev = NULL;

    return value;
}

ListDataType PopBack(List* list)
{
    if (!list)
    {
        ErrorCode = 2;
        return 0;
    }
    ErrorCode = 0;

    Node* iter = list->head;
    while (iter->next->next)
    {
        iter = iter->next;
    }
    
    ListDataType value = iter->next->key;
    
    Node* last_node = iter->next;
    iter->next = NULL;
    free(last_node);
    
    return value;    
}

void DeleteNode(List* list, Node* target)
{
    if (!list)
    {
        ErrorCode = 2;
        return;
    }
    ErrorCode = 0;

    if (!target)
    {
        ErrorCode = 3;
        return;
    }
    ErrorCode = 0;
    
    if (list->head == target)
    {
        list->head = target->next;
        list->head->prev = NULL;
    }
    else if (target->next == NULL)
    {
        target->prev->next = NULL;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    free(target);
    return;
}

Node* DeleteValue(List* list, ListDataType value)
{
    if (!list)
    {
        ErrorCode = 2;
        return NULL;
    }
    ErrorCode = 0;

    if (!list->head)
    {
        ErrorCode = 3;
        return NULL;
    }
    ErrorCode = 0;

    Node* current = list->head;
    while (current->next)
    {
        if (current->key == value)
        {
            Node* return_node = current->prev;
            DeleteNode(list, current);
            return return_node;
        }
        current = current->next;
    }
    if (current->key == value)
    {
        Node* return_node = current->prev;
        DeleteNode(list, current);
        return return_node;
    }
    else
    {
        return current;
    }
}

Node* Find(List* list, ListDataType value)
{
    if (!list)
    {
        ErrorCode = 2;
        return NULL;
    }
    ErrorCode = 0;

    if (!list->head)
    {
        ErrorCode = 3;
        return NULL;
    }
    ErrorCode = 0;

    Node* current = list->head;
    while (current->next)
    {
        if (current->key == value)
        {
            return current;
        }
        current = current->next;
    }
    if (current->key == value)
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

bool CheckForError(int errorcode)
{
    switch (errorcode)
    {
        
        case 1:
        {
            printf("ERROR: failed memory allocation - insufficient memory\n");
            return false;
        }
        case 2:
        {
            printf("ERROR: Empty list passed to method\n");
            return false;
        }
        case 3:
        {
            printf("ERROR: NULL node passed to method\n");
            return false;
        }
        case 0:
        {
            return true;
        }
    }
}