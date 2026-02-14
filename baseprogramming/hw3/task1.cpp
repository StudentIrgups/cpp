#include <iostream>
#include <fstream>
class addresses {
    std::string __city;
    std::string __street;
    int __building;
    int __room;

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

    public:
        addresses(){}
        addresses(std::string city, std::string street, int building, int room){
            __city     = city;
            __street   = street;
            __building = building;
            __room     = room;
        }
        std::string get_address() {
            return __city + ", " +__street + ", " + toStr(__building) +  ", " + toStr(__room); 
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

        addresses* package = new addresses[n];

        for (int i = 0; i < n; ++i) {
            std::string city{};
            std::string street{};
            std::string building{0};
            std::string room{0};

            file_in >> city;
            file_in >> street;
            file_in >> building;
            file_in >> room;

            package[i] = addresses(city, street, toInt(building), toInt(room));
        }
        file_in.close();
        
        if (sizeof(package) > 0) {
            std::ofstream file_out("out.txt");           
            if (file_out.is_open()) {

                file_out << size << std::endl;
                for (int i = size-1; i > -1; --i)
                    file_out << (package+i)->get_address()  << std::endl;
                file_out.close();
            }
        }
        delete[] package;
    }
    
    return 0;
}