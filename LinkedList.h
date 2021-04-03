#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <string>

using namespace std;

class LinkedList
{
	public:
		private:
    	Node* head;
        Node* prev;
        Node* curr;
        Node* tail;        
    public:
    	LinkedList();
        void addNode_User(string name, string psw); //no restriction - allow double, no sorting
        void addNode_dest(string dest, string leaving, string time_arrival, string time_departure, int tickets, int ID);
        void deleteNode(int item);
        void traverse_user();
        void traverse_dest();
        void buy_ticket(int bus_ID, string user);
        bool buy_ticket_dest (int bus_ID);
        void delete_dest(int bus_ID);
        int search_dest(int bus_ID);
        void tickets_bought(string user);
        bool search_user(string user);
        string verify_user(string username, string psw);
        ~LinkedList();
	protected:
};

#endif

