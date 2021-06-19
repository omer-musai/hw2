#include "examDetails.h"


namespace mtm
{
    ExamDetails::ExamDetails(int course_number, int month, int day, float hour, int duration, const std::string& link)
    {
        int rounded_hour = (int)hour;

        if (std::abs(hour - (float)rounded_hour) < EPSILON)
        {
            hour = (float)rounded_hour;
        }
        else if (std::abs(hour - ((float)rounded_hour + 0.5)) < EPSILON)
        {
            hour = (float)rounded_hour + 0.5;
        }
        else if (std::abs(hour - (float)rounded_hour + 1) < EPSILON)
        {
            hour = (float)rounded_hour + 1;
        }
        else
        {
            throw InvalidTimeException();
        }

        if(day <= 0 || day > DAYS_IN_MONTH || month < 1 || month > 12)
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
        ExamDetails exam(MATAM_COURSE_NUM, MATAM_MONTH, MATAM_DAY, MATAM_HOUR, MATAM_DURATION, MATAM_LINK);
        return exam;
    }

    std::string ExamDetails::getLink() const
    {
        return this->link;
    }


    void ExamDetails::setLink(const std::string& new_link)
    {
        this->link = new_link;
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
                bool equal = std::abs(this->hour - exam.hour) < EPSILON;
                return (!equal && this->hour < exam.hour);
            }

            return (this->day < exam.day);
        }

        return (this->month < exam.month);
    }


    std::ostream& operator<<(std::ostream& os, const ExamDetails& exam)
    {
        std::string minutes = "00";
        int rounded_hour = (int)exam.hour;

        if(exam.hour > (float)rounded_hour)
        {
            minutes = "30";
        }

        os << "Course Number: " << exam.course_number << "\n"
           << "Time: " << exam.day << "." << exam.month << " at " << rounded_hour << ":" << minutes << "\n"
           << "Duration: "<< exam.duration << ":" << "00" << "\n"
           << "Zoom Link: " << exam.link << std::endl;

        return os;
    }
}