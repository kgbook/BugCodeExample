//
// Created by joey on 2024/5/14.
//

void foo() {
    int (*pt2Function) (float, char, char) =
            reinterpret_cast<int (*)(float, char, char)>(0x08040000);
    int result2 = (*pt2Function) (12, 'a', 'b');
}
