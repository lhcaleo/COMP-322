#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
using namespace std;

struct ticket
{
    unsigned int numbers[6];
    ticket *next;
};
// Question 1
class SuperDraw
{
  private:
    ticket *ticketListHead;
    ticket *ticketListTail;

  public:
    SuperDraw();
    ~SuperDraw();
    SuperDraw(int n);
    SuperDraw(const SuperDraw &old_sd);
    void newTicket(int verbose = 0);
    void printAllTicketNumbers();
    void verifySequence(int nums[]);
    void deleteSequence(int nums[]);
};

// Constructor
SuperDraw::SuperDraw()
{
    this->ticketListHead = NULL;
    this->ticketListTail = NULL;
}
// Question 3, constructor with arg
SuperDraw::SuperDraw(int n)
{
    this->ticketListHead = NULL;
    this->ticketListTail = NULL;

    cout << n << " new ticket were successfuly generated. " << endl;
    cout << "";
    for (int i = 0; i < n; i++)
    {
        newTicket(2);
    }
}
// Question 7, Destructor
SuperDraw::~SuperDraw()
{
    ticket *ptr = this->ticketListHead;
    while (ptr != NULL)
    {
        ticket *tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    }
    this->ticketListHead = NULL;
    this->ticketListTail = NULL;
}
// Question 2
void SuperDraw::newTicket(int verbose)
{
    int arr[6];
    for(int i = 0; i < 6 ; i++){
        int r;
        bool same = true;
        // Avoid repeating numbers
        while(same){
            // random number
            r = rand()%49+1;
            for(int j = 0; j <= i; j++){
                // if it's already generated
                if(r == arr[j]){
                    same = true;
                } else {
                    same = false;
                }
            }    
        }
        arr[i] = r;
    }
    // sort array in ascending order
    sort(arr, arr + 6);
    // create a ticket and declare a ticket pointer point to it
    ticket *tmp = new ticket;

    tmp->next = NULL;
    if (ticketListHead == NULL)
    {
        ticketListHead = tmp;
        ticketListTail = tmp;
    }
    else
    {
        ticketListTail->next = tmp;
        ticketListTail = ticketListTail->next;
    }

    // generate 6 random numbers to the ticket
    for (int c = 0; c < 6; c++)
    {
        tmp->numbers[c] = arr[c];
    }

    // Print first 6 elements in the array if required
    if (verbose == 1)
    {
        cout << "A new ticket was successfully generated. " << endl;
        for (int k = 0; k < 6; k++)
        {
            if (k == 5)
            {
                cout << tmp->numbers[k] << endl;
            }
            else
            {
                cout << tmp->numbers[k] << ", ";
            }
        }
    }
    // Custom input for output of Q3
    if (verbose == 2)
    {
        cout << "The numbers are: ";
        for (int k = 0; k < 6; k++)
        {
            if (k == 5)
            {
                cout << tmp->numbers[k] << endl;
            }
            else
            {
                cout << tmp->numbers[k] << ", ";
            }
        }
    }
}
// Question 4
void SuperDraw::printAllTicketNumbers()
{
    ticket *tmp1 = this->ticketListHead;
    int count = 0;
    while (tmp1 != NULL)
    {
        count++;
        tmp1 = tmp1->next;
    }
    ticket *tmp2 = this->ticketListHead;
    cout << "We found " << count << " generated tickets: " << endl;
    while (tmp2 != NULL)
    {
        for (int k = 0; k < 6; k++)
        {
            if (k == 5)
            {
                cout << tmp2->numbers[k] << endl;
            }
            else
            {
                cout << tmp2->numbers[k] << ", ";
            }
        }
        tmp2 = tmp2->next;
    }
}
//Question 5
void SuperDraw::verifySequence(int nums[])
{
    bool generated = false;
    ticket *tmp = this->ticketListHead;
    while (tmp != NULL)
    {
        int same = 0;
        for (int k = 0; k < 6; k++)
        {
            if (nums[k] == tmp->numbers[k])
            {
                same++;
            }
        }
        if (same == 6)
        {
            generated = true;
            break;
        }
        tmp = tmp->next;
    }
    if (generated == true)
    {
        cout << "The provided sequence of numbers was already generated." << endl;
    }
    else
    {
        cout << "The provided sequence of numbers was never generated before." << endl;
    }
}
// Question 6
void SuperDraw::deleteSequence(int nums[])
{
    bool generated = false;

    ticket *tmp = this->ticketListHead;

    while (tmp != NULL)
    {
        int same = 0;
        for (int k = 0; k < 6; k++)
        {
            if (nums[k] == tmp->numbers[k])
            {
                same++;
            }
        }
        if (same == 6)
        {
            generated = true;
            break;
        }
        tmp = tmp->next;
    }
    if (generated == true)
    {
        // Find the previous ticket

        ticket *prev = this->ticketListHead;

        if (tmp == this->ticketListHead)
        {
            cout << "tmp is head " << endl;
            ticket *temp;
            temp = tmp->next;
            delete tmp;
            this->ticketListHead = temp;
            return;
        }

        while (prev->next != NULL && prev->next != tmp)
        {

            prev = prev->next;
        }
        ticket *temp;
        temp = prev->next;
        prev->next = temp->next;
        delete temp;
        cout << "The provided sequence of numbers was successfully deleted." << endl;
    }
    else
    {
        cout << "The provided sequence of numbers was never generated before." << endl;
    }
}
// Question 8, copy constructor
SuperDraw::SuperDraw(const SuperDraw &old_sd)
{
    this->ticketListHead = NULL;
    this->ticketListTail = NULL;

    if (old_sd.ticketListHead != NULL)
    {

        // pointer point to the old tickets head
        ticket *ptr = old_sd.ticketListHead;
        ticket *newTicket = new ticket;
        this->ticketListHead = newTicket;

        // for all tickets of this new SuperDraw
        while (true)
        {
            // copy 6 numbers
            for (int i = 0; i < 6; i++)
            {
                newTicket->numbers[i] = ptr->numbers[i];
            }
            // move to next ticket
            newTicket->next = new ticket;
            newTicket = newTicket->next;
            ptr = ptr->next;

            // Special case, when we reach the tail
            if (ptr == old_sd.ticketListTail)
            {

                for (int j = 0; j < 6; j++)
                {
                    newTicket->numbers[j] = ptr->numbers[j];
                }
                // Finally set the tail, and its next point to NULL, and break the loop
                this->ticketListTail = newTicket;
                newTicket->next = NULL;
                break;
            }
        }
    }
}

// Main method
int main()
{
    cout << "--Question 2 begin--" << endl;
    SuperDraw sd;
    sd.newTicket(1);
    cout << "--Question 2 end----\n" << endl;


    cout << "--Question 3 begin--" << endl;
    SuperDraw sdd(2);
    cout << "--Question 3 end----\n" << endl;


    cout << "--Question 4 begin--" << endl;
    sd.newTicket();
    sd.newTicket();
    sd.newTicket();
    sd.printAllTicketNumbers();
    cout << "--Question 4 end----\n" << endl;


    cout << "--Question 5 begin--" << endl;
    int myNumbers_1[6] = {2, 4, 17, 29, 31, 34};
    sd.verifySequence(myNumbers_1);
    cout << "--Question 5 end----\n" << endl;


    cout << "--Question 6 begin--" << endl;
    int myNumbers_2[6] = {2, 4, 6, 8, 10, 12};
    sd.verifySequence(myNumbers_2);
    cout << "--Question 6 end----\n" << endl;


    cout << "--Question 8 begin--" << endl;
    SuperDraw sd2(sd);
    sd2.printAllTicketNumbers();
    cout << "--Question 8 end----\n" << endl;
}