

#include <string>
#include <iostream>
#include <memory> // std::auto_ptr
class Sensor {
public:
    virtual void get_price() const = 0;
    virtual ~Sensor() {};
};

class Temp: public Sensor {
public:
    virtual void get_price() const {
        std::cout << "Temperature sensor" << std::endl;
    }
};

class DeluxePizza : public Sensor {
public:
    virtual void get_price() const {
        std::cout << "No Sensor" << std::endl;
    }
};

class HawaiianPizza : public Sensor {
public:
    virtual void get_price() const {
        std::cout << "Hawaiian: $11.5" << std::endl;
    }
};

class PizzaFactory {
public:
    static Sensor* create_pizza(const std::string& type) {
        if (type == "Ham and Mushroom")
            return new Temp();
        else if (type == "Hawaiian")
            return new HawaiianPizza();
        else
            return new DeluxePizza();
    }
};
//usage
int main() {

    std::auto_ptr<const Sensor> pizza(PizzaFactory::create_pizza("Default"));
    pizza->get_price();

    pizza.reset(PizzaFactory::create_pizza("Ham and Mushroom"));
    pizza->get_price();

    pizza.reset(PizzaFactory::create_pizza("Hawaiian"));
    pizza->get_price();
}
