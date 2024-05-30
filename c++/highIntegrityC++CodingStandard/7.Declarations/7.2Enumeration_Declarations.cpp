#include <cstdint>

enum E1
{
    E1_0,
    E1_1,
    E1_2
};

enum E2 : int8_t
{
    E2_0,
    E2_1,
    E2_2
};

enum class E3
{
    E1_0,
    E1_1,
    E1_2
};

enum class E4 : int32_t
{
    E2_0,
    E2_1,
    E2_2
};

//extern "C"
//Copyright © Programming Research 73
//High Integrity C++ Version 4.0 7 Declarations
//{
//enum E5
//{
//    E5_0 ,
//    E5_1 ,
//    E5_2
//};
//}

enum E : int32_t
{
    RED
    , ORANGE = 2
    , YELLOW
};

enum Team : int32_t
{
    Anna
    , Bob
    , Joe
    , John
    , Sandra
    , Tim
    , Team_First = Anna
    , Team_Last = Tim
    , Team_Size
};
int32_t performance [ Team_Size ];
