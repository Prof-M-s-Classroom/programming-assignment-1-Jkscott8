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
    void print() { cout << data << " "; }
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
    // Constructor
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
    Node<T>* get(int index) {
        if (index >= length || index < 0) {
            return NULL;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
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
            Node<T>* front = get(index-1);
            Node<T>* back = get(index);
            node -> next = back;
            node -> prev = front;
            back -> prev = node;
            front -> next = node;
            length++;
        }
    }
    // Insert a waypoint at a specified index.
    void removeWaypointAtBeginning();
    // Remove the first waypoint from the list.
    void removeWaypointAtEnd();
    // Remove the last waypoint from the list.
    void removeWaypointAtIndex(int index);
    // Remove a waypoint at a specified index.
    void traverseForward();
    // Print all waypoints from the first to the last.
    void traverseBackward();
    // Print all waypoints in reverse order from last to first.
    Node<T>* getWaypoint(int index);
    // Retrieve a waypoint at a specified index.
    void setWaypoint(int index, T& data);
    // Modify the details of a waypoint at a specified index
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

