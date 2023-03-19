### root root->left root->right 
breadth first search
queue store same level 
> 1. q [3] 3->left 3->right
> 2. q.size() --> search root left and right and store in queue
> 3. store this root value to this temp array as level
> 4. pop
> 5. repeat until queue is empty