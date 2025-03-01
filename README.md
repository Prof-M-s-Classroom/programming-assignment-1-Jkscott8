[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Constructor
- The constructor is just initializing the doubly linked list, and setting the length to zero
- The big O is O(1) because it’s just one variable assignment

Destructor
- The destructor is looping through each node in the list starting at the head and re-assigning the head till the head is null
- The big O is O(n) because it’s looping through the N items in the list

Insertions

Beginning
- It first checks to see if the list is empty, if so it sets the node as head and tail and the length to one. If it’s not empty it links the heads ‘prev’ pointer to the new node and re-assigns the new node as the head and its ‘next’ pointer points at the previous head. Then add one to the length.
- The Big O is O(1) because there is no looping needed.

End
- It first checks to see if the list is empty, if so it sets the node as head and tail and the length to one. If it’s not, it takes the tails ‘next’ pointer to the new node, and - then re-assigns the new node as the tail.
- The Big O is O(1) because there is no looping needed.

Index
- It takes in the index and checks if it is 0, if so it just calls the add at the beginning.  If it’s out of range it just returns text saying out of range. If the index is equal to length it will call the add the end because the last index is length-1 so length would be equal to the last index after adding the new node. If the length is 0 and the called index is 0, it won’t add the node twice because the add at head function is called first so the length would be one after that’s called. If it’s none of those then it finds the waypoint at and before that index. It then re-assigns all the pointers so the one before the index ‘next’ points at the new node, and the one that previously was at the index ‘prev’ also points at the new node. The new node points forward and back to those two nodes. Then add one to the length.
- There is no looping in this one either, except it calls get waypoint which does loop so it’s O(N).

Deletions

Beginning
- It first checks to see if it’s empty, if so it just returns text saying it’s empty. If it’s not empty it moves the head over to the next node, which if the length is just one then it will just make the list empty. Then it deletes the node that was previously the head node.
- The Big O is O(1) because there is no looping needed

End
- It first checks to see if it’s empty, if so it just returns text saying it’s empty. If it is length one then it will call the remove head. If it’s not empty or one it moves the tail to the previous node.
- The Big O is O(1) because there is no looping needed.

Index
- It starts by checking if the index is in range, if it’s not between 0 and length -1 it will return out of range. If it is length -1 it calls remove from end, if it’s index 0 if removes the beginning. If none of these it gets the waypoint at the index, before, and after the index. It then points the index-1 and index+1 at each other and deletes the one that was previously at that index
- Same as the insertion because it calls get waypoint, which loops through the list it is O(N)

Traversal

Forward
- If the list is empty then it returns the list is empty. If it’s not empty then it will iterate through the list starting from the head until it reaches the end. Each time it goes to a new node it will output the value stored in it.
- O(N) because it is looping through N items in the list

Backward
- If the list is empty then it returns the list is empty. If it’s not empty then it will iterate through the list starting from the tail until it reaches the start. Each time it goes to a new node it will output the value stored in it.
- O(N) because it is looping through N items in the list

Get Waypoint
- If the index isn’t in the range of length -1 to 0 then  it returns out of range. If it’s the head or tail it will just return that. If neither of those then it will loop through starting at the head until it reaches the requested index and returns the node at that index.
- O(N) because it loops through N items in the list.

Set Waypoint
- If the index isn’t in the range of length -1 to 0 then  it returns out of range. If it’s the head or tail it will change the data in that node to the new data. If not it calls the get waypoint to find the index, then assigns the new data to that node.
- O(N) because it loops through the N items in the list using get waypoint.

Print
- It basically does the same thing as traverse forward
- O(N)  because it is looping through N items in the list
