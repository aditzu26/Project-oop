#include "FootballTicket.h"
#include <cstring>

int FootballTicket::totalTicketsSold = 0;

FootballTicket::FootballTicket() : Ticket(), teams(nullptr), numTeams(0) {
    totalTicketsSold++;
}

FootballTicket::FootballTicket(const char* id, const int* seats, const char** teams, int numTeams) : Ticket(id, seats), numTeams(numTeams) {
    totalTicketsSold++;

    // Dynamically allocate memory for teams
    this->teams = new char* [numTeams];
    for (int i = 0; i < numTeams; ++i) {
        this->teams[i] = new char[strlen(teams[i]) + 1];
        strcpy_s(this->teams[i],1, teams[i]);
    }
}

FootballTicket::~FootballTicket() {
    // Deallocate memory for teams
    for (int i = 0; i < numTeams; ++i) {
        delete[] teams[i];
    }
    delete[] teams;

    totalTicketsSold--;
}

int FootballTicket::getTotalTicketsSold() {
    return totalTicketsSold;
}

void FootballTicket::validateTicket() const {
    // Implementation for football ticket validation
}

void FootballTicket::processTicket() {
    // Generic method implementation for football ticket
}

void FootballTicket::displayTicketInfo() const {
    // Display football ticket information
}

void FootballTicket::saveToFile(std::ofstream& file) const {
    // Save data to binary file, including data from the base class
    Ticket::saveToFile(file);

    // Save additional data specific to FootballTicket
    file.write(reinterpret_cast<const char*>(&numTeams), sizeof(int));
    for (int i = 0; i < numTeams; ++i) {
        int teamLength = strlen(teams[i]) + 1;
        file.write(reinterpret_cast<const char*>(&teamLength), sizeof(int));
        file.write(teams[i], sizeof(char) * teamLength);
    }
}

void FootballTicket::loadFromFile(std::ifstream& file) {
    // Load data from binary file, including data from the base class
    Ticket::loadFromFile(file);

    // Load additional data specific to FootballTicket
    file.read(reinterpret_cast<char*>(&numTeams), sizeof(int));

    // Deallocate existing memory for teams
    for (int i = 0; i < numTeams; ++i) {
        delete[] teams[i];
    }
    delete[] teams;

    // Allocate new memory for teams
    teams = new char* [numTeams];
    for (int i = 0; i < numTeams; ++i) {
        int teamLength;
        file.read(reinterpret_cast<char*>(&teamLength), sizeof(int));

        teams[i] = new char[teamLength];
        file.read(teams[i], sizeof(char) * teamLength);
    }
}
