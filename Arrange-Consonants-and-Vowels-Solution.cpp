########################################################################################  Question  ############################################################################################################################################################################################

Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

Example 1:

Input:
n = 9
linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 
Output: 
a -> e -> i -> b -> c -> d -> f -> g -> h
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
Example 2:

Input:
n = 8
linked list: a -> b -> a -> b -> d -> e -> e -> d 
Output: 
a -> a -> e -> e -> b -> b -> d -> d
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
Your Task:
Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 104
'a' <= elements of linked list <= 'z'





##########################################################################################  Solution  ##########################################################################################################################################################################################

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    int isVowel(char a){
        return (a=='a'|| a=='e'|| a=='i'|| a=='o' || a=='u');
       
    }
    struct Node* arrangeCV(Node* head) {
        // Code here
        if(head==nullptr ||head->next==nullptr)
        return head;
        
        struct Node* vowel=nullptr;
        
        struct Node* t1=head;
        struct Node* p=nullptr;
        struct Node* t2=nullptr;
        
        while(t1!=nullptr){
            
            if(isVowel(t1->data)){
                struct Node *temp= new Node(t1->data);
                if(t2!=nullptr){
                    t2->next=temp;
                    
                    t2=t2->next;
                    
                }else{
                    vowel=temp;
                    t2=vowel;
                }
                
                if(p!=nullptr ){
                p->next=t1->next;
                t1=p->next;
                    
                }else if(p==nullptr && t1==head){
                    head=head->next;
                    t1=head;
                }
                
            }else{
                
            p=t1;
            t1=t1->next;
            }
        }
        
       
     
    if(!vowel){
        return head;
    }else{
        t2->next=head;
        return vowel;
    }
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends
