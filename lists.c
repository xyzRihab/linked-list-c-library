#include<stdio.h>
#include "lists.h"

struct node{
   int data;
   struct node* next;
}_node;

//is_empty: checks if the list is empty
bool is_empty(Node head){
    return head == nothing;
}

//cons: adds an element to the beginning of the list
Node cons(int data, Node list){
    Node node = malloc(sizeof(_node));
    if(node == nothing) exit(1);
    node->data = data;
    node->next = list;
    return node;
}

//from_number: creates a list of digits from an integer number
Node from_number(int num){
    if(num == 0) return nothing;
    else return cons(num % 10, from_number(num / 10));
}

//from_array: creates a list from an array of int elements
Node from_array(int arr[], int size){
    if(size == 0) return nothing;
    else return concatenate(from_array(arr, size - 1), singleton(arr[size - 1]));
}

//print_list: prints the contents of the list
void print_list(const Node head, Printer print, bool start) {
    if (is_empty(head)) printf("[]\n");
    else {
        if (start) {
            printf("[");
        }
        print(current_item);
        if (!is_empty(tail)) {
            printf(", ");
        }
        else {
            printf("]\n"); return;
        }
    print_list(tail, print, false);
    }
}

//append: adds an element to the end of the list
Node append(int data, const Node head){
    if(is_empty(head)) return singleton(data);
    else return cons(current_item, append(data, tail));
}

//length: calculates the length of the list
int length(const Node head){
    if(is_empty(head)) return 0;
    else return 1 + length(tail);
}

//insert_at: inserts an element at a specified index in the list
Node insert_at(int data, int index, const Node head){
    if(is_empty(head)) return nothing;
    else if(index == 0) return cons(data, tail);
    else return cons(current_item, insert_at(data, index - 1, tail));
}

//concatenate: concatenates two lists
Node concatenate(const Node left, const Node right){
    if(is_empty(left)) return right;
    else return cons(left->data, concatenate(left->next, right));
}

//reverse: reverses the order of the elements in the list
Node reverse(const Node head){
    if(is_empty(head)) return nothing;
    else return concatenate(reverse(tail), cons(current_item, nothing));
}

//delete: deletes the first occurrence of an element from the list
Node delete(const Node head,int item,comparision compare_items){
    if(is_empty(head)) return nothing;
    else return (compare_items(current_item,item)) ? tail : cons(current_item, delete(tail, item, compare_items));
}

//delete_all: deletes all occurrences of an element from the list
Node delete_all(const Node head,int item,comparision compare_items){
    if(is_empty(head)) return nothing;
    else return (compare_items(current_item,item)) ? delete_all(tail, item, compare_items) : cons(current_item, delete_all(tail, item, compare_items));
}

//search: checks if an element is present in the list
bool search(Node head,int key,comparision compare_items){
    if(is_empty(head)) return false;
    else return (compare_items(current_item,key)) ? true : search(tail,key,compare_items);
}

//distinct: removes duplicates from the list
Node distinct(Node head,comparision compare_items){
    if(is_empty(head)) return nothing;
    else return (search(tail,current_item,compare_items)) ? cons(current_item, distinct(delete(tail,current_item,compare_items),compare_items)) : cons(current_item, distinct(tail,compare_items));
}

//singleton: creates a list with a single element
Node singleton(int a){
    Node head = malloc(sizeof(_node));
    current_item = a;
    tail = NULL;
    return head;
}

//last: returns the last element of the list
int last(Node head){
    if(is_empty(head)) return nothing;
    else return (tail==nothing) ? current_item : last(tail);
}

//intersperse: inserts an element between each pair of elements in the list
Node intersperse(int item,Node head){
    if(is_empty(tail)) return concatenate(singleton(current_item),tail);
    else return concatenate(singleton(current_item), cons(item,intersperse(item,tail)));
}

//replicate: creates a list with a given element repeated a given number of times
Node replicate(int s,int f){
    if(f==0) return nothing;
    else return cons(s,replicate(s,f-1));
}

