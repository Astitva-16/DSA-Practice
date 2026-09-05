/*141. Linked List Cycle
LeetCode link -> https://leetcode.com/problems/linked-list-cycle/
*/

// APPROACH ->
/*
slow aur fast dono ko head se start karo.
slow 1 step move karta hai, fast 2 steps move karta hai.
Agar linked list mein cycle nahi hai → fast eventually nullptr ho jayega → false.
Agar cycle hai → fast aur slow cycle ke andar eventually ek dusre se milenge → true.
slow == fast check karke cycle detect karo.
Initial check head == nullptr || head->next == nullptr → empty ya single-node list mein cycle nahi ho sakta.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr) return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) return true;
        }

        return false;
    }
};
