#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct Node *link;
}Node;

Node *head = NULL;
Node *end  = NULL;

void insertNode (int); // Insert node at the end position
void deleteNode (); // Delete node at nth position
void print (); // Print all list elements
void insertNodeNth (int , int); // Insert node at the nth position


int main()
{
    insertNode (1);
    insertNode (2);
    insertNode (3);
    insertNode (4);
    print();

    //insertNodeNth (54,5);
    deleteNode();
    print();

    return 0;
}



void insertNode (int data) // insert node at the end
{
    int i;
    Node *current = (Node*) malloc(sizeof(Node));
    if (head == NULL) // Adding the first Node

    {
        head = current;
        end = current;

        current->data = data;
        current->link = NULL;

    }


    else

    {

        end->link = current;
        current->data = data;
        current->link = NULL;

        end = current;

    }

}

void insertNodeNth (int data, int position) //Insert Node at nth position

{
    int i;

    Node *newNode = (Node*) malloc(sizeof (Node));
    Node *temp = head;
    for (i = 0; i < position-2; i++)
    {
        temp = temp->link;

    }
    newNode->link = temp->link;
    temp->link = newNode;
    newNode -> data = data;

    if (newNode->link == NULL) //This means that I inserted a node at the end
        end = newNode;


}

void deleteNode()

{
    Node *temp = head;

    while (temp->link != end)
    {
        temp = temp->link;
    }
    temp->link = NULL;
    free(end);




}



void print ()
{
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%i\n", temp->data);

        temp = temp->link;


    }
}


















