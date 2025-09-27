#include<bits/stdc++.h>
using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode *fast, *slow;
    fast = head;
    slow = head;

    while (fast && fast->next) {
        curr = curr->next;
        fast = fast->next->next;
    }

    return curr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	return 0;
}