//filter: removes elements from the list that don't satisfy a predicate function
Node filter(Node head, predicate pred){
    if(is_empty(head)) return nothing;
    else return (!pred(current_item)) ? filter(tail,pred) : cons(current_item,filter(tail,pred));
}

//delete_if: removes elements from the list that satisfy a predicate function
Node delete_if(Node head, predicate pred){
    if(is_empty(head)) return nothing;
    else return (pred(current_item)) ? delete_if(tail,pred) : cons(current_item,delete_if(tail,pred));
}

//clone: creates a copy of the list
Node clone(Node head){
    if(is_empty(head)) return nothing;
    else return cons(current_item,clone(tail));
}

//all: checks if all elements of the list satisfy a predicate function
bool all(Node head,predicate pred){
    if(is_empty(head)) return true;
    else return pred(current_item) ? all(tail,pred) : false;
}

//any: checks if any element of the list satisfies a predicate function
bool any(Node head,predicate pred){
    if(is_empty(head)) return false;
    else return pred(current_item) ? true : any(tail,pred);
}

//take: returns the first n elements of the list
Node take(int index,Node head){
    if(is_empty(head)) return nothing;
    else return (index==0) ? nothing : cons(current_item,take(index-1,tail));
}

//zip_by: applies a binary function to the corresponding elements of two lists, producing a new list
Node zip_by(Node head,Node list,func function){
    if(is_empty(head) || is_empty(list)) return nothing;
    else return cons(function(current_item,list->data),zip_by(tail,list->next,function));
}

//isSubsequenceOf: checks if the list is a subsequence of another list
bool isSubsequenceOf(Node head,Node list,comparision compare_items){
    if(is_empty(head)) return true;
    else return search(list,current_item,compare_items) ? isSubsequenceOf(tail,list,compare_items) : false;
}

//get_at: returns the element at a specified index in the list
int get_at(Node head,int index){
    if(is_empty(head)) return nothing;
    else return (index==0) ? current_item : get_at(tail,index-1);
}

//intersect: returns a list containing the elements that are present in both input lists.
Node intersect(Node head,Node list,comparision compare_items){
    if(is_empty(head) || is_empty(list)) return nothing;
    else return (search(list,current_item,compare_items)) ? distinct(cons(current_item,intersect(tail,list,compare_items)),compare_items) : intersect(tail,list,compare_items);
}

//difference: returns the elements that only appear in the first list.
Node difference(Node head,Node list,comparision compare_items){
    if(is_empty(head)) return nothing;
    else return (search(list,current_item,compare_items)) ? difference(tail,list,compare_items) : cons(current_item,difference(tail,list,compare_items));
}

//drop: Drops the first n items from a list.
Node drop(int n,Node head){
    if(is_empty(head)) return nothing;
    else return (n==0) ? head : drop(n-1,tail);
}

//find_item_index: Finds the index of a specified item in a list.
int find_item_index(Node head,int item){
    if(is_empty(head)) return 0;
    else return (current_item==item) ? 1 : 1 + find_item_index(tail,item);
}

//positional_equality: Determines if two linked lists have equal items at corresponding positions.
bool positional_equality(Node head,Node list,comparision compare_items){
    if(is_empty(head) && is_empty(list)) return true;
    else if (length(head)!=length(list)) return false;
    else return (compare_items(current_item,list->data)) ? positional_equality(tail,list->next,compare_items) : false;
}

//map: Applies a specified function to each item of a list.
Node map(Node head,func2 function){
    if(is_empty(head)) return nothing;
    else return cons(function(current_item),map(tail,function));
}

//take_while: Returns a new linked list containing the items that satisfy the predicate.
Node take_while(Node head,predicate pred){
    if(is_empty(head)) return nothing;
    else (pred(current_item)) ? cons(current_item,take_while(tail,pred)) : nothing;
}

//drop_while: Drops the items that doesn't satisfy the predicate.
Node drop_while(Node head,predicate pred){
    if(is_empty(head)) return nothing;
    else (pred(current_item)) ? drop_while(tail,pred) : cons(current_item,drop_while(tail,pred));
}

