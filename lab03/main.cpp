# include <iostream>
# include <conio.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

using namespace std;

const int kvant=5;

struct Node
{
    int x;
	int y;
    Node * next;
};

class Spisok
{
private:
    Node *a,*b;
public:
    void pop(int ts,int tk);
    void push(Node *a);
	void shiftpointr();
	void rr(int kol,int &mid);

    Spisok()
    {
        a=nullptr;
        b=nullptr;
    }

    ~Spisok ()
    {
		delete a;
    }
};

void Spisok::pop(int ts,int tk)
{
    if((a==nullptr)&&(b==nullptr))
    {
        b=new Node;
        b->next=b;
        b->x=ts;
		b->y=tk;
        a=b;
    }
    else
    {
        Node *p;
        p=new Node;
        p->x=ts;
		p->y=tk;
        p->next=a;
        a=p;
		b->next=a;
    }
}

void Spisok::push(Node *a)
{
	Node *p;
	p=a;
	while(p!=a->next)
	{
		a=a->next;
	}
	a->next=p->next;
}

void Spisok::shiftpointr()
{
	a=a->next;
	b=b->next;
}

void Spisok::rr(int kol,int &mid)
{
	int sum=0;
	bool nt=true;
	int j=0;
	int p;
	while (nt)
	{
		++j;
		for(int i=0;i<kol;++i)
		{
			p=kvant^j;
			if(a->x<=p)
			{
				sum=sum+kvant;
				a->y=a->y-kvant;
				if(a->y<=0)
				{
					sum=sum-kvant-(a->y);
					push(a);
					if(a=a->next)
					{
						sum=sum+(a->y);
						nt=false;
						i=kol;
					}
				}
			}
			a=a->next;
		}
		mid=sum/kol;
	}
}



int main()
{
    Spisok n;
    Node m;
	
	int kol;
    int ts;
	int tk;
    int mid;
	cout<<"Enter kol-vo elements";
	cin>>kol;
	for(int i=1;i<=kol;++i)
	{
		cout<<"enter time for "<<i<<" element\n";
		cin>>ts;
		cout<<"enter kvant for "<<i<<" element\n";
		cin>>tk;
		n.pop(ts,tk);
	}
	n.rr(kol,mid);
	cout<<"\nmidle effection\n"<<mid;
	getch();
    return 0;

}
