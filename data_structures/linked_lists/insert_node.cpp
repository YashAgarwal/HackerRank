//Insert a node at the head of a linked list

/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node* N = new Node();

    N->next = head;
    head = N;
    N->data = data;

    return head;
}


//Insert a node at a specific position of a linked list

/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
  Node* N = new Node();
  N->data = data;

  Node *t = head, *t_old = head;
  int p = 0;

  //if the list is empty
  if(head == NULL || position == 0){
    N->next = head;
    head = N;
  }
  else{
    //Go to the position while storing a pointer to the previous node too
    while(t != NULL && p < position){
       t_old = t;
       t = t->next;
       p++;
    }

    //Insert the element
    N->next = t;
    t_old->next = N;
  }

  return head;
}
