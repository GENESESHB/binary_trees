![binary_trees](https://th.bing.com/th/id/R.15aa133c85db433d294aa0ed5d161840?rik=4nB33wnQDDrSvg&pid=ImgRaw&r=0)
# binary_trees

# TASKS 🔋💻

``firstly y shold create a new-node with empty shield``

```c
#include <stdlib.h>
#include "binary_trees.h"
```
- This part of the code includes the necessary headers. `stdlib.h` is included for the `malloc` function, and `"binary_trees.h"` is included to access the structures and functions related to binary trees.

```c
/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
```
- This marks the beginning of the `binary_tree_node` function definition. This function creates a new binary tree node. The comments above the function describe the parameters and the expected behavior.

```c
{
    binary_tree_t *new_node;
```
- Declaration of a variable `new_node` that will be used to store the address of the newly created node.

```c
    new_node = malloc(sizeof(binary_tree_t));
```
- The `malloc` function allocates memory for a new binary tree node, with a size equivalent to that of the `binary_tree_t` structure.

```c
    if (new_node == NULL)
        return (NULL);
```
- Checks if the memory allocation was successful. If `new_node` is equal to `NULL`, it means the allocation failed. In this case, the function returns `NULL` to indicate failure.

```c
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
```
- These lines initialize the fields of the new node:
  - `n`: Stores the value of the node.
  - `parent`: Points to the parent node specified as a parameter.
  - `left` and `right`: Initialized to `NULL`, as the new node doesn't have any children yet.

```c
    return (new_node);
```
- The function returns a pointer to the newly created node, now that all its fields have been properly initialized.

```c
}
```
- End of the `binary_tree_node` function definition.

In summary, this code defines a `binary_tree_node` function that creates a new binary tree node with the specified parent and value. The node is dynamically allocated in memory, its fields are initialized, and a pointer to the node is returned.

# 1️⃣
 ``insert new-node in left``

```c
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
```
This is the function declaration. It takes a pointer to a `binary_tree_t` node called `parent` and an integer `value`. It returns a pointer to a `binary_tree_t` node, which is the newly created node or `NULL` in case of failure.

```c
{
    binary_tree_t *new_node;
```
Here, a new pointer to a `binary_tree_t` node named `new_node` is declared. This will be used to create the new node to insert.

```c
    if (parent == NULL)
        return (NULL);
```
This line checks if the provided `parent` pointer is `NULL`. If it is, then it's not possible to insert a new left child, so the function immediately returns `NULL`.

```c
    new_node = binary_tree_node(parent, value);
```
This line creates a new binary tree node using the `binary_tree_node` function. It passes `parent` as the parent of the new node and `value` as the value to store in the new node. The resulting node is assigned to the `new_node` pointer.

```c
    if (new_node == NULL)
        return (NULL);
```
Here, it's checked if the `new_node` creation was successful. If it's not, the function returns `NULL` to indicate failure.

```c
    if (parent->left != NULL)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }
```
This block of code handles the case where the parent node already has a left child. If that's the case, the current left child of the parent is assigned as the left child of the `new_node`. Additionally, the parent of the original left child is updated to point to the `new_node`.

```c
    parent->left = new_node;
```
This line updates the `parent` node's left child pointer to point to the newly created `new_node`, effectively inserting it as the left child.

```c
    return (new_node);
```
Finally, the function returns a pointer to the `new_node`, indicating that the insertion was successful.

# 2️⃣
```c

        its a some works in tasks 1 
             change left with rieght
```

# 3️⃣


```c
void binary_tree_delete(binary_tree_t *tree)
```

This is the function declaration. It's a `void` function, which means it doesn't return any value. It takes a pointer to a `binary_tree_t` node named `tree` as input. This pointer should point to the root of the binary tree that you want to delete.

```c
{
    if (tree == NULL)
        return;
```

This block of code checks if the input `tree` pointer is `NULL`. If it's `NULL`, it means there's nothing to delete, so the function simply returns, effectively doing nothing.

```c
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
```

These two lines are recursive calls to the `binary_tree_delete` function. They are responsible for deleting the left and right subtrees of the current node. By making these recursive calls, the function ensures that all nodes in the tree are traversed and deleted.

```c
    free(tree);
```

After the recursive calls, the function reaches this line, which frees the memory 

# 4️⃣

```c
int binary_tree_is_leaf(const binary_tree_t *node)
```

This is the function declaration. It returns an integer (1 or 0) and takes a constant pointer to a `binary_tree_t` node named `node` as input. This pointer refers to the node that you want to check if it's a leaf or not.

```c
{
    if (node == NULL)
        return (0);
```

This block of code checks if the input `node` pointer is NULL. If it's NULL, it means there's no node to check, so the function returns 0 to indicate that a NULL node is not a leaf.

```c
    return (node->left == NULL && node->right == NULL);
```

This line is the return statement of the function. It checks if both the `left` and `right` pointers of the given `node` are NULL. If both pointers are NULL, it means that the node doesn't have any children, and thus the node is a leaf. In this case, the function returns 1, indicating that the node is a leaf. If at least one of the pointers is not NULL, the node has children and is not a leaf, so the function returns 0

