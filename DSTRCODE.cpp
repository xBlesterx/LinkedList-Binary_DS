#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
//#include <bits/stdc++.h>
using namespace std;


struct Login{
	string userid;
	string pass;
	string type;
	Login* left;
	Login* right;
};


class Node
{
    public:
    int order_ID;
    int product_ID;
    std::string product_name;
    int quantity;
    double price;
    int day;
    int month;
    int year;
    std::string status;
    Node *next;
    Node(int order_ID,int ID, std::string product, int quantity, double price,int day,int month,int year){
        this -> order_ID = order_ID;
        this -> product_ID = ID;
        this -> product_name = product;
        this -> quantity = quantity;
        this -> price = price;
        this -> day = day;
        this -> month = month;
        this -> year = year;
        this -> status = "Not delivered";
        next = NULL;
    }

    Node(){
        this -> order_ID =0;
        this -> product_ID =0;
        this -> product_name = "";
        this -> quantity = 0;
        this -> price = 0;
        this -> day = 0;
        this -> month = 0;
        this -> year = 0;
        this -> status = "Not delivered";
        next = NULL;
    }
};


class LinkedList{
    public:
    // Default constructor
    LinkedList() { head = NULL;}
    Node* head= NULL;
    Node* new_node;
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int order_ID,int product_ID, std::string product_name, int quantity, double price,int day,int month,int year);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    bool deleteNode(Node* , Node*&);

    // Function to change the
    // state of a given node
    void change_status_record();

    // Function to search the
    // record by product ID
    void filter_by_product_ID();

    // Function to search the
    // record by order ID
    void filter_by_order_ID();

    // Function to sort the
    //record by product ID
    void sortfromMinById();

    // Function to sort the
    //record by day
    void sortfromMinByDay();

    // Function to sort the
    //record by quantity
    void sortfromMinByQuantity();

    // Function to add a
    //new record to the
    //linked list
    void add_new_record();
    
    
    Node* searchID(int);
    
    // Function to sort the
    //record by Descending
    void reverse();
};

void LinkedList::reverse(){
    Node *current,*prev,*next;
    current = head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}//("Reverse a linked list - GeeksforGeeks", 2022)
//Reverse a linked list - GeeksforGeeks. GeeksforGeeks. (2022). Retrieved 29 July 2022, from https://www.geeksforgeeks.org/reverse-a-linked-list/.


