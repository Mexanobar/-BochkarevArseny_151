#include <iostream>  
#include <vector>


int max(int a, int b)
{
  if (a > b) return a;
  else return b;
}

class tree
{
  private:
    struct node
    {
      int key;
      int height;
      node* parent = NULL;
      node* heir1 = NULL;
      node* heir2 = NULL;

      node(int k, int h = 1, node* par = NULL, node* h1 = NULL, node* h2 = NULL);
    };
    node * p;
    void destroy_tree(node *leaf);  
    friend void fix_Height(node* n);
    friend void rebalance(node* ptr);
    friend void rebalanceLeft(node* ptr); 
    friend void rebalanceRight(node* ptr);
    friend void rotateRight(node* & ptr);
    friend void rotateLeft(node* & ptr);
    void bfs(std::vector< std::vector<int> > &V, int depth=0, node*pv = NULL);
    void change_tree(node * pointer);



  public:
    void destroy_tree();
    tree(int k);
    ~tree();
    void insert(int k);
    bool find(int k); 
    void get_height();
    void bfs();
};

tree::node::node(int k, int h, node* par, node* h1, node* h2)
{
  this->key = k;
  this->height = h;
  this->parent = par;
  this->heir1 = h1;
  this->heir2 = h2;
}

tree::tree(int k)
{
    p = new node(k, 1, NULL, NULL, NULL);
}

tree::~tree()
{
    destroy_tree();
}

void tree::destroy_tree(node *leaf)
{
  if(leaf != NULL)
  {
    destroy_tree(leaf->heir1);
    destroy_tree(leaf->heir2);
    delete leaf;
  }
}

void tree::destroy_tree()
{
    destroy_tree(p);
}


void fix_Height(tree::node* n)
{ 
  while (n->parent != NULL)
  {
    n->height = 1 + max((n->heir1 != NULL) ? n->heir1->height : 0,
      (n->heir2 != NULL) ? n->heir2->height : 0);
    n = n->parent; 
  }
  n->height = 1 + max((n->heir1 != NULL) ? n->heir1->height : 0,
    (n->heir2 != NULL) ? n->heir2->height : 0);
}


void tree::change_tree(tree::node * pointer)
{
	while(pointer->parent != NULL)
		pointer = pointer->parent;
	std::cout << "change_tree(), key == " << pointer->key << "\n";
	this->p = pointer;
}


void tree::insert(int k)
{
  node * tmp = p;
  while ((tmp->heir1 != NULL) || (tmp->heir2 != NULL))
  {
    fix_Height(tmp);
    if (k < tmp->key)
    {
      if (tmp->heir1 != NULL)
        tmp = tmp->heir1;
      else
        break;
    }
    else
    {
      if (tmp->heir2 != NULL)
        tmp = tmp->heir2;
      else
        break;
    }
  } 
  
  node *new_node = new node(k, 1, tmp, NULL, NULL);
  new_node->key = k;


  if (k < tmp->key) 
  {
    tmp->heir1 = new_node; 
    tmp->heir1->parent = tmp;
  }
  else 
  {
    tmp->heir2 = new_node; 
    tmp->heir2->parent = tmp;
  }
  fix_Height(new_node); 

  rebalance(new_node);


  std::cout << "insert(), new_node->key == " << new_node->key << "\n";
  std::cout << "insert(), new_node->parent->key == ";
  if (new_node->parent != NULL)
  {
    std::cout << new_node->parent->key << "\n";
    if (new_node->parent->heir1 != NULL)
  	  std::cout << "insert(), new_node->parent->heir1->key == " << new_node->parent->heir1->key << "\n";
    if (new_node->parent->heir1 != NULL)
  	  std::cout << "insert(), new_node->parent->heir2->key == " << new_node->parent->heir2->key << "\n";
    if (new_node->parent->parent != NULL)
    {
  	  std::cout << "insert(), new_node->parent->parent->key == " << new_node->parent->parent->key << "\n";
      if (new_node->parent->parent->heir1 != NULL)
  	    std::cout << "insert(), new_node->parent->parent->heir1->key == " << new_node->parent->parent->heir1->key << "\n";
      if (new_node->parent->parent->heir2 != NULL)
  	    std::cout << "insert(), new_node->parent->parent->heir2->key == " << new_node->parent->parent->heir2->key << "\n";
    }
  }
  else 
  	 std::cout << "NULL\n";

  this->change_tree(new_node);

}


bool tree::find(int k)
{
  node * tmp = p;
  while ((tmp->heir1 != NULL) || (tmp->heir2 != NULL))
  {
    if (tmp->key == k)
      break;
    if (k < tmp->key)
    {
      if (tmp->heir1 != NULL)
          tmp = tmp->heir1;
      else
          break;
    }
    else
    {
      if (tmp->heir2 != NULL)
          tmp = tmp->heir2;
      else
          break;
    }
  }
  if (tmp->key == k)
    return true;
  return false;
}



void tree::get_height()
{
  std::cout << "height of a tree == " << p->height << "\n";
}


