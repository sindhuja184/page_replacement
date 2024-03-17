#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
int len(node *head){
    int len = 0; 
    node *temp = head;
    while(temp != NULL){
        len++; 
        temp = temp -> next;
    }
    return len;
}
int main(){
    int max, pagefaults = 0, data;
    printf("Enter the number of frames :");
    scanf("%d", &max);
    int ch = 1;
    while(ch){
        printf("Enter the data or -1 to exit :");
        scanf("%d", &data);
        if(data == -1) break;
        int l = len(head);
        if(l < max){
            l = len(head);
            node *newnode = (node*)malloc(sizeof(node));
            newnode -> data = data;
            newnode -> next = NULL;
            if(head == NULL){
                head = newnode;
            } 
            else{
                node *p = head;
                while(p -> next != NULL){
                    p = p -> next;
                }
                p -> next = newnode;
            }
            pagefaults++;
        }
        else{
            int found = 0;
            node *temp = head;
            while(temp != NULL){
                if(temp -> data == data){
                    found = 1;
                    break;
                }
                temp = temp -> next;
            }
            if(found==0){
                pagefaults++;
                node *newnode = (node*)malloc(sizeof(node));
                newnode -> data = data;
                newnode -> next = NULL;
                free(temp);
                head = head -> next;
                node *p = head;
                while(p -> next){
                    p = p -> next;
                }
                p -> next = newnode;
            }
        }
    }
    printf("Number of pagefaults : %d\n", pagefaults);
}