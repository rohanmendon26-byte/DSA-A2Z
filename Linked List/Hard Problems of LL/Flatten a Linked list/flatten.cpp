// Time	O(N × K)	Repeated merging
// Auxiliary space	O(K)	Recursive call stack


Node *merge(Node *list1, Node *list2) {
    Node *dummynode = new Node(-1);
    Node *res = dummynode;

    while(list1 != NULL && list2 != NULL) {
        if(list1->data < list2->data) {
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else {
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = nullptr;
    }

    if(list1)
        res->bottom = list1;
    else
        res->bottom = list2;

    if(dummynode->bottom)
        dummynode->bottom->next = nullptr;

    return dummynode->bottom;
}




Node* flatten(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node *mergedhead = flatten(head->next);

    head = merge(head, mergedhead);

    return head;
}