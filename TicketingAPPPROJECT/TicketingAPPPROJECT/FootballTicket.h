#pragma once
#include "Ticket.h"

class FootballTicket : public Ticket {
private:
    static int totalTicketsSold;
    char** teams; // Dynamically allocated array of strings
    int numTeams;

public:
    FootballTicket();
    FootballTicket(const char* id, const int* seats, const char** teams, int numTeams);
    ~FootballTicket();

    static int getTotalTicketsSold(); // Static method

    virtual void validateTicket() const override;

    virtual void processTicket() override; // Generic method
    virtual void displayTicketInfo() const override;

    virtual void saveToFile(std::ofstream& file) const override;
    virtual void loadFromFile(std::ifstream& file) override;
};
