/*
    Problem Statement: 
        You are given the head of a singly linked list. Write a function to:

        Detect if there is a cycle (loop) in the linked list.

        If a cycle exists, return the starting node of the cycle

        Input: 
        1 -> 2 -> 3 -> 4 -> 5
                   ^        |
                   |________|
        Output True
*/

#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;

    ListNode(int x): data(x), next(NULL) {}
};

ListNode* linked_list_loop(ListNode *head){
    ListNode *fast = head, *slow = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            break;
        }
    }

    if(fast == slow){
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }
    return NULL;
}

void deleteList(ListNode *head, ListNode *cycle_start){
    if(cycle_start){
        ListNode *temp = cycle_start;
        while(temp->next != cycle_start){
            temp = temp->next;
        }
        temp->next = NULL; // break the cycle
    }

    ListNode *current = head;
    ListNode *temp;

    while(current){
        temp = current;
        current = current->next;
        cout<< "Deleting node " << temp->data << "->";
        delete temp;
    }

    cout << "NULL" << endl;
}

int main(){
    // Creating a list with a cycle:
    // 1 -> 2 -> 3 -> 4 -> 5
    //               ^        |
    //               |________|

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating cycle here: 5 -> 3
    head->next->next->next->next->next = head->next->next; 

    ListNode* cycle_start = linked_list_loop(head);
    if (cycle_start) {
        cout << "Cycle detected starting at node with data = " << cycle_start->data << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    deleteList(head, cycle_start);

    return 0;
}