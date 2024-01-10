#include "FootballTicket.h"
#include "MovieTicket.h"
#include "TheaterTicket.h"
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Football Ticket
    const char* footballTeams[] = { "TeamA", "TeamB" };
    FootballTicket ft("ABC123", new int(25), footballTeams, 2);

    // Movie Ticket
    MovieTicket mt("XYZ789", new int(50), "VIP");

    // Theater Ticket
    TheaterTicket tt("DEF456", new int(30), "Category1");

    // Display information using cout
    std::cout << "Football Ticket Info:\n";
    std::cout << "ID: " << ft.getUniqueId() << "\n";
    std::cout << "Seats: " << *ft.getSeatNumbers() << "\n";
    std::cout << "Teams: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << footballTeams[i] << " ";
    }
    std::cout << "\n";

    std::cout << "\nMovie Ticket Info:\n";
    std::cout << "ID: " << mt.getUniqueId() << "\n";
    std::cout << "Seats: " << *mt.getSeatNumbers() << "\n";
    // std::cout << "Category: " << mt.getCategory() << "\n";

    std::cout << "\nTheater Ticket Info:\n";
    std::cout << "ID: " << tt.getUniqueId() << "\n";
    std::cout << "Seats: " << *tt.getSeatNumbers() << "\n";
    // std::cout << "Category: " << tt.getCategory() << "\n";

    ft.saveToFile(outFile);
    mt.saveToFile(outFile);
    tt.saveToFile(outFile);

    outFile.close();

    // Load existing tickets from binary file
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return 1;
    }

    FootballTicket loadedFT;
    MovieTicket loadedMT;
    TheaterTicket loadedTT;

    loadedFT.loadFromFile(inFile);
    loadedMT.loadFromFile(inFile);
    loadedTT.loadFromFile(inFile);

    inFile.close();

   
  

    return 0;
}
