/*23. Merge k Sorted Lists
LeetCode link -> https://leetcode.com/problems/merge-k-sorted-lists/
*/

// APPROACH ->
/*
mergeTwoLists() → 2 sorted linked lists ko recursively merge karta hai.
l1->val <= l2->val → l1 ka node choose karo, uske next ko remaining lists ke merge se connect karo.
Otherwise → same kaam l2 ke saath.
partitionANDmerge(start,end) → K lists ko recursively 2 halves mein divide karta hai.
Left half ko l1, right half ko l2 mein merge karo.
Phir mergeTwoLists(l1,l2) → dono sorted halves ko merge karta hai.
mergeKLists() → agar lists empty nahi hain, partitionANDmerge(0,k-1) se all K sorted lists merge kar deta hai.
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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

        if(l1 == nullptr) return l2;

        if(l2 == nullptr) return l1;

        if(l1 -> val <= l2 -> val){

            l1 -> next = mergeTwoLists(l1 -> next, l2);

            return l1;
        }
        else{

            l2 -> next = mergeTwoLists(l1, l2 -> next);

            return l2;          
        }

        return nullptr;
    }

    ListNode* partitionANDmerge(int start, int end, vector<ListNode*>& lists){
        if(start > end) return nullptr;

        if(start == end) return lists[start];

        int mid = start + (end - start) / 2;

        ListNode* l1 = partitionANDmerge(start, mid, lists);

        ListNode* l2 = partitionANDmerge(mid + 1, end, lists);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return nullptr;

        return partitionANDmerge(0, k - 1, lists);
    }
};
