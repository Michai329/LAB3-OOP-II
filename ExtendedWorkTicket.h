#pragma once
/* This is a ExtendedWorkTicket class header file so that we will intialize all the data in here and also define it here. This code
 * is just for the understanding for polymorphism and inheritance. This will be the child class taking all the attributes from
 * WorkTicket class. We will be adding one more vairble which will see to that if the ticket is opened or not. To check that we will
 * also overload and override some of the functions.
 *
 * @author: Kaifkhan Vakil.
 * @author:  Michai Pryce.
 * Date: 2nd October 2020.
 */
#pragma once



#ifndef _EXTENDED_WORK_TICKET_
#define _EXTENDED_WORK_TICKET_



#include "WorkTicket.h"
#include <string>



 /* Creating a class from the base class WorkTicket. And like base class, child class will also be public. */
class ExtendedWorkTicket : public WorkTicket
{
    // Declaring a private bool method to check if the ticket is open or not. 
private:
    bool isOpen;



public:
    //Constructor function:
    ExtendedWorkTicket() : isOpen(true){}
    ExtendedWorkTicket(bool Ticket_open);



    ExtendedWorkTicket(int ticket_number, const string& client_id, int month, int day, int year,
                       const string& description,
                       bool Ticket_open);
    // Declaring a SetWorkTicket mutator, we will overload this function and will add one more parameter for isOpen.
    bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool Ticket_open = true);



   //  Declaring a accessor which will show the output in the method as we want.
    void ShowWorkTicket() const override;



   //  Declaring a mutator which will change the isOpen variable to false.
    bool CloseTicket();



   //  Declaring a getter method for isOpen.
    bool getOpen() const;



   //  Declaring a setter method for isOpen.
    void SetOpen(bool value);



   //  Declaring a output stream function to overload it.
    friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& show);
};



// Defining ostream function.
inline ostream& operator<<(ostream& out, const ExtendedWorkTicket& show)
{
    // This will have the same functionality as the ShowWorkTicket() function method. But this will also have one more attribute for
    // isOpen.
    out << "\nWork Ticket #: " << WorkTicket(show).GetTicketNumber()
        << "\nClient ID:     " << WorkTicket(show).GetClientId()
        << "\nDate:          " << WorkTicket(show).GetDate()
        << "\nIssue:         " << WorkTicket(show).GetDescription()
        << ExtendedWorkTicket(show).getOpen();
    //out << ExtendedWorkTicket(show).ShowWorkTicket();
    return out;
}



//inline ExtendedWorkTicket::ExtendedWorkTicket( const int ticket_number, const string& client_id, const int month, const int day, const int year, const string& description, bool Ticket_open)
//{
//    SetTicketNumber(ticket_number);
//    SetClientId(client_id);
//    SetDescription(description);
//    SetDate(day, month, year);
//    SetOpen(Ticket_open);
//    
//}



// Defining SetWorkTicket function which will decide the value to each of the attribute.
inline bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year,
    const string& description, bool Ticket_open)
{
    // First it will have same validation as the SetWorkTicket function in the WorkTicket class.
    WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description);
    // Adding to it this function will set the value for the isOpen attribute.
    isOpen = Ticket_open;



    return true;

}



// Defining ShoeWorkTicket accessor to displpay the output in the manner we want, but we also want to add isOpen function into it.
inline void ExtendedWorkTicket::ShowWorkTicket() const
{
    // This is just taking function from the bass class.
    WorkTicket::ShowWorkTicket();
    // This will display the message if the ticket is closed or open.
    if (getOpen() == true)
    {
        cout << "Ticket is opened" << endl;
    }
    else
    {
        cout << "Ticket is closed" << endl;
    }
}




// Defining closeTicket mutator. This will change the isOpen to false
inline bool ExtendedWorkTicket::CloseTicket()
{
    if (isOpen == true)
    {
        isOpen = false;
    }
    return isOpen;
}



// Defining accessor for isOpen function.
inline bool ExtendedWorkTicket::getOpen() const
{
    return isOpen;
}



// Defining mutator for isOpen function.
inline void ExtendedWorkTicket::SetOpen(bool value)
{
    isOpen = value;
}
#endif