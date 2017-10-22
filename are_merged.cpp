//Check if the two list given merge somewhere

#include <bits/stdc++.h>

/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.

    unordered_map<string, int> M;

    stringstream s;
    Node *t = headA;
    while(t!=NULL){
        s.str("");
        s << t;
        string S = s.str();
        //cout << S << endl;
        if(M.find(S) == M.end())
            M[s.str()] = t->data;

        t = t->next;
    }

    t = headB;
    while(t!=NULL){
        s.str("");
        s << t;
        string S = s.str();
        //cout << S << endl;
        if(M.find(S) != M.end())
            return M[S];
        t = t->next;
    }
    return -1;
}
