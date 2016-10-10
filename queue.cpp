#include<iostream>
#include<cstring>
using namespace std;

struct sinhvien{
	string name;
	int ID;
};

void nhap(sinhvien &sv){
	cout<<"nhap thong tin sv"<<endl;
	cout<<"ID  : ";
	cin>>sv.ID;
	cout<<"name: ";//enter coi nhu bo trong
	fflush(stdin);
	getline(cin,sv.name);
}

struct node{
	node *next;
	sinhvien data;
};

struct queue{
	node *first, *last;
	int dem;
};

void init(queue &q){
	q.first = q.last = NULL;
	q.dem = 0;
}

int empty(queue q){
	if(q.dem == 0)
		return 1;
	return 0;
}

void push(queue &q, sinhvien sv){
	node *p = new node;
	if(p == NULL){
		cout<<"ko du bo nho";
		return;
	}
	nhap(sv);
		p -> data.name = sv.name;
		p -> data.ID = sv.ID;
		p -> next = NULL;
	if(empty(q)){
		q.first = q.last = p;
	}
	else {
		q.last -> next = p;
		q.last = p;
	}
	q.dem++;
}

void pop(queue &q){//xem sv o dau , ko xoa
	if(!empty(q)){
		cout<<"sv o dau queue la: "<<endl<<"ID  : "<<q.first -> data.ID<<endl<<"name: "<<q.first -> data.name<<endl;
	}
	else cout<<"queue rong"<<endl;
}

void del(queue &q){//xem sv o dau va xoa luon sv do
	if(!empty(q)){
		cout<<"sv o dau queue la: "<<endl<<"ID  : "<<q.first -> data.ID<<endl<<"name: "<<q.first -> data.name<<endl;
		q.first = q.first -> next;
		q.dem --;
	}
	else cout<<"queue rong"<<endl;
}

void showAll(queue q){// hien thi tat ca sv
	node *p = q.first;
	int i = 1;
	while(p != NULL){
		cout<<i<<": "<<p -> data.ID<<endl;
		cout<<"   "<<p -> data.name<<endl;
		p = p -> next;
		i++;
	}
	if(i == 1){
		cout<<"queue rong"<<endl;
	}
}

void searchID(queue q, int x){
	node *p = q.first;
	int t = 0;
	while(p != NULL){		
		if(p -> data.ID == x){
			t = 1;
			cout<<"ten: "<<p -> data.name<<", tuoi: "<<p -> data.ID<<endl;
		}
		p = p -> next;
	}
	if(t == 0) cout<<"ko thay"<<endl;
}

void destroyQueue(queue &q){//xoa het
	node *p;
	if (!empty(q))
     {
         while(q.first != NULL)
         {
             p = q.first -> next;
             delete q.first;
             q.first = p;
         }
         q.first = q.last = NULL;
     }
}

main(){
	queue q;
	init(q);
	sinhvien sv;
	
	int chon;
	while(1){
		cout<<"1: them 1 sv vao dinh queue \n2: lay 1 sv tu dau queue \n3: lay 1 sv tu dau queue va xoa sv do\n4: show all\n5: search ID\n6: xoa het sv"<<endl;
		cin>>chon;
		switch(chon){
			case 1:{
				push(q,sv);
				break;
			}
			case 2:{
				pop(q);
				break;
			}
			case 3:{
				del(q);
				break;
			}
			case 4:{
				showAll(q);
				break;
			}
			case 5:{
				int x;
				cout<<"nhap ID tim: ";
				cin>>x;
				searchID(q,x);
				break;
			}
			case 6:{
				destroyQueue(q);
				break;
			}
		}	
	}
}

