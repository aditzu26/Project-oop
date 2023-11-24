#include <iostream>
#include <cstring>
#ifndef EVENTTICKET_H
#define EVENTTICKET_H

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class EventTicket {
private:
    char* eventName;    // Dynamically defined field
    int* seatNumbers;   // Statically defined array
    static int totalTickets; // Static field
    const int maxSeats; // Constant field
    double ticketPrice;

public:
    // Constructors
    EventTicket(const char* name, int maxSeats, double price);
    EventTicket(const EventTicket& other);
    EventTicket& operator=(const EventTicket& other);
    ~EventTicket();

    // Accessor functions
    const char* GetEventName() const;
    void SetEventName(const char* name);

    const int* GetSeatNumbers() const;
    void SetSeatNumbers(const int* seats, int count);

    double GetTicketPrice() const;
    void SetTicketPrice(double price);

    // Other methods
    void DisplayTicketInfo() const;
    void ProcessTicket();

    // Overloaded operators
    int& operator[](int index);
    EventTicket operator+(const EventTicket& other) const;
    EventTicket operator++();        // Prefix increment
    EventTicket operator++(int);     // Postfix increment
    explicit operator double() const; // Explicit cast to double
    bool operator!() const;           // Negation operator
    bool operator<(const EventTicket& other) const;
    bool operator==(const EventTicket& other) const;

    // Friend functions
    friend ostream& operator<<(ostream& os, const EventTicket& ticket);
    friend istream& operator>>(istream& is, EventTicket& ticket);
};

// Implementation of the class methods
EventTicket::EventTicket(const char* name, int maxSeats, double price)
    : maxSeats(maxSeats), ticketPrice(price) {
    eventName = new char[strlen(name) + 1];

    strcpy_s(eventName, strlen(name) + 1, name);

    seatNumbers = new int[maxSeats];
    totalTickets++;
}

EventTicket::EventTicket(const EventTicket& other) : maxSeats(other.maxSeats), ticketPrice(other.ticketPrice) {
    eventName = new char[strlen(other.eventName) + 1];
    strcpy_s(eventName, strlen(other.eventName) + 1, other.eventName);

    seatNumbers = new int[maxSeats];
    memcpy(seatNumbers, other.seatNumbers, maxSeats * sizeof(int));
    totalTickets++;
}

EventTicket& EventTicket::operator=(const EventTicket& other) {
    if (this != &other) {
        delete[] eventName;
        delete[] seatNumbers;

        eventName = new char[strlen(other.eventName) + 1];
        strcpy_s(eventName, strlen(other.eventName) + 1, other.eventName);

        seatNumbers = new int[maxSeats];
        memcpy(seatNumbers, other.seatNumbers, maxSeats * sizeof(int));

        ticketPrice = other.ticketPrice;
    }
    return *this;
}

EventTicket::~EventTicket() {
    delete[] eventName;
    delete[] seatNumbers;
    totalTickets--;
}

const char* EventTicket::GetEventName() const {
    return eventName;
}

void EventTicket::SetEventName(const char* name) {
    delete[] eventName;
    eventName = new char[strlen(name) + 1];
    strcpy_s(eventName, strlen(name) + 1, name);
}

const int* EventTicket::GetSeatNumbers() const {
    return seatNumbers;
}

void EventTicket::SetSeatNumbers(const int* seats, int count) {
    // Validation and exception handling can be added here
    if (count > maxSeats) {
        throw invalid_argument("Number of seats exceeds the maximum allowed.");
    }

    memcpy(seatNumbers, seats, count * sizeof(int));
}

double EventTicket::GetTicketPrice() const {
    return ticketPrice;
}

void EventTicket::SetTicketPrice(double price) {
    ticketPrice = price;
}

void EventTicket::DisplayTicketInfo() const {
    cout << "Event: " << eventName << endl;
    cout << "Seats: ";
    for (int i = 0; i < maxSeats; ++i) {
        cout << seatNumbers[i] << " ";
    }
    cout << endl;
}

void EventTicket::ProcessTicket() {
    // Implementation for processing a ticket
}

int& EventTicket::operator[](int index) {
    // Validation and exception handling can be added here
    if (index < 0 || index >= maxSeats) {
        throw out_of_range("Invalid index for seatNumbers.");
    }

    return seatNumbers[index];
}

EventTicket EventTicket::operator+(const EventTicket& other) const {
    EventTicket result(*this);
    for (int i = 0; i < maxSeats; ++i) {
        result.seatNumbers[i] += other.seatNumbers[i];
    }
    return result;
}

EventTicket EventTicket::operator++() {
    // Incrementing all seat numbers by 1
    for (int i = 0; i < maxSeats; ++i) {
        ++seatNumbers[i];
    }
    return *this;
}

EventTicket EventTicket::operator++(int) {
    EventTicket temp(*this);
    // Incrementing all seat numbers by 1
    for (int i = 0; i < maxSeats; ++i) {
        ++seatNumbers[i];
    }
    return temp;
}

EventTicket::operator double() const {
    return ticketPrice;
}

bool EventTicket::operator!() const {
    // Negation logic - consider a ticket to be invalid if the event name is empty
    return (eventName == nullptr) || (strlen(eventName) == 0);
}

bool EventTicket::operator<(const EventTicket& other) const {
    // Comparison based on the number of seat numbers
    return maxSeats < other.maxSeats;
}

bool EventTicket::operator==(const EventTicket& other) const {
    // Equality check based on both event name and seat numbers
    return (strcmp(eventName, other.eventName) == 0) && (maxSeats == other.maxSeats);
}

ostream& operator<<(ostream& os, const EventTicket& ticket) {
    os << "Event: " << ticket.eventName << ", Seats: ";
    for (int i = 0; i < ticket.maxSeats; ++i) {
        os << ticket.seatNumbers[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, EventTicket& ticket) {
    cout << "Enter event name: ";
    is >> ticket.eventName;


    ticket.seatNumbers = new int[ticket.maxSeats];

    cout << "Enter seat numbers: ";
    for (int i = 0; i < ticket.maxSeats; ++i) {
        is >> ticket.seatNumbers[i];
    }

    cout << "Enter ticket price: ";
    is >> ticket.ticketPrice;

    return is;
}

#endif
