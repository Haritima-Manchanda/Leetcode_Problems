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

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

int get_length(ListNode *current_ptr){
    int len = 0;
    while(current_ptr){
        len++;
        current_ptr = current_ptr->next;
    }

    return len;
}

ListNode* find_intersection_by_aligning_lengths(ListNode *headA, ListNode *headB){
    
    // If either of the lists are empty
    if(!headA || !headB){
        return NULL;
    }

    // Find lengths of both linked lists
    int lenA = get_length(headA); // 5
    int lenB = get_length(headB); // 6

    ListNode *currentA = headA;
    ListNode *currentB = headB;

    // Align the starting position of both linked lists.
    while(lenA > lenB){
        currentA = currentA->next;
        lenA--;
    }

    while(lenB > lenA){
        currentB = currentB->next;
        lenB--;
    }

    while(currentA && currentB){
        if(currentA == currentB){
            return currentA;
        }
        currentA = currentA->next;
        currentB = currentB->next;
    }

    return NULL;

    // Updated condition: loop until either we find the intersection, or reach end of both lists
    // while ((currentA && currentB) && (currentA != currentB)){
    //     currentA = currentA->next;
    //     currentB = currentB->next;
    // }

    // return currentA;
}

ListNode* find_intersection_by_two_pointers_approach(ListNode *headA, ListNode *headB){
    
    // If either of the lists are empty
    if(!headA || !headB){
        return NULL;
    }

    ListNode *currentA = headA;
    ListNode *currentB = headB;

    while(currentA != currentB){
        if (currentA){
            currentA = currentA->next;
        }
        else{
            currentA = headB;
        }

        if (currentB){
            currentB = currentB->next;
        }
        else{
            currentB = headA;
        }
    }

    return currentA;

}

// Helper to delete nodes until a given stop node (non-inclusive)
void deleteUntil(ListNode* head, ListNode* stop) {
    while (head != stop) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper to delete the full list from a given head
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){

    // listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]

    ListNode *common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* intersectionNode = find_intersection_by_aligning_lengths(headA, headB);
    if (intersectionNode) {
        cout << "The value of intersection node is: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    
    intersectionNode = find_intersection_by_two_pointers_approach(headA, headB);
    if (intersectionNode) {
        cout << "The value of intersection node is: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    deleteUntil(headA, common); // deletes 4 → 1
    deleteUntil(headB, common); // deletes 5 → 6 → 1
    deleteList(common);         // deletes 8 → 4 → 5


    // listA = [1,9,1,2,4], listB = [3,2,4]

    ListNode *common2 = new ListNode(2);
    common2->next = new ListNode(4);

    ListNode *headA2 = new ListNode(1);
    headA2->next = new ListNode(9);
    headA2->next->next = new ListNode(1);
    headA2->next->next->next = common2;

    ListNode *headB2 = new ListNode(3);
    headB2->next = common2;

    intersectionNode = find_intersection_by_aligning_lengths(headA2, headB2);
    if (intersectionNode) {
        cout << "The value of intersection node is: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    deleteUntil(headA2, common2); // deletes 1 → 9 → 1
    deleteUntil(headB2, common2); // deletes 3
    deleteList(common2);          // deletes 2 → 4

    return 0;
}