// AVL trees with the rotation
/*
AVL tree in C program is defined as an algorithm that is written in C programming language, 
of the AVL tree is a self-balancing Binary Search Tree named after the inventors Adelson, 
Velski & Landis where the left and the right nodes of the tree are balanced. 
*/

#include <stdio.h>
#include <stdlib.h>

struct tree_node_type {
    int value;
    struct tree_node_type* left;
    struct tree_node_type* right;
	int height;
};

/*
In the process of left rotation, the right child of a node “A”, say “B” becomes the parent node of “A” and the corresponding left child of “B” becomes the right child of “A”. 
On the other hand, the right rotation is just the vice versa of the left and is done specifically when the left side’s height is significantly more than the right side.
Refer to the pictures from your notes
*/
typedef struct tree_node_type node;

node* construct_node(int value) {
    node* construct = malloc(sizeof(node));

    construct -> value = value;
    construct -> left = NULL;
    construct -> right = NULL;
	construct -> height = 1;

    return construct;
}
//https://www.programiz.com/dsa/avl-tree - refer to images here for concept / or notes


int get_height(node* root) {
	if (!root) {
		return 0;
	}
	return root -> height;
}

node* set_height(node* root) {
	root -> height = 1 + (get_height(root -> left) > get_height(root -> right) ? get_height(root -> left) : get_height(root -> right));
	return root;
}

int get_balance(node* root)
{
	if (!root) {
		return 0;
	}
	int balance = get_height(root -> left) - get_height(root -> right);
	return balance;
}


/*
// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}
*/

node* right_rotate(node* root) {
	node* left_node = root -> left;
	node* right_node = left_node -> right;

	left_node -> right = root;
	root -> left = right_node;

	root = set_height(root);
	left_node = set_height(left_node);

	return left_node;
}

/*
// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}
*/

node* left_rotate(node* root) {

	node* right_node = root -> left;
	node* left_node = right_node -> right;

	right_node -> left = root;
	root -> right = left_node;

	root = set_height(root);
	right_node = set_height(right_node);

	return right_node;
}

/*
// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}
*/


node* insert(node* root, int value) {

    if (!root) {
        return construct_node(value);
    } 
	else if (value < root -> value) {
        root -> left = insert(root -> left, value);
    } 
	else if (value > root -> value ) {
        root -> right = insert(root -> right, value);
    }

	root = set_height(root);

	int balance = get_balance(root);

	if (balance > 1 && value < root -> left -> value) {
		return right_rotate(root);
	}
	if (balance < -1 && value > root -> right -> value) {
		return left_rotate(root);
	}
	if (balance > 1 && value > root -> left -> value) {
		root -> left = left_rotate(root -> left);
		return right_rotate(root);
	}
	if (balance < -1 && value < root -> right -> value) {
		root -> right = right_rotate(root -> right);
		return left_rotate(root);
	}

    return root;
}

//having node create tree here
node* create_tree(int* array, int length) {

    node* root = NULL;

    if (length != 0) {

        root = construct_node(array[0]);

        for (int i = 0; i < length; i++) {
            root = insert(root, array[i]);
        }
    }

    return root;
}

/*
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}
*/


void print_inorder(node* root) {

	if(root -> left) {
        printf("(");
        print_inorder(root -> left);
        printf(")");
    }

    if (root) {
        printf(" %d ", root -> value);
    }

    if (root -> right) {
        printf("(");
        print_inorder(root -> right);
        printf(")");
    }
}

//printng here returning void tho - just function declaration as we will see 

void print_preorder(node* root) {

    if (root) {
        printf("%d, ", root -> value);

		if(root -> left) {
			print_preorder(root -> left);
		}

		if (root -> right) {
			print_preorder(root -> right);
		}
    }
}

node* search(node* root, int value) {

    if (!root) {
        return root;
    }
	else if (value < root -> value) {
        return search(root -> left, value);
    }
	else if(value > root -> value ) {
        return search(root -> right, value);
    }
	else {
        return root;
    }
}



node* get_minimum(node* root) {

    node* current = root;

    if (!(current -> left)) {
        return current;
    }
	else {
        return get_minimum(current -> left);
    }
}


/*
// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}
*/

node* delete(node* root, int value) {
    
	if (!root) {
        return root;
    }
	else if (value > root -> value) {
        root -> right = delete(root -> right, value);
    }
	else if (value < root -> value) {
        root -> left = delete(root -> left, value);
    }
	else {
        node* _ = NULL;

        if (!(root -> left) && !(root -> right)) {
            free(root);
            return _;
        }
		else if (!(root->left)) {
            _ = root -> right;
            free(root);
            return _;
        }
		else if (!(root->right)) {
            _ = root -> left;
            free(root);
            return _;
        }
		else {
            node* successor = get_minimum(root);
            root -> value = successor -> value;
            free(successor);
        }
    }

    return root;
}

int main() {

	int size = 7;
	int* array = create_array(size);
	print_array(array, size);

    node* root = create_tree(array, size);
    print_inorder(root);
	printf("\n");

    return 0;
}

/*
/ Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
*/