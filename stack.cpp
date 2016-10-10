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

struct stack{
	node *top;
};

void init(stack &s){// khoi tao stack rong
	s.top = NULL;
}

int empty(stack s){//kt rong
	if(s.top == NULL)
		return 1;
	return 0;
}

void push(stack &s, sinhvien &sv){//them sv vao dinh
	node *p = new node;
	if(p == NULL){
		cout<<"ko du bo nho";
		return;
	}
	nhap(sv);
		p -> data.name = sv.name;
		p -> data.ID = sv.ID;
		p -> next = NULL;
	if(s.top == NULL){
		s.top = p;
	}
	else {
		p -> next = s.top;
		s.top = p;
	}	
}

void peek(stack &s){//xem sv o dinh , ko xoa
	if(!empty(s)){
		cout<<"sv o dinh stack la\nID  : "<<s.top -> data.ID<<endl;
		cout<<"name: "<<s.top -> data.name<<endl;
	}
	else cout<<"stack rong"<<endl;
}

void pop(stack &s){//xem sv o dinh va xoa luon sv do
	if(!empty(s)){
		cout<<"sv o dinh stack la\nID  : "<<s.top -> data.ID<<endl;
		cout<<"name: "<<s.top -> data.name<<endl;	
		s.top = s.top -> next;
	}
	else cout<<"stack rong"<<endl;
}

void showAll(stack s){// hien thi tat ca sv
	node *p = s.top;
	int i = 1;
	while(p != NULL){
		cout<<i<<": "<<p -> data.ID<<endl;
		cout<<"   "<<p -> data.name<<endl;
		p = p -> next;
		i++;
	}
	if(i == 1) cout<<"stack rong"<<endl;
}

void searchID(stack s, int x){//tim theo tuoi
	node *p = s.top;
	int t = 0;
	while(p != NULL){
		if(p -> data.ID == x){
			t = 1;
			cout<<"ID: "<<p -> data.ID<<", name: "<<p -> data.name<<endl;
		}
		p = p -> next;
	}
	if(t == 0) cout<<"ko ton tai"<<endl;
}

//void searchName(stack s, string x){//tim kiem theo ten
//	node *p = s.top;
//	int t = 0;
//	const char * string1 = x.c_str();
//	const char * string2 = (p -> data.name).c_str();
//	while(p != NULL){
//		if(strcmp(string1, string2) == 0){
//			t = 1;
//			cout<<"ID   : "<<p -> data.ID<<", name: "<<p -> data.name<<endl;
//			p = p -> next;
//		}
//		else{
//			p = p -> next;
//		}		
//	}
//	if(t == 0) cout<<"ko ton tai"<<endl;
//}

void destroyStack(stack &s){//xoa het
	node *p;
	while(!empty(s)){
		p = s.top -> next;
		delete s.top;
		s.top = p;
	}
}

void delID(stack &s, int x){
	node *p = s.top;
	while(p != NULL){
		if(p -> data.ID == x){
			delete
				p -> data.ID;
				p -> data.name;
			
			p -> next;
			
		}
	}
}

main(){
	stack s;
	init(s);
	sinhvien sv;
	
	int chon;
	while(1){
		cout<<"1: them 1 sv vao dinh stack \n2: lay 1 sv tu dinh stack \n3: lay 1 sv tu dinh stack va xoa sv do\n4: show all sinh vien\n5: search ID\n6: search name\n7: destroy stack"<<endl;
		cin>>chon;
		switch(chon){
			case 1:{
				push(s,sv);
				break;
			}
			case 2:{
				peek(s);
				break;
			}
			case 3:{
				pop(s);
				break;
			}
			case 4:{
				showAll(s);
				break;
			}
			case 5:{
				int t;
				cout<<"nhap ID tim: ";
				cin>>t;
				searchID(s,t);
				break;
			}
//			case 6:{
//				string t;
//				fflush(stdin);
//				getline(cin,t);
//				searchName(s,t);
//				break;
//			}
			case 7:{
				destroyStack(s);
				break;
			}
		}	
	}	
}