void LinkedList::sortfromMinByDay(){
            Node *new_node = head;
            int count = 0, i;
            Node *start = new_node;
            Node *curr = NULL;
            Node *prev = NULL;
            Node *temp = NULL;

            while(start != NULL) { //grab count
            count++;
            start = start->next;
            }

            for(i = 0; i<count; i++) { //for every element in the list

            curr = prev = head; //set curr and prev at the start Node

            while (curr->next != NULL) { //for the rest of the elements in the list
                if (curr->day > curr->next->day) { //compare curr and curr->next

                temp = curr->next; //swap pointers for curr and curr->next
                curr->next = curr->next->next;
                temp->next = curr;

                //now we need to setup pointers for prev and possibly head
                if(curr == head) //this is the case of the first element swapping to preserve the head pointer
                    head = prev = temp;
                else //setup prev correctly
                    prev->next = temp;
                curr = temp; //update curr to be temp since the positions changed
                }
                //advance pointers
                prev = curr;
                curr = curr->next;
            }
            }
}//("Program To Swap Nodes In A Singly Linked List Without Swapping Data - javatpoint", 2022)
//Program To Swap Nodes In A Singly Linked List Without Swapping Data - javatpoint. www.javatpoint.com. (2022). Retrieved 29 July 2022, from https://www.javatpoint.com/program-to-swap-nodes-in-a-singly-linked-list-without-swapping-data.
void LinkedList::sortfromMinByQuantity(){
    Node *new_node = head;
            int count = 0, i;
            Node *start = new_node;
            Node *curr = NULL;
            Node *prev = NULL;
            Node *temp = NULL;

            while(start != NULL) { //grab count
            count++;
            start = start->next;
            }

            for(i = 0; i<count; i++) { //for every element in the list

            curr = prev = head; //set curr and prev at the start Node

            while (curr->next != NULL) { //for the rest of the elements in the list
                if (curr->quantity > curr->next->quantity) { //compare curr and curr->next

                temp = curr->next; //swap pointers for curr and curr->next
                curr->next = curr->next->next;
                temp->next = curr;

                //now we need to setup pointers for prev and possibly head
                if(curr == head) //this is the case of the first element swapping to preserve the head pointer
                    head = prev = temp;
                else //setup prev correctly
                    prev->next = temp;
                curr = temp; //update curr to be temp since the positions changed
                }
                //advance pointers
                prev = curr;
                curr = curr->next;
            }
            }

}//("Program To Swap Nodes In A Singly Linked List Without Swapping Data - javatpoint", 2022)
//Program To Swap Nodes In A Singly Linked List Without Swapping Data - javatpoint. www.javatpoint.com. (2022). Retrieved 29 July 2022, from https://www.javatpoint.com/program-to-swap-nodes-in-a-singly-linked-list-without-swapping-data.
void LinkedList::sortfromMinById()
{
    Node *new_node = head;
    int count = 0, i;
    Node *start = new_node;
    Node *curr = NULL;
    Node *prev = NULL;
    Node *temp = NULL;

    while(start != NULL) { //grab count
    count++;
    start = start->next;
    }

    for(i = 0; i<count; i++) { //for every element in the list

    curr = prev = head; //set curr and prev at the start Node

    while (curr->next != NULL) { //for the rest of the elements in the list
        if (curr->product_ID > curr->next->product_ID) { //compare curr and curr->next

        temp = curr->next; //swap pointers for curr and curr->next
        curr->next = curr->next->next;
        temp->next = curr;

        //now we need to setup pointers for prev and possibly head
        if(curr == head) //this is the case of the first element swapping to preserve the head pointer
            head = prev = temp;
        else //setup prev correctly
            prev->next = temp;
        curr = temp; //update curr to be temp since the positions changed
        }
        //advance pointers
        prev = curr;
        curr = curr->next;
    }
    }
}//("Program To Swap Nodes In A Singly Linked List Without Swapping Data - javatpoint", 2022)
//Program To Swap Nodes In A Singly Linked List Without Swapping Data - javatpoint. www.javatpoint.com. (2022). Retrieved 29 July 2022, from https://www.javatpoint.com/program-to-swap-nodes-in-a-singly-linked-list-without-swapping-data.

bool LinkedList::deleteNode(Node* position, Node*& Head){
    if (position == NULL) {
		cout << "\nThe given ID is not found\n";
		return false;
	}
	else if (position == Head) {
		Head = position->next;
		delete position;
		return true;
	}
	Node* current = Head;
	while (current != NULL) {
		if (current->next == position) {
			current->next = position->next;
			delete position;
			return true;
		}
		current = current->next;
	}
	return false;

}

void LinkedList::printList() {
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }else{
        // Traverse the list.
        cout << "\nOrder ID\tProduct ID\tProduct Name\tQuantity\tPrice\tDay\tMonth\tYear\tOrder Status\n";
        while (temp != NULL) {
        	cout<<"   "<<temp->order_ID << "\t\t" << temp->product_ID<<"\t\t"<<temp->product_name<<"\t\t"<<temp->quantity<<"\t\t"<<temp->price<<"\t"<<temp->day<<"\t"<<temp->month<<"\t"<<temp->year<<"\t"<<temp->status<<"\n";
            temp = temp->next;
        }
    }
}

void LinkedList::insertNode(int order_ID,int product_ID, std::string product_name, int quantity, double price,int day,int month,int year){
        Node** temp = &head;
        Node *new_node = new Node(order_ID, product_ID, product_name, quantity, price, day, month, year);
        new_node->next = (*temp);
        (*temp) = new_node;
}

