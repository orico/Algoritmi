#include <stdlib.h>

typedef struct forest_node_t {
    void* value;
    struct forest_node_t* parent;
	int rank;
} forest_node;

typedef struct{
	forest_node** sets;
	int num_elements;
} forest;

forest* Make_Forest(forest* f, int num_sets){
	f = (forest*) malloc(sizeof(forest));
	if(f == NULL){
		perror("Spazio non sufficiente!\n");
		exit(1);
	}
	f->sets = (forest_node**) malloc(num_sets * sizeof(forest_node));
	f->sets = 0;
	return f;
}

forest_node* MakeSet(forest* F, void* value) {
	forest_node* node;
	F->sets[F->num_elements] = (forest_node*) malloc(sizeof(forest_node));
    node = F->sets[F->num_elements++];	
    node->value = value;
    node->parent = NULL;
	node->rank = 0;
    return node;
}

forest_node* Find(forest_node* node) {
    while (node->parent != NULL) {
        node = node->parent;
    }
    return node;
}

/* Given the root elements of two trees, merge the trees into one tree balancing them on rank*/
void Union(forest_node* node1, forest_node* node2) {
    if(node1->rank > node2->rank)
		node2->parent = node1;
	else{
		if(node1->rank < node2->rank){
			void* exchange_tmp;
			node1->parent = node2;
			exchange_tmp = node1->value;
			node1->value = node2->value;
			node2->value = exchange_tmp;
		}
		else{
			node2->parent = node1;
			node1->rank++;
		}
	}
}

