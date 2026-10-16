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


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(auto x:lists){
            while(x){
                arr.push_back(x->val);
                x=x->next;
            }
        }
        if(arr.size()==0 ) return nullptr;
        sort(arr.begin(),arr.end());

        ListNode*head=new ListNode(arr[0]);
        ListNode*temp=head;


        for(int i=1;i<arr.size();i++){
            temp->next=new ListNode(arr[i]);
            temp=temp->next;
        }

        return head;
    }
};