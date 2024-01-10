#pragma once
#include "Ticket.h"

class MovieTicket : public Ticket {
private:
    static int totalTicketsSold;
    char* category; // Dynamically allocated array of characters

public:
    MovieTicket();
    MovieTicket(const char* id, const int* seats, const char* category);
    ~MovieTicket();

    static int getTotalTicketsSold(); // Static method

    virtual void validateTicket() const override;

    virtual void processTicket() override; // Generic method
    virtual void displayTicketInfo() const override;

    virtual void saveToFile(std::ofstream& file) const override;
    virtual void loadFromFile(std::ifstream& file) override;
};
