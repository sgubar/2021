#include<iostream>
#include<cstring>

using namespace std;

class Product {
private:

    char* name;
    int ident;
public:

    Product(void) {// конструктор за замовчуванням

        ident = 0;
        name = nullptr;
    }

    Product(int num_ident, const char* name) { // параметричний конструктор

        ident = num_ident;
        this->name = _strdup(name);
    }

    Product(const Product &copy) { // конструктор копіювання

        this->name = _strdup(copy.name);
        ident = copy.ident;
    }

    void set_name(const char* name) { // модифікатор ім'я

        if (nullptr != this->name) {
            free(this->name);
        }
        this->name = _strdup(name);
    }

    void set_ident(int num_ident) { // модифікатор ідкентифікатора 

        ident = num_ident;
    }

    char* get_name() { // селектор ім'я

        return name;
    }

    int get_ident() { // селектор ідентифікатора

        return ident;
    }

    ~Product() { // деструктор
        if (nullptr != name) {
            free(name);
        }
        cout << " End " << endl;
    }
};
int main(int argc, const char* argv[]) {

    Product first(548002587, (char*)"Comp");
    cout << "First" << endl;
    cout << "Name - " << first.get_name() << " identifier - " << first.get_ident() << endl;

    first.set_name("Mouse");
    first.set_ident(432889412);
    cout << "Name - " << first.get_name() << " identifier - " << first.get_ident() << endl;

    cout << endl;

    Product second(first);
    cout << "Second" << endl;
    cout << "Name - " << second.get_name() << " identifier - " << second.get_ident() << endl;

    return 0;
}
