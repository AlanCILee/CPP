#include <iostream>

using namespace std;

class Date {
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int date);
    void addDay(int inc);
    void addMonth(int inc);
    void addYear(int inc);

    void showDate();
};

Date::Date(int year, int month, int date) {
    this->year = year;
    this->month = month;
    this->day = date;
}

void Date::showDate() {
    cout << this->year << "/" << this->month << "/" << this->day << endl;
}

void Date::addDay(int inc) { 
    while(inc > 0) {
        int maxAdded = 31;
        switch(this-> month) {
            case 2:
                if(((this->year & 0x03) == 0) && ((this->year % 100) != 0)) {
                    maxAdded = 29;                    
                } else {
                    maxAdded = 28;
                }
                break;
            case 4: case 6: case 9: case 11:
                maxAdded = 30;
                break;
            default:
                break;
        }

        if((this->day + inc) > maxAdded) {
            inc -= (maxAdded - this->day + 1);
            this->day = 1;
            addMonth(1);
        } else { 
            this->day += inc;
            inc = 0;
        } 
    }
} 
 
void Date::addMonth(int inc) {
    this->month += inc;
    int addYear = this->month / 12;
    this->month %= 12;    
    this->addYear(addYear);
}

void Date::addYear(int inc) {
    this->year += inc;
}

int main(){
    Date date {2020, 2, 25};
    date.addDay(365);
    date.showDate();
    date.addMonth(13);
    date.showDate();
}