/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
// Complexity
// Time: O(n) because every node is visited once.
// Space: O(n) due to recursive call stack.

int addhelper(Node *temp){
    if(temp==NULL)
       return 1;
    
    int carry=addhelper(temp->next);
    temp->data+=carry;
    if(temp->data<10)
       return 0;
    temp->data=0;
    return 1;
}


Node *addOne(Node *head)
{
    int carry=addhelper(head);
    if(carry==1){
        Node *newnode=new Node(1);
        newnode->next=head;
        head=newnode;
    }
    return head;
}


// Example:
// Input: Initial Linked List: 1 -> 5 -> 2
// Output: Modified Linked List: 1 -> 5 -> 3
// Explanation: Initially the number is 152. After incrementing it by 1, the number becomes 153.

// nput: Head: 4->5->6
// Output: 457

// Input: Head: 1->2->3
// Output: 124