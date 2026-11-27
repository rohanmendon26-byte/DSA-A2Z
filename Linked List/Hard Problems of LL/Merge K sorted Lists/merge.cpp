
// Time	(O(N log K))	
// Auxiliary space	\(O(K)\)



Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<pair<int, Node*>,
    vector<pair<int, Node*>>,
    greater<pair<int, Node*>>> pq;

    // Step 1: Insert the first node of every list
    for(int i = 0; i < listArray.size(); i++)
    {
        if(listArray[i])
            pq.push({listArray[i]->data, listArray[i]});
    }

    // Step 2: Create a dummy node
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Step 3: Process the smallest element
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        // Insert the next node of the extracted list
        if(it.second->next)
            pq.push({it.second->next->data, it.second->next});

        // Attach the smallest node to the merged list
        temp->next = it.second;
        temp = temp->next;
    }

    return dummyNode->next;
}

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []