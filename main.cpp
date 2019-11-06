#include <iostream>

using namespace std;
//using  branch 1
class Node
{
private:
int data;
Node *left;
Node *right;
int height;
public:
Node(int);
void set_data(int);
int get_data();
void set_left(Node*);
Node* get_left();
void set_right(Node*);
Node* get_right();
void set_height(int);
int get_height(Node*);
};
Node::Node(int data)
{
        this->data=data;
        left=NULL;
        right=NULL;
        height=1;
}
void Node::set_data(int data)
{
        this->data=data;
}
int Node::get_data()
{
        return data;
}
void Node::set_left(Node *ptr)
{
        left=ptr;
}
Node* Node::get_left()
{
        return left;
}
void Node::set_right(Node *ptr)
{
        right=ptr;
}
Node* Node::get_right()
{
        return right;
}
void Node::set_height(int height)
{
    this->height=height;
}
int Node::get_height(Node *temp)
{
	if (temp == NULL)
		return 0;
	return temp->height;
}
class Avl
{
  private:
  Node *root;
  public:
  Avl();
  void add_node(int);
  Node* help_add_node(Node*,int);
  void display();
  void display_help(Node*);
  int max(int a, int b);
  int get_bal(Node*);
  Node* left_rotation(Node*);
};
Avl::Avl()
{
    root=NULL;
 }
void Avl::add_node(int data)
{
  root=help_add_node(root,data);
}
Node* Avl::help_add_node(Node *temp,int data)
{
    if(temp==NULL)
    {
        Node *temp=new Node(data);
        return temp;
    }
    else if(data<temp->get_data())
    {
        temp->set_left(help_add_node(temp->get_left(),data));
    }
    else if(data>temp->get_data())
    {
        temp->set_right(help_add_node(temp->get_right(),data));
    }
    else
        return temp;
        temp->set_height(1+max(temp->get_height(temp->get_left()),temp->get_height(temp->get_right())));
        int bal=get_bal(temp);
        if(bal==-2&&data>temp->get_data()&&data>temp->get_right()->get_data())
                temp=left_rotation(temp);
        return temp;
 }
void Avl::display()
{
        Node *temp=root;
        if(temp==NULL)
        {
                cout << "Avl tree is empty\n";
        }
        else
        {
                display_help(temp);
        }
}
void Avl::display_help(Node *temp)
{
        if(temp==NULL)
        {
                return;
        }
        cout << temp->get_data() << endl;
        display_help(temp->get_left());
        display_help(temp->get_right());
}
int Avl::max(int a, int b)
{
	return (a > b)? a : b;
}
int Avl::get_bal(Node *temp)
{
    if(temp==NULL)
    return 0;
    return temp->get_height(temp->get_left())-temp->get_height(temp->get_right());
}
Node* Avl::left_rotation(Node *temp)
{
    Node *temp2=temp->get_right();
    Node *temp3=temp2->get_left();
    temp2->set_left(temp);
    temp->set_right(temp3);
    temp2->set_height(1+max(temp2->get_height(temp2->get_left()),temp2->get_height(temp2->get_right())));
    temp->set_height(1+max(temp->get_height(temp->get_left()),temp->get_height(temp->get_right())));
    cout << "We are done\n";
    return temp2;
}
int main()
{
        Avl object;
        while(true)
        {
                int option,input;
                cout << "****************************************\n";
                cout << "Enter 1 for insert value in Avl tree\n";
                cout << "Enter 2 for display\n";
                cout << "Enter 3 for search value in Avl tree\n";
                cout << "Enter 4 for remove value in Avl tree\n";
                cout << "****************************************\n";
                cin >> option;
                if(option==1)
                {
                        cout << "Enter value to insert in Avl tree\n";
                        cin >> input;
                        object.add_node(input);
                }
                 else if(option==2)
                {
                        object.display();
                }
             /*  else if(option==3)
                {
                        cout << "Enter value you want to search\n";
                        cin >> input;
                        object.search_help(input);
                }
                else if(option==4)
                {
                        cout << "Enter value you want to remove\n";
                        cin >> input;
                        object.help_to_remove(input);
                }
                */
        }
}
