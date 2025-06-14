#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


class Solution {
  public:

    // using slow and fast pointers  
    void removeLoop(Node* head) {
      
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(!fast || !fast->next) return;
        fast=head;

        // if both slow and fast ast head
        if(slow==fast){
            while(slow->next!=fast) slow=slow->next;
            
        }
        // else 
        else{
           while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
           } 
        }
        
        slow->next=NULL;
        return;
    }
};