#include "examDetails.h"



ExamDetails::ExamDetails(int course_number, Month month, int day, float hour, int duration, std::string link = "") : 
    course_number(course_number), month(month), day(day), hour(hour), duration(duration), link(link)
    {
        //everything initialized
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
    return (this->day - exam.day); 
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

std::ostream& operator<<(std::ostream& os, const ExamDetails& exam)
{
    string minutes = "00";
    int rounded_hour = exam.hour;
    
    if(exam.hour > rounded_hour)
    {
        minutes = "30";
    }

    os << endl
        << "Course Number: " << exam.course_number << endl
        << "Time: " << exam.day << "." << exam.month << "at" << rounded_hour << ":" << minutes << endl
        << "Duration: "<< exam.duration << ":" << "00" << endl
        << "Zoom Link: " << exam.link;

    return os;
}

