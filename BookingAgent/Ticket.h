#ifndef FINAL_TICKET_H
#define FINAL_TICKET_H


class Ticket {
protected:
    int date;
    int fullPrice;
    double discount;
public:
    Ticket(int d, int f) :
            date(d), fullPrice(f) {
        discount = 0.0;
    }

    int getDate() {
        return date;
    }

    double getTicketPrice() {
        return (1.0-discount) * fullPrice;
    }

    virtual void printTicket() = 0;

    virtual ~Ticket() {
    }
};


#endif
