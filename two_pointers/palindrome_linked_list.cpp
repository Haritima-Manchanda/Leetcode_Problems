/*
    Problem Statement:
        Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

    Example 1: 

        Input: head = [1,2,2,1]
        Output: true

    Example 2:
        Input: head = [1,2]
        Output: false
*/


#include<iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x) , next(NULL) {};
};

ListNode* find_middle_linked_list(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* reverse_linked_list(ListNode *startNode){
    ListNode *temp;
    ListNode *prev = NULL;

    while(startNode){
        temp = startNode;
        startNode = startNode->next;
        temp->next = prev;
        prev = temp;
    }

    return prev;
}

// Helper to delete the full list from a given head
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool is_palindrome(ListNode* head){
    if (!head || !head->next){
        return true;
    }

    // Step 1: Find the middle of linked list
    // Step 2: Reverse the second half of the linked list
    // Step 3: Check if it is palindrome using inward two pointers approach


    ListNode *middleNode = find_middle_linked_list(head);
    ListNode *firstHalfStartNode = head;
    ListNode *secondHalfStartNode = reverse_linked_list(middleNode);
    ListNode *copySecondHalfStartNode = secondHalfStartNode;
    bool isPalin = true;

    while(secondHalfStartNode){
        if(secondHalfStartNode->val != firstHalfStartNode->val){
            isPalin = false;
            break;
        }
        secondHalfStartNode = secondHalfStartNode->next;
        firstHalfStartNode = firstHalfStartNode->next;
    }

    middleNode->next = reverse_linked_list(copySecondHalfStartNode);
    return isPalin;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    bool result = is_palindrome(head);
    cout << (result ? "true" : "false") << endl;

    deleteList(head);  

    return 0;
}