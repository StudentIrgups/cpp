#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class SomeDevice {
   public: 
      SomeDevice(const std::string& name) : name_(name){}
      std::string rise_message() {
         return "Device " + name_ + " return: some data";
      }
   private:
      std::string name_;
};

class LogCommand {
   public:
      virtual ~LogCommand() = default;
      virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
   public:
      void print(const std::string& message) override {
         std::cout << message << std::endl;
      }
};

class FileLogCommand : public LogCommand {
   public:
      explicit FileLogCommand(const std::string& filename) : filename_(filename){}

      void print(const std::string& message) override {
         std::ofstream file(filename_, std::ios::app);
         if (file.is_open()) {
            file << message << std::endl;
         }
      }
   private:
      std::string filename_;
};

class RemoteControl {
   std::vector<LogCommand*> commands_;
   public:
      void add_command(LogCommand* command) {
         commands_.push_back(command);
      }
      void push_message(int slot, const std::string& message) {
         if (slot >= 0 && slot < commands_.size())
            commands_[slot]->print(message);
      }
};

int main() {

   SomeDevice d1("TV");
   SomeDevice d2("PC");
   SomeDevice d3("HotSpot");

   RemoteControl remote;
   remote.add_command(new ConsoleLogCommand());
   remote.add_command(new FileLogCommand("./file.txt"));

   remote.push_message(0, d1.rise_message());
   remote.push_message(1, d1.rise_message());

   remote.push_message(0, d2.rise_message());
   remote.push_message(1, d2.rise_message());

   remote.push_message(0, d3.rise_message());
   remote.push_message(1, d3.rise_message());

   return 0;
}