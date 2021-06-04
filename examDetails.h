
#include <string>
#include <iostream>

#define ROUNDED_HOUR_LIMIT 23
#define DAYS_IN_MONTH 30
#define MATAM_COURSE_NUM 234124
#define MATAM_DAY 28
#define MATAM_DURATION 3
#define MATAM_HOUR 13
#define MATAM_LINK "https://tinyurl.com/59hzps6m"

namespace mtm
{

enum Month{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};


class ExamDetails
{
    private:
        int course_number;
        int day;
        Month month;
        float hour;
        int duration;
        std::string link;

    public:
        //constructors
        ExamDetails(int course_number, Month month, int day, float hour, int duration, std::string link = "");
        ExamDetails(const ExamDetails& exam); //that's the copy constructor
        
        //destructor
        ~ExamDetails();
        //assignment operator (should release old resources and allocate new ones)
        ExamDetails& operator=(const ExamDetails& exam);

        //methods
        static ExamDetails makeMatamExam();    
        std::string getLink();
        void setLink(std::string link);

        //operators
        int operator-(const ExamDetails& exam) const;
        bool operator<(const ExamDetails& exam) const;

        //print operator
        friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);

        //exceptions
        class InvalidDateException {};
        class InvalidTimeException {};
        class InvalidArgsException {};
        
};


}