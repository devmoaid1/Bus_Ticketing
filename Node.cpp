#include "Node.h"

Node::Node(string name, string psw)
{
	user_name = name;
	user_psw = psw;
	ticket_counter = 0;
	tickets_amount = 0;
	for (int i=0; i<100; i++)
	{
		tickets[i] = -1;
	}
}

Node::Node(string des, string leav, string time_a, string time_d, int tickets_, int ID)
{
	dest = des;
	leaving = leav;
	time_arrival = time_a;
	time_departure = time_d;
	tickets_amount = tickets_;
	bus_ID = ID;
}

void Node::buy_tick(int bus_ID)
{
	tickets[ticket_counter]=bus_ID;
	ticket_counter++;
	if (ticket_counter == 100)
	{
		ticket_counter = 0;
	}
}

Node::~Node()
{
}

