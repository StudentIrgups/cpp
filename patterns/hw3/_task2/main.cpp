#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Observer {
public:
    virtual ~Observer() = default;
    
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Observable {
private:
    std::vector<Observer*> observers_;

public:
    void addObserver(Observer* observer) {
        if (observer) {
            observers_.push_back(observer);
        }
    }

    void removeObserver(Observer* observer) {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer),
            observers_.end()
        );
    }

    void warning(const std::string& message) const {
        for (auto* obs : observers_) {
            obs->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        for (auto* obs : observers_) {
            obs->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        for (auto* obs : observers_) {
            obs->onFatalError(message);
        }
    }
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "[WARNING] " << message << std::endl;
    }
    
    ~WarningObserver() override {
        std::cout << "(WarningObserver уничтожен)" << std::endl;
    }
};

class ErrorObserver : public Observer {
private:
    std::string filepath_;
public:
    explicit ErrorObserver(const std::string& filepath) : filepath_(filepath) {}

    void onError(const std::string& message) override {
        std::ofstream file(filepath_, std::ios::app);
        if (file.is_open()) {
            file << "[ERROR] " << message << std::endl;
        }
    }
    
    ~ErrorObserver() override {
        std::cout << "(ErrorObserver уничтожен)" << std::endl;
    }
};

class FatalErrorObserver : public Observer {
private:
    std::string filepath_;
public:
    explicit FatalErrorObserver(const std::string& filepath) : filepath_(filepath) {}

    void onFatalError(const std::string& message) override {
        std::cout << "[FATAL] " << message << std::endl;

        std::ofstream file(filepath_, std::ios::app);
        if (file.is_open()) {
            file << "[FATAL] " << message << std::endl;
        }
    }
    
    ~FatalErrorObserver() override {
        std::cout << "(FatalErrorObserver уничтожен)" << std::endl;
    }
};

int main() {
    Observable logger;

    WarningObserver warningObs;
    ErrorObserver errorObs("errors.log");
    FatalErrorObserver fatalObs("fatal.log");

    logger.addObserver(&warningObs);
    logger.addObserver(&errorObs);
    logger.addObserver(&fatalObs);

    logger.warning("Низкий уровень заряда");
    logger.error("Ошибка подключения");
    logger.fatalError("Критический сбой системы");
    logger.removeObserver(&warningObs);
    logger.fatalError("Ещё одна фатальная ошибка");

    return 0;
}