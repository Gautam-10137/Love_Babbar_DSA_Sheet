#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


class Solution {
  public:
  // recursive way
  Node* reverse(struct Node* head){
    if(!head || !head->next) return head;
    
    Node* curr=head;
    Node* next=curr->next;
    Node* newHead=reverse(next);

    next->next=curr;
    return newHead;

  }

  // iterative way
    Node* reverseList(struct Node* head) {
        if(!head || !head->next) return head;
        // code here
        Node* prev=NULL;
        Node* curr=head;
        Node* next=curr->next;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
        
    }
};