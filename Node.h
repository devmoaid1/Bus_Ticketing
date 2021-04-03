#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		string user_name;
		string user_psw;
		string dest;
		string leaving;
		string time_arrival;
		string time_departure;
		int tickets_amount;
		int bus_ID;
		int tickets [100];
		int ticket_counter;
        Node *next;
        Node (string name, string psw);
        Node (string dest, string leaving, string time_arrival, string time_departure, int tickets, int ID);
        void buy_tick(int bus_ID);
		~Node();
	protected:
};

#endif

