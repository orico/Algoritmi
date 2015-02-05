   #include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//we represent each partition using a tree. The nodes of the tree have no child pointers, but do have parent pointers.
typedef struct forest_node_simple_t
{
    void* value;
    struct forest_node_simple_t* parent;
    int rank;
} forest_node_simple;

forest_node_simple* MakeSet(void* );
void Union(forest_node*, forest_node*);

int main()
{
    int *v,n,i;
    forest_node_simple_t *s;


    for(i=0; i<n; i++)
    {
        s[i]=MakeSetSimple(&v[i]);
    }

    system("pause");
    return 0;
}

//Create a new partition containing a single given element.
forest_node_simple* MakeSet(void* value)
{
    forest_node_simple* node = malloc(sizeof(forest_node_simple));
    node->value = value;
    node->parent = NULL;
    node->rank=0;
    return node;
}


void Union(forest_node* node1, forest_node* node2)
{
    // they are different. We attach the tree with smaller rank to the root of the tree with larger rank.
    if (node1->rank > node2->rank)
    {
        node2->parent = node1;
    } else if (node2->rank > node1->rank)
      {
        node1->parent = node2;
      } else
        { /* they are equal */
          node2->parent = node1;
          node1->rank++;
        }
}
