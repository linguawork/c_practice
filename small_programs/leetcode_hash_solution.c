#include <stdio.h>

struct node{
    int key;
    int val;
    struct node *next;
};
struct table{
    int size;
    struct node **list;
};
struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}
int hashCode(struct table *t,int key){
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}
void insert(struct table *t,int key,int val){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}
int lookup(struct table *t,int key){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}



int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    struct table *t = createTable(numsSize);
    int i;
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)* *returnSize);
    for(i = 0; i < numsSize; i++){
        insert(t, nums[i], i);
    }
    for(i = 0; i < numsSize; i++){
        int complement = target - nums[i];
        if(lookup(t, complement)!= -1 && lookup(t, complement)!= i){
            result[0] = lookup(t, complement);
            result[1] = i;
        }
    }
    free(t);

    return result;
}