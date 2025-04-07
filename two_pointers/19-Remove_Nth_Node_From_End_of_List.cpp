#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 1;
        auto tmp = head;
        while (tmp->next)
        {
            tmp = tmp->next;
            size++;
        }

        if (size == n)
            return head->next;

        int toDelete = size - n;
        tmp = head;
        ListNode *prev = nullptr;
        while (toDelete-- > 0)
        {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next=tmp->next;

        return head;
    }
};