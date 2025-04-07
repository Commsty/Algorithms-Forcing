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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        auto tmp = head;
        int size = 1;

        while (tmp->next)
        {
            size++;
            tmp = tmp->next;
        }

        k %= size;
        if (k == 0)
            return head;

        k = size - k;
        tmp = head;
        while (k-- > 1)
            tmp = tmp->next;

        auto newHead = tmp->next;
        tmp->next = nullptr;

        tmp = newHead;
        while (tmp->next)
            tmp = tmp->next;

        tmp->next = head;
        return newHead;
    }
};