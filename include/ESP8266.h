#include <SoftwareSerial.h>

namespace Core {
    enum OperationMode {
        STATION = 1, // 01
        ACCESS_POINT // 10
    };

    class ESP8266 {
        public:
        ESP8266(const int& rxPin, const int& txPin);

        void begin(const long& speed);
        void end();

        void send(const char* data);
        String read();

        void setOperationMode(const int& operationMode);
        void setOperationMode(const OperationMode& operationMode);
        void setBaudrate(const int& newBaudrate);

        bool hasData();

        private:
        SoftwareSerial serial;
    };
}