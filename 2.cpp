#include<iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next){} 
};

// Error vi integer qua to thi se bi loi
// class Solution{
// public:
//     int return_num(ListNode *list){
//         int res = 0; 
//         int i = 1;
//         do{
//             res = list->val*i + res;
//             i *= 10;
//             list = list->next;
//         } while(list != NULL);
//         return res;
//     }
//     ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
//         ListNode *res1 = new ListNode();
//         ListNode *res2 = res1;
//         int sum = return_num(l1) + return_num(l2);
//         int len = std::to_string(sum).length();
//         for(int i = 0 ; i < len ; i ++){
//             res1->val = sum%10;
//             sum /= 10;
//             if(i != len - 1){
//                 res1 -> next = new ListNode();
//                 res1 = res1 -> next;
//             } else{
//                 res1 -> next = NULL;
//             }
//         }
//         return res2;
//     }
// };

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;
        int carry = 0;
        while(l1 || l2 || carry){
            int x = (l1 != NULL) ? l1->val:0;
            int y = (l2 != NULL) ? l2->val:0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum%10);
            curr = curr -> next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return dummyHead->next;
    }
};

int main(){
    ListNode l1(2);
    l1.next = new ListNode(4);
    l1.next->next = new ListNode(3);

    ListNode l2(5);
    l2.next = new ListNode(6);
    l2.next->next = new ListNode(4);
    Solution s = Solution();
    ListNode *res;
    res = s.addTwoNumbers(&l1, &l2);
    while(res != NULL){
        std::cout << res -> val << std::endl;
        res = res->next;
    }
    return 0;
}