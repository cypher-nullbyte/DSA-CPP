// ---------DEMAND---------------
/*
Create a linked list of double variables with following
functionalities :
1. Adding a node at the start of the list.
2. Adding a node at the end of the list.
3. Deleting a node at the end of the list.
4. Deleting head node of the list.
5. Deleting the ith node in the list.
6. Adding a node after the ith node in the list.
7. Displaying the contents of the list.
8. Displaying the contents of the list in reverse_order.
9. Reverse the contents of the list.
*/
//-----------SOLUTION------------
#include<iostream>
#include<limits>

class NODE
{
private:
    double data;
    NODE* next;
    NODE* prev;
public:
    NODE()
    {
        data = 0.0;
        next = NULL;
        prev=NULL;
    }
    NODE(double d)
    {
        data = d;
        next = NULL;
        prev=NULL;
    }
    friend class DLList;
};
class DLList
{
private:
NODE* head;
NODE* tail;
public:
DLList()
{
    head= NULL;
    tail = NULL;
}
//Adding a node at the start of the list.
void addFirst(double val)
{
    NODE* temp=new NODE(val);
    if(head!=NULL)
    {
        head->prev=temp;
        temp->next=head;
    }
    else
        tail=temp;
    head=temp;
}
//Adding a node at the end of the list.
void addLast(double val)
{
    NODE *temp=new NODE(val);
    if(head!=NULL)
    {
        tail->next=temp;
        temp->prev=tail;
    }
    else
        head=temp;
    tail=temp;
}
//Deleting a node at the end of the list.
double delLast()
{
    NODE *temp=tail;
    if(head!=NULL)
    {
        double d=temp->data;
        if(head==tail)
        {
            head=NULL;
            tail=NULL;
            delete temp;
            return d;
        }
        tail=temp->prev;
        tail->next=NULL;
        delete temp;
        return d;
    }
    return std::numeric_limits<double>::infinity();
}
//Deleting head node of the list.
double delFirst()
{
    NODE *temp=head;
    if(head!=NULL)
    {
        double d=temp->data;
        if(head==tail)
        {
            head=NULL;
            tail=NULL;
            delete temp;
            return d;
        }
        head=temp->next;
        head->prev=NULL;
        delete temp;
        return d;
    }
    return std::numeric_limits<double>::infinity();
}
//Deleting the ith node in the list.
double delAt(unsigned int I)
{
    if(head!=NULL)
    {
    NODE *temp=head;
    for(int i=0;i<I;i++)
    {
        if(temp==NULL)
            return std::numeric_limits<double>::infinity();
        temp=temp->next;
    }
    if(temp->prev!=NULL &&temp->next!=NULL)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    else if(temp->next!=NULL && temp->prev==NULL)
    {
        temp->next->prev=NULL;
        head=temp->next;

    }
    else
    {
        temp->prev->next=NULL;
        tail=temp->prev;
    }

    double d=temp->data;
    delete temp;
    return d;
    }
    return std::numeric_limits<double>::infinity();
}
//Adding a node after the ith node in the list.
double addAfter(int I, double val)
{
    NODE *temp=new NODE(val);
    if(I==-1)
    {
        if(head==tail && head==NULL)
        {
            head=temp;
            tail=temp;
            return val;
        }
        temp->next=head;
        head->prev=temp;
        head=temp;
        return val;
    }
    else if(I<-1)
        return std::numeric_limits<double>::infinity();

    NODE *rat=head;
    for(int i=0;i<I;i++)
    {
        if(rat==NULL)
            return std::numeric_limits<double>::infinity();
        rat=rat->next;
    }
    if(rat==NULL)
        return std::numeric_limits<double>::infinity();
    if(rat->next==NULL)
    {
        rat->next=temp;
        temp->prev=rat;
        tail=temp;
        return temp->data;
    }
    else
    {
        temp->prev=rat;
        temp->next=rat->next;
        rat->next->prev=temp;
        rat->next=temp;
        return temp->data;
    }

}
// Displaying the contents of the list.
void display()
{
    NODE* temp=head;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<'\t';
        temp=temp->next;
    }
    std::cout<<std::endl;
}
//Displaying the contents of the list in reverse Order.
void display_rev()
{
    NODE* temp=tail;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<'\t';
        temp=temp->prev;
    }
    std::cout<<std::endl;
}
 void reverse()
 {
    NODE *current=head;
    NODE *nxt;
    while(current!=NULL)
    {
        nxt=current->next;
        current->next=current->prev;
        current->prev=nxt;
        current=nxt;
    }
    current=tail;
    tail=head;
    head=current;
 }
~DLList()
{
    NODE* temp=head;

        while(temp!=tail)
        {
            NODE* forw=temp;
            temp=temp->next;
            temp->prev=NULL;
            head=temp;
            delete forw;
        }
        tail=NULL;
        head=NULL;
        delete temp;
}
};

//Driver method
int main()
{
    DLList *l1 =new DLList();
    l1->addAfter(-1,2);
    l1->addAfter(0,4);
    l1->addLast(6);
    l1->reverse();
    l1->display();
    l1->display_rev();
    l1->reverse();
    l1->addLast(8);
    l1->addFirst(0);
    l1->display();
    l1->delLast();
    l1->display();
    l1->delFirst();
    l1->display();
    l1->display_rev();
    l1->~DLList();
    l1->display(); // Blank line means empty list!
    std::cout<<"END!!";
    return 0;
}
