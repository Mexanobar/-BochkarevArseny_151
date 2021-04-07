#include <iostream>
#include <vector>
#include <algorithm>

class tree
{
private:
    struct node
    {
        int key;
        node* parent = NULL;
        node* heir1 = NULL;
        node* heir2 = NULL;

        node(int k, node* par = NULL, node* h1 = NULL, node* h2 = NULL);
    };
    node * p;
    void destroy_tree(node *leaf);
    void sort(node* leaf);
    void bfs(std::vector< std::vector<int> > &V, int depth=0, node*pv = NULL);

public:
    void destroy_tree();
    tree(int k);
    ~tree();
    void insert(int k);
    bool find(int k);
    std::vector <int> sort();
    void bfs();
};

tree::node::node(int k, node* par, node* h1, node* h2)
{
    this->key = k;
    this->parent = par;
    this->heir1 = h1;
    this->heir2 = h2;
}

tree::tree(int k)
{
    p = new node(k, NULL, NULL, NULL);
}

tree::~tree(){
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


void tree::insert(int k)
{
    node * tmp = p;
    while ((tmp->heir1 != NULL) || (tmp->heir2 != NULL))
    {
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

    node *new_node = new node(k, tmp, NULL, NULL);
    new_node->key = k;

    if (k < tmp->key)
        tmp->heir1 = new_node;
    else
        tmp->heir2 = new_node;
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
};

void tree::sort(node* leaf)
{
    if (leaf != NULL)
    {
        if (leaf->heir1 != NULL)
            sort(leaf->heir1);
        std::cout << leaf->key << " ";
        if (leaf->heir2 != NULL)
            sort(leaf->heir2);
    }
}

std::vector <int> tree::sort()
{
    sort(p);
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

    std::cin >> k;
    new_t.insert(k);

    std::cin >> k;
    new_t.insert(k);

    std::cin >> k;
    new_t.insert(k);

    new_t.sort();


    return 0;
}
