#include<bits/stdc++.h>
using namespace std;

class Node {
public:
     int data;
     Node *next;
     Node() {
         this->data = 0;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->next = NULL;
     }
     Node (int data, Node *next) {
         this->data = data;
         this->next = next;
     }
};

Node *addTwoNumbers(Node *temp1, Node *temp2)
{
    Node *head = new Node;
    Node *temp = head;
    while(temp1 != NULL || temp2 != NULL)    {
        int sum = 0;
        if(temp1 != NULL)    {
            sum = temp1->data;
            temp1 = temp1->next;
        }
        if(temp2 != NULL)    {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        sum += temp->data;
        temp->data = sum%10;
        if(temp1 == NULL && temp2 == NULL)    {
            if(sum/10 != 0)    {
                temp->next = new Node(sum/10);
            }
        }
        else    {
            temp->next = new Node(sum/10);
            temp = temp->next;
        }
    }
    return head;
}
