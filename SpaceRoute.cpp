#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << endl; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    SpaceRoute() {
        length = 0;
    }

    ~SpaceRoute() {
        Node<T>* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        if (length == 0) {
            head = new Node<T>(data);
            tail = head;
            length = 1;
        }
        else {
            Node<T>* node = new Node<T>(data);
            Node<T>* oldHead = head;
            head->prev = node;
            node->next = oldHead;
            head = head -> prev;
            length++;
        }
    }

    void addWaypointAtEnd(T& data) {
        if (length == 0) {
            head = new Node<T>(data);
            tail = head;
            length = 1;
        }
        else {
            Node<T>* node = new Node<T>(data);
            tail->next = node;
            node->prev = tail;
            tail = node;
            length++;
        }
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else if (index>length || index<0) {
            cout << "Index Out of Range" << endl;
        }
        else if (index==length) {
            addWaypointAtEnd(data);
        }
        else {
            Node<T>* node = new Node<T>(data);
            Node<T>* front = getWaypoint(index-1);
            Node<T>* back = getWaypoint(index);
            node -> next = back;
            node -> prev = front;
            back -> prev = node;
            front -> next = node;
            length++;
        }
    }

    void removeWaypointAtBeginning() {
        if (length == 0) {
            cout << "List Is Empty" << endl;
            return;
        }
        Node<T>* del = head;
        Node<T>* newHead = head->next;
        head = newHead;
        delete del;
        length--;
    }

    void removeWaypointAtEnd() {
        if (length == 0) {
            cout << "List Is Empty" << endl;
            return;
        }
        if (length==1) {
            removeWaypointAtBeginning();
        }
        else {
            Node<T>* del = tail;
            Node<T>* newTail = tail->prev;
            delete del;
            tail = newTail;
            tail -> next = nullptr;
            length--;
        }
    }

    void removeWaypointAtIndex(int index) {
        if (index >= length || index < 0) {
            cout << "Index Out of Range" << endl;
        }
        else if (index==length-1) {
            removeWaypointAtEnd();

        }
        else if (index==0) {
            removeWaypointAtBeginning();

        }
        else {
            Node<T>* del = getWaypoint(index);
            Node<T>* front = getWaypoint(index-1);
            Node<T>* back = getWaypoint(index+1);
            front->next = back;
            back -> prev = front;
            delete del;
            length--;
        }
    }

    void traverseForward() {
        if (length == 0) {
            cout << "List Is Empty" << endl;
        }
        else {
            cout << "Traversing Forward: " << endl;
            Node<T>* current = head;
            while (current != nullptr) {
                cout << current -> data << endl;
                current = current -> next;
            }
        }
        cout << endl;
    }

    void traverseBackward() {
        if (length == 0) {
            cout << "List Is Empty" << endl;
        }
        else {
            cout << "Traversing Backward: " << endl;
            Node<T>* current = tail;
            while (current != nullptr) {
                cout << current -> data << endl;
                current = current -> prev;
            }
            cout << endl;
        }
    }

    Node<T>* getWaypoint(int index) {
        if (index >= length || index < 0) {
            cout << "Waypoint Index Out of Range" << endl;
            return nullptr;
        }
        else if (index==0) {
            return head;
        }
        else if (index==length-1) {
            return tail;
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    }

    void setWaypoint(int index, T& newData) {
        if (index >= length || index < 0) {
            cout << "Waypoint Index Out of Range" << endl;
        }
        else if (index==0) {
            head->data = newData;
        }
        else if (index==length-1) {
            tail->data = newData;
        }
        else {
            Node<T>* current = getWaypoint(index);
            current->data = newData;
        }
    }


    void print(){
        cout << "Priting List: " << endl;
            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }
};

