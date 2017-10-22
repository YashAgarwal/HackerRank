/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
  //return if the list has 1 element or less
  if(head == NULL || head->next == NULL){
      return head;
  }

  //count duplicates of the current node
  Node *t = head->next;
  int val = head->data;

  while(t!=NULL){
      if(val == t->data){
          Node *r = t;
          t = t->next;
          delete r;
      }
      else{
          break;
      }
  }

  head->next = RemoveDuplicates(t);
  return head;
}
