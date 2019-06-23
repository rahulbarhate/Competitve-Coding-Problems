#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
struct Node *addToEmpty(struct Node *last, int data) 
{ 
    // This function is only for empty list 
    if (last != NULL) 
      return last; 
  
    // Creating a node dynamically. 
    struct Node *temp =  (struct Node*)malloc(sizeof(struct Node)); 
  
    // Assigning the data. 
    temp -> data = data; 
    last = temp; 
  
    // Creating the link. 
    last -> next = last; 
  
    return last; 
} 
  
struct Node *addBegin(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
  
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
  
    return last; 
} 
  
struct Node *addEnd(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
      
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
  
    return last; 
} 
  
struct Node *addAfter(struct Node *last, int data, int item) 
{ 
    if (last == NULL) 
        return NULL; 
  
    struct Node *temp, *p; 
    p = last -> next; 
    do
    { 
        if (p ->data == item) 
        { 
            temp = (struct Node *)malloc(sizeof(struct Node)); 
            temp -> data = data; 
            temp -> next = p -> next; 
            p -> next = temp; 
  
            if (p == last) 
                last = temp; 
            return last; 
        } 
        p = p -> next; 
    }  while(p != last -> next); 
  
    cout << item << " not present in the list." << endl; 
    return last; 
  
} 

struct Node *deleteAllPositions(struct Node *last, int data)  
{
	struct Node *temp, *head;
	
	// If the list is empty
	if(last == NULL)
	{
		return NULL;
	}
	
	head = last->next;
	
	// If the list has only one element
	if(last->next == last && last->data == data)
	{
		temp = last;
		last = NULL;
		free(temp);
		return NULL;
	}
	
	// Deleting the first element
	if(head->data==data)
	{
		temp = head;
		last->next = head->next;
		head =last->next;
		free(temp);
		return head;
	}
	
	
	// Deleting an element in the middle
	while(head->next!= last)
	{
		if(head->next->data == data)
		{
			temp = head->next;
			head->next=temp->next;
			free(temp);
			return head;
		}
		
		head=head->next;
	}
	
	
	//Deleting the last element
	if(head->next->data == data)
	{
		temp = head->next;
        head->next = last->next;
        free(temp);		
        last = head;
        return head;
	}
	
	
	
}
    
  
void traverse(struct Node *last) 
{ 
    struct Node *p; 
  
    // If list is empty, return. 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
  
    // Pointing to first Node of the list. 
    p = last -> next; 
  
    // Traversing the list. 
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
  
} 
  
// Driven Program 
int main() 
{ 
    struct Node *last = NULL; 
  
  	// Insert at various locations
    last = addToEmpty(last, 6); 
    last = addBegin(last, 4); 
    last = addBegin(last, 2); 
    last = addEnd(last, 8); 
    last = addEnd(last, 12); 
    last = addAfter(last, 10, 8);
	
	// Delete
	last = deleteAllPositions(last, 2);
	
	// Traversing the List
    traverse(last); 
  
    return 0; 
} 

