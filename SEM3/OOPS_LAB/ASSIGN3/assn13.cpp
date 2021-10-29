class Node
{
   int data;
   Node *next;
   public:
   Node* get_next()
   {
       return next;
   }
   void set_data(int val);
   void set_next_ptr()
   {
      next=nullptr;
   }
};
void Node::set_data(int val)
{
    data=val;
}
class Linked_List
{
   static Node *head;
   public:
   static Node* get_head()
   {
       return head;
   }
   Linked_List()
   {
       head=nullptr;
   }
   Node* get_head()
   {
       return head;
   }
   void append_Node(int data);
   void insert_At_front(int data);
   void insert_After(int data);
   void print_list();
   void delete_list();
   void delete_element(int value);
};
void Linked_List::append_Node(int data)
{
    Node *node=new Node();
    node->set_data(data);
    node->set_next_ptr();
    if(Linked_List::head==nullptr)
    Linked_List::head=node;
    else
    {
        Node *temp;
        temp=Linked_List::head;
        while(temp->get_next())
        temp=temp->get_next();
        temp->set_next_ptr=node;
        free(temp);
    }
    


}
int main()
{
    return 0;
}