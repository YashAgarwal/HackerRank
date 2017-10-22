/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method

  //if the list is empty
  if(head == NULL){
  }
  else if(position == 0){
      Node *y = head;
      y = y->next;
      delete head;
      return y;
  }
  else{

    Node *t=head, *t_old=head;
    int p=0;

    //Go to the position while storing a pointer to the previous node too
    while(t != NULL && p < position){
       t_old = t;
       t = t->next;
       p++;
    }

    //Delete the element
    t_old->next = t->next;
    delete t;
  }

  return head;
}
