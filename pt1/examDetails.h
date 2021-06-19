
#include <string>
#include <iostream>
#include <cmath>

#define ROUNDED_HOUR_LIMIT 23
#define DAYS_IN_MONTH 30
#define MATAM_COURSE_NUM 234124
#define MATAM_MONTH 7
#define MATAM_DAY 28
#define MATAM_DURATION 3
#define MATAM_HOUR 13
#define MATAM_LINK "https://tinyurl.com/59hzps6m"

namespace mtm
{
    class ExamDetails
    {
        private:
            int course_number;
            int day;
            int month;
            float hour;
            int duration;
            std::string link;
            static constexpr float EPSILON = 0.000001;

        public:
            //constructors
            ExamDetails(int course_number, int month, int day, float hour, int duration, const std::string& link = "");
            ExamDetails(const ExamDetails& exam) = default;

            //destructor
            ~ExamDetails() = default;
            //assignment operator (should release old resources and allocate new ones)
            ExamDetails& operator=(const ExamDetails& exam);

            //methods
            static ExamDetails makeMatamExam();
            std::string getLink() const;
            void setLink(const std::string& link);

            //operators
            int operator-(const ExamDetails& exam) const;
            bool operator<(const ExamDetails& exam) const;

            //print operator
            friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);

            //exceptions
            class InvalidDateException : std::exception {};
            class InvalidTimeException : std::exception {};
            class InvalidArgsException : std::exception {};

    };
}