void rebalance(tree::node *ptr)
{
  tree::node* prnt = ptr->parent;

  if (((ptr->heir1 != NULL) ? ptr->heir1->height : 0) > 
   ((ptr->heir2 != NULL) ? ptr->heir2->height : 0) + 1)
    rebalanceRight(ptr);

  if (((ptr->heir2 != NULL) ? ptr->heir2->height : 0) > 
   ((ptr->heir1 != NULL) ? ptr->heir1->height : 0) + 1)
    rebalanceLeft(ptr);
   
  fix_Height(ptr);

  std::cout << " rebalance(), key == " << ptr->key << "\n";


  if (prnt != NULL)
    rebalance(prnt); 
}


void rebalanceRight(tree::node* ptr)
{
  tree::node* left = ptr->heir1;
  if ((left != NULL) && (left->heir2 != NULL))
    if (((left->heir1 != NULL) ? left->heir1->height : 0) > 
    ((left->heir2 != NULL) ? left->heir2->height : 0))
      rotateLeft(left);
  rotateRight(ptr);  
  fix_Height(ptr);
}



void rebalanceLeft(tree::node* ptr)
{
  tree::node* right = ptr->heir2; 
  if ((right != NULL) && (right->heir1 != NULL))
    if (((right->heir2 != NULL) ? right->heir2->height : 0) > 
    ((right->heir1 != NULL) ? right->heir1->height : 0))
      rotateRight(right); 
  rotateLeft(ptr);   
  fix_Height(ptr);
}


void rotateRight(tree::node* & ptr)
{
  tree::node* left = ptr->heir1;
  tree::node* right = ptr->heir2;
  tree::node* left_right = (left != NULL) ? left->heir2 : NULL;

  std::cout << "   rotateRight(), key == " << ptr->key << "\n";
  left->heir2 = ptr;
  left->parent = ptr->parent;
  ptr->parent = left;

  if (left->parent != NULL)
  {
  	if (left->parent->heir1->key == ptr->key)
  		left->parent->heir1 = left;
  	else 
  		left->parent->heir2 = left;
  }

  std::cout << "   rotateRight(), left == " << left->key << "\n";
  std::cout << "   rotateRight(), left->heir1 == " << left->heir1->key << "\n";
  std::cout << "   rotateRight(), left->heir2 == " << left->heir2->key << "\n";
  

  ptr->heir1 = left_right;
  if (ptr->heir1 != NULL)
    ptr->heir1->parent = ptr;

  fix_Height(ptr);
  fix_Height(left);
}


void rotateLeft(tree::node* & ptr)
{
  tree::node* right = ptr->heir2;
  tree::node* left = ptr->heir1;
  tree::node* right_left = (right != NULL ) ? right->heir1 : NULL;
  
  std::cout << "  rotateLeft(), key == " << ptr->key << "\n";
  right->heir1 = ptr;
  right->parent = ptr->parent;
  ptr->parent = right;
  if (right->parent != NULL)
  {
  	if (right->parent->heir1->key == ptr->key)
  		right->parent->heir1 = right;
  	else 
  		right->parent->heir2 = right;
  }

  std::cout << "  rotateLeft(), right == " << right->key << "\n";
  std::cout << "  rotateLeft(), right->heir1 == " << right->heir1->key << "\n";
  std::cout << "  rotateLeft(), right->heir2 == " << right->heir2->key << "\n";
  std::cout << "  rotateLeft(), right->heir1->parent == " << right->heir1->parent->key << "\n";

  ptr->heir2 = right_left;
  if (ptr->heir2 != NULL)
    ptr->heir2->parent = ptr;
  

  fix_Height(ptr);
  fix_Height(right);
}




void tree::bfs(std::vector<std::vector<int> > &V, int depth, node* pv)
{
  if (pv == NULL)
    pv = p;
  //std::cout << "key: " << pv->key << "\n";
  //std::cout << "depth: " << depth << "\n";
  if (depth == V.size()) V.push_back({});
  V[depth].push_back(pv->key);
  if (pv->heir1 != NULL) 
    bfs(V, depth+1, pv->heir1);
  if (pv->heir2 != NULL) 
    bfs(V, depth+1, pv->heir2); 
}

void tree::bfs()
{
  std::vector<std::vector<int> > res;
  bfs(res);
  //std::cout << "qqq\n";
  for (int i = 0; i < res.size(); i++)
  {
  	std::cout << "layer " << i << ": ";
    for (int j = 0; j < res[i].size(); j++)
    {
      std::cout << res[i][j] << " ";
    }
    std::cout << "\n";
  }
}






int main()
{
  int k;
  std::cin >> k;
  tree new_t(k); 

  std::cin >> k;
  new_t.insert(k); 

  std::cout << "\n\n"; 
  new_t.bfs(); 
  std::cout << "\n\n"; 

  std::cin >> k;
  new_t.insert(k); 

  std::cout << "\n\n"; 
  new_t.bfs(); 
  std::cout << "\n\n"; 

  std::cin >> k;
  new_t.insert(k); 

  std::cout << "\n\n"; 
  new_t.bfs(); 
  std::cout << "\n\n"; 

  std::cin >> k;
  new_t.insert(k); 

  std::cin >> k;
  new_t.insert(k); 

  std::cin >> k;
  new_t.insert(k); 


  std::cout << "\n\n"; 
  new_t.bfs(); 
  std::cout << "\n\n"; 

  return 0;
}
