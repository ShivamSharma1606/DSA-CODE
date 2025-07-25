//optimal approach
//tc =o(n) it may look like n^2 but it is o(n) (do it on pen and paper)
//sc =1

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    Node *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node *nextNode=temp->next;
        while(nextNode!=NULL && nextNode->data==temp->data){
            Node *duplicate=nextNode;
            nextNode=nextNode->next;
            free(duplicate);
        }
        temp->next=nextNode;
        if(nextNode)    nextNode->prev=temp;
        temp=temp->next;
    }
    return head;
}
