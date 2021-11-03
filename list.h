template <typename T>
class List
{
    class Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    public:
    List(){
        head=tail=nullptr;
    }
    void insertAtHead(T element){
        Node* temp=new Node;
        temp->next=head;
        head=temp;
        temp->data=element;
        if (head->next==nullptr)
            tail=temp;
    }
    void deleteAtHead(){
        if (head!=nullptr){
            Node*temp=head->next;
            delete head;
            head=temp;
        }
        if (head==nullptr)
            tail=nullptr;
    }
    void returnData(Node* ptr, T& element){
        if (ptr!=nullptr){
            element=ptr->data;
        }
    }
};


