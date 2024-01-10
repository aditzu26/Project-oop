#pragma once
#include <iostream>
#include <fstream>

class Ticket {
protected:
    const int MAX_SEATS = 1000;
    char* uniqueId; // Dynamically allocated array of characters
    int* seatNumbers; // Dynamically allocated array of integers

public:
    Ticket();
    Ticket(const char* id, const int* seats);
    virtual ~Ticket();

    char* getUniqueId() const;
    int* getSeatNumbers() const;
    void setUniqueId(const char* id);
    void setSeatNumbers(const int* seats);

    virtual void validateTicket() const = 0;

    virtual void processTicket(); // Generic method
    virtual void displayTicketInfo() const;

    virtual void saveToFile(std::ofstream& file) const;
    virtual void loadFromFile(std::ifstream& file);

    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
    friend std::istream& operator>>(std::istream& is, Ticket& ticket);
    bool operator==(const Ticket& other) const; // Relational operator
    Ticket operator++(); // Prefix increment operator
    Ticket operator--(int); // Postfix decrement operator
};
