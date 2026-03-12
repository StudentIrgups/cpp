#include "menu/menu.h"

int main(void) {
    std::cout << Hello << std::endl;

    menu * omenu = new menu();
    int racesSize = omenu->get_races_size(); 

    for (int i = 0; i < racesSize; ++i) {
        std::cout << i+1 << ". " << omenu->get_races()[i] << std::endl;
    }
    
    std::cout << TakeTypeOfRace;
    int typeRace{0};
    std::cin >> typeRace;
    omenu->set_type_race(typeRace - 1);

    std::cout << TakeDistance;
    int dis{0};
    std::cin >> dis;
    omenu->set_distance(dis);

    std::cout << NeedNoLessThenTwoTypesOfVehilces << std::endl;
    std::cout << RegistrationVehicle << std::endl;
    std::cout << ChooseAction;
    int action{0};
    std::cin >> action;

    if (action == static_cast<int>(actions::Registration)) {
        std::string reged{""};
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
            std::cin >> action;
            if (action != static_cast<int>(actions::RegistrationStop)) {
                omenu->add_to_reg(action);
                std::cout << omenu->get_last() << RegistrationSuccess << std::endl;
                if (reged.length() == 0) 
                    reged = omenu->get_last();
                else
                    reged += ", " + omenu->get_last();
            }
        } while(action != 0);
    } else {
        std::cout << NoAction << std::endl;
    }
    return 0;
}