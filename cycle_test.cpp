/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <bits/stdc++.h>

bool has_cycle_bad(Node* head) {
    // Complete this function
    // Do not write the main method

    if(head == NULL) return 0;

    unordered_map<string, bool> M;

    stringstream s;
    Node *t = head;
    while(t!=NULL){
        s.str("");
        s << t;

        string S = s.str();
        //cout << S << endl;
        if(M.find(S) == M.end())
            M[s.str()] = true;
        else
            return 1;

        t = t->next;
    }
    return 0;
}

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method

    Node *fast = head, *slow = head;

    while(fast !=NULL && slow != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return 1;
        }
    }

    return 0;
}
