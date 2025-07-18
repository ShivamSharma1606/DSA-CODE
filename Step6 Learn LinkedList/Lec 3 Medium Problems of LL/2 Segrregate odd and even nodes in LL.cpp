/*
brute force approach
1. create an array
2. insert first odd element
3. insert then even element
4. converty array into linked list

tc = n/2 + n/2
sc= n
*/
//optimal approach tc= n/2 and sc =1




class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};


Node* oddEvenList(Node* head)
{
	if(head==NULL || head->next==NULL){
        return head;
    }

    Node* odd= head;
    Node* even=head->next;
    Node* evenHead=head->next;

    while(even!=NULL && even->next!=NULL){

        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }

    odd->next=evenHead;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* result = oddEvenList(head);

    // Print the modified linked list
    Node* current = result;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
    
}