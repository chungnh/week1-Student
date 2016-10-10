#include<iostream>
#include <string>
#include <memory.h>
#include<fstream>

using namespace std;

class sinhvien{
private:
	int id;
	string ten;
	string diachi;
	string gioitinh;
	float toan;
	float ly;
	float hoa;
public:
	void setID(int x){
		id = x;
	}
	int getID(){
		return id;
	}		
	void setTen(string x){
		ten = x;
	}
	string getTen(){
		return ten;
	}		
	void setDiachi(string x){
		diachi = x;
	}		
	string getDiachi(){
		return diachi;
	}		
	void setGioitinh(string x){
		gioitinh = x;
	}		
	string getGioitinh(){
		return gioitinh;
	}		
	void setToan(float x){
		toan = x;
	}		
	float getToan(){
		return toan;
	}
	void setLy(float x){
		ly = x;
	}		
	float getLy(){
		return ly;
	}
	void setHoa(float x){
		hoa = x;
	}		
	float getHoa(){
		return hoa;
	}

	float getTong(){
		return(toan + ly + hoa);
	}

	void nhap(int a, string b, string c, string d, float e, float f, float g);
	void xuat();
};

void sinhvien::nhap(int a, string b, string c, string d, float e, float f, float g){//lay vao 1 sv
	id = a;
	ten = b;
	diachi = c;
	gioitinh = d;
	toan = e;
	ly = f;
	hoa = g;
}

int kt(int n, sinhvien sv[], int id){
	if(n <= 1) return 0;
	for(int i = 1; i <= n; i++){
		if(sv[i].getID() == id){
			return 1;
		}
	}
	return 0;
}

void them(int n, sinhvien sv[]){
	int id;
	string ten;
	string diachi;
	string gioitinh;
	float toan;
	float ly;
	float hoa;

	cout<<"ID: ";
	cin>>id;
	cout<<"Ten: ";
	fflush(stdin);
	getline(cin, ten);
	cout<<"Dia chi: ";
	fflush(stdin);
	getline(cin, diachi);
	cout<<"Gioi tinh: ";
	fflush(stdin);
	getline(cin, gioitinh);
	cout<<"Toan: ";
	cin>>toan;

	while(toan > 10 || toan < 0){
		cout<<"diem toan hop le, y/c nhap lai"<<endl;
		cin >>toan;
	}
	cout<<"Ly: ";
	cin>>ly;
	while(ly > 10 || ly < 0){
		cout<<"diem ly hop le, y/c nhap lai"<<endl;
		cin >>ly;
	}
	cout<<"Hoa: ";
	cin>>hoa;	

	while(hoa > 10 || hoa < 0){
		cout<<"diem hoa hop le, y/c nhap lai"<<endl;
		cin >>hoa;
	}

	if(kt(n, sv, id)){
		cout<<"trung r, nhap lai di"<<endl;
		them(n, sv);
	}
	else sv[n].nhap(id, ten, diachi, gioitinh, toan, ly, hoa);
}

void sinhvien::xuat(){//xuat tat ca sv 
	cout<<"ID: "<<id<<endl;
	cout<<"Ten: "<<ten<<endl;
	cout<<"dia chi: "<<diachi<<endl;
	cout<<"gioi tinh: "<<gioitinh<<endl;
	cout<<"toan: "<<toan<<endl;
	cout<<"ly: "<<ly<<endl;
	cout<<"hoa: "<<hoa<<endl;
}

void swap(sinhvien &sv1, sinhvien &sv2){//doi cho 2 sv
	sinhvien tem;
	memcpy(&tem, &sv1, sizeof(sinhvien));
	memcpy(&sv1, &sv2, sizeof(sinhvien));
	memcpy(&sv2, &tem, sizeof(sinhvien));
}

void sortID(int n, sinhvien sv[]){//sx theo ID
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(sv[i].getID() > sv[j].getID()){
				swap(sv[i], sv[j]);
			}
		}
	}
}

void sortTong(int n, sinhvien sv[]){//sx theo tong diem
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(sv[i].getTong() > sv[j].getTong()){
				swap(sv[i], sv[j]);
			}
		}
	}
}

void sortName(int n, sinhvien sv[]){//sx theo ten
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(sv[i].getTen() > sv[j].getTen()){
				swap(sv[i], sv[j]);
			}
		}
	}
}

