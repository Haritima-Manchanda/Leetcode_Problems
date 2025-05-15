/*
    Problem Statement: 
        Given the heads of two singly linked-lists headA and headB, 
        return the node at which the two lists intersect. 
        If the two linked lists have no intersection at all, return null.

        The test cases are generated such that there are no cycles anywhere in the entire linked structure.

        Note that the linked lists must retain their original structure after the function returns.

        Example 1:
            Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
            Output: Intersected at '8'
            Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
            From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
            There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

        Example 2: 
            Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
            Output: Intersected at '2'
            Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).

        Example 3: 
            Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
            Output: No intersection
            Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
            Explanation: The two lists do not intersect, so return null.

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Deletes all nodes starting from head until it reaches stop (exclusive).
void deleteList(ListNode* head, ListNode* stop = nullptr) {
    while (head && head != stop) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int get_length(ListNode *current_ptr){
    int len = 0;
    while(current_ptr){
        len++;
        current_ptr = current_ptr->next;
    }
    return len;
}

ListNode* find_intersection_by_aligning_lengths(ListNode *headA, ListNode *headB){
    if(!headA || !headB){
        return NULL;
    }
    int lenA = get_length(headA);
    int lenB = get_length(headB);
    ListNode *currentA = headA;
    ListNode *currentB = headB;

    while(lenA > lenB){
        currentA = currentA->next;
        lenA--;
    }
    while(lenB > lenA){
        currentB = currentB->next;
        lenB--;
    }
    while(currentA && currentB && currentA != currentB){
        currentA = currentA->next;
        currentB = currentB->next;
    }
    return currentA;
}

int main() {
    // Test 1 - Normal Intersection
    {
        cout << "Test 1 - Normal Intersection" << endl;

        ListNode* intersect = new ListNode(8);
        intersect->next = new ListNode(4);
        intersect->next->next = new ListNode(5);

        ListNode* headA = new ListNode(4);
        headA->next = new ListNode(1);
        headA->next->next = intersect;

        ListNode* headB = new ListNode(5);
        headB->next = new ListNode(6);
        headB->next->next = new ListNode(1);
        headB->next->next->next = intersect;

        cout << "List A: "; printList(headA);
        cout << "List B: "; printList(headB);

        ListNode* result = find_intersection_by_aligning_lengths(headA, headB);
        if (result) {
            cout << "Intersected at '" << result->val << "'" << endl;
        } else {
            cout << "No intersection" << endl;
        }

        deleteList(headA, intersect);
        deleteList(headB, intersect);
        deleteList(intersect);
        cout << endl;
    }

    // Test 2 - No Intersection
    {
        cout << "Test 2 - No Intersection" << endl;

        ListNode* headA = new ListNode(2);
        headA->next = new ListNode(6);
        headA->next->next = new ListNode(4);

        ListNode* headB = new ListNode(1);
        headB->next = new ListNode(5);

        cout << "List A: "; printList(headA);
        cout << "List B: "; printList(headB);

        ListNode* result = find_intersection_by_aligning_lengths(headA, headB);
        if (result) {
            cout << "Intersected at '" << result->val << "'" << endl;
        } else {
            cout << "No intersection" << endl;
        }

        deleteList(headA);
        deleteList(headB);
        cout << endl;
    }

    // Test 3 - One Empty List
    {
        cout << "Test 3 - One Empty List" << endl;

        ListNode* headA = nullptr;
        ListNode* headB = new ListNode(1);
        headB->next = new ListNode(2);

        cout << "List A: "; printList(headA);
        cout << "List B: "; printList(headB);

        ListNode* result = find_intersection_by_aligning_lengths(headA, headB);
        if (result) {
            cout << "Intersected at '" << result->val << "'" << endl;
        } else {
            cout << "No intersection" << endl;
        }

        deleteList(headB);
        cout << endl;
    }

    // Test 4 - Intersection at Head
    {
        cout << "Test 4 - Intersection at Head" << endl;

        ListNode* shared = new ListNode(7);
        shared->next = new ListNode(2);
        shared->next->next = new ListNode(3);

        ListNode* headA = shared;
        ListNode* headB = shared;

        cout << "List A: "; printList(headA);
        cout << "List B: "; printList(headB);

        ListNode* result = find_intersection_by_aligning_lengths(headA, headB);
        if (result) {
            cout << "Intersected at '" << result->val << "'" << endl;
        } else {
            cout << "No intersection" << endl;
        }

        deleteList(shared);
        cout << endl;
    }

    // Test 5 - Same Single Node
    {
        cout << "Test 5 - Same Single Node" << endl;

        ListNode* node = new ListNode(10);

        cout << "List A: "; printList(node);
        cout << "List B: "; printList(node);

        ListNode* result = find_intersection_by_aligning_lengths(node, node);
        if (result) {
            cout << "Intersected at '" << result->val << "'" << endl;
        } else {
            cout << "No intersection" << endl;
        }

        delete node;
        cout << endl;
    }

    return 0;
}
