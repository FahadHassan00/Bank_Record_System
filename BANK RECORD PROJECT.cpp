#include<iostream>

#include<fstream>
#include<string>

using namespace std;

class Node {
public:
	int id;
	string name;
	string Address;
	string balance;
	Node* next;

};

class list {
private:
	static int lines;
public:
	Node* head;

	list() {
		head = NULL;
	}

	void adddata(string name,string address,string balance) {
		Node* temp = new Node();
		int a = Countlines();
		temp->id = a;
		temp->name = name;
		temp->Address = address;
		temp->balance = balance;
		a++;
		ofstream op;
		op.open("data.txt", ofstream::out | ofstream::app | ios::ate);
		if (!op) {
			cout << "cant open file " << endl;
		}
		else {
			op << a << "   " << name << "   " << address << "   " << balance << endl;
			lines++;
		}

		lines++;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
		cout << name << "'s  Account number is = " << a << " remember it or write it down " << endl;
		op.close();
	}
	void Delete_from_memory(int id) {
		if (head == NULL) {
			cout << "Data not in memory" << endl;
		}
		else {
			Node* ptr = head;
			Node* ptr1 = head;

			while (ptr != NULL && ptr->id != id) {
				ptr1 = ptr;
				ptr = ptr->next;
			}
			if (ptr == NULL) {
				cout << " specific data not currently in memory " << endl;
			}
			if (ptr->next == NULL && ptr->id == id) {
				delete(ptr);
				ptr1->next == NULL;
			}
			if (ptr != head && ptr->id == id) {
				ptr1->next = ptr->next;
				delete(ptr);
			}
			if (ptr == head && ptr->id == id) {
				head = ptr->next;
				delete(ptr);
			}
		}
		
	}
	void print() {
		Node* ptr = head;
		while (ptr != NULL) {
			cout << ptr->id << " " << ptr->name;
			ptr = ptr->next;
		}
		cout << endl;
	}
	

	bool Search(int id) {
		int check = 1;
		fstream out;
		string line;
		out.open("data.txt", ios::in);
		if (!out) {
			cout << "cant open file " << endl;
		}
		else {
			while (getline(out, line)) {

				if (check == id) {
					cout << line << endl;
					return true;

				}
				else {
					check++;
				}
			}
			out.close();
			return false;

		}
		
	}
	int Countlines() {
		int count = 0;
		fstream out;
		string line;
		out.open("data.txt", ios::in);
		if (!out) {
			cout << "cant open file " << endl;
		}
		else {

			while (getline(out, line)) {
				count++;

			}
			
		}
		return count;
		out.close();
		
	}

	void Show(int id) {
		int find = 1;
		int a = Countlines();


		string line;

		fstream read;
		fstream write;

		read.open("data.txt", ios::in);

		if (!read) {
			cout << "cant open files " << endl;
		}
		else {
			if (id > a) {
				cout << " record not found " << endl;
			}
			else {
				while (getline(read, line)) {

					if (find == id) {
						cout << "your current data is " << line << endl;

						find++;
					}
					else {
						find++;

					}
				}
			}

			read.close();
			write.close();

		}
	}
	void Delete_From_file(int id) {
		int find = 1;
		int a = Countlines();

		string line;

		fstream read;
		fstream write;
		if (id > a) {
			cout << " record not found " << endl;
		}
		else {
			read.open("data.txt", ios::in);
			write.open("Temp.txt", ios::out);
			if (!read && !write) {
				cout << "cant open files " << endl;
			}
			else {

			
			while (getline(read, line)) {

				if (find == id) {
					cout << "your data was " << line << endl;
					write << "     " << endl;
					find++;
				}
				else {
					find++;
					write << line << endl;
				}
			}
		

		read.close();
		write.close();

		fstream read1;
		fstream write1;
		string copy;

		read1.open("Temp.txt", ios::in);
		write1.open("data.txt", ios::out);
		if (!read1 && !write1) {
			cout << "cant open files " << endl;
		}
		else {
			while (getline(read1, copy)) {

				write1 << copy << endl;

			}

			read1.close();
			write1.close();
		}



			}
		}
		


	}
	void update_in_memory(int id) {
		Node* ptr = head;
		if (head == NULL) {
			cout << "**************Data is not currently available in memory*************** " << endl;
		}
		else {
			while (ptr != NULL && ptr->id != id) {

				ptr = ptr->next;
			}
			if (ptr->id == id) {
				string name;
				cout << "enter name to update " << endl;
				cin >> name;
				ptr->name = name;
			}
			else {
				cout << "Data is not currently available in memory " << endl;
			}
		}
		
	}
	void update(int id) {

		int find = 1;
		int a = Countlines();

		string line;
		string name;
		fstream read;
		fstream write;
		if (id > a) {
			cout << " ********************Record not found in File********************* " << endl;
		}
		else {
			read.open("data.txt", ios::in);
			write.open("Temp.txt", ios::out);
			if (!read && !write) {
				cout << "cant open files " << endl;
			}
			else {


				string name;
				string address;
				string balance;
				cout << "Enter new Name " << endl;
				cin >> name;
				cout << "Enter new address " << endl;
				cin >> address;
				cout << "Enter new balance " << endl;
				cin >> balance;
				while (getline(read, line)) {

					if (find == id) {
						//cout << "your current data is " << line << endl;
						write << id << "   " << name << "   " << address << "   " << balance << endl;

						find++;
					}
					else {
						find++;
						write << line << endl;
					}
				}


				read.close();
				write.close();

				fstream read1;
				fstream write1;
				string copy;

				read1.open("Temp.txt", ios::in);
				write1.open("data.txt", ios::out);
				if (!read && !write) {
					cout << "cant open files " << endl;
				}
				else {
					while (getline(read1, copy)) {

						write1 << copy << endl;

					}
					read1.close();
					write1.close();
				}


			}
		}
		

	}
	bool isEmpty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

};
int list::lines = 1;

