#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>

enum class LogType {
    WARNING,
    ERROR,
    FATAL_ERROR,
    UNKNOWN
};

class LogMessage {
private:
    LogType type_;
    std::string message_;
public:
    LogMessage(LogType type, const std::string& message) : type_(type), message_(message) {}

    LogType type() const { 
        return type_; 
    }
    const std::string& message() const { 
        return message_; 
    }
};


class LogHandler {
protected:
    std::unique_ptr<LogHandler> next_; 

public:
    virtual ~LogHandler() = default;

    LogHandler& setNext(std::unique_ptr<LogHandler> next) {
        next_ = std::move(next);
        return *this;
    }
    virtual void handle(const LogMessage& msg) = 0;
};

class FatalErrorHandler : public LogHandler {
public:
    void handle(const LogMessage& msg) override {
        if (msg.type() == LogType::FATAL_ERROR) {
            throw std::runtime_error("FATAL: " + msg.message());
        }
        if (next_) next_->handle(msg);
    }
};

class ErrorHandler : public LogHandler {
private:
    std::string filepath_;
public:
    explicit ErrorHandler(const std::string& filepath) : filepath_(filepath) {}

    void handle(const LogMessage& msg) override {
        if (msg.type() == LogType::ERROR) {
            std::ofstream file(filepath_, std::ios::app);
            if (file.is_open()) {
                file << "[ERROR] " << msg.message() << std::endl;
            }
        } else {
            if (next_) next_->handle(msg);
        }
    }
};

class WarningHandler : public LogHandler {
public:
    void handle(const LogMessage& msg) override {
        if (msg.type() == LogType::WARNING) {
            std::cout << msg.message() << std::endl;
        } else {
            if (next_) next_->handle(msg);
        }
    }
};

class UnknownHandler : public LogHandler {
public:
    void handle(const LogMessage& msg) override {
        if (msg.type() == LogType::UNKNOWN) {
            throw std::runtime_error("Неизвестное сообщение: " + msg.message());
        } else {
            if (next_) next_->handle(msg);
        }
    }
};

int main() {
    auto warning = std::make_unique<WarningHandler>();
    auto error = std::make_unique<ErrorHandler>("errors.log");
    auto fatal = std::make_unique<FatalErrorHandler>();
    auto unknown = std::make_unique<UnknownHandler>();

    error->setNext(std::move(warning));
    fatal->setNext(std::move(error));
    unknown->setNext(std::move(fatal)); 

    auto unknown2 = std::make_unique<UnknownHandler>();
    auto warning2 = std::make_unique<WarningHandler>();
    auto error2 = std::make_unique<ErrorHandler>("errors.log");
    auto fatal2 = std::make_unique<FatalErrorHandler>();

    warning2->setNext(std::move(unknown2));
    error2->setNext(std::move(warning2));
    fatal2->setNext(std::move(error2));

    LogHandler* head = fatal2.get();

    try {
        head->handle(LogMessage(LogType::WARNING, "Это предупреждение"));
        head->handle(LogMessage(LogType::ERROR, "Это ошибка"));
        head->handle(LogMessage(LogType::FATAL_ERROR, "Это фатальная ошибка"));
    } catch (const std::exception& e) {
        std::cerr << "Поймано исключение: " << e.what() << std::endl;
    }

    try {
        head->handle(LogMessage(LogType::UNKNOWN, "Что-то странное"));
    } catch (const std::exception& e) {
        std::cerr << "Поймано исключение: " << e.what() << std::endl;
    }
    return 0;
}