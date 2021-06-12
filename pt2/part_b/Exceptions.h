#ifndef MTM_EXCEPTIONS_H
#define MTM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace mtm
{
    class Exception : std::exception
    {
        public:
            Exception() = delete;
            Exception(const Exception& other) = default;
            virtual ~Exception() noexcept = default;

            explicit Exception(const std::string& error_message);
            const char* what() const noexcept override;
        private:
            std::string error_type;
    };

    class IllegalArgument : Exception
    {
        public:
            IllegalArgument();
    };

    class IllegalCell : Exception
    {
        public:
            IllegalCell();
    };

    class CellEmpty : Exception
    {
        public:
            CellEmpty();
    };

    class CellOccupied : Exception
    {
        public:
            CellOccupied();
    };

    class OutOfRange : Exception
    {
        public:
            OutOfRange();
    };

    class OutOfAmmo : Exception
    {
        public:
            OutOfAmmo();
    };

    class IllegalTarget : Exception
    {   
        public:
            IllegalTarget();

    };
}

#endif //MTM_EXCEPTIONS_H
