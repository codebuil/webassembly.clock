double M_PI=3.14159265359;
double cos(double x) {
    // converter o ângulo para o intervalo [-pi, pi]
    while (x < -3.14159265359) {
        x += 6.28318530718;
    }
    while (x > 3.14159265359) {
        x -= 6.28318530718;
    }
    
    double result = 1.0;
    double term = 1.0;
    double sign = -1.0;
    double power = x * x;
    int i = 2;
    while (term > 1e-15) {  // parar quando a série converge
        term = power / (i * (i - 1));
        result += sign * term;
        sign *= -1.0;
        power *= x * x;
        i += 2;
    }
    
    return result;
}
double sin(double x) {
    // converter o ângulo para o intervalo [-pi, pi]
    while (x < -3.14159265359) {
        x += 6.28318530718;
    }
    while (x > 3.14159265359) {
        x -= 6.28318530718;
    }
    
    double result = x;
    double term = x;
    double sign = -1.0;
    double power = x * x * x;
    int i = 3;
    while (term > 1e-15) {  // parar quando a série converge
        term = power / (i * (i - 1));
        result += sign * term;
        sign *= -1.0;
        power *= x * x;
        i += 2;
    }
    
    return result;
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