//find_index: Finds the index of the item in a list that satisfies a predicate.
int find_index(Node head,predicate pred){
    if(is_empty(head)) return 0;
    else return (pred(current_item)) ? 1 : 1 + find_index(tail,pred);
}

//set_equality: Determines if two linked lists have the same set of items, regardless of their order.
bool set_equality(Node head,Node list,comparision compare_items){
    if(is_empty(head)) return true;
    else if (length(head)>length(list)) return false;
    else return (search(list,current_item,compare_items)) ? set_equality(tail,list,compare_items) : false;
}

//is_prefix_of: Determines if a linked list is a prefix of another linked list.
bool is_prefix_of(Node head, Node list,comparision compare_items){
    if(is_empty(head)) return false;
    else if(is_empty(tail)) return true;
    else return (compare_items(current_item,list->data)) ? is_prefix_of(tail,list->next,compare_items) : false;
}

//is_infix_of: Determines if a linked list is an infix of another linked list.
bool is_infix_of(Node head, Node list,comparision compare_items){
    if(is_empty(head) || is_empty(list)) return false;
    else if(is_empty(tail)) return true;
    else return (!compare_items(current_item,list->data)) ? is_infix_of(head,list->next,compare_items) : is_infix_of(tail,list->next,compare_items);
}

//is_suffix_of: Determines if a linked list is a suffix of another linked list.
bool is_suffix_of(Node head, Node list,comparision compare_items){
    if(is_empty(head)) return true;
    else if(last(head)!=last(list)) return false;
    else return (!compare_items(current_item,list->data)) ? is_suffix_of(head,list->next,compare_items) : is_suffix_of(tail,list->next,compare_items);
}

//sum_while: Computes the sum of the items in a linked list up to a specified item.
int sum_while(Node head,int item){
    if(current_item==item) return current_item;
    else return current_item + sum_while(tail,item);
}

//accumulate: Computes a new linked list where each item is the sum of all items up to that point.
Node accumulate(Node head){
    if(is_empty(head)) return nothing;
    else return cons(sum_while(head,current_item),head);
}

//accumulate_with: Applies a specified function to each item in a list.
Node accumulate_with(Node head,func2 function){
    if(is_empty(head)) return nothing;
    else return cons(function(current_item),accumulate_with(tail,function));
}

//count_if: Counts the number of items in a list that satisfy a predicate.
int count_if(Node head,predicate pred){
    if(is_empty(head)) return 0;
    else return (pred(current_item)) ? 1 + count_if(tail,pred) : count_if(tail,pred);
}

//union_: Computes the set union of two lists.
Node union_(Node head,Node list,comparision compare_items){
    if(is_empty(head)) return nothing;
    else return (search(list,current_item,compare_items)) ? cons(current_item,union_(tail,list,compare_items)) : union_(tail,delete(list,current_item,compare_items),compare_items);
}

//merge: Merges two linked lists into a single linked list in ascending order.
Node merge(Node head,Node list,comparision compare_items){
    if(is_empty(head)) return list;
    else if(is_empty(list)) return head;
    else return (compare_items(current_item,list->data)) ? cons(current_item,merge(tail,list,compare_items)) : cons(list->data,merge(head,list->next,compare_items));
}

int foldl(Node head, List reducer,List accumulator){
    if(is_empty(head)) return accumulator;
    else return foldl(tail,reducer,reducer(accumulator,current_item));
}

//sub_list: Returns a new list containing a specified sub-range of items from a given linked list.
Node sub_list(int lower,int upper,Node head){
    if(is_empty(head) || lower>upper) return nothing;
    else if(lower==0) return cons(current_item,sub_list(lower,upper-1,tail));
    else if(upper==0) return head;
    else return sub_list(lower-1,upper-1,tail);
}

//xor: takes in two lists and returns a new list that only contains elements unique in both lists.
Node xor(Node head,Node list,comparision compare_items){
    if(is_empty(head)) return list;
    else return (!search(list,current_item,compare_items)) ? cons(current_item,xor(tail,list,compare_items)) : xor(tail,delete(list,current_item,compare_items),compare_items);
}