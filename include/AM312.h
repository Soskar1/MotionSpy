#include <inttypes.h>
#include <Arduino.h>

namespace Core {
    // Motion sensor
    class AM312 {
        public:
        AM312(const uint8_t& pin);

        void begin() const;

        const uint8_t& getPin() const;
        int read() const;

        private:
        uint8_t pin;
    };
}