void LinkedList::change_status_record(){
    Node* temp = head;
    if (head == NULL) {
        cout << "Recorder is empty";
        return;
    }
    cout << "\nPlease enter the order ID you want to change: ";
    int ID;
    cin >> ID;
    // Loops through the whole records of the linked list
    while (temp != NULL){
        // Check if the selected ID is in the linked list by checking the ID of that node
        if (ID == temp->order_ID){
            cout << "1. Delivered\n"
                    "2. Canceled\t";
            int status;
            cin >> status;
            switch (status)
            {
            case 1:
                temp->status = "Delivered";
                break;
            case 2:
                temp->status = "Canceles";
            default:
                break;
            }
        }
        temp = temp->next;
    }
}
//To filter the data by the product ID
void LinkedList::filter_by_product_ID(){
    Node* temp = head;
    if (head == NULL) {
        cout << "Recorder is empty";
        return;
    }
    cout << "Please enter the product ID\t";
    int ID;
    cin >> ID;
    while (temp != NULL){
        if (ID == temp->product_ID){
            cout << "\nOrder ID            : " << temp->order_ID;
			cout << "\nProduct ID          : " << temp->product_ID;
			cout << "\nProduct Name        : " << temp->product_name;
			cout << "\nQuantity            : " << temp->quantity;
			cout << "\nPrice               : " << temp->price;
			cout << "\nDay                 : " << temp->day;
            cout << "\nMounth              : " << temp->month;
            cout << "\nYear                : " << temp->year;
            cout << "\nStatus              : " << temp->status<<"\n";
		}
        temp = temp->next;
    }
}
//To filter the data by the ID
void LinkedList::filter_by_order_ID(){
    Node* temp = head;
    if (head == NULL) {
        cout << "Recorder is empty";
        return;
    }
    cout << "Please enter the Order ID\t";
    int ID;
    cin >> ID;
    while (temp != NULL){
        if (ID == temp->product_ID){
            cout << "\nOrder ID            : " << temp->order_ID;
			cout << "\nProduct ID          : " << temp->product_ID;
			cout << "\nProduct Name        : " << temp->product_name;
			cout << "\nQuantity            : " << temp->quantity;
			cout << "\nPrice               : " << temp->price;
			cout << "\nDay                 : " << temp->day;
            cout << "\nMounth              : " << temp->month;
            cout << "\nYear                : " << temp->year;
            cout << "\nStatus              : " << temp->status<<"\n";
        }
        temp = temp->next;
    }
}
void LinkedList::add_new_record(){
    std::string product_name,end,status;
    double price;
    int Order_ID,Product_ID,quantity,day,month,year;
    std::cout << "Order ID: ";
    std::cin >> Order_ID;
    std::cout << "Product ID: ";
    std::cin >> Product_ID;
    std::cout << "Product Name: ";
    std::cin >> product_name;
    std::cout << "How many product: ";
    std::cin >> quantity;
    std::cout << "Order price: ";
    std::cin >> price;
    std::cout << "Date: ";
    std::cin >> day;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Year: ";
    std::cin >> year;
    insertNode(Order_ID,Product_ID,product_name,quantity,price,day,month,year);
    std::cout << "\n";
}


