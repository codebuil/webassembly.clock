double M_PI=3.14159265359;
double abs(double x) {
    return (x >= 0) ? x : -x;
}
double cos(double x) {
    double result = 1.0f;
    double term = 1.0f;
    double sign = -1.0f;

    for (int i = 2; i < 10; i += 2) {
        term *= (x * x) / (i * (i - 1));
        result += sign * term;
        sign *= -1.0f;
    }

    return result;
}
double sin(double x) {
    const double B = 4.0f / M_PI;
    const double C = -4.0f / (M_PI * M_PI);

    double y = B * x + C * x * abs(x);

    const double P = 0.225f;

    y = P * (y * abs(y) - y) + y;

    return y;
}

double calcX(int size, int seconds) {
  double sizes=size;
  double secondss=seconds ;
  if(sizes==0.00)sizes=0.01;
  if(secondss==0.00)sizes=0.01;
  double angle = secondss /(sizes/2.00) * M_PI;
  if(angle==0.00)angle=0.01;
  return sin(angle);
}

double calcY(int size, int seconds) {
  double sizes=size;
  double secondss=seconds ;
  if(sizes==0.00)sizes=0.01;
  if(secondss==0.00)sizes=0.01;
  double angle = secondss /(sizes/2.00) * M_PI;
  if(angle==0.00)angle=0.01;
  return cos(angle);
}