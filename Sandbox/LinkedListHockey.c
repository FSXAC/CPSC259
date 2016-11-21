/*
   VERSION 1:  Example of the use of pointers to create a simple
   linked list of hockey players.

   Here is the sample output from running this code ...

Node 1 is: Wayne Gretzky, Jersey Number 99
There were 1 node(s) in the list.

Node was added.

Node was added.

Node 1 is: Henrik Sedin, Jersey Number 33
Node 2 is: Daniel Sedin, Jersey Number 22
There were 2 node(s) in the list.

Press any key to continue . . .
*/

#include <stdio.h>
#include <stdlib.h>

struct player {
	int              jersey_number;
	char *           name;
	struct player *  next;     /* to link this node to the next node */
};


/* function prototypes */
struct player *  insert_at_head(struct player * head,
  	                            int             player_number,
  	                            char *          player_name);
void display_list(struct player * node);


int main(void) {
  struct player *  head_list1 = NULL;
	struct player *  head_list2 = NULL;

	struct player    gretzky = {99, "Wayne Gretzky", NULL};

	/* Example 1 */
	head_list1 = &gretzky;
	display_list(head_list1);

	/* Example 2 */
	head_list2 = insert_at_head(head_list2, 22, "Daniel Sedin");
	head_list2 = insert_at_head(head_list2, 33, "Henrik Sedin");
	display_list(head_list2);

	system("pause");
	return 0;
}

/* This function adds a new node to the front of the list,
   and returns the new node as the new head. */
struct player *  insert_at_head(struct player * head,
  	                            int             player_number,
  	                            char *          player_name) {
	struct player *  new_node;

	new_node = (struct player *) malloc( sizeof(struct player) );

	new_node->jersey_number = player_number;
	new_node->name = player_name;
	new_node->next = head;   /* point to current head of list */

	printf("Node was added.\n\n");
	return new_node;         /* the new node is the new head */
}


void display_list(struct player * node) {
	int  k = 0;

  /* only stop when node becomes NULL */
	while (node) {
		printf("Node %d is: %s, Jersey Number %d\n",
			    k, node->name, node->jersey_number);
		node = node->next;
		k++;
	}

	printf("There were %d node(s) in the list.\n\n", k);
}
