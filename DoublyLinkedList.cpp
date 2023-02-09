#include <iostream>
using namespace std;

/*
 This Program works on the concept that, Doubly Linked list is two Singly Linked list with a single node.
 There is a single node with two fronts named as "head" and "tail".
 Basically Singly nodes inbuilt which can traverse from both sides.
 *****"Tail" can also be regarded as "First"*****
 */

class Node{
public:
    Node* prev;
    Node* next;
    int data;

    Node(int data){
        this->prev = nullptr;
        this->next = nullptr;
        this->data = data;
    }
};

class DoublyLinkedList{
private:
    Node* head;
public:
    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        if(head!=NULL) head->prev = newNode;
        head = newNode;
    }

    void insertAtFirst(int data){
        Node* newNode = new Node(data);
        Node* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        if(newNode->prev == nullptr){       //If there were no nodes previously then tail = newNode = head;
            head = newNode;
        }
    }

    void insertAtPos(int data, int Pos){
        Node* newNode = new Node(data);     //The new Node
        Node* temp = head;                  //Node1 in front of which new Node to be added

        if(Pos == 0){                       //To Put the element at Head [Mechanism of adding node to "head" is different.]
            insertAtHead(data);
            return;
        }
        int i = 0;
        while(i<Pos-1){
            if(!temp->next->next){          //Check insertAtFirst() method to understand this more.
                insertAtFirst(data);        //To Put the element at Tail [Mechanism of adding node to "tail" is different.]
                return;
            }

            temp = temp->next;
            i++;
        }

        Node* temp2 = temp->next;           //Node2 in whose previous new Node to be added
        temp->next = newNode;               //Previous Node is now pointing forward to the new Node
        newNode->prev = temp;               //New Node is pointing backward to the Previous Node
        newNode->next = temp2;              //New Node is pointing forward to the Next Node
        temp2->prev = newNode;              //Next Node is pointing backward to the new Node
    }

    void deleteAtHead(){
        Node* temp = head->next;
        head = temp;
        head->prev = nullptr;
    }

    void deleteAtFirst(){
        Node* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        Node* temp = tail->prev;
        tail = temp;
        tail->next = nullptr;
    }

    void deleteAtPos(int Pos){
        Node* temp = head;                  //Previous Node from the "Node to be deleted"

        if(Pos == 0){                       //To Remove the element at Head [Remember the mechanism of deleting node at "head" is different.]
            deleteAtHead();
            return;
        }

        int i = 0;
        while(i<Pos-1){
            if(!temp->next->next->next){    //Check deleteAtFirst() method to understand this more
                deleteAtFirst();            //To Remove the element at Tail [Mechanism of removing node at "tail" is different.]
                return;
            }
            temp = temp->next;
            i++;
        }

        Node* node2del = temp->next;        //Node to be deleted
        Node* temp2 = node2del->next;       //Next Node from the "Node to be deleted"

        temp->next = temp2;
        temp2->prev = temp;
    }

    void printFromHead(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"\t->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void printFromFirst(){
        Node* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        cout<<"NULL";
        while(tail){
            cout<<"\t->"<<tail->data;
            tail = tail->prev;
        }
        cout<<endl;
    }
};

int main() {
    DoublyLinkedList list;

    int op = 1;
    cout<<"\n****MENU****\n\n"<<
    "1.Insert at Head\n"<<
    "2.Insert at First\n"<<
    "3.Insert at Position\n"<<
    "4.Delete at Head\n"<<
    "5.Delete at First\n"<<
    "6.Delete at Position\n"<<
    "7.Display from Head\n"<<
    "8.Display from First\n"<<
    "0.Exit\n"<<endl;

    while(op){
        cout<<"Enter Option: ";
        cin>>op;
        int data,pos;
        switch(op){
            case 0:
                break;
            case 1:
                cout<<"Enter Data: ";
                cin>>data;
                list.insertAtHead(data);
                break;
            case 2:
                cout<<"Enter Data: ";
                cin>>data;
                list.insertAtFirst(data);
                break;
            case 3:
                cout<<"Enter Data: ";
                cin>>data;
                cout<<"\nEnter Position[0-n]: ";
                cin>>pos;
                list.insertAtPos(data,pos);
                break;
            case 4:
                list.deleteAtHead();
                break;
            case 5:
                list.deleteAtFirst();
                break;
            case 6:
                cout<<"\nEnter Position[0-n]: ";
                cin>>pos;
                list.deleteAtPos(pos);
                break;
            case 7:
                list.printFromHead();
                break;
            case 8:
                list.printFromFirst();
                break;
            default:
                cout<<"Invalid Option!"<<endl;
        }
    }
    return 0;
}
