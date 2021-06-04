#include "examDetails.h"


using namespace mtm;

ExamDetails::ExamDetails(int course_number, Month month, int day, float hour, int duration, std::string link = "")
{
        int rounded_hour = hour;

        if(day <= 0 || day > DAYS_IN_MONTH || month < JANUARY || month > DECEMBER)
        {
            throw InvalidDateException();
        }
        if(rounded_hour < 0 || rounded_hour > ROUNDED_HOUR_LIMIT)
        {
            throw InvalidTimeException();
        }
        if(course_number < 0 || duration < 0) //not quite sure if they meant that course_number should be natural number and not integer
        {
            throw InvalidArgsException();
        }

        this->course_number = course_number;
        this->day = day;
        this->month = month;
        this->hour = hour;
        this->duration = duration;
        this->link = link;
}


ExamDetails::ExamDetails(const ExamDetails& exam) : 
     course_number(exam.course_number), month(exam.month), day(exam.day), hour(exam.hour), duration(exam.duration), link(exam.link)
{
    //everything copied
}

ExamDetails::~ExamDetails()
{
    //nothing to do basically
}

ExamDetails& ExamDetails::operator=(const ExamDetails& exam)
{
    if(this == &exam)
    {
        return *this;
    }
    course_number = exam.course_number;
    day = exam.day;
    month = exam.month;
    hour = exam.hour;
    duration = exam.duration;
    link = exam.link;

    return *this;
}

ExamDetails ExamDetails::makeMatamExam()
{
    ExamDetails exam(MATAM_COURSE_NUM, JULY, MATAM_DAY, MATAM_HOUR, MATAM_DURATION, MATAM_LINK);
    return exam;
}

std::string ExamDetails::getLink()
{
    return this->link;
}


void ExamDetails::setLink(std::string link)
{
    this->link = link;
}

   
int ExamDetails::operator-(const ExamDetails& exam) const
{
    int month_diff = this->month - exam.month;

    return(this->day - exam.day + (month_diff * DAYS_IN_MONTH));
}

bool ExamDetails::operator<(const ExamDetails& exam) const
{
    if(this->month == exam.month)
    {
        if(this->day == exam.day)
        {
           return (this->hour < exam.hour); //return false if equal as required
        }
       
       return (this->day < exam.day);
    }

    return (this->month < exam.month);
}


std::ostream& mtm::operator<<(std::ostream& os, const ExamDetails& exam)
{
    std::string minutes = "00";
    int rounded_hour = exam.hour;
    
    if(exam.hour > rounded_hour)
    {
        minutes = "30";
    }

    os << "\n"
        << "Course Number: " << exam.course_number << "\n"
        << "Time: " << exam.day << "." << exam.month << "at" << rounded_hour << ":" << minutes << "\n"
        << "Duration: "<< exam.duration << ":" << "00" << "\n"
        << "Zoom Link: " << exam.link;

    return os;
}

