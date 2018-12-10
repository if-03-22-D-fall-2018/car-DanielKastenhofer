#include "car.h"
#include <stdbool.h>

struct CarImplementation {
  int speed;
  int max_speed;
  enum Color color;
  enum Type type;
  double fill_level;
  double acceleration_rate;
  bool is_available;
  double lowest_acceleration_rate;
  double highest_acceleration_rate;
};

struct CarImplementation aixam{0, 45, RED, AIXAM, 16.0, 0.0, true, -8.0, 1.0};
struct CarImplementation jeep1{0, 196, SILVER, JEEP, 80.0, 0.0, true, -8.0, 3.14};
struct CarImplementation jeep2{0, 196, BLACK, JEEP, 80.0, 0.0, true, -8.0, 3.14};
struct CarImplementation fiat_multipla1{0, 170, GREEN, FIAT_MULTIPLA, 65.0, 0.0, true, -8.0, 2.26};
struct CarImplementation fiat_multipla2{0, 170, BLUE, FIAT_MULTIPLA, 65.0, 0.0, true, -8.0, 2.26};
struct CarImplementation fiat_multipla3{0, 170, ORANGE, FIAT_MULTIPLA, 65.0, 0.0, true, -8.0, 2.26};

Car car_park[6] = {&aixam, &jeep1, &jeep2, &fiat_multipla1, &fiat_multipla2, &fiat_multipla3};

Car get_car(enum Type type)
{
  for (int i = 0; i < 6; i++) {
    if (type == car_park[i]->type && car_park[i]->is_available) {
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
  double addedSpeed = car->acceleration_rate * 3.6;
    if(addedSpeed + car->speed < car->max_speed)
    {
      car->speed += addedSpeed;
    }
    else if(car->speed < car->max_speed){
      double difference = car->max_speed - car->speed;
      car->speed += difference;
    }
}

void set_acceleration_rate(Car car, double rate)
{
  if (rate>=car->lowest_acceleration_rate && rate<=car->highest_acceleration_rate) {
    car->acceleration_rate = rate;
  }
  else if (rate<car->lowest_acceleration_rate) {
    car->acceleration_rate=car->lowest_acceleration_rate;
  }
  else{
    car->acceleration_rate=car->highest_acceleration_rate;
  }
}

int get_speed(Car car)
{
  if (car->speed - (int)car->speed >= 0.5) {
  return (int)car->speed+1;
}
return (int)car->speed;;
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
  return car->type;
}

double get_acceleration_rate(Car car)
{
  return car->acceleration_rate;
}
