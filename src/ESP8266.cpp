#include "ESP8266.h"

namespace Core {
    ESP8266::ESP8266(const int& rxPin, const int& txPin) : serial(rxPin, txPin) { }

    void ESP8266::begin(const long& speed) {
        serial.begin(speed);
    }

    void ESP8266::end() {
        serial.end();
    }

    bool ESP8266::hasData() {
        return serial.available();
    }
    
    void ESP8266::send(const char* data) {
        serial.write(data);
        serial.write("\r\n");
        //serial.write()
    }

    String ESP8266::read() {
        return serial.readString();
    }

    void ESP8266::setOperationMode(const int& operationMode) {
        String command = "AT+CWMODE_CUR=" + String(operationMode);
        send(command.c_str());
    }

    void ESP8266::setOperationMode(const OperationMode& operationMode) {
        setOperationMode((int)operationMode);
    }
}