class BRM {
private:
	list l1;
	int size;
public:
	
	void ADD_Record(string name,string address,string balance) {
		l1.adddata(name,address,balance);
	}

	void Delete_from_file(int id) {
		
		l1.Delete_From_file(id);
		
	}
	void Show_data_from_file(int id) {
		l1.Show(id);
	}
	void delete_data_from_memory(int id) {
		l1.Delete_from_memory(id);
	}
	void Search_data(int id) {
		int a=l1.Search(id);
		if (a == 1) {
			cout<<"Data found " << endl;
		}
		else {
			cout << "data not found" << endl;
		}
	}
	void update_data_in_file(int id) {
		l1.update(id);
	}
	void Update_in_memory(int id) {
		l1.update_in_memory(id);
		
	}

	void display() {

		ifstream inp;
		string line;
		inp.open("data.txt", ios::in);
		if (!inp) {
			cout << "cant open file " << endl;
		}
		else {
			while (getline(inp, line)) {

				cout  << line << "\n";
			}
		}


	}
};


int main() {
	BRM bank;
	int a = 0;
	while (a != -1) {
		cout << "\n\n";
		cout << "\t\t\tPRESS 1 TO ADD DATA IN RECORD " << endl;
		cout << "\t\t\tPRESS 2 TO DELETE DATA FROM CURRENT MEMORY " << endl;
		cout << "\t\t\tPRESS 3 TO DELETE DATA FROM RECORD " << endl;
		cout << "\t\t\tPRESS 4 TO RETRIEVE DATA FROM RECORD " << endl;
		cout << "\t\t\tPRESS 5 TO UPDATE IN RECORD " << endl;
		cout << "\t\t\tPRESS 6 TO UPDATE IN MEMORY " << endl;
		cout << "\t\t\tPRESS 7 TO DISPLAY ALL DATA IN RECORD " << endl;
		cout << "\t\t\tPRESS -1 TO STOP " << endl;
		cin >> a;
		if (a == 1) {
			string name, address, balance;
			cout << "ENTER USER'S NAME = ";
			cin >> name;
			cout << "ENTER USER'S ADDRESS = ";
			cin >> address;
			cout << "ENTER USER'S BANK BALANCE = ";
			cin >> balance;
			bank.ADD_Record(name, address, balance);
			system("pause");
			system("cls");
		}
		else if(a == 2) {
			int id;
			cout << "ENTER ACCOUNT NUMBER TO DELETE = ";
			cin >> id;
			bank.delete_data_from_memory(id);
			system("pause");
			system("cls");
		}
		else if (a == 3) {
			int id;
			cout << "ENTER ACCOUNT NUMBER TO DELETE = ";
			cin >> id;
			bank.Delete_from_file(id);
			system("pause");
			system("cls");
		}
		else if (a == 4) {
			int id;
			cout << "ENTER ACCOUNT NUMBER TO RETRIEVE DATA = ";
			cin >> id;
			bank.Show_data_from_file(id);
			system("pause");
			system("cls");
		}
		else if (a == 5) {
			int id;
			cout << "ENTER ACCOUNT NUMBER TO UPDATE DATA = ";
			cin >> id;
			bank.update_data_in_file(id);
			system("pause");
			system("cls");
		}
		else if (a == 6) {
			int id;
			cout << "ENTER ACCOUNT NUMBER TO UPDATE DATA = ";
			cin >> id;
			bank.Update_in_memory(id);
			system("pause");
			system("cls");
		}
		else if (a == 7) {
			system("cls");
			bank.display();
			system("pause");
			system("cls");
		}
		else if (a == -1) {
			
		}
		else {
			cout << " WRONG INPUT " << endl;
		}
	}
}