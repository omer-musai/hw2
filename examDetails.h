#include <string>

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
    ExamDetails(); //not sure if we need to create this one
    ExamDetails(int course_number, Month month, int day, float hour, int duration, std::string link);
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
    
};

//print operators must be defined as non_members
std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);
