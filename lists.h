#include <stdbool.h>
#include<stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define nothing NULL
#define current_item head->data
#define tail head->next

typedef void(*Printer)(int);
typedef struct node* Node;
typedef bool(*predicate)(int);
typedef int(*func)(int,int);
typedef int(*func2)(int);
typedef Node(*List)(Node,predicate);
typedef bool(*comparision)(int,int);

bool is_empty(const Node);
Node cons(int, Node);
Node from_number(int);
void print_list(const Node,Printer,bool);
Node from_array(int*, int);
Node append(int, Node);
int length(const Node);
Node insert_at(int, int, const Node);
Node reverse(const Node);
Node concatenate(const Node, const Node);
Node delete(const Node,int,comparision);
Node delete_all(const Node,int,comparision);
bool search(Node, int,comparision);
Node distinct(Node,comparision);
Node singleton(int);
int last(Node);
Node intersperse(int, Node);
Node replicate(int, int);
Node filter(Node, predicate);
Node delete_if(Node, predicate);
Node clone(Node);
bool all(Node, predicate);
bool any(Node, predicate);
Node take(int, Node);
Node zip_by(Node, Node, func);
bool isSubsequenceOf(Node, Node, comparision);
int get_at(Node, int);
Node intersect(Node, Node, comparision);
Node difference(Node, Node, comparision);
Node drop(int, Node);
int find_item_index(Node, int);
bool positional_equality(Node, Node, comparision);
Node map(Node, func2);
Node take_while(Node, predicate);
Node drop_while(Node, predicate);
int find_index(Node, predicate);
bool set_equality(Node, Node, comparision);
bool is_prefix_of(Node, Node, comparision );
bool is_infix_of(Node, Node, comparision );
bool is_suffix_of(Node, Node, comparision);
int sum_while(Node, int);
Node accumulate(Node);
int count_if(Node, predicate);
int sum_if(Node, predicate);
int multipy_if(Node, predicate);
Node union_(Node, Node, comparision);
int foldl(Node, List, List);
Node sub_list(int,int,Node);
Node xor(Node,Node,comparision);