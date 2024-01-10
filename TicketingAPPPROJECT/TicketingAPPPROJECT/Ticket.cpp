#include "Ticket.h"
#include <cstring>

Ticket::Ticket() {
    uniqueId = new char[1](); // Initialize with null character
    seatNumbers = new int[1]();
}

Ticket::Ticket(const char* id, const int* seats) {
    uniqueId = new char[strlen(id) + 1];
    strcpy_s(uniqueId,1, id);

    seatNumbers = new int[1]();
    *seatNumbers = *seats;
}

Ticket::~Ticket() {
    delete[] uniqueId;
    delete[] seatNumbers;
}

char* Ticket::getUniqueId() const {
    return uniqueId;
}

int* Ticket::getSeatNumbers() const {
    return seatNumbers;
}

void Ticket::setUniqueId(const char* id) {
    delete[] uniqueId;
    uniqueId = new char[strlen(id) + 1];
    strcpy_s(uniqueId,1, id);
}

void Ticket::setSeatNumbers(const int* seats) {
    delete[] seatNumbers;
    seatNumbers = new int[1]();
    *seatNumbers = *seats;
}

void Ticket::processTicket() {
    // Generic method implementation
}

void Ticket::displayTicketInfo() const {
    // Display ticket information
}

void Ticket::saveToFile(std::ofstream& file) const {
    // Save data to binary file
    file.write(reinterpret_cast<const char*>(uniqueId), sizeof(char) * (strlen(uniqueId) + 1));
    file.write(reinterpret_cast<const char*>(seatNumbers), sizeof(int));
}

void Ticket::loadFromFile(std::ifstream& file) {
    // Load data from binary file
    delete[] uniqueId;
    file.read(reinterpret_cast<char*>(&uniqueId), sizeof(char*));
    int idLength = strlen(uniqueId) + 1;
    uniqueId = new char[idLength];
    file.read(reinterpret_cast<char*>(uniqueId), sizeof(char) * idLength);

    delete[] seatNumbers;
    seatNumbers = new int;
    file.read(reinterpret_cast<char*>(seatNumbers), sizeof(int));
}

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
    // Implementation for output operator
    return os;
}

std::istream& operator>>(std::istream& is, Ticket& ticket) {
    // Implementation for input operator
    return is;
}

bool Ticket::operator==(const Ticket& other) const {
    // Implementation for relational operator
    return false;
}


