#include "MovieTicket.h"
#include <cstring>

int MovieTicket::totalTicketsSold = 0;

MovieTicket::MovieTicket() : Ticket(), category(nullptr) {
    totalTicketsSold++;
}

MovieTicket::MovieTicket(const char* id, const int* seats, const char* category) : Ticket(id, seats) {
    totalTicketsSold++;

    // Dynamically allocate memory for category
    this->category = new char[strlen(category) + 1];
    strcpy_s(this->category,1, category);
}

MovieTicket::~MovieTicket() {
    // Deallocate memory for category
    delete[] category;
    totalTicketsSold--;
}

int MovieTicket::getTotalTicketsSold() {
    return totalTicketsSold;
}

void MovieTicket::validateTicket() const {
    // Implementation for movie ticket validation
}

void MovieTicket::processTicket() {
    // Generic method implementation for movie ticket
}

void MovieTicket::displayTicketInfo() const {
    // Display movie ticket information
}

void MovieTicket::saveToFile(std::ofstream& file) const {
    // Save data to binary file, including data from the base class
    Ticket::saveToFile(file);

    // Save additional data specific to MovieTicket
    int categoryLength = strlen(category) + 1;
    file.write(reinterpret_cast<const char*>(&categoryLength), sizeof(int));
    file.write(category, sizeof(char) * categoryLength);
}

void MovieTicket::loadFromFile(std::ifstream& file) {
    // Load data from binary file, including data from the base class
    Ticket::loadFromFile(file);

    // Load additional data specific to MovieTicket
    int categoryLength;
    file.read(reinterpret_cast<char*>(&categoryLength), sizeof(int));

    // Deallocate existing memory for category
    delete[] category;

    // Allocate new memory for category
    category = new char[categoryLength];
    file.read(category, sizeof(char) * categoryLength);
}
