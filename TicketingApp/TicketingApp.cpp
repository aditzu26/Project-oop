#include <iostream>
#include <cstring>
#include "EventTicket.h"
#include "MovieTicket.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;



int EventTicket::totalTickets = 0;
int main() {
    EventTicket ticket("Concert", 100, 50.0);
   // cout << ticket;
    

    return 0;
}