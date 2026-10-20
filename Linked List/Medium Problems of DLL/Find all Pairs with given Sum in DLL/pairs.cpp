/* Structure of Doubly Linked List Node
class Node {
	public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int val) {
		data = val;
		next = nullptr;
		prev = nullptr;
	}
}; */

// Time: \(O(n)\) — find the tail and traverse using two pointers.
// Auxiliary space: \(O(1)\), excluding the output vector.

class Solution {
	public:
	
	Node *findtail(Node* head) {
	    if(head==NULL)
	       return NULL;
		Node *tail = head;
		while (tail->next != NULL)
			tail = tail->next;
		return tail;
	}
	
	vector<vector<int>> givenSumPairs(Node* head, int target) {
		
		vector<vector<int>> ans;
		if (head == NULL)
			return ans;
		
		Node *left = head;
		Node *right = findtail(head);
		
		while (left->data<right->data) {
			if (left->data + right->data == target) {
				ans.push_back({left->data, right->data});
				left = left->next;
				right = right->prev;
			}
			else if (left->data + right->data<target)
				left = left->next;
			else
				right = right->prev;
		}
		return ans;
	}
};


// Input:
// target = 7
// Output: [[1, 6], [2, 5]]
// Explanation: There are two pairs (1, 6) and (2,5) with sum 7.


// Input: 
// target = 6
// Output: [[1, 5]]
// Explanation: There is one pairs  (1, 5) with sum 6.