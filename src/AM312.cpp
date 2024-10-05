#include "AM312.h"

namespace Core {
    AM312::AM312(const uint8_t& pin) : pin(pin) { }

    void AM312::begin() const {
        pinMode(pin, INPUT);
    }

    const uint8_t& AM312::getPin() const {
        return pin;
    }

    int AM312::read() const {
        return digitalRead(pin);
    }
}