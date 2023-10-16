#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


enum class Size { Small, Medium, Large, ExtraLarge };
enum class Thickness { Thin, Regular, Thick };
enum class Topping { Cheese, Tomato, Pepperoni, Mushroom, Bacon, Olives, Onions, Mushrooms, Pineapple };
enum class ExtraTopping { None, Olives, Onions, Mushrooms, Pineapple };

Size stringToSize(const string& sizeStr) {
    static map<string, Size> sizeMap = {
        {"Small", Size::Small},
        {"Medium", Size::Medium},
        {"Large", Size::Large},
        {"ExtraLarge", Size::ExtraLarge}
    };
    return sizeMap[sizeStr];
}

Thickness stringToThickness(const string& thicknessStr) {
    static map<string, Thickness> thicknessMap = {
        {"Thin", Thickness::Thin},
        {"Regular", Thickness::Regular},
        {"Thick", Thickness::Thick}
    };
    return thicknessMap[thicknessStr];
}
string sizeToString(Size size) {
    static map<Size, string> sizeMap = {
        {Size::Small, "Small"},
        {Size::Medium, "Medium"},
        {Size::Large, "Large"},
        {Size::ExtraLarge, "ExtraLarge"}
    };
    return sizeMap[size];
}

string thicknessToString(Thickness thickness) {
    static map<Thickness, string> thicknessMap = {
        {Thickness::Thin, "Thin"},
        {Thickness::Regular, "Regular"},
        {Thickness::Thick, "Thick"}
    };
    return thicknessMap[thickness];
}

string toppingToString(Topping topping) {
    static map<Topping, string> toppingMap = {
        {Topping::Cheese, "Cheese"},
        {Topping::Tomato, "Tomato"},
        {Topping::Pepperoni, "Pepperoni"},
        {Topping::Mushroom, "Mushroom"},
        {Topping::Bacon, "Bacon"},
        {Topping::Olives, "Olives"},
        {Topping::Onions, "Onions"},
        {Topping::Mushrooms, "Mushrooms"},
        {Topping::Pineapple, "Pineapple"}
    };
    return toppingMap[topping];
}

string extraToppingToString(ExtraTopping extraTopping) {
    static map<ExtraTopping, string> extraToppingMap = {
        {ExtraTopping::None, "None"},
        {ExtraTopping::Olives, "Olives"},
        {ExtraTopping::Onions, "Onions"},
        {ExtraTopping::Mushrooms, "Mushrooms"},
        {ExtraTopping::Pineapple, "Pineapple"}
    };
    return extraToppingMap[extraTopping];
}

Topping stringToTopping(const string& toppingStr) {
    static map<string, Topping> toppingMap = {
        {"Cheese", Topping::Cheese},
        {"Tomato", Topping::Tomato},
        {"Pepperoni", Topping::Pepperoni},
        {"Mushroom", Topping::Mushroom},
        {"Bacon", Topping::Bacon},
        {"Olives", Topping::Olives},
        {"Onions", Topping::Onions},
        {"Mushrooms", Topping::Mushrooms},
        {"Pineapple", Topping::Pineapple}
    };
    return toppingMap[toppingStr];
}

ExtraTopping stringToExtraTopping(const string& extraToppingStr) {
    static map<string, ExtraTopping> extraToppingMap = {
        {"None", ExtraTopping::None},
        {"Olives", ExtraTopping::Olives},
        {"Onions", ExtraTopping::Onions},
        {"Mushrooms", ExtraTopping::Mushrooms},
        {"Pineapple", ExtraTopping::Pineapple}
    };
    return extraToppingMap[extraToppingStr];
}

class Pizza {
private:
    Size size;
    Thickness thickness;
    float price;
    Topping topping;
    ExtraTopping extraTopping;

    void calculatePrice();

public:
    Pizza(Size size, Thickness thickness, Topping topping, ExtraTopping extraTopping);
    void displayPizzaDetails();
};

void Pizza::calculatePrice() {
    switch (size) {
    case Size::Small:
        price = 10;
        break;
    case Size::Medium:
        price = 15;
        break;
    case Size::Large:
        price = 20;
        break;
    case Size::ExtraLarge:
        price = 25;
        break;
    }

    switch (topping) {
    case Topping::Cheese:
        price += 5;
        break;
    case Topping::Tomato:
        price += 4;
        break;
    case Topping::Pepperoni:
        price += 6;
        break;
    case Topping::Mushroom:
        price += 4;
        break;
    case Topping::Bacon:
        price += 5;
        break;
    }

    switch (extraTopping) {
    case ExtraTopping::None:
        break;
    case ExtraTopping::Olives:
        price += 2;
        break;
    case ExtraTopping::Onions:
        price += 2;
        break;
    case ExtraTopping::Mushrooms:
        price += 2;
        break;
    case ExtraTopping::Pineapple:
        price += 2;
        break;
    }
}
Pizza::Pizza(Size size, Thickness thickness, Topping topping, ExtraTopping extraTopping)
    : size(size), thickness(thickness), topping(topping), extraTopping(extraTopping) {
    calculatePrice();
}

void Pizza::displayPizzaDetails() {
    cout << "Size: " <<sizeToString(size)<< "\n";
    cout << "Thickness: " << thicknessToString(thickness) << "\n";
    cout << "Topping: " << toppingToString(topping) << "\n";
    cout << "Extra Topping: " << extraToppingToString(extraTopping) << "\n";
    cout << "Price: " << price << "\n";
}



int main() {
    string choice;
    Pizza* pizza = nullptr;
    vector<Pizza*> pizzas;

    while (true) {
        cout << "1. Order a new pizza\n";
        cout << "2. Confirm payment and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            string sizeStr, thicknessStr, toppingStr, extraToppingStr;

            cout << "Enter size (Small, Medium, Large, ExtraLarge): ";
            cin >> sizeStr;
            cout << "Enter thickness (Thin, Regular, Thick): ";
            cin >> thicknessStr;
            cout << "Enter topping (Cheese, Tomato, Pepperoni, Mushroom, Bacon, Olives, Onions, Mushrooms, Pineapple): ";
            cin >> toppingStr;
            cout << "Enter extra topping (None, Olives, Onions, Mushrooms, Pineapple): ";
            cin >> extraToppingStr;

            Size size = stringToSize(sizeStr);
            Thickness thickness = stringToThickness(thicknessStr);
            Topping topping = stringToTopping(toppingStr);
            ExtraTopping extraTopping = stringToExtraTopping(extraToppingStr);

            pizza = new Pizza(size, thickness, topping, extraTopping);
            pizzas.push_back(pizza);

            pizza->displayPizzaDetails();
        }
        else if (choice == "2") {
            if (!pizzas.empty()) {
                cout << "Confirm payment for " << pizzas.size() << " pizzas? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    break;
                }
            }
            else {
                cout << "No pizza ordered yet.\n";
            }
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    for (Pizza* p : pizzas) {
        delete p;
    }

    return 0;
}