void WriteFile(int n, sinhvien sv[]){//in ra file
	fstream f;
	f.open("output.txt", ios::out);
	f << "ID Ten DiaChi GioiTinh Toan Ly Hoa"<<endl;
	for(int i = 1; i <= n; i++){
		f << sv[i].getID()<< "  " << sv[i].getTen()<<"  "<<sv[i].getDiachi()<<"  "<<sv[i].getGioitinh()<<"  "<<sv[i].getToan()<<"  "<<sv[i].getLy()<<"  "<<sv[i].getHoa()<<endl;
	}
	f.close();
}

void sort(int n2, sinhvien tem[]){//sort main
	cout<<"0.sx theo ID"<<endl<<"1.sx theo ten"<<endl<<"2.sx theo tong diem"<<endl;
	int b;
	cin>>b;
	if(b == 0){
		sortID(n2, tem);
		for(int i = 1; i <= n2; i++){
			tem[i].xuat();
		}
	}
	if(b == 1){
		sortName(n2, tem);
		for(int i = 1; i <= n2; i++){
			tem[i].xuat();
		}
	}
	if(b == 2){
		sortTong(n2, tem);
		for(int i = 1; i <= n2; i++){
			tem[i].xuat();
		}
	}
	WriteFile(n2, tem);
}

void sua(int n, sinhvien sv[]){
	if(n == 0){
		cout<<"ds rong"<<endl;
	}
	else{
		cout<<"nhap ID: "<<endl;
		int k = 0;
		int x;
		cin>>x;
		for(int i = 1; i <= n; i++){
			if(sv[i].getID() == x){
				k = 1;
				them(i, sv);	
			}						
		}
		if(k == 0){
			cout<<"ko co sinh vien thoa man"<<endl;
		}
	}
}

void thongke(int n, sinhvien sv[]){//thong ke
	int a = 0, b = 0, c = 0, d = 0;
	for(int i = 1; i <= n; i++){
		if(sv[i].getTong() < 15){
			d++;
		}
		if(sv[i].getTong() >= 15 && sv[i].getTong() < 20){
			c++;
		}
		if(sv[i].getTong() >= 20 && sv[i].getTong() < 25){
			b++;
		}
		if(sv[i].getTong() >= 25){
			a++;
		}
	}
	cout<<"Thong ke."<<endl;
	cout<<"Co tat ca "<<n<<" sinh vien. Trong do co: \n";
		cout<<d<<" sv co diem > 15"<<endl;
		cout<<c<<" sv co diem tu 15 den 20"<<endl;
		cout<<b<<" sv co diem tu 20 den 25"<<endl;
		cout<<a<<" sv co diem > 25"<<endl;

	fstream f;
	f.open("thongke.txt", ios::out);
	f << "Thong ke."<<endl;
		f<<d<<" sv co diem > 15"<<endl;
		f<<c<<" sv co diem tu 15 den 20"<<endl;
		f<<b<<" sv co diem tu 20 den 25"<<endl;
		f<<a<<" sv co diem > 25"<<endl;
	f.close();
}

