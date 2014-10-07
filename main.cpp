# include <iostream>
# include <conio.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

using namespace std;

struct Node
{
    int x;
    Node * next;
};

class Spisok
{
private:
    Node *a,*b;
public:
    void pop(int t);
    int push(int &t);

    Spisok()
    {
        a=nullptr;
        b=nullptr;
    }

    ~Spisok ()
    {
		while (a!=nullptr)
		{
			Node *p;
			p=a->next;
			delete a;
			a=p;
		}
    }
};

void Spisok::pop(int t)
{
    if((a==nullptr)&&(b==nullptr))
    {
        b=new Node;
        b->next=b;
        b->x=t;
        a=b;
    }
    else
    {
        Node *p;
        p=new Node;
        p->x=t;
        p->next=a;
        a=p;
		delete p;
    }
}

int Spisok::push(int &t)
{
    if(a!=b)
    {
        Node *p;
		p=a;
        while(p->next!=b)
        {
            p=p->next;
        }
        t=b->x;
        p->next=b->next;
        delete b;
        p=b;
        return 0;
    }
    else
        if((a==b)&&(b!=nullptr))
    {
        t=b->x;
        delete b;
        b=nullptr;
        a=b;
        return 0;
    }
    else
        if((a==b)&&(b==nullptr))
    {
        return -1;
    }
}



int main()
{
    Spisok n;
    Node m;
    int t;
    int k=0;
    int rez;
    cout<<"1-Enter the element\n"
		<<"2-Delete the element\n"
		<<"3-Exit\n";
	while(1)
	{
    cin>>k;
	if(k==3)
		break;
    switch (k)
	{
case 1:
    cout<<"Enter the element:\n";
    cin>>t;
    n.pop(t);
    break;
case 2:
    rez=n.push(t);
    if(rez==0)
    cout<<"Dlete element is "<<t;
    else
        cout<<"No element";
    break;
case 3:
    break;
	}
	}
    getch();
    return 0;

}
