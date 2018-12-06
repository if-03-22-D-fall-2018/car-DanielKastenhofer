#include "car.h"
#include <stdbool.h>

struct CarImplementation {
  int speed;
  enum Color color;
  enum Type type;
  double fill_level;
  double acceleration_rate;
  bool is_available;
};

struct CarImplementation aixam{0, RED, AIXAM, 16.0, 0.0, true};
struct CarImplementation jeep1{0, SILVER, JEEP, 16.0, 0.0, true};
struct CarImplementation jeep2{0, BLACK, JEEP, 16.0, 0.0, true};
struct CarImplementation fiat_multipla1{0, GREEN, FIAT_MULTIPLA, 65.0, 0.0, true};
struct CarImplementation fiat_multipla2{0, BLUE, FIAT_MULTIPLA, 65.0, 0.0, true};
struct CarImplementation fiat_multipla3{0, ORANGE, FIAT_MULTIPLA, 65.0, 0.0, true};

Car car_park[6] = {&aixam, &jeep1, &jeep2, &fiat_multipla1, &fiat_multipla2, &fiat_multipla3};

Car get_car(enum Type type)
{
  for (int i = 0; i < 6; i++) {
    if (type == car_park[i]->type && car_park[i]->is_available == true) {
      car_park[i]->is_available = false;
      return car_park[i];
    }
  }
  return 0;
}

void init()
{
  for (int i = 0; i < 6; i++) {
    car_park[i]->acceleration_rate = 0.0;
    car_park[i]->is_available = true;
    car_park[i]->speed = 0;
  }
}

void accelerate(Car car)
{

}

void set_acceleration_rate(Car car, int rate)
{

}

int get_speed(Car car)
{
  return 0;
}

enum Color get_color(Car car)
{
  return car->color;
}

double get_fill_level(Car car)
{
  return  car->fill_level;
}
enum Type get_type(Car car)
{
  return AIXAM;
}

double get_acceleration_rate(Car car)
{
  return 0;
}
