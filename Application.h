#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

#include "Node.h"
#include "LinkedList.h"

using namespace std;


class Application
{
	private:
		LinkedList *list_user;
		LinkedList *list_dest;
	public:
		Application();
		void addDestination();
		void deleteDestination();
		void printBusTickets();
		void buyBusTicket(string userName_);
		void showTicketsBought(string userName_);
		void adminScreen();
		void userScreen(string userName_);
		void loginScreen();
		void registerScreen();
		void choice(char input_);
		void mainScreen();
		~Application();
};

#endif