int main(){
	sinhvien sv[1000];
	int n = 0;//dem so sv
	while(1){
		cout<<"==========================="<<endl;
		cout<<"moi chon chuc nang: "<<endl;
		cout<<"1.Nhap"<<endl;
		cout<<"2.Xuat"<<endl;
		cout<<"3.Edit"<<endl;
		cout<<"4.Delete"<<endl;
		cout<<"5.Search tong diem"<<endl;
		cout<<"6.Search ID"<<endl;
		cout<<"7.Search name"<<endl;
		cout<<"8.Search toan"<<endl;
		cout<<"9.Search ly"<<endl;
		cout<<"10.Search hoa"<<endl;
		cout<<"11.Thong ke"<<endl;
		cout<<"0.Thoat"<<endl;
		int a;
		cin>>a;
		switch(a){
			case 1:{//chuc nang them 1 sv
				n++;
				cout<<"sv thu "<<n<<". "<<endl;
				them(n, sv);		
				sortID(n, sv);
				WriteFile(n, sv);
				break;
				   }
			case 2:{//show all
				if(n == 0){
					cout<<"danh sach rong."<<endl;
				}
				else {
					for(int i = 1; i <= n; i++){
						cout<<i<<". "<<endl;
						sv[i].xuat();
					}
					WriteFile(n, sv);
				}
				break;
				   }
			case 3:{//edit 1 sv
					sua(n, sv);				
				break;
				   }
			case 4:{//delete 1 sv
				cout<<"nhap ID: "<<endl;
				int k = 0;
				int t;
				int x;
				cin>>x;
				for(int i = 1; i <= n; i++){
					if(sv[i].getID() == x){
						k = 1;
						t = i;
						n--;
						break;						
					}
				}
				for(int i = t; i <= n ; i++){
					sv[i] = sv[i+1];					
				}
				if(k == 0){
					cout<<"ko tim thay sv"<<endl;
				}
				break;
				   }
			case 5:{//tim kiem theo tong diem
				int k = 0;
				if(n == 0){
					cout<<"ds rong"<<endl;
				}
				else{
					cout<<"nhap tong diem can tim: ";
					float x;
					sinhvien tem[1000];
					int n2 = 0;
					cin>>x;
					for(int i = 1; i <= n; i++){
						if(sv[i].getTong() == x){
							n2++;
							memcpy(&tem[n2], &sv[i], sizeof(sinhvien));
							k = 1;
						}
					}
					if(k == 0){
						cout<<"ko tim thay"<<endl;
					}
					else{
						sort(n2, tem);
					}
				}
				break;
				   }
			case 6:{// tim theo ID
				int k = 0;
				sinhvien tem[1000];
				int n2 = 0;
				if(n == 0){
					cout<<"ds rong"<<endl;
				}
				else{
					cout<<"nhap ID can tim: ";
					int x;
					cin>>x;
					for(int i = 1; i <= n; i++){
						if(sv[i].getID() == x){
							n2++;
							memcpy(&tem[n2], &sv[i], sizeof(sinhvien));
							k = 1;
						}
					}
					if(k == 0){ 
						cout<<"ko tim thay"<<endl;
					}
					else{
						sort(n2, tem);
						//WriteFile(n2, tem);
					}
				}
				break;
				   }
			case 7:{// tim theo ten
				int k = 0;
				if(n == 0){
					cout<<"ds rong"<<endl;
				}
				else{	
					sinhvien tem[1000];
					int n2 = 0;
					cout<<"nhap ten can tim: ";
					string s;
					fflush(stdin);
					getline(cin,s);
					for(int i = 1; i <= n; i++){
						if(sv[i].getTen() == s){
							k = 1;
							n2++;
							memcpy(&tem[n2], &sv[i], sizeof(sinhvien));
						}
					}
					if(k == 0){
						cout<<"ko tim thay"<<endl;
					}
					else{
						sort(n2, tem);
					}
				}				
				break;
				   }
			case 8:{// tim theo diem toan
				int k = 0;
				if(n == 0){
					cout<<"ds rong"<<endl;
				}
				else{
					sinhvien tem[1000];
					int n2 = 0;
					cout<<"nhap dem toan can tim: ";
					int x;
					cin>>x;
					for(int i = 1; i <= n; i++){
						if(sv[i].getToan() == x){
							n2++;
							memcpy(&tem[n2], &sv[i], sizeof(sinhvien));
							k = 1;
						}
					}
					if(k == 0){
						cout<<"ko tim thay"<<endl;
					}
					else{
						sort(n2, tem);
					}
				}
				break;
				   }
			case 9:{// tim theo diem ly
				int k = 0;
				if(n == 0){
					cout<<"ds rong"<<endl;
				}
				else{
					sinhvien tem[1000];
					int n2 = 0;
					cout<<"nhap dem ly can tim: ";
					int x;
					cin>>x;
					for(int i = 1; i <= n; i++){
						if(sv[i].getLy() == x){
							n2 ++;
							memcpy(&tem[n2], &sv[i], sizeof(sinhvien));
							k = 1;
						}
					}
					if(k == 0) {
						cout<<"ko tim thay"<<endl;
					}
					else{
						sort(n2, tem);
					}
				}
				break;
				   }
			case 10:{// tim theo diem hoa
				int k = 0;
				if(n == 0){
					cout<<"ds rong"<<endl;
				}
				else{
					sinhvien tem[1000];
					int n2 = 0;
					cout<<"nhap dem hoa can tim: ";
					int x;
					cin>>x;
					for(int i = 1; i <= n; i++){
						if(sv[i].getHoa() == x){
							n2 ++;
							memcpy(&tem[n2], &sv[i], sizeof(sinhvien));
							k = 1;
						}
					}
					if(k == 0){
						cout<<"ko tim thay"<<endl;
					}
					else{
						sort(n2, tem);
					}
				}
				break;
			}
			case 11:{//thong ke
				thongke(n, sv);
				break;
					}
			case 0:{//thoat
				return 0;
				   }
		}
	}
	return 0;
}

