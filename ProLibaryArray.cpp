#include<iostream>
#include<iomanip>
#include<string.h>
#include<string>
#include<sstream>

using namespace std;
void init(string student[][4],string Book[][6]);
void AddStudent(string student[][4]);
void AddBook(string Book[][6]);
void BorrowBook(string student[][4],string Book[][6]);
void ReturnBook(string student[][4],string Book[][6]);
void Report(string student[][4],string Book[][6]);

int main()
{
	string student[101][4]={{"501","Miyafuji Yoshika","Fuso Imperial Navy European Dispatch Fleet 24th","Air support"},
							{"502","Lynette Bishop","Britannian Air Force 610th","Fighter wing"},
							{"503","Minna Dietlinde Wilcke","Karlsland Air Force JG3","Wing Commander"},
							{"504","Sakamoto Mio","Fuso Imperial Navy European Dispatch Fleet 24th","Squadron Leader"},
							{"505","Gertrud Barkhorn","Karlsland Air Force JG 2","Berserker"},
							{"506","Charlotte E. Yeager","United States of Liberion Army Air Corps","Fighter Squadron"},
							{"507","Erica Hartmann","Karlsland Air Force","2nd Staffel"},
							{"508","Perrine H. Clostermann","Free Gallia Air ForceBritannian Air Force 610th","Paladin"},
							{"509","Sanya V. Litvyak","Empire of Orussia Imperial Army","586th Fighter Aviation Regiment"},
							{"510","Eila Ilmatar Juutilainen","Suomus Air Force","24th Unit"},
							{"511","Francesca Lucchini","Duchy of Romagna Air Force","4th Air Unit"}};
	string Book[101][6]  = {{"1001","10 Choose of Happyness","Dan Savo","Phozik","1996","00"},
						    {"1002","Fundamental of IT","KaoEng","711","2010","00"},
						    {"1003","Use Your Power to Protect","Dr.Miyafuji","Fuso","1940","00"},
						    {"1004","Ace Combat series","Unknown","Bandai","2009","00"},
						    {"1005","Good Famiry","Jokana","MexiPaint","1999","00"},
						    {"1006","HTML5&CSS","Unknown","Siam","2015","00"},
						    {"1007","BanPeeHod","Suvid","LukPim","1990","00"},
						    {"1008","Electronic 1","J.Songsompan","BanMoo","1985","00"},
						    {"1009","Kanchok Pitak Kancha","Di5trotion","Multilane","2020","00"},
						    {"1010","108 Menu Mega Cheese","ChefBA","Papaya","2018","00"},
						    {"1011","Vitas Music of Future","DJ.Vokob","inRussia","2100","00"}};
	int Choose=0;
	init(student,Book); //Set Zero
	do{
		system("cls");
		cout << setfill('=') << setw(30) <<"="<< endl;
		cout << ":\t0. To Exit."<< endl;
		cout << ":\t1. Add New Students."<< endl;
		cout << ":\t2. Add New Book/Text."<< endl;
		cout << ":\t3. Borrow books"<< endl;
		cout << ":\t4. Return books"<< endl;
		cout << ":\t5. Report."<< endl;
		cout << setfill('=') <<setw(30)<<"="<< endl;
		cout << "Choose the menu : ";
		cin >> Choose;
		if(Choose == 0)break;
		else if(Choose == 1) AddStudent(student);
		else if(Choose == 2) AddBook(Book);
		else if(Choose == 3) BorrowBook(student,Book);
		else if(Choose == 4) ReturnBook(student,Book);
		else if(Choose == 5) Report(student,Book);
		else {
			cout << "Error! Choose try again."<< endl;
			system("pause");
		}
	}while(true);
	cout << "Exit Program" << endl;
	system("pause");
	return(0);
}

void init(string student[][4],string Book[][6]){
	for(int r=11;r<101;r++){
		student[r][0]="00";
		Book[r][0]="00";
	}
}

void AddStudent(string student[][4]){
	char C;
	int r,t;
	for(r=0;r<=100;r++){
		if (student[r][0]=="00")break;
		else if (r == 100){
			cout <<"Error Memory Full."<< endl;
			system("pause");
			system("cls");
			return;
		}
	}
	do{
	first:
	system("cls");
	cout <<"Enter your ID : ";
	cin.ignore();
	getline(cin,student[r][0]);
	for(t=0;t<100;t++){
		if (r==t);// ตัวเดียวกันไม่ต้องทำไร
		else if(student[t][0]==student[r][0]){
			cout <<"StudentID has already been created." <<endl;
			system("pause");
			goto first;
		}	
	}
	cout << "Enter your name : ";
	getline(cin,student[r][1]);
	cout << "Enter your Faculty : ";
	getline(cin,student[r][2]);
	cout << "Enter your Major : ";
	getline(cin,student[r][3]);
	cout <<"ID : "<<student[r][0]<<endl;
	cout <<"Name : "<<student[r][1]<<endl;
	cout <<"Faculty : "<<student[r][2]<<endl;
	cout <<"Major : "<<student[r][3]<<endl;
	cout << "Confirm? Yes(1) No(0) : ";
	cin >> C;
	}while(C == '0');
}

