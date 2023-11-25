#ifndef CONCERTTICKET_H
#define CONCERTTICKET_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class ConcertTicket {
private:
    string eventName;
    int maxSeats;
    string artists;
    int concertLength;
    string seatType;

    static int totalConcertTickets;  // Static field

public:
    // Constructors
    ConcertTicket(const string& eventName, int maxSeats, const string& artists, int concertLength, const string& seatType)
        : eventName(eventName), maxSeats(maxSeats), artists(artists), concertLength(concertLength), seatType(seatType) {
        totalConcertTickets++;  // Increment static field in the constructor
    }

    ConcertTicket(const ConcertTicket& other)
        : eventName(other.eventName + "_copy"), maxSeats(other.maxSeats),
          artists(other.artists + "_copy"), concertLength(other.concertLength), seatType(other.seatType) {
        totalConcertTickets++;  // Increment static field in the copy constructor
    }

    // Destructor
    ~ConcertTicket() {
        totalConcertTickets--;  // Decrement static field in the destructor
    }

    // Overloaded operator =
    ConcertTicket& operator=(const ConcertTicket& other) {
        if (this != &other) {  // Avoid self-assignment
            eventName = other.eventName + "_copy";
            maxSeats = other.maxSeats;
            artists = other.artists + "_copy";
            concertLength = other.concertLength;
            seatType = other.seatType;
        }
        return *this;
    }

    // Accessor methods
    const string& GetEventName() const {
        return eventName;
    }

    void SetEventName(const string& name) {
        eventName = name;
    }

    int GetMaxSeats() const {
        return maxSeats;
    }

    void SetMaxSeats(int seats) {
        if (seats > 0) {
            maxSeats = seats;
        } else {
            throw invalid_argument("Max seats must be greater than 0.");
        }
    }

    const string& GetArtists() const {
        return artists;
    }

    void SetArtists(const string& artistList) {
        artists = artistList;
    }

    int GetConcertLength() const {
        return concertLength;
    }

    void SetConcertLength(int length) {
        if (length >= 0) {
            concertLength = length;
        } else {
            throw invalid_argument("Concert length cannot be negative.");
        }
    }

    const string& GetSeatType() const {
        return seatType;
    }

    void SetSeatType(const string& type) {
        seatType = type;
    }

    // Additional methods
    void DisplayTicketInfo() const {
        cout << "Event: " << eventName << ", Artists: " << artists
             << ", Max Seats: " << maxSeats << ", Concert Length: " << concertLength
             << ", Seat Type: " << seatType << endl;
    }

    double CalculateTotalPrice() const {
        // Assume some calculation based on concert attributes
        return concertLength * maxSeats;
    }

    // Operator overloads
    friend ostream& operator<<(ostream& os, const ConcertTicket& ticket) {
        os << "Event: " << ticket.eventName << ", Artists: " << ticket.artists
           << ", Max Seats: " << ticket.maxSeats << ", Concert Length: " << ticket.concertLength
           << ", Seat Type: " << ticket.seatType;
        return os;
    }

    friend istream& operator>>(istream& is, ConcertTicket& ticket) {
        cout << "Enter event name: ";
        is >> ticket.eventName;

        cout << "Enter max seats: ";
        is >> ticket.maxSeats;

        cout << "Enter artists (separated by commas): ";
        is >> ticket.artists;

        cout << "Enter concert length (in minutes): ";
        is >> ticket.concertLength;

        cout << "Enter seat type: ";
        is >> ticket.seatType;

        return is;
    }

    string operator[](int index) const {
        // For simplicity, returning a value based on the index
        return artists + to_string(index);
    }

    ConcertTicket operator+(const ConcertTicket& other) const {
        // Concatenating artist names and creating a new ConcertTicket
        return ConcertTicket("", 0, artists + other.artists, 0, seatType);
    }

    ConcertTicket operator++() {
        // Prefix increment operator, upgrading seat type
        if (seatType == "normal") {
            seatType = "premium";
        } else if (seatType == "premium") {
            seatType = "vip";
        } else if (seatType == "vip") {
            seatType = "ultravip";
        }
        return *this;
    }

    ConcertTicket operator++(int) {
        // Postfix increment operator, upgrading seat type
        ConcertTicket temp = *this;
        if (seatType == "normal") {
            seatType = "premium";
        } else if (seatType == "premium") {
            seatType = "vip";
        } else if (seatType == "vip") {
            seatType = "ultravip";
        }
        return temp;
    }

    operator int() const {
        // Cast operator to int, converting concert length to int
        return static_cast<int>(concertLength);
    }

    ConcertTicket operator!() const {
        // Negation operator, swapping between normal and ultravip seat types
        ConcertTicket temp = *this;
        if (seatType == "normal") {
            temp.seatType = "ultravip";
        } else if (seatType == "ultravip") {
            temp.seatType = "normal";
        }
        return temp;
    }

    bool operator<(const ConcertTicket& other) const {
        // Conditional operator <, checking if the seat type is "better" than the other
        // (normal < premium < vip < ultravip)
        return GetSeatTypePriority(seatType) < GetSeatTypePriority(other.seatType);
    }

    bool operator==(const ConcertTicket& other) const {
        // Equality operator ==, checking if seat types are the same
        return seatType == other.seatType;
    }

    // Static method
    static int GetTotalConcertTickets() {
        return totalConcertTickets;
    }

private:
    // Helper method to determine seat type priority
    static int GetSeatTypePriority(const string& type) {
        if (type == "normal") {
            return 0;
        } else if (type == "premium") {
            return 1;
        } else if (type == "vip") {
            return 2;
        } else if (type == "ultravip") {
            return 3;
        } else {
            return -1; // Unknown seat type
        }
    }
};

#endif // CONCERTTICKET_H
