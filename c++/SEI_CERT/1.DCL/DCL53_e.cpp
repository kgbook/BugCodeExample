
#include <mutex>
#include <iostream>

static std::mutex m;
static int shared_resource;

void increment_by_42() {
    std::unique_lock<std::mutex>(m);
    shared_resource += 42;
}

struct Widget {
    Widget() { std::cout << "Constructed" << std::endl; }
};

void f1() {
    Widget w();
}

struct Widget1 {
    explicit Widget1(int i) { std::cout << "Widget constructed" << std::endl; }
};

struct Gadget {
    explicit Gadget(Widget1 wid) { std::cout << "Gadget constructed" << std::endl; }
};

void f() {
    int i = 3;
    Gadget g(Widget1(i));
    std::cout << i << std::endl;
}