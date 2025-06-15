#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


class Solution {
  public:

    Node* reverseL(Node* head){
     if(!head || !head->next) return head;
    
     Node* newHead=reverseL(head->next);
     head->next->next=head;
     head->next=NULL;
  
     return newHead;

    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* currH=head;
        Node* prevH=NULL;

        
        
    }
};