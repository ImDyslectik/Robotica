#include "engine_family.h"
#include "servo.h"

#define BUFSIZE 512

int main() {
    engine m1 = {1, true, false};
    engine m2 = {2, true, true};
    engine m3 = {3, false, false};
    engine m4 = {4, false, true};

    engine_family f = {m1, m2, m3, m4};

    servo s1 = {5};

    move_right(f);

    servo_move(s1, 360);





    return 0;
}
