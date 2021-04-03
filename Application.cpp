#include "Application.h"

Application::Application(){
	list_user = new LinkedList();
	list_dest = new LinkedList();
	list_user->addNode_User("admin","admin");
	list_dest -> addNode_dest("johor", "KL", "23:55", "20:00", 5, 1);
	list_dest -> addNode_dest("johor1", "KL2", "21:55", "17:00", 51, 2);
	list_dest -> addNode_dest("johor2", "KL3", "22:55", "2:00", 52, 3);
	list_dest -> addNode_dest("johor3", "KL4", "20:55", "5:00", 53, 4);
}


void Application::addDestination(){
	system("cls");
	
	string destination, leaving, timeArrival, timeDeparture;
	int numberOfTickets, busID;
	
	cout << "Please input the destination for the bus" << endl;
	cin.ignore();
	getline(cin,destination);
	
	cout << "Please input place the bus is leaving from" << endl;
	getline(cin,leaving);
	
	cout << "Please input the time of arrivel (mm:ss)" << endl;
	getline(cin, timeArrival);
	
	cout << "Please input the time of departure (mm:ss)" << endl;
	getline(cin,timeDeparture);
	
	cout << "Please input the number of tickets available for the bus" << endl;
	cin >> numberOfTickets;
	
	cout << "Please input ID number for the bus" << endl;
	cin >> busID;
	
	int busIDCheck = list_dest->search_dest(busID);
	if(busIDCheck == -1){
		list_dest->addNode_dest(destination, leaving, timeArrival, timeDeparture, numberOfTickets, busID);
		cout << "Bus destination added." << endl;
	}else{
		cout << "Bus ID already in use! Bus destination not added." << endl;
	}
	cout << "\nPress any key to go back." << endl;
	getch();
}
void Application::deleteDestination(){
	system("cls");
	
	cout << "Please input the bus ID for the bus to delete" << endl;
	int busIDDelete;
	cin >> busIDDelete;
	list_dest -> delete_dest(busIDDelete);
	cout << "\nPress any key to go back." << endl;
	getch();
}



void Application::printBusTickets(){
	system("cls");
	list_dest->traverse_dest();
	cout << "\nPress any key to go back." << endl;
	getch();
}
void Application::buyBusTicket(string userName_){
	system("cls");
	cout << "Input bus ID to buy ticket." << endl;
	int busID;
	cin >> busID;
	int busIDCheck = list_dest->search_dest(busID);
	if(busIDCheck == -1){
		cout << "Bus ID does not exist. Ticket was not bought." << endl;
	}else{
		if(list_dest->buy_ticket_dest(busID)){
			list_user->buy_ticket(busID, userName_);
		}		
	}
	cout << "\nPress any key to go back." << endl;
	getch();
}

void Application::showTicketsBought(string userName_){
	system("cls");
	list_user->tickets_bought(userName_);
	cout << "\nPress any key to go back." << endl;
	getch();
}


void Application::adminScreen(){
	int goBack = 0;
	while(true){
		system("cls");
		cout << "Admin Screen" << endl;
		cout << "[0] Go back to start screen." << endl;
		cout << "[1] Add new destination." << endl;
		cout << "[2] Delete destination." << endl;
		cout << "[3] See available bus tickets." << endl;
		char input;
		cin >> input;
		while(true){
			switch(input){
				case '0':
					goBack = -1;
					break;
				case '1':
					addDestination();
					break;
				case '2':
					deleteDestination();
					break;
				case '3':
					printBusTickets();
					break;
				default:
					cout << "Input incorrect! Try again." << endl;
					continue;
			}
			break;
		}		
		if(goBack == -1){
			break;
		}
	}
}
void Application::userScreen(string userName_){
	int goBack = 0;
	while(true){
		system("cls");
		cout << "User Screen" << endl;
		cout << "Please chose on of the options below" << endl;
		cout << "[0] Go back to start screen." << endl;
		cout << "[1] See available bus tickets." << endl;
		cout << "[2] Buy bus ticket." << endl;
		cout << "[3] Tickets bought." << endl;
		char input;
		cin >> input;
		while(true){
			switch(input){
				case '0':
					goBack = -1;
					break;
				case '1':
					printBusTickets();
					break;
				case '2':
					buyBusTicket(userName_);
					break;
				case '3':
					showTicketsBought(userName_);
					break;
				default:
					cout << "Input incorrect! Try again." << endl;
					continue;
			}
			break;
		}
		if(goBack == -1){
			break;
		}
	}
}

void Application::loginScreen(){
	system("cls");
	string userName;
	string password;
	cin.ignore();
	cout << "Please type in your username:" << endl;
	getline(cin,userName);
	cout << "Please type in your password:" << endl;
	getline(cin,password);
	if(list_user->verify_user(userName,password) == "~false~"){
		cout << endl;
	}else{
		if(userName == "admin"){
			adminScreen();
		}else{
			userScreen(userName);
		}
	}
	
	cout << "\nPress any key to go back." << endl;
	getch();
}

void Application::registerScreen(){
	system("cls");
	cout << "Please chose a username:" << endl;
	string userName;
	cin.ignore();
	getline(cin,userName);
	cout << "Please chose a password:" << endl;
	string password;
	getline(cin,password);
	if(userName == "~false~"){
		cout << "Username: '~false~' is not available" << endl;
	}else if(list_user->search_user(userName)){
		cout << "Username already in uses, cannot create user." << endl;
	}else{
		list_user -> addNode_User(userName, password);
	}
	
	
	cout << "\nPress any key to go back." << endl;
	getch();
}

void Application::choice(char input_){
	char input = input_;
	while(true){
		switch(input){
			case '1':
				loginScreen();
				break;
			case '2':
				registerScreen();
				break;
			default:
				cout << "Input incorrect. Try again" << endl;
				cin >> input;
				continue;
		}
		break;
	}
}

void Application::mainScreen(){
	system("cls");
	cout << "Please chose your one of the two options below" << endl;
	cout << "[1] Login" << endl;
	cout << "[2] Register" << endl;
	char input;
	cin >> input;
	choice(input);
}


Application::~Application(){}








