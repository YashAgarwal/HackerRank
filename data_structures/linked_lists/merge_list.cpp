/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission.
  // You only need to complete this method
  if(headA==NULL)
      return headB;
  else if(headB==NULL)
      return headA;
  else{
      Node *t;
      if(headA->data >= headB->data){
          t = headB;
          t->next = MergeLists(headA, headB->next);
      }
      else{
          t = headA;
          t->next = MergeLists(headB, headA->next);
      }
      return t;
  }
}