void AddBook(string Book[][6]){
	char C;
	int r;
	for(r=0;r<=100;r++){
		if (Book[r][0]=="00")break;
		else if (r == 100){
			cout <<"Error Memory Full."<< endl;
			system("pause");
			system("cls");
			return;
		}
	}
	do{
	system("cls");
	cout <<"====================Add=Book========================"<<endl;
	cin.ignore();
	cout << "Enter ISBN : ";
	getline(cin,Book[r][0]);
	cout << "Enter Bookname : ";
	getline(cin,Book[r][1]);
	cout << "Enter writer name : ";
	getline(cin,Book[r][2]);
	cout << "Enter publisher : ";
	getline(cin,Book[r][3]);
	cout << "Enter book's year : ";
	getline(cin,Book[r][4]);
	cout <<"ISBN : "<<Book[r][0]<<endl;
	cout <<"Bookname : "<<Book[r][1]<<endl;
	cout <<"Writer : "<<Book[r][2]<<endl;
	cout <<"Publisher : "<<Book[r][3]<<endl;
	cout <<"Year : "<<Book[r][4]<<endl;
	cout << "Confirm? Yes(1) No(0) : ";
	cin >> C;
	}while(C == 0);
}

void BorrowBook(string student[][4],string Book[][6]){
	string ID,borrow,temp;
	int r,C,t,B;
	do{
	again:
	system("cls");
	cout <<"=====================Borrow========================"<<endl;
	cout << "Enter your StudentID(0 To Menu) : ";
	cin >> ID;
	for(r=0;r<=100;r++){
		if (ID==student[r][0])break;
		else if (ID =="0")return;
		else if (r==100){
			cout << "Error ID not found or wrong ID!!!\nTry again"<<endl;
			system("pause");
			goto again;
		}
	}
	cout <<"======================Student======================"<<endl;
	cout << student[r][1] << endl;
	cout <<"Faculty : "<<student[r][2]<<endl;
	cout <<"Major : "<<student[r][3]<<endl;
	cout <<"===================================================\n"<<endl;
	cout <<"Collect? Yes(1) No(0) : ";
	cin >> C;
	}while(C == 0);
	for(t=0;t<3;t++){
		AG:
		cout <<"Enter ISBN book"<<t+1<<" (0 to skip) : ";
		cin >> borrow;
		if (borrow!="0"){
		for(B=0;B<=100;B++){
			if(Book[B][0]==borrow)break;
			else if(B==100){
				cout << "Book not Found or wrong ISBN." <<endl;
				system("pause");
				goto AG;
			}
		}}else goto skip;
		cout <<"================Information==================="<<endl;
		cout <<"<<<"<<Book[B][1]<<">>>"<<endl;
		cout <<"Writer : "<<Book[B][2]<<endl;
		cout <<"Publisher : "<<Book[B][3]<<endl;
		cout <<"Year : "<<Book[B][4]<<endl;
		cout <<"==============================================\n"<<endl;
		cout <<"Borrow? Confirm(1) Not this book(0) : ";
		cin >> C;
		if(C==1){
			cout <<"Borrow Completed!\n"<<endl;
			stringstream ss;
			ss << r;
			Book[B][5]=ss.str();
		}else{
			system("pause");
			goto AG;
		}
	}
	skip:
	cout << "list your Borrowed" << endl;
	cout <<setfill(' ');
	cout<<"|"<<setw(10)<<"ISBN"<<"|"<<setw(30)<<"NameBook"<<"|"<<setw(15)<<"Writer"<<"|"<<setw(12)<<"Publisher"<<"|"<<setw(5)<<"Year"<<"|"<<endl;
	cout <<setfill('=') << setw(78) <<"="<<endl;
	stringstream ss;
	ss << r;
	cout <<setfill(' ');
	for(B=0;B<=100;B++){
		if(Book[B][5]==ss.str()){
			cout<<"|"<<setw(10)<<Book[B][0]<<"|"<<setw(30)<<Book[B][1]<<"|"<<setw(15)<<Book[B][2]<<"|"<<setw(12)<<Book[B][3]<<"|"<<setw(5)<<Book[B][4]<<"|"<<endl;
		}
	}
	cout <<setfill('=') << setw(78) <<"="<<endl;
	system("pause");
}

