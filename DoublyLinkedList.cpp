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
    Node* tail;
public:
    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        cout<<head<<endl;
        if(head!=NULL) head->prev = newNode;
        head = newNode;
        cout<<"YES";

        if(newNode->next == nullptr){       //If there were no nodes previously then head = newNode = tailNode
            tail = newNode;
        }
        cout<<"Inserted!!"<<endl;
    }

    void insertAtFirst(int data){
        Node* newNode = new Node(data);
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

        int i = 0;
        while((i<Pos-1)&&temp->next){
            temp = temp->next;
            i++;
        }
        cout<<"YES";

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

    void deleteAtTail(){
        Node* temp = tail->prev;
        tail = temp;
        tail->next = nullptr;
    }

    void deleteAtPos(int Pos){
        Node* temp = head;                  //Previous Node from the "Node to be deleted"
        int i = 0;
        while((i<Pos-1)&&temp->next){
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
        while(temp->next){
            cout<<temp->data<<"\t->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void printFromFirst(){
        Node* temp = tail;
        while(temp->prev){
            cout<<temp->data<<"\t<-";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtHead(55);
//    int op = 1;
//    cout<<"\n****MENU****\n\n"<<
//    "1.Insert at Head\n"<<
//    "2.Insert at First\n"<<
//    "3.Insert at Position\n"<<
//    "4.Delete at Head\n"<<
//    "5.Delete at First\n"<<
//    "6.Delete at Position\n"<<
//    "7.Display from Head\n"<<
//    "8.Display from First\n"<<
//    "0.Exit\n"<<endl;
//
//    while(op){
//        cout<<"Enter Option: ";
//        cin>>op;
//        int data,pos;
//        switch(op){
//            case 0:
//                break;
//            case 1:
//                cout<<"Enter Data: ";
//                cin>>data;
//                list.insertAtHead(data);
//                break;
//            case 2:
//                cout<<"Enter Data: ";
//                cin>>data;
//                list.insertAtFirst(data);
//                break;
//            case 3:
//                cout<<"Enter Data: ";
//                cin>>data;
//                cout<<"\nEnter Position: ";
//                cin>>pos;
//                list.insertAtPos(data,pos);
//                break;
//            case 4:
//                list.deleteAtHead();
//                break;
//            case 5:
//                list.deleteAtTail();
//                break;
//            case 6:
//                cout<<"\nEnter Position: ";
//                cin>>pos;
//                list.deleteAtPos(pos);
//                break;
//            case 7:
//                list.printFromHead();
//                break;
//            case 8:
//                list.printFromFirst();
//                break;
//            default:
//                cout<<"Invalid Option!"<<endl;
//        }
//    }
    return 0;
}
