#include "examDetails.h"


ExamDetails::ExamDetails(int course_number, Month month, int day, float hour, int duration, std::string link)
{

}

ExamDetails::ExamDetails(const ExamDetails& exam)
{

}

ExamDetails::~ExamDetails()
{

}

ExamDetails& ExamDetails::operator=(const ExamDetails& exam)
{

}

static ExamDetails::ExamDetails makeMatamExam()
{

}

std::string ExamDetails::getLink()
{
    return this->link;
}


void ExamDetails::setLink(std::string link)
{
    this->link = link;
    return;
}

   
int ExamDetails::operator-(const ExamDetails& exam) const
{
    return (this->day - exam.day); //not quite sure which one is the "right exam" and which is the "left exam"
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

}

