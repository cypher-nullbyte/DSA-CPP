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
8. Reverse the contents of the list.
*/
//-----------SOLUTION------------
#include<iostream>
#include<limits>
#include<conio.h>       //for getch
class NODE
{
private:
    double data;
    NODE* next;
public:
    NODE()
    {
        data=0.0;
        next=NULL;
    }
    NODE(double d)
    {
        data=d;
        next=NULL;
    }
    friend class SLList;
};
class SLList
{
private:
    NODE* head;
    NODE* tail;
public:
    SLList()
    {
        head=NULL;
        tail=NULL;
    }
    void addFirst(double val)
    {
        NODE* temp=new NODE(val);
        if(head!=NULL)
            temp->next=head;
        else
            tail=temp;
        head=temp;
    }
    void addLast(double val)
    {
        NODE* temp=new NODE(val);
        if(head!=NULL)
            tail->next=temp;
        else
            head=temp;
        tail=temp;
    }
    double delLast()
    {
        if(tail!=NULL)
        {
            if(head!=tail)
            {
                NODE* temp=head;
                NODE* prev=NULL;
                NODE* prev2=NULL;
                while(temp!=NULL)
                {
                    prev2=prev;
                    prev=temp;
                    temp=temp->next;
                }
                double d=prev->data;
                delete prev;            // deleting the node :)
                prev2->next=NULL;
                tail=prev2;
                return d;
            }
            double d=head->data;
            tail=NULL;
            NODE *temp=head;
            delete temp;
            head=NULL;
            return d;

        }
        return std::numeric_limits<double>::infinity();
    }

    double delFirst()
    {
        if(head!=NULL)
        {

            if(head!=tail)
            {
                double d=head->data;
                NODE* temp=head;
                head=head->next;
                delete temp;
                return d;
            }
            double d=head->data;
            NODE *temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
            return d;

        }
        return std::numeric_limits<double>::infinity();
    }
    double delAt(unsigned int I)
    {
        if(head==tail && head!=NULL)
        {
            double d=head->data;
            NODE *temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
            return d;
        }
        else if(I==0)
        {
            NODE *temp=head;
            head=head->next;
            double d=temp->data;
            delete temp;
            return d;
        }
        NODE* temp=head;
        NODE* prev=NULL;
        for(int i=0;i<I;i++)
        {   if(temp==NULL)
                return std::numeric_limits<double>::infinity();
            prev=temp;
            temp=temp->next;
        }
        double d=temp->data;
        prev->next=temp->next;

        if(temp->next==NULL)
            tail=prev;
        delete temp;
        return d;
    }

    double addAfter(int I,double val)  // note that we assume index start from '0'
    {
        //if we want to insert at starting
        if(I==-1)
        {
            NODE *temp=new NODE(val);
            temp->next=head;
            head=temp;
            if(tail==NULL)
                tail=head;
            return temp->data;
        }
        //if invalid -ve index
        else if(I<-1)
            return std::numeric_limits<double>::infinity();
        //general case
        NODE* pt=head;
        NODE* temp=new NODE(val);
        for(int i=0;i<I;i++)
        {
            if(pt==NULL) // to check if iterator{i} is running out of SLList
            {
                delete temp;
                return std::numeric_limits<double>::infinity();
            }
            pt=pt->next;
        }
        temp->next=pt->next;
        pt->next=temp;

        if(temp->next==NULL)
            tail=temp;

        return temp->data;
    }
    void display()
    {
        NODE* temp=head;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<'\t';
            temp=temp->next;
        }std::cout<<std::endl;
    }
    void reversea()
    {
        NODE* current=head;
        NODE* prev=NULL;
        NODE* forw;
        tail=head;

        while(current!=NULL)
        {
            forw=current->next;
            current->next=prev;
            prev=current;
            current=forw;

        }
        head=prev;
    }

    ~SLList()
    {
        NODE* temp=head;

        while(temp!=tail)
        {
            NODE* forw=temp;
            temp=temp->next;
            head=temp;
            delete forw;
        }
        tail=NULL;
        head=NULL;
        delete temp;

    }

};

// Driver function
int main()
{
SLList *l1=new SLList();
l1->display();
l1->addFirst(11.1);
l1->addFirst(12.2);
l1->addFirst(13.3);
l1->addLast(14.4);
l1->addLast(15.5);
l1->addLast(16.6);
l1->delFirst();
l1->delLast();
l1->display();
l1->delAt(2);
l1->addAfter(1, 1000.1);
l1->display();
l1->reversea();
l1->display();
l1->~SLList();  // let us delete l1
l1->display();  // To check if it is really deleted from our database.
SLList *l2=new SLList();
l2->addAfter(-1,12);
l2->addFirst(11);
l2->addLast(14);
l2->display();
l2->delAt(0);
l2->reversea();
l2->display();
l2->~SLList();
l2->display();
getch();
return 0;
}
