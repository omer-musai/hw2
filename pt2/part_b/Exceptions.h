#ifndef MTM_EXCEPTIONS_H
#define MTM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace mtm
{
    class Exception : public std::exception
    {
        public:
            Exception() = delete;
            Exception(const Exception& other) = default;
            virtual ~Exception() noexcept = default;

            explicit Exception(const std::string& error_message);
            const char* what() const noexcept override;
        private:
            std::string error_type;
            std::string error_message;
    };

    class IllegalArgument : public Exception
    {
        public:
            IllegalArgument();
    };

    class IllegalCell : public Exception
    {
        public:
            IllegalCell();
    };

    class CellEmpty : public Exception
    {
        public:
            CellEmpty();
    };

    class CellOccupied : public Exception
    {
        public:
            CellOccupied();
    };

    class OutOfRange : public Exception
    {
        public:
            OutOfRange();
    };

    class OutOfAmmo : public Exception
    {
        public:
            OutOfAmmo();
    };

    class IllegalTarget : public Exception
    {   
        public:
            IllegalTarget();
    };

    class MoveTooFar : public Exception
    {
        public:
            MoveTooFar();
    };
}

#endif //MTM_EXCEPTIONS_H
