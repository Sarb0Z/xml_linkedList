#include "list.h"
template <typename T>
class Stack
{
    List<T> list;
    int size;
    public:
    Stack(){
        size=0;
    }
    void push(T element){
        list.insertAtHead(element);
        size++;
    }
    void pop(T& element){
        if (size==0)
            return;
        list.returnData(element);
        list.deleteAtHead();
        size--;
    }
    void top(T& element){
        if (size!=0)
            list.returnData(element);
    }

};
