#include "vector2.h"
#include <vector>
#include <cstdio>

template<class T1, class T2>
auto Sum(T1 a, T2 b) -> decltype(a + b) {
  return a + b;
}

class Cislo {
 public:
  double c;
};

int main() {
  Sum(1, 6);
  vector2<double> woo{1, 3.5, 5};
  vector2<int> hoo{5, 3, 5};
  vector2<Cislo> boo;
  printf("woo:\n");
  woo.Print();
  printf("hoo:\n");
  hoo.Print();
  printf("woo + hoo:\n");
  (woo + hoo).Print();
  printf("woo + 20:\n");
  (woo + 20).Print();

  printf("woo < hoo:\n");
  printf("%d\n", woo < hoo);
  printf("woo < hoo:\n");
  printf("%d\n", woo > hoo);

  printf("Woo.Sum() woo.Mean()\n");
  printf("%lf %lf\n", (double) woo.Sum(), (double) woo.Mean());
  printf("Woo.Map(... 2 * a ...)\n");
  woo.Map([](double a){return 2 * a;}).Print();
  
  woo += hoo;
  printf("woo += hoo\n");
  woo.Print();
  
  woo -= 2 * hoo;
  printf("woo -= 2 * hoo\n");
  woo.Print();

  woo *= hoo;
  printf("woo *= hoo\n");
  woo.Print();
  
}