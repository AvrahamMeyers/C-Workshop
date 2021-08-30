#pragma once
#include <stdbool.h>

/// @brief the type of the data of the list
typedef int ListDataType;

/// @brief a struct for the nodes of the list, with a previous and next pointer
typedef struct Node_t 
{
    ListDataType key;
    struct Node_t* next;
    struct Node_t* prev;
} Node;

/// @brief a global variable for storing errors that occur in the program
/// code 1: failed memory allocation - insufficient memory 
/// code 2: Empty list passed to method
/// code 3: NULL node passed to method
int ErrorCode = 0;

bool CheckForError(int errorcode);

/// @brief a struct for the list with a head node
typedef struct List_t 
{
    Node* head;
} List;

/// @brief creates a list
/// @param no parameters 
/// @return a pointer to the list created
List* CreateList(void);

/// @brief deletes all of the memory used for the list
/// @param list the list to delete
void FreeList(List* list);

/// @brief returns the length of the list
/// @param list the list to check
/// @return the length of the list
size_t GetListSize(List* list);

/// @brief returns a pointer to the head of the list
/// @param list the list to check for the head
/// @return a pointer to the head of the list
Node* GetListHead(List* list);

/// @brief returns the next node after the node passed
/// @param currentNode the node to check for the next node
/// @return a pointer to the next node after the current node
Node* GetNextNode(Node* currentNode);

/// @brief returns the value of the node passed
/// @param node the node to check for a value
/// @return the value of the key of the node
ListDataType GetValue(Node* node);

/// @brief inserts a node with the passed value after the passed node
/// @param after the node to place before the new node
/// @param newValue the value of the key of the new node
/// @return a pointer to the new node
Node* Insert(Node* after, ListDataType newValue);

/// @brief adds a new node with the passed value to the head of the list
/// @param list the list to add the value to
/// @param newValue the value to add to the list 
/// @return a pointer to the new head of the list
Node* PushFront(List* list, ListDataType newValue);

/// @brief adds a new node to the end of the list with the passed value
/// @param list the list to add the value to 
/// @param newValue the value of the new node to add
/// @return a pointer to the new node
Node* PushBack(List* list, ListDataType newValue);

/// @brief removes the head of the list and returns the value in the key of the node
/// @param list the list to remove the head from
/// @return the value of the head of the list
ListDataType PopFront(List* list);

/// @brief removes the last node from the list and returns the value from the node
/// @param list the list to remove the last node from
/// @return the value of the last node of the list
ListDataType PopBack(List* list);

/// @brief deletes the target node from the list
/// @param list the list to remove the node from
/// @param target the node to remove from the list
void DeleteNode(List* list, Node* target);

/// @brief deletes the node from the list with the passed value as its key
/// @param list the list to remove the value from
/// @param value the value to remove from the list
/// @return a oointer to the deleted node
Node* DeleteValue(List* list, ListDataType value);

/// @brief returns a pointer to the node in the list with the passed value
/// @param list the list to check for the value
/// @param value the value to look for
/// @return a pointer to the node in the list with the passed value
Node* Find(List* list, ListDataType value);

