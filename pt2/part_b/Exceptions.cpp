#include "Exceptions.h"

namespace mtm
{
    Exception::Exception(const std::string& error_type) : error_type(error_type)
    {}

    const char* Exception::what() const noexcept {
        return ("A game related error has occurred: " + error_type).c_str();
    }

    IllegalArgument::IllegalArgument()
        : Exception("IllegalArgument")
    {}

    IllegalCell::IllegalCell() :
        Exception("IllegalCell")
    {}

    CellEmpty::CellEmpty() :
        Exception("CellEmpty")
    {}

    CellOccupied::CellOccupied() :
        Exception("CellOccupied")
    {}

    OutOfRange::OutOfRange() :
        Exception("OutOfRange")
    {}

    OutOfAmmo::OutOfAmmo() :
        Exception("OutOfAmmo")
    {}

    IllegalTarget::IllegalTarget() :
        Exception("IllegalTarget")
    {}

    MoveTooFar::MoveTooFar() :
        Exception("MoveTooFar")
    {}
}