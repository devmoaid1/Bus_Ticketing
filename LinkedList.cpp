#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    prev = NULL;
    curr = NULL;
    tail = NULL;
}

void LinkedList::addNode_User(string name, string psw)
{
    Node *newNode = new Node(name, psw);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode; //put newNode on the front of tail
        tail = newNode;       // set newNode as the new tail
    }
}

void LinkedList::addNode_dest(string dest, string leaving, string time_arrival, string time_departure, int tickets, int ID)
{
    Node *newNode = new Node(dest, leaving, time_arrival, time_departure, tickets, ID);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode; //put newNode on the front of tail
        tail = newNode;       // set newNode as the new tail
    }
}

void LinkedList::traverse_user()
{
    curr = head;
    if (curr == NULL)
        cout << "List is empty!";
    else
        while (curr != NULL)
        {
            cout << "User: " << curr->user_name << endl;
            curr = curr->next;
        }
}

void LinkedList::traverse_dest()
{
    curr = head;
    if (curr == NULL)
        cout << "List is empty!";
    else
        while (curr != NULL)
        {
            cout << "destination: " << curr->dest;
            cout << " departure: " << curr->leaving;
            cout << " time departure: " << curr->time_departure;
            cout << " time arrival: " << curr->time_arrival;
            cout << " number of tickets: " << curr->tickets_amount;
            cout << " Bus ID: " << curr->bus_ID << endl;
            curr = curr->next;
        }
}

bool LinkedList::search_user(string user)
{
    curr = head;
    while ((curr != NULL) && (curr->user_name != user))
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string LinkedList::verify_user(string username, string psw)
{
    bool found;
    curr = head;
    while ((curr != NULL) && (curr->user_name != username))
    {
        curr = curr->next;
    }

    if (curr == NULL)
        cout << "User " << username << " do not exist in list" << endl;
    else
    {
        if (curr->user_psw == psw)
        {
            cout << "Succesful login" << endl;
            return username;
        }
        else
        {
            cout << "Password incorrect" << endl;
        }
    }

    return "~false~";
}

void LinkedList::delete_dest(int bus_)
{
    bool found;
    curr = head;
    while ((curr != NULL) && (curr->bus_ID != bus_))
    {
        prev = curr; //to assign new tail for tail deletion!
        curr = curr->next;
    }

    if (curr == NULL)
        cout << "Bus ID " << bus_ << " does not exist in list - no deletion!" << endl;
    else
    {
        cout << "Bus ID " << bus_ << " is deleted" << endl;
        if (curr == head) // deletion on the head
        {
            head = curr->next;
            delete curr;
        }
        else if (curr == tail)
        {
            tail = prev;
            tail->next = NULL;
            delete curr;
        }
        else // item deletion in a middle of 2 nodes
        {
            prev->next = curr->next;
            delete curr;
        }
    }
}

void LinkedList::buy_ticket(int bus_ID, string user)
{
    curr = head;
    while ((curr != NULL) && (curr->user_name != user))
    {
        curr = curr->next;
    }

    if (curr == NULL)
        cout << "User Doesn't exist. Should never happen" << endl;
    else
    {
        cout << "Ticket bought" << endl;
        curr->buy_tick(bus_ID);
    }
}

int LinkedList::search_dest(int bus_)
{
    int found = 0;
    curr = head;
    while ((curr != NULL) && (curr->bus_ID != bus_))
    {
        curr = curr->next;
        found++;
    }

    if (curr == NULL)
    {
        return -1;
    }
    else
    {
        return found;
    }
}

bool LinkedList::buy_ticket_dest(int bus_)
{
    curr = head;
    while ((curr != NULL) && (curr->bus_ID != bus_))
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return false;
    }
    else
    {
        if (curr->tickets_amount == 0)
        {
            cout << "no more tickets" << endl;
            return false;
        }
        else
        {
            curr->tickets_amount--;
            return true;
        }
    }
    return false;
}

void LinkedList::tickets_bought(string user)
{
    curr = head;
    while ((curr != NULL) && (curr->user_name != user))
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << "shouldn't happen, means user doesn't exist" << endl;
    }
    else
    {
        cout << "Owned tickets: " << endl;
        int i = 0;
        while (curr->tickets[i] != -1)
        {
            cout << "Bus ID: " << curr->tickets[i] << endl;
            i++;
        }
    }
}

LinkedList::~LinkedList()
{
}
