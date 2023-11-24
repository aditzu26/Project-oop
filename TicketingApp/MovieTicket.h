#ifndef MOVIETICKET_H
#define MOVIETICKET_H

#include <iostream>


using namespace std;

class MovieTicket {
private:
    string eventName;
    int maxSeats;
    string movieTitle;
    double ticketPrice;

    static int totalMovieTickets;  // Static field
    const double TAX_RATE = 0.1;   // Constant field

public:
    // Constructors
    MovieTicket(const string& eventName, int maxSeats, const string& movieTitle, double ticketPrice)
        : eventName(eventName), maxSeats(maxSeats), movieTitle(movieTitle), ticketPrice(ticketPrice) {
        totalMovieTickets++;  // Increment static field in the constructor
    }

    MovieTicket(const MovieTicket& other)
        : eventName(other.eventName + "_copy"), maxSeats(other.maxSeats),
        movieTitle(other.movieTitle + "_copy"), ticketPrice(other.ticketPrice) {
        totalMovieTickets++;  // Increment static field in the copy constructor
    }

    // Destructor
    ~MovieTicket() {
        totalMovieTickets--;  // Decrement static field in the destructor
    }

    // Overloaded operator =
    MovieTicket& operator=(const MovieTicket& other) {
        if (this != &other) {  // Avoid self-assignment
            eventName = other.eventName + "_copy";
            maxSeats = other.maxSeats;
            movieTitle = other.movieTitle + "_copy";
            ticketPrice = other.ticketPrice;
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
        }
        else {
            throw invalid_argument("Max seats must be greater than 0.");
        }
    }

    const string& GetMovieTitle() const {
        return movieTitle;
    }

    void SetMovieTitle(const string& title) {
        movieTitle = title;
    }

    double GetTicketPrice() const {
        return ticketPrice;
    }

    void SetTicketPrice(double price) {
        if (price >= 0) {
            ticketPrice = price;
        }
        else {
            throw invalid_argument("Ticket price cannot be negative.");
        }
    }

    // Additional methods
    void DisplayTicketInfo() const {
        cout << "Event: " << eventName << ", Movie: " << movieTitle
            << ", Max Seats: " << maxSeats << ", Ticket Price: $" << ticketPrice << endl;
    }

    double CalculateTotalPrice() const {
        return ticketPrice * maxSeats;
    }

    // Operator overloads
    friend ostream& operator<<(ostream& os, const MovieTicket& ticket) {
        os << "Event: " << ticket.eventName << ", Movie: " << ticket.movieTitle
            << ", Max Seats: " << ticket.maxSeats << ", Ticket Price: $" << ticket.ticketPrice;
        return os;
    }

    friend istream& operator>>(istream& is, MovieTicket& ticket) {
        cout << "Enter event name: ";
        is >> ticket.eventName;

        cout << "Enter max seats: ";
        is >> ticket.maxSeats;

        cout << "Enter movie title: ";
        is >> ticket.movieTitle;

        cout << "Enter ticket price: $";
        is >> ticket.ticketPrice;

        return is;
    }

    double operator[](int index) const {
        // For simplicity, returning a value based on the index
        return ticketPrice + index;
    }

    MovieTicket operator+(const MovieTicket& other) const {
        // Adding ticket prices and creating a new MovieTicket
        return MovieTicket("", 0, "", ticketPrice + other.ticketPrice);
    }

    MovieTicket operator++() {
        // Prefix increment operator, increasing ticket price
        ticketPrice++;
        return *this;
    }

    MovieTicket operator++(int) {
        // Postfix increment operator, increasing ticket price
        MovieTicket temp = *this;
        ticketPrice++;
        return temp;
    }

    operator double() const {
        // Cast operator to double, converting ticket price to double
        return static_cast<double>(ticketPrice);
    }

    bool operator!() const {
        // Negation operator, checking if ticket price is zero
        return ticketPrice == 0;
    }

    bool operator<(const MovieTicket& other) const {
        // Conditional operator <, checking if the ticket is more expensive than the other
        return ticketPrice < other.ticketPrice;
    }

    bool operator==(const MovieTicket& other) const {
        // Equality operator ==, checking if ticket prices are the same
        return ticketPrice == other.ticketPrice;
    }

    // Static method
    static int GetTotalMovieTickets() {
        return totalMovieTickets;
    }
};

#endif // MOVIETICKET_H

