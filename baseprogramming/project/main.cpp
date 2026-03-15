#include "mymenu.h"
#include <limits>

int main(void) {
    std::cout << Hello << std::endl;
    int action{0};
    do {
        menu * omenu = new menu();
        int racesSize = omenu->get_races_size(); 
        
        int typeRace{0};
        while(true) { 
            typeRace = 0;         
            for (int i = 0; i < racesSize; ++i) {
                std::cout << i+1 << ". " << omenu->get_races()[i] << std::endl << std::flush;
            }
            std::cout << TakeTypeOfRace << std::flush;   
             
            while (!(std::cin >> typeRace)) {
                std::cin.clear();                        
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');            
                std::cout << "Ошибка! Введите число: ";
            }
            
            std::system("clear");                
            typeRace = omenu->set_type_race(typeRace - 1);
            if (typeRace == -1) {
                std::cout << NoThisType << std::endl;
                continue;
            }
            break;
        } 
        
        std::cout << TakeDistance;
        int dis{0};
        std::cin >> dis;
        omenu->set_distance(dis);
        
        std::system("clear");
        std::string reged{""};
        std::cout << NeedNoLessThenTwoTypesOfVehilces << std::endl;
        int action1{0};
        do {
            std::cout << RegistrationVehicle << std::endl;
            if (omenu->get_reged_size() > 2) {
                std::cout << StartRaceing << std::endl;
            }
            std::cout << ChooseAction;
            
            std::cin >> action1;
            std::system("clear");

            if (action1 == static_cast<int>(actions::Registration)) {                
                do {
                    std::cout << omenu->get_type_race() << ". " << Distance << omenu->get_distance() << std::endl;
                    if (reged.length() > 0) {
                        std::cout << RegisteredVehicles << reged << std::endl;                
                    }
                    int arrvehicles_size = omenu->get_arrvehicles_size();

                    for (int i = 0; i < arrvehicles_size; ++i) {
                        std::cout << i+1 << ". " << omenu->get_vehicles()[i] << std::endl;
                    }
                    std::cout << dRegistrationStop << std::endl;
                    std::cout << ChooseVehicleOrZeroToStop;
                    std::cin >> action1;
                    std::system("clear");
                    if (action1 != static_cast<int>(actions::RegistrationStop)) {
                        std::string res = omenu->add_to_reg(action1-1);
                        if (res == "1") {
                            std::cout << omenu->get_last() << RegistrationSuccess << std::endl;
                            if (reged.length() == 0) 
                                reged = omenu->get_last();
                            else
                                reged += ", " + omenu->get_last();
                        } else {
                            std::cout << res << std::endl << std::endl;
                        }
                    }       
                } while (action1 != 0);      
            } else if (action1 == static_cast<int>(actions::StartRace)) {
                std::cout << Results << std::endl;

                for (int i = 0; i < omenu->get_reged_size() - 1; ++i) {
                    processor oprocessor;
                    vehicle ovehicle = omenu->get_reged()[i];
                    std::cout << i + 1 << ". " << ovehicle.get_name() << ". " << Time << oprocessor.process(omenu->get_reged()[i], dis) << std::endl;
                }               
                std::cout << std::endl;
                std::cout << AnotherRace << std::endl << Exit << std::endl; 
                std::cout << ChooseAction;
            
                std::cin >> action1;
                std::system("clear");
                reged = "";
                if (action1 == 2) {
                    action = 2;
                    break;
                }
            } else {
                delete omenu;
                std::cout << NoAction << std::endl;
                break;                
            }
        } while(action1 != 1);  
    } while (action != 2);
    return 0;
}