void ReturnBook(string student[][4],string Book[][6]){
	string ID,ISBN;
	int r,C,t,B;
	bool trig=false;
	do{
	again:
	system("cls");
	cout <<"=====================ReturnBook========================"<<endl;	
	cout << "Enter your StudentID(0 To Menu) : ";
	cin >> ID;
	for(r=0;r<=100;r++){
		if (ID==student[r][0])break;
		else if (ID =="0")return;
		else if (r==100){
			cout << "Error ID not found or wrong ID!!!\nTry again"<<endl;
			system("pause");
			goto again;
		}
	}
	cout <<"====================Student===================="<<endl;
	cout << student[r][1] << endl;
	cout <<"Faculty : "<<student[r][2]<<endl;
	cout <<"Major : "<<student[r][3]<<endl;
	cout <<"===============================================\n"<<endl;
	cout <<"Collect? Yes(1) No(0) : ";
	cin >> C;
	}while(C == 0);
	cout << "list your Borrowed" << endl;
	cout <<setfill(' ');
	cout<<"|"<<setw(10)<<"ISBN"<<"|"<<setw(30)<<"NameBook"<<"|"<<setw(15)<<"Writer"<<"|"<<setw(12)<<"Publisher"<<"|"<<setw(5)<<"Year"<<"|"<<endl;
	cout <<setfill('=') << setw(78) <<"="<<endl;
	stringstream ss;
	ss << r;
	for(B=0;B<=100;B++){
		if(Book[B][5]==ss.str()){
			cout<<"|"<<setw(10)<<Book[B][0]<<"|"<<setw(30)<<Book[B][1]<<"|"<<setw(15)<<Book[B][2]<<"|"<<setw(12)<<Book[B][3]<<"|"<<setw(5)<<Book[B][4]<<"|"<<endl;
			trig = true;
		}
	}
	if(trig==false){
		cout <<"You not borrow books!!!"<<endl;
		system("pause");
		system("cls");
		goto again;
	}
	cout <<"======================================"<<endl;
	cout <<"		1 Return each book."<<endl;
	cout <<"		2 Return all books."<<endl;
	cout <<"		0 To Exit."<<endl;
	cout <<"======================================"<<endl;
	cout <<"Enter Choose : ";
	cin >> C;
	if (C==1){
		EnISBN:
		cout<<"Enter ISBN(0 to exit) : ";
		cin >> ISBN;
		if (ISBN!="0")
			for(B=0;B<=100;B++){
			if((Book[B][0]==ISBN) && (Book[B][5]==ss.str())){
				Book[B][5]=="00";
				cout << Book[B][1] <<" return!"<<endl;
				goto EnISBN;
			}else if(B==100){
				cout << "ISBN not found or Book not borrow." <<endl;
			}
			}
	}else if(C==2){
		for(B=0;B<=100;B++){
		if(Book[B][5]==ss.str()){
			Book[B][5]=="00";
			cout << Book[B][1] <<"	Returned!"<<endl;
		}
	}
	}else if(C==0)return;
	system("pause");
}

void Report(string student[][4],string Book[][6]){
	int r,B;
	for(r=0;r<=100;r++){
	bool trig=false;
	stringstream ss;
	ss << r;
	if(student[r][0]=="00")break;
	for(B=0;B<=100;B++){
		if(Book[B][5]==ss.str()){
			trig=true;
		}
	}
	cout << student[r][1];
	if (trig==false){
		cout<<" not borrow books.\n"<<endl;
		goto Reskip;
	}else cout<<endl;
	cout <<setfill(' ');
	cout <<setfill('=') << setw(78) <<"="<<endl;
	cout <<setfill(' ')<<"|"<<setw(10)<<"ISBN"<<"|"<<setw(30)<<"NameBook"<<"|"<<setw(15)<<"Writer"<<"|"<<setw(12)<<"Publisher"<<"|"<<setw(5)<<"Year"<<"|"<<endl;
	cout <<setfill('=') << setw(78) <<"="<<endl;
	cout <<setfill(' ');
	for(B=0;B<=100;B++){
		if(Book[B][5]==ss.str()){
			cout<<"|"<<setw(10)<<Book[B][0]<<"|"<<setw(30)<<Book[B][1]<<"|"<<setw(15)<<Book[B][2]<<"|"<<setw(12)<<Book[B][3]<<"|"<<setw(5)<<Book[B][4]<<"|"<<endl;
		}
	}
	cout <<setfill('=') << setw(78) <<"="<<endl;
	Reskip:;
	}
	cout << "Book in library"<<endl;
	cout <<setfill(' ');
	cout <<setfill('=') << setw(78) <<"="<<endl;
	cout<<setfill(' ')<<"|"<<setw(10)<<"ISBN"<<"|"<<setw(30)<<"NameBook"<<"|"<<setw(15)<<"Writer"<<"|"<<setw(12)<<"Publisher"<<"|"<<setw(5)<<"Year"<<"|"<<endl;
	cout <<setfill('=') << setw(78) <<"="<<endl;
	cout <<setfill(' ');
	for(B=0;B<=100;B++){
		if(Book[B][5]=="00"){
			cout<<"|"<<setw(10)<<Book[B][0]<<"|"<<setw(30)<<Book[B][1]<<"|"<<setw(15)<<Book[B][2]<<"|"<<setw(12)<<Book[B][3]<<"|"<<setw(5)<<Book[B][4]<<"|"<<endl;
		}
	}
	cout <<setfill('=') << setw(78) <<"="<<endl;
	system("pause");
}