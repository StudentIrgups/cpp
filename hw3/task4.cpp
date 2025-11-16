#include <iostream>
std::string getStrNum(int num) {
    std::string first_s{};
    if (num == 0)
        first_s = "Zero";
    else if (num == 100)
        first_s = "Hundred";
    else if (num < 10)
        switch (num) {
            case 1: first_s = "One"; break;
            case 2: first_s = "Two"; break;
            case 3: first_s = "Three"; break;
            case 4: first_s = "Four"; break;
            case 5: first_s = "Five"; break;
            case 6: first_s = "Six"; break;
            case 7: first_s = "Seven"; break;
            case 8: first_s = "Eight"; break;
            case 9: first_s = "Nine"; break;
        }
    else
    switch (num / 10) {
        case 1: switch (num % 10) {
                case 1: first_s = "Eleven"; break;
                case 2: first_s = "Twelve"; break;
                case 3: first_s = "Thirteen"; break;
                case 4: first_s = "Fourteen"; break;
                case 5: first_s = "Fiveteen"; break;
                case 6: first_s = "Sixteen"; break;
                case 7: first_s = "Seventeen"; break;
                case 8: first_s = "Eighteen"; break;
                case 9: first_s = "Nineteen"; break;
                case 0: first_s = "Ten"; break;
            } break;
        case 2: switch (num % 10) {
                case 1: first_s = "Twenty-one"; break;
                case 2: first_s = "Twenty-two"; break;
                case 3: first_s = "Twenty-three"; break;
                case 4: first_s = "Twenty-four"; break;
                case 5: first_s = "Twenty-five"; break;
                case 6: first_s = "Twenty-six"; break;
                case 7: first_s = "Twenty-seven"; break;
                case 8: first_s = "Twenty-eight"; break;
                case 9: first_s = "Twenty-nine"; break;
                case 0: first_s = "Twenty"; break;
            } break;
        case 3: switch (num % 10) {
                case 1: first_s = "Thirty-one"; break;
                case 2: first_s = "Thirty-two"; break;
                case 3: first_s = "Thirty-three"; break;
                case 4: first_s = "Thirty-four"; break;
                case 5: first_s = "Thirty-five"; break;
                case 6: first_s = "Thirty-six"; break;
                case 7: first_s = "Thirty-seven"; break;
                case 8: first_s = "Thirty-eight"; break;
                case 9: first_s = "Thirty-nine"; break;
                case 0: first_s = "Thirty"; break;
            } break;
        case 4: switch (num % 10) {
                case 1: first_s = "Fourty-one"; break;
                case 2: first_s = "Fourty-two"; break;
                case 3: first_s = "Fourty-three"; break;
                case 4: first_s = "Fourty-four"; break;
                case 5: first_s = "Fourty-five"; break;
                case 6: first_s = "Fourty-six"; break;
                case 7: first_s = "Fourty-seven"; break;
                case 8: first_s = "Fourty-eight"; break;
                case 9: first_s = "Fourty-nine"; break;
                case 0: first_s = "Fourty"; break;
            } break;
        case 5: switch (num % 10) {
                case 1: first_s = "Fivety-one"; break;
                case 2: first_s = "Fivety-two"; break;
                case 3: first_s = "Fivety-three"; break;
                case 4: first_s = "Fivety-four"; break;
                case 5: first_s = "Fivety-five"; break;
                case 6: first_s = "Fivety-six"; break;
                case 7: first_s = "Fivety-seven"; break;
                case 8: first_s = "Fivety-eight"; break;
                case 9: first_s = "Fivety-nine"; break;
                case 0: first_s = "Fivety"; break;
            } break;
        case 6: switch (num % 10) {
                case 1: first_s = "Sixty-one"; break;
                case 2: first_s = "Sixty-two"; break;
                case 3: first_s = "Sixty-three"; break;
                case 4: first_s = "Sixty-four"; break;
                case 5: first_s = "Sixty-five"; break;
                case 6: first_s = "Sixty-six"; break;
                case 7: first_s = "Sixty-seven"; break;
                case 8: first_s = "Sixty-eight"; break;
                case 9: first_s = "Sixty-nine"; break;
                case 0: first_s = "Sixty"; break;
            } break;
        case 7: switch (num % 10) {
                case 1: first_s = "Seventy-one"; break;
                case 2: first_s = "Seventy-two"; break;
                case 3: first_s = "Seventy-three"; break;
                case 4: first_s = "Seventy-four"; break;
                case 5: first_s = "Seventy-five"; break;
                case 6: first_s = "Seventy-six"; break;
                case 7: first_s = "Seventy-seven"; break;
                case 8: first_s = "Seventy-eight"; break;
                case 9: first_s = "Seventy-nine"; break;
                case 0: first_s = "Seventy"; break;
            } break;
        case 8: switch (num % 10) {
                case 1: first_s = "Eighty-one"; break;
                case 2: first_s = "Eighty-two"; break;
                case 3: first_s = "Eighty-three"; break;
                case 4: first_s = "Eighty-four"; break;
                case 5: first_s = "Eighty-five"; break;
                case 6: first_s = "Eighty-six"; break;
                case 7: first_s = "Eighty-seven"; break;
                case 8: first_s = "Eighty-eight"; break;
                case 9: first_s = "Eighty-nine"; break;
                case 0: first_s = "Eighty"; break;
            } break;
        case 9: switch (num % 10) {
                case 1: first_s = "Ninety-one"; break;
                case 2: first_s = "Ninety-two"; break;
                case 3: first_s = "Ninety-three"; break;
                case 4: first_s = "Ninety-four"; break;
                case 5: first_s = "Ninety-five"; break;
                case 6: first_s = "Ninety-six"; break;
                case 7: first_s = "Ninety-seven"; break;
                case 8: first_s = "Ninety-eight"; break;
                case 9: first_s = "Ninety-nine"; break;
                case 0: first_s = "Ninety"; break;
            } break;
    }
    return first_s;
}
int main () {
    int first{};
    std::cout << "Enter first number: ";
    std::cin >> first;

    int second{};
    std::cout << "Enter second number: ";
    std::cin >> second;    

    if (first > 100  || first < -100 || second > 100 || second < -100) {
        std::cout << "Error! One from numbres out of range!" << std::endl;
    } else 
    std::cout << 
        (first < 0 ? "Minus " : "") 
        + getStrNum(first < 0 ? first * -1 : first) 

        << (first > second ? " more than " : first == second ? " equal " : " less than ") <<

        (second < 0 ? "Minus " : "") 
        + getStrNum(second < 0 ? second * -1 : second)         
        << std::endl;    
    return 0;
}