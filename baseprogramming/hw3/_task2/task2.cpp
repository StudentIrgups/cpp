#include <iostream>
#include <fstream>

class addresses {
    public:
        struct __address {
            std::string __city;
            std::string __street;
            int __building;
            int __room;
        };
        addresses(){}
        addresses(int size):__size(size) {
            __size = size;
            package = new __address[__size];
        }
        
        std::string get_address() {
            std::string tmp = toStr(__size) + "\n";
            for (int i = 0; i < __size; ++i) {
                tmp += package[i].__city            + " " + 
                       package[i].__street          + " " + 
                       toStr(package[i].__building) + " " +
                       toStr(package[i].__room)     + "\n";
            }
            return tmp;
        } 
        void insertAddress(__address &adr) { 
            package[__now++] = adr; 
            if (__now == 1)         
                return;
            else {
                for (int i = 0; i < __now; ++i){
                    for (int j = i; j < __now; ++j) {
                        if (package[i].__city > package[j].__city) {
                            __address tmp = package[i];
                            package[i] = package[j];
                            package[j] = tmp;
                        }
                    }
                }
            }
        }
        ~addresses(){
            delete[] package;
        }
    private:
        int __size = 0;
        int __now = 0;
        __address* package;

        std::string toStr(int num) {
            std::string str = "";
            while (num != 0) {
                char c = num % 10;
                str += c + '0';
                num /= 10;
            }
            int len = str.length();
            for (int i = 0; i < len/2; ++i){
                char tmp = str[i];
                str[i] = str[len-1-i];
                str[len-1-i] = tmp;
            }
            return str;
        }

};

int toInt(std::string data) {
    int n = 0;
    for (int i = 0; i < data.length(); ++i) {
        n *= 10;
        n += data[i] - '0';        
    }
    return n;
}

int main(void){
    std::ifstream file_in("in.txt");

    if (file_in.is_open()) {
        std::string data{};
        file_in >> data;
        int n = toInt(data);
        int size = n;

        addresses instance(n);
        addresses::__address address;

        for (int i = 0; i < n; ++i) {
            std::string city{};
            std::string street{};
            std::string building{0};
            std::string room{0};

            file_in >> city;
            file_in >> street;
            file_in >> building;
            file_in >> room;

            address.__city     = city;
            address.__street   = street;
            address.__building = toInt(building);
            address.__room     = toInt(room);

            instance.insertAddress(address);
        }
        file_in.close();
        
        std::ofstream file_out("out.txt");           
        if (file_out.is_open()) {
            file_out << instance.get_address();
            file_out.close();
        } 
    }
    
    return 0;
}