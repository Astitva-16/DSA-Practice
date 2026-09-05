/*19. Remove Nth Node From End of List
LeetCode link -> https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

// APPROACH ->
/*
fast aur slow dono ko head par rakho.
fast ko N steps ahead move karo → ab fast aur slow ke beech n nodes ka gap hai.
Agar fast == nullptr → iska matlab head hi Nth node from end hai → head ko head->next par shift karke old head delete karo.
Otherwise, fast aur slow ko saath-saath move karo jab tak fast->next != nullptr.
Ab slow Nth node se just pehle wale node par hoga.
slow->next ko delete karne ke liye:
  dnode = slow->next
  slow->next = slow->next->next
  delete dnode
Finally updated head return karo.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }

        if(fast == nullptr){

            ListNode* dnode = head;
            head = head -> next;
            delete dnode;
            return head;
        }

        while(fast -> next != nullptr){
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode* dnode = slow -> next;
        slow -> next = slow -> next -> next;
        delete dnode;
        return head;

    }
};
