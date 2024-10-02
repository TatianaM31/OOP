//Маслова Татьяна БИВ238

//Студенты с кафедры робототехники запускают радиоуправляемый автомобиль. На автомобиль ещё не успели поставить GPS-модуль, 
// поэтому его местоположение придётся вычислять по переданным с пульта командам. 
// Напишите программу, позволяющую рассчитать координаты автомобиля на основании переданных с пульта команд. 
// Считать, что в целях экономии аккумулятора, команды передаются только тогда, когда требуется задать 
// новую скорость или изменить радиус поворота.

//Автомобиль, хранящий и изменяющий свое состояние (скорость, ускорение, угол, координаты).


#include <iostream>
#include <cassert>
#include <cmath>
#include <string>

class Remote_car {
private:
    double speed;        
    double acceleration; 
    double angle;        
    double pos_x;        
    double pos_y;        

public:
    Remote_car() : speed(0), acceleration(0), angle(0), pos_x(0), pos_y(0) {}

    Remote_car(double spd, double accel, double ang, double x, double y) 
        : speed(spd), acceleration(accel), angle(ang), pos_x(x), pos_y(y) {
        assert(speed >= 0);
        assert(acceleration >= 0);
    }

    Remote_car(const Remote_car &other) 
        : speed(other.speed), acceleration(other.acceleration), 
          angle(other.angle), pos_x(other.pos_x), pos_y(other.pos_y) {}

    double get_speed() const { return speed; }
    double get_acceleration() const { return acceleration; }
    double get_angle() const { return angle; }
    double get_pos_x() const { return pos_x; }
    double get_pos_y() const { return pos_y; }

    void set_speed(double spd) {
        assert(spd >= 0);
        speed = spd;
    }

    void set_acceleration(double accel) {
        assert(accel >= 0);
        acceleration = accel;
    }

    void move(double time) {
        pos_x += speed * cos(angle) * time;
        pos_y += speed * sin(angle) * time;
        speed += acceleration * time; 
    }
};

int main() {
    Remote_car car1;
    assert(car1.get_speed() == 0);
    assert(car1.get_pos_x() == 0);
    assert(car1.get_pos_y() == 0);

    Remote_car car2(10, 2, M_PI / 4, 0, 0);
    assert(car2.get_speed() == 10);
    assert(car2.get_pos_x() == 0);
    assert(car2.get_pos_y() == 0);

    car2.move(1); 
    assert(fabs(car2.get_pos_x() - 7.07107) < 1e-5); 
    assert(fabs(car2.get_pos_y() - 7.07107) < 1e-5);

    car2.set_speed(15);
    assert(car2.get_speed() == 15);

    std:: cout << "All tests passed!";
    return 0;
}
