#include<cstdio>
#include<list>

void printList(const std::list<int> &list) {
    for (auto item: list) {
        printf("%d ", item);
    }
    printf("\n");
}

void listOpt() {
    std::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(2);

    printList(list);

    for (auto iter = list.begin(); iter != list.end(); iter++) {
        if (*iter == 2) {
            list.erase(iter);
        }
    }

    printList(list);
}

int main() {
    listOpt();
    return 0;
}