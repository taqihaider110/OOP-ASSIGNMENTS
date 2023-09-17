#include <iostream>
#include <string>
using namespace std;

class Flight
{
private:
    int flight_no;
    string source;
    string destination;
    int available_seats;

public:
    Flight() : flight_no(0), available_seats(0), source("empty"), destination("empty") {}
    Flight(int x, int y) : flight_no(x), available_seats(y) {}

    void set_data()
    {
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
        lengthCheck();
    }

    void reserve_seat(int seat)
    {
        if (seat > available_seats)
        {
            cout << "Seats not available!" << endl;
        }
        else
        {
            available_seats -= seat;
            cout << "Your seats have been reserved!" << endl;
        }
    }

    void cancel_reservation(int seat, char choice)
    {
        if (choice == 'y' || choice == 'Y')
        {
            int temp;
            cout << "Number of seats you want to cancel: ";
            cin >> temp;
            if (temp > seat)
            {
                cout << "Invalid Input!" << endl;
            }
            else
            {
                available_seats += temp;
                cout << "You have canceled " << seat - temp << " seats" << endl;
                cout << "Available Seats: " << available_seats << endl;
            }
        }
        else
        {
            cout << "Present Seats Available are " << available_seats << endl;
        }
    }

    void display()
    {
        cout << "Flight Number: " << getFlightNumber() << endl;
        cout << "From: " << getSource() << endl;
        cout << "To: " << getDestination() << endl;
    }

    int getFlightNumber() const
    {
        return flight_no;
    }

    string getSource() const
    {
        return source;
    }

    string getDestination() const
    {
        return destination;
    }

    pair<int, int> getFlightInfo() const
    {
        return make_pair(flight_no, available_seats);
    }

    void lengthCheck()
    {
        if (source.length() > 3)
        {
            source = source.substr(0, 3);
            for (char &c : source)
            {
                c = toupper(static_cast<unsigned char>(c));
            }
        }
        if (destination.length() > 3)
        {
            destination = destination.substr(0, 3);
            for (char &c : destination)
            {
                c = toupper(static_cast<unsigned char>(c));
            }
        }
    }
};

int main()
{
    Flight f[2];
    int flight_no[2], available_seats;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter Details of Flight " << i + 1 << endl;
        cout << "Enter Flight Number: ";
        cin >> flight_no[i];
        cout << "Enter Number Of Seats Available: ";
        cin >> available_seats;
        f[i] = Flight(flight_no[i], available_seats);
        f[i].set_data();

        int seat;
        cout << "Enter Number Of Seats You Want To Reserve: ";
        cin >> seat;
        f[i].reserve_seat(seat);

        char choice;
        cout << "Do you want to modify/cancel your reservations (Y/y or N/n): ";
        cin >> choice;
        f[i].cancel_reservation(seat, choice);
        f[i].display();
    }

    cout << endl;

    for (int i = 0; i < 2; i++)
    {
        if (flight_no[i] == flight_no[i + 1])
        {
            cout << "The Flights Are Same!" << endl;
        }
        else
        {
            cout << "The Flights Are Not Same!" << endl;
        }
    }

    return 0;
}
