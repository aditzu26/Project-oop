#include "TheaterTicket.h"
#include <cstring>

int TheaterTicket::totalTicketsSold = 0;

TheaterTicket::TheaterTicket() : Ticket(), category(nullptr) {
    totalTicketsSold++;
}

TheaterTicket::TheaterTicket(const char* id, const int* seats, const char* category) : Ticket(id, seats) {
    totalTicketsSold++;

    // Dynamically allocate memory for category
    this->category = new char[strlen(category) + 1];
    strcpy_s(this->category,1, category);
}

TheaterTicket::~TheaterTicket() {
    // Deallocate memory for category
    delete[] category;
    totalTicketsSold--;
}

int TheaterTicket::getTotalTicketsSold() {
    return totalTicketsSold;
}

void TheaterTicket::validateTicket() const {
    // Implementation for theater ticket validation
}

void TheaterTicket::processTicket() {
    // Generic method implementation for theater ticket
}

void TheaterTicket::displayTicketInfo() const {
    // Display theater ticket information
}

void TheaterTicket::saveToFile(std::ofstream& file) const {
    // Save data to binary file, including data from the base class
    Ticket::saveToFile(file);

    // Save additional data specific to TheaterTicket
    int categoryLength = strlen(category) + 1;
    file.write(reinterpret_cast<const char*>(&categoryLength), sizeof(int));
    file.write(category, sizeof(char) * categoryLength);
}

void TheaterTicket::loadFromFile(std::ifstream& file) {
    // Load data from binary file, including data from the base class
    Ticket::loadFromFile(file);

    // Load additional data specific to TheaterTicket
    int categoryLength;
    file.read(reinterpret_cast<char*>(&categoryLength), sizeof(int));

    // Deallocate existing memory for category
    delete[] category;

    // Allocate new memory for category
    category = new char[categoryLength];
    file.read(category, sizeof(char) * categoryLength);
}
