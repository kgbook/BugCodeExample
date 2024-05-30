//1
auto g(int val) {
    auto outer = [val] {
        int i = val;
        auto inner = [&] {
            i += 30;
            return i;
        };
        return inner;
    };
    return outer();
}

void f() {
    auto fn = g(12);
    int j = fn();
}
//2
auto g1() {
    int i = 12;
    return [&] {
        i = 100;
        return i;
    };
}

void f1() {
    int j = g1()();
}