Node* LinkedList::searchID(int id){
    Node* current = head;
	if (head == NULL) {
		cout << "\nNo record added yet\n";
	}
	while (current != NULL) {
		if (current->order_ID == id) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return NULL;
}

/*
void LinkedList::deleteNode(int nodeOffset)
{
}
  */
LinkedList list;
class sales{
    public:
    void sort_data(){
        int chois;
        std::cout << "\n1. Sort by product ID.\n"
                     "2. Sort by Quantity\n"
                     "3. Sort by day.\n"
                     "4. Sort by descending\n"
                     "Please select the option you need: ";
        std::cin >> chois;
        switch (chois)
        {
        case 1:
            list.sortfromMinById();
            break;
        case 2:
            list.sortfromMinByQuantity();
        case 3:
            list.sortfromMinByDay();
        case 4:
            list.reverse();
        default:
            break;
        }
    }

    void Delete_record(){
        int ID;
        cout << "\nPlease enter the order ID you want to delete: ";
        cin >> ID;
        if(list.deleteNode(list.searchID(ID),list.head) == true){
        	cout << "\nThe purchases record was deleted successfully\n";
        }
        else {
            cout << "\nCould not delete the purchase record\n";
        }

    }

    void choice(){
        int chois;
        int search_Choice;
        std::cout << "\n1. Add purchase order records placed online.\n"
                     "2. Modify/Update\n"
                     "3. Delete record\n"
                     "4. View all purchase orders.\n"
                     "5. Sort the record\n"
                     "6. Search purchase order\n"
                     "7. Logout\n"
                     "Please select the option you need: ";
        std::cin >> chois;
        switch (chois)
        {
        case 1:
            list.add_new_record();
            choice();
            break;
        case 2:
            list.change_status_record();
            choice();
            break;
        case 3:
            Delete_record();
            choice();
            break;
        case 4:
            list.printList();
            choice();
            break;
        case 5:
            sort_data();
            choice();
            break;
        case 6:
            cout << "\n1. Search by order ID\n"
                    "2. Search by product ID\t";
            cin >> search_Choice;
            if (search_Choice == 1){list.filter_by_order_ID();}
            else if (search_Choice == 2){list.filter_by_product_ID();}
            else{
                cout << "\nInvalid choice";

            }
            choice();
            break;
        case 7:
            return;
        default:
            cout << "\nInvalid choice";
            choice();
            break;
        }
    }
};





class Admin{
    public:    
    void summaryReport(string type,int month,Node*temp){
    	temp= list.head;
        int total = 0;
        int totalq = 0;
        cout << "\nOrder ID\tProduct ID\tProduct Name\tQuantity\tPrice\tDay\tMonth\tYear\tOrder Status\n";
        while(temp!=NULL){
            if(temp->product_name == type && month==0){
                cout<<"   "<<temp->order_ID << "\t\t" << temp->product_ID<<"\t\t"<<temp->product_name<<"\t\t"<<temp->quantity<<"\t\t"<<temp->price<<"\t"<<temp->day<<"\t"<<temp->month<<"\t"<<temp->year<<"\t"<<temp->status<<"\n";
                totalq += temp->quantity;

            }else if(temp->month == month && type==""){
                cout<<"   "<<temp->order_ID << "\t\t" << temp->product_ID<<"\t\t"<<temp->product_name<<"\t\t"<<temp->quantity<<"\t\t"<<temp->price<<"\t"<<temp->day<<"\t"<<temp->month<<"\t"<<temp->year<<"\t"<<temp->status<<"\n";
                total += temp->price;
                totalq += temp->quantity;
                
            }else if(temp->month == month && temp->product_name == type){
                cout<<"   "<<temp->order_ID << "\t\t" << temp->product_ID<<"\t\t"<<temp->product_name<<"\t\t"<<temp->quantity<<"\t\t"<<temp->price<<"\t"<<temp->day<<"\t"<<temp->month<<"\t"<<temp->year<<"\t"<<temp->status<<"\n";
                total += temp->price;
                totalq += temp->quantity;
            }
            temp = temp->next;
        }
        if(total != 0 ){
            cout<<"\t\t\t" <<"Total Amount" << "\tTotal Quantity"<< endl;
            cout<< "\t\t\t" << total <<"\t\t\t"<<totalq<< endl;
        }
        else{
            cout<<"Products does not exist";
        }
    }

    void salesReport(Node *temp){
        int choice;
        int secondChoice;
        int sortType;
        list.printList();
        cout<<"\nDo you wan to sort?\nType 1 = yes\n2 = no\n:" << endl;
        cin >>choice;
        if(choice ==1){
            cout<<"\nSort by ID:Press 1\nDay:Press 2\nQuantity:Press 3\n:";
            cin >> sortType;
            if(sortType == 1){
                cout<<"\nFor ascending order Type 1\n Descending Type 2\n Back Type 3\n:";
                cin >> secondChoice;
            if(secondChoice == 1){
                list.sortfromMinById();
                list.printList();
            }
            else if(secondChoice == 2){
                list.reverse();
                list.printList();
            }
            else if(secondChoice == 3){
                return;
            }
            else{
                cout<<"\nPlease enter valid number:";
                salesReport(temp);
            }
            }else if(sortType==2){
                cout<<"\nFor ascending order Type 1\n Descending Type 2\n Back Type 3\n:";
                cin>> secondChoice;
                if(secondChoice == 1){
                    list.sortfromMinByDay();
                    list.printList();
                }else if(secondChoice==2){
                	list.reverse();
                	list.printList();
                }else{
                	return;
                }

            }
            else if(sortType==3){
                cout<<"\nFor ascending order Type 1\n Descending Type 2\n Back Type 3\n:";
                cin>> secondChoice;
                if(secondChoice == 1){
                    list.sortfromMinByQuantity();
                    list.printList();
                }else if(secondChoice ==2){
                	list.reverse();
                	list.printList();
                }
            else{
                cout<<"\nPlease enter valid number:";
                salesReport(temp);
                }
            }
            else{
                return;
            }

        }
    }

    void Delete_record(){
    int ID;
    cout << "\nPlease enter the order ID you want to delete: ";
    cin >> ID;
    if(list.deleteNode(list.searchID(ID),list.head) == true){
        cout << "\nThe purchases record was deleted successfully\n";
    }
    else {
        cout << "\nCould not delete the purchase record\n";
    }

    }

    void choice() {
        Node * temp =list.head;
        int firstChoice;
        int SecondChoice;
        int option;
        string pn = "";
        int mo = 0;
        cout << "\n1.Add order record.\n2.View all original list order\n3.Search order\n4.Generate Report\n5.Delete Record\n6.Logout:\t" << endl;
        cin >> firstChoice;
        if(firstChoice==1){
        	list.add_new_record();
        	choice();
        }
        else if(firstChoice==2){
        	list.printList();
			choice();
            }
        else if(firstChoice==3){
        	cout<<"Order" << endl;
        	list.filter_by_product_ID();
        	choice();
            return;
        }
        else if(firstChoice==4){
        	cout<< "\n1.Sales Order Report\n2.Summary Report\n3.Back\t\n:";
			cin >> SecondChoice;
			if(SecondChoice==1){
				salesReport(temp);
				choice();
			}
            else if(SecondChoice==2){
				cout<< "\nSummary Report of product:Press 1\nMonth:Press 2\nBoth:Press 3\nBack:Press 4\t";
				cin >> option;
				switch(option){
				case 1:
					cout<< "\nEnter Product Name: ";
					cin >> pn;
					summaryReport(pn,mo,temp);
					choice();
					break;
				case 2:
					cout <<"Enter Month: ";
					cin >> mo;
					summaryReport(pn,mo,temp);
					choice();
					break;
				case 3:
					cout<< "Enter Product Name: ";
					cin >> pn;
					cout <<"Enter Month: ";
					cin >> mo;
					summaryReport(pn,mo,temp);
					choice();
					break;
				default:
					break;
			    }
		    }
        }
        else if (firstChoice == 5){
            Delete_record();
            choice();
        }
        else if(firstChoice==6){
        	return;

        }else{
        	cout<< "\nPlease enter a valid choice:";
			choice();
        }
}
};

Login* GetNewNode(string userid,string pass,string type){ //creating new node
	Login* newNode = new Login();
	newNode->userid= userid;
	newNode->pass = pass;
	newNode->type = type;
	newNode->left = newNode->right = NULL;
	return newNode;
}


string Search(Login* root,string userid,string pass,string type){
	//string atype="a";
	//string stype = "s";
	if(root==NULL) return "f";
	else if(root->userid == userid && root->pass == pass && root->type == "a")return "a";
	else if(root->userid == userid && root->pass == pass && root->type == "s")return "s";
	else if(userid <= root->userid && pass<= root->pass) return Search(root->left,userid,pass,type);
	else return Search(root->right,userid,pass,type);
}



Login* Insert(Login* root,string userid,string pass,string type){ // we need pass the address else it wont work, 3 ways, 1 postringer to postringer, 2 global variable root. 3.return
	if(root == NULL){
		root=GetNewNode(userid,pass,type);

	}else if(userid <= root->userid){
		root->left = Insert(root->left,userid,pass,type);
		}
	else{
		root->right = Insert(root->right,userid,pass,type);
	}
	return root;
}

int main(){
    Admin admin;
    sales sales;
	while(!NULL){
        Login* root;
        root=NULL;
        string uid;
        string pas;
        string typ;

        string vID;
        string vPas;
        string vTyp;
        cout<<"----------------"<<endl;
        cout<<"     Login      " << endl;
        cout<<"----------------"<<endl;
        cout<<"Enter User ID:";
        cin >> vID;
        cout<<"Enter Password:";
        cin >> vPas;
        cout<<"Enter Account Type:";
        cin >> vTyp;

        string file = "C:\\Users\\user\\Desktop\\APU_Level2\\Semester 2\\DSTR\\GroupNo-Tp056678-Tp056815-Tp056564\\userinfo.txt";//Add the userinfo.txt file path here before running the program
        ifstream userinfo(file);
        string line;

        if(userinfo.is_open()){
            while(getline(userinfo,line)){
                istringstream ss(line);
                ss >> uid >> pas >> typ;
                root = Insert(root,uid,pas,typ);
            }
        }else{
            cout<<"file not found";
        }
        if(Search(root,vID,vPas,vTyp)== "a") {
            cout <<"Welcome Admin!\n";
            admin.choice();
        }
        if(Search(root,vID,vPas,vTyp)== "s") {
            cout <<"Welcome Sales\n";
            sales.choice();
        }
        else if(Search(root,vID,vPas,vTyp)== "f") {
            cout<< "Wrong ID or Password!" << endl;
        }
        }
        return 0;
}