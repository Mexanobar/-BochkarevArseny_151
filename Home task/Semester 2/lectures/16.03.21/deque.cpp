struct deque
{
    private:
        struct node 
        {
            int data;
            node *next;
            node *prev;
 
            node(int i, node *n = NULL, node *p = NULL) : data(i), next(n), prev(p) {}
        };
 
        int size;
        node *first;
        node *last;
 
    public:
        deque();
        ~deque();

        int head() const;
        int tail() const;
        int size();

        void push_front(int k);
        void push_back(int k);

        int pop_front();
        int pop_back();

        void print();
        void clear();
 
};