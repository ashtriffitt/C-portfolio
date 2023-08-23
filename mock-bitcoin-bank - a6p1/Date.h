//
// Created by datsu on 11/27/2022.
//

#ifndef ASSIGNMENT6_DATE_H
#define ASSIGNMENT6_DATE_H


class Date {
private :
    // All the information that a date holds
    int year;
    int month;
    int day;
    int minute;
    int hour;
    int second;

public :
    // This will get the date and time of whenever it is called.
    Date get_date();

};


#endif //ASSIGNMENT6_DATE_H
