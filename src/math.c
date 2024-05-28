#include "math.h"
#include <stdio.h>

double fac(double x);
float facf(float x);
long double facl(long double x);

// trig stuff

double cos(double x) {
    double result = 0.0;
    int sign      = 1;
    for (int i = 0; i < 15; i++) {
        result += sign * pow(x, 2 * i) / fac(2 * i);
        sign *= -1;
    }
    return result;
}

float cosf(float x) {
    float result = 0.0f;
    int sign     = 1;
    for (int i = 0; i < 10; i++) {
        result += sign * powf(x, 2 * i) / facf(2 * i);
        sign *= -1;
    }
    return result;
}

long double cosl(long double x) {
    long double result = 0.0;
    int sign           = 1;
    for (int i = 0; i < 20; i++) {
        result += sign * powl(x, 2 * i) / facl(2 * i);
        sign *= -1;
    }
    return result;
}

double sin(double x) {
    double result = 0.0;
    int sign      = 1;
    for (int i = 0; i < 15; i++) {
        result += sign * pow(x, 2 * i + 1) / fac(2 * i + 1);
        sign *= -1;
    }
    return result;
}

float sinf(float x) {
    float result = 0.0f;
    int sign     = 1;
    for (int i = 0; i < 10; i++) {
        result += sign * powf(x, 2 * i + 1) / facf(2 * i + 1);
        sign *= -1;
    }
    return result;
}

long double sinl(long double x) {
    long double result = 0.0;
    int sign           = 1;
    for (int i = 0; i < 20; i++) {
        result += sign * powl(x, 2 * i + 1) / facl(2 * i + 1);
        sign *= -1;
    }
    return result;
}

double tan(double x) {
    return sin(x) / cos(x);
}

float tanf(float x) {
    return sinf(x) / cosf(x);
}

long double tanl(long double x) {
    return sinl(x) / cosl(x);
}

double acos(double x) {
    double result = 0.0;
    int sign      = -1;
    for (int i = 0; i < 15; i++) {
        result += sign * pow(x, i) / i;
        sign *= -1;
    }
    return result;
}

float acosf(float x) {
    float result = 0.0f;
    int sign     = -1;
    for (int i = 0; i < 10; i++) {
        result += sign * powf(x, i) / i;
        sign *= -1;
    }
    return result;
}

long double acosl(long double x) {
    long double result = 0.0;
    int sign           = -1;
    for (int i = 0; i < 20; i++) {
        result += sign * pow(x, i) / i;
        sign *= -1;
    }
    return result;
}

double asin(double x) {
    double result = 0.0;
    int sign      = 1;
    for (int i = 0; i < 15; i++) {
        result += sign * pow(x, i) / i;
        sign *= -1;
    }
    return result;
}

float asinf(float x) {
    float result = 0.0f;
    int sign     = 1;
    for (int i = 0; i < 10; i++) {
        result += sign * powf(x, i) / i;
        sign *= -1;
    }
    return result;
}

long double asinl(long double x) {
    long double result = 0.0;
    int sign           = 1;
    for (int i = 0; i < 20; i++) {
        result += sign * pow(x, i) / i;
        sign *= -1;
    }
    return result;
}

double atan(double x) {
    double result = 0;
    int sign      = 1;
    double term   = x;
    for (int i = 1; i <= 15; i += 2) {
        result += sign * term;
        sign *= -1;
        term *= x * x;
    }
    return result;
}

float atanf(float x) {
    float result = 0.0f;
    int sign     = 1;
    float term   = x;
    for (int i = 1; i <= 10; i += 2) {
        result += sign * term;
        sign *= -1;
        term *= x * x;
    }
    return result;
}

long double atanl(long double x) {
    long double result = 0;
    int sign           = 1;
    long double term   = x;
    for (int i = 1; i <= 20; i += 2) {
        result += sign * term;
        sign *= -1;
        term *= x * x;
    }
    return result;
}

// double atan2(double x) {
//     printf("el no implemento");
//     return 0;
// }

// float atan2f(float x) {
//     printf("el no implemento");
//     return 0;
// }

// long double atan2l(long double x) {
//     printf("el no implemento");
//     return 0;
// }

double cosh(double x) {
    double result = 1.0;
    double term   = 1.0;
    for (int i = 1; i <= 15; i += 2) {
        term *= x * x / ((i - 1) * i);
        result += term;
    }
    return result;
}

float coshf(float x) {
    float result = 1.0f;
    float term   = 1.0f;
    for (int i = 1; i <= 10; i += 2) {
        term *= x * x / ((i - 1) * i);
        result += term;
    }
    return result;
}

long double coshl(long double x) {
    long double result = 1.0;
    long double term   = 1.0;
    for (int i = 1; i <= 20; i += 2) {
        term *= x * x / ((i - 1) * i);
        result += term;
    }
    return result;
}

double sinh(double x) {
    double result = x;
    double term   = x;
    for (int i = 1; i <= 15; i += 2) {
        term *= x * x / ((i + 1) * i);
        result += term;
    }
    return result;
}

float sinhf(float x) {
    float result = x;
    float term   = x;
    for (int i = 1; i <= 10; i += 2) {
        term *= x * x / ((i + 1) * i);
        result += term;
    }
    return result;
}

long double sinhl(long double x) {
    long double result = x;
    long double term   = x;
    for (int i = 1; i <= 20; i += 2) {
        term *= x * x / ((i + 1) * i);
        result += term;
    }
    return result;
}

double tanh(double x) {
    return sinh(x) / cosh(x);
}

float tanhf(float x) {
    return sinhf(x) / coshf(x);
}

long double tanhl(long double x) {
    return sinhl(x) / coshl(x);
}

double acosh(double x) {
    return log(x + sqrt(x * x - 1));
}

float acoshf(float x) {
    return logf(x + sqrtf(x * x - 1));
}

long double acoshl(long double x) {
    return logl(x + sqrtl(x * x - 1));
}

double asinh(double x) {
    return log(x + sqrt(x * x + 1));
}

float asinhf(float x) {
    return logf(x + sqrtf(x * x + 1));
}

long double asinhl(long double x) {
    return logl(x + sqrtl(x * x + 1));
}

double atanh(double x) {
    return 0.5 * log((1 + x) / (1 - x));
}

float atanhf(float x) {
    return 0.5 * logf((1 + x) / (1 - x));
}

long double atanhl(long double x) {
    return 0.5 * logl((1 + x) / (1 - x));
}

// exp stuff

double fac(double x) {
    if (x == 0)
        return 1;
    return x * fac(x - 1);
}

float facf(float x) {
    if (x == 0)
        return 1;
    return x * facf(x - 1);
}

long double facl(long double x) {
    if (x == 0)
        return 1;
    return x * facl(x - 1);
}

double exp(double x) {
    double result = 0.0;
    for (int i = 0; i < 15; i++) {
        result += pow(x, i) / fac(i);
    }
    return result;
}

float expf(float x) {
    float result = 0.0f;
    for (int i = 0; i < 10; i++) {
        result += powf(x, i) / facf(i);
    }
    return result;
}

long double expl(long double x) {
    long double result = 0.0;
    for (int i = 0; i < 20; i++) {
        result += pow(x, i) / fac(i);
    }
    return result;
}

double frexp(double x, int* exp) {
    printf("el no implemento");
    return 0;
}

float frexpf(float x, int* exp) {
    printf("el no implemento");
    return 0;
}

long double frexpl(long double x, int* exp) {
    printf("el no implemento");
    return 0;
}

double ldexp(double x, int exp) {
    printf("el no implemento");
    return 0;
}

float ldexpf(float x, int exp) {
    printf("el no implemento");
    return 0;
}

long double ldexpl(long double x, int exp) {
    printf("el no implemento");
    return 0;
}

double log(double x) {
    if (x <= 0)
        return 0.0;
    double result = 0.0;
    int sign      = 1;
    for (int i = 1; i <= 15; i++) {
        result += sign * pow(x - 1, i) / i;
        sign *= -1;
    }
    return result;
}

float logf(float x) {
    if (x <= 0)
        return 0.0;
    float result = 0.0f;
    int sign     = 1;
    for (int i = 1; i <= 10; i++) {
        result += sign * powf(x - 1, i) / i;
        sign *= -1;
    }
    return result;
}

long double logl(long double x) {
    if (x <= 0)
        return 0.0;
    long double result = 0.0;
    int sign           = 1;
    for (int i = 1; i <= 20; i++) {
        result += sign * powl(x - 1, i) / i;
        sign *= -1;
    }
    return result;
}

double log10(double x) {
    return log(x) / log(10);
}

float log10f(float x) {
    return logf(x) / logf(10);
}

long double log10l(long double x) {
    return logl(x) / logl(10);
}

double modf(double x, double* intpart) {
    printf("el no implemento");
    return 0;
}

float modff(float x, float* intpart);
long double modfl(long double x, long double* intpart) {
    printf("el no implemento");
    return 0;
}

double exp2(double x) {
    printf("el no implemento");
    return 0;
}

float exp2f(float x) {
    printf("el no implemento");
    return 0;
}

long double exp2l(long double x) {
    printf("el no implemento");
    return 0;
}

double expm1(double x) {
    printf("el no implemento");
    return 0;
}

float expm1f(float x) {
    printf("el no implemento");
    return 0;
}

long double expm1l(long double x) {
    printf("el no implemento");
    return 0;
}

int ilogb(double x) {
    printf("el no implemento");
    return 0;
}

int ilogbf(float x) {
    printf("el no implemento");
    return 0;
}

int ilogbl(long double x) {
    printf("el no implemento");
    return 0;
}

double log1p(double x) {
    printf("el no implemento");
    return 0;
}

float log1pf(float x) {
    printf("el no implemento");
    return 0;
}

long double log1pl(long double x) {
    printf("el no implemento");
    return 0;
}

double log2(double x) {
    return log(x) / log(2);
}

float log2f(float x) {
    return logf(x) / logf(2);
}

long double log2l(long double x) {
    return logl(x) / logl(2);
}

double logb(double x) {
    printf("el no implemento");
    return 0;
}

float logbf(float x) {
    printf("el no implemento");
    return 0;
}

long double logbl(long double x) {
    printf("el no implemento");
    return 0;
}

double scalbn(double x, int n) {
    printf("el no implemento");
    return 0;
}

float scalbnf(float x, int n) {
    printf("el no implemento");
    return 0;
}

long double scalbnl(long double x, int n) {
    printf("el no implemento");
    return 0;
}

double scalbln(double x, long int n) {
    printf("el no implemento");
    return 0;
}

float scalblnf(float x, long int n) {
    printf("el no implemento");
    return 0;
}

long double scalblnl(long double x, long int n) {
    printf("el no implemento");
    return 0;
}

// pow stuff

double pow(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

float powf(float base, float exponent) {
    float result = 1.0f;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

long double powl(long double base, long double exponent) {
    long double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

double sqrt(double x) {
    if (x == 0)
        return 0;
    double guess      = x / 2.0;
    double prev_guess = x;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess      = (guess + x / guess) / 2.0;
    }
    return guess;
}

float sqrtf(float x) {
    if (x == 0)
        return 0;
    float guess      = x / 2.0;
    float prev_guess = x;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess      = (guess + x / guess) / 2.0;
    }
    return guess;
}

long double sqrtl(long double x) {
    if (x == 0)
        return 0;
    long double guess      = x / 2.0;
    long double prev_guess = x;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess      = (guess + x / guess) / 2.0;
    }
    return guess;
}

double cbrt(double x) {
    if (x == 0)
        return 0;
    double guess      = x / 3.0;
    double prev_guess = x;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess      = (2 * prev_guess + x / (prev_guess * prev_guess)) / 3.0;
    }
    return guess;
}

float cbrtf(float x) {
    if (x == 0)
        return 0;
    float guess      = x / 3.0;
    float prev_guess = x;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess      = (2 * prev_guess + x / (prev_guess * prev_guess)) / 3.0;
    }
    return guess;
}

long double cbrtl(long double x) {
    if (x == 0)
        return 0;
    long double guess      = x / 3.0;
    long double prev_guess = x;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess      = (2 * prev_guess + x / (prev_guess * prev_guess)) / 3.0;
    }
    return guess;
}

double hypot(double x, double y) {
    printf("el no implemento");
    return 0;
}

float hypotf(float x, float y) {
    printf("el no implemento");
    return 0;
}

long double hypotl(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

// gamma stuff

double erf(double x) {
    printf("el no implemento");
    return 0;
}

float erff(float x) {
    printf("el no implemento");
    return 0;
}

long double erfl(long double x) {
    printf("el no implemento");
    return 0;
}

double erfc(double x) {
    printf("el no implemento");
    return 0;
}

float erfcf(float x) {
    printf("el no implemento");
    return 0;
}

long double erfcl(long double x) {
    printf("el no implemento");
    return 0;
}

double tgamma(double x) {
    printf("el no implemento");
    return 0;
}

float tgammaf(float x);
long double tgammal(long double x) {
    printf("el no implemento");
    return 0;
}

double lgamma(double x) {
    printf("el no implemento");
    return 0;
}

float lgammaf(float x) {
    printf("el no implemento");
    return 0;
}

long double lgammal(long double x) {
    printf("el no implemento");
    return 0;
}

// rounding stuff

double ceil(double x) {
    int result = (int)x;
    if (x > 0 && x != result)
        result++;
    return (double)result;
}

float ceilf(float x) {
    int result = (int)x;
    if (x > 0 && x != result)
        result++;
    return (float)result;
}

long double ceill(long double x) {
    int result = (int)x;
    if (x > 0 && x != result)
        result++;
    return (long double)result;
}

double floor(double x) {
    int result = (int)x;
    if (x < 0 && x != result)
        result--;
    return (double)result;
}

float floorf(float x) {
    int result = (int)x;
    if (x < 0 && x != result)
        result--;
    return (float)result;
}

long double floorl(long double x) {
    int result = (int)x;
    if (x < 0 && x != result)
        result--;
    return (long double)result;
}

double fmod(double numer, double denom) {
    printf("el no implemento");
    return 0;
}

float fmodf(float numer, float denom) {
    printf("el no implemento");
    return 0;
}

long double fmodl(long double numer, long double denom) {
    printf("el no implemento");
    return 0;
}

double trunc(double x) {
    printf("el no implemento");
    return 0;
}

float truncf(float x) {
    printf("el no implemento");
    return 0;
}

long double truncl(long double x) {
    printf("el no implemento");
    return 0;
}

double round(double x) {
    double result;
    if (x >= 0)
        result = (int)(x + 0.5);
    else
        result = (int)(x - 0.5);
    return result;
}

float roundf(float x) {
    float result;
    if (x >= 0)
        result = (int)(x + 0.5);
    else
        result = (int)(x - 0.5);
    return result;
}

long double roundl(long double x) {
    long double result;
    if (x >= 0)
        result = (int)(x + 0.5);
    else
        result = (int)(x - 0.5);
    return result;
}

long int lround(double x) {
    if (x >= 0)
        return (long int)(x + 0.5);
    else
        return (long int)(x - 0.5);
}

long int lroundf(float x) {
    if (x >= 0)
        return (long int)(x + 0.5);
    else
        return (long int)(x - 0.5);
}

long int lroundl(long double x) {
    if (x >= 0)
        return (long int)(x + 0.5);
    else
        return (long int)(x - 0.5);
}

long long int llround(double x) {
    if (x >= 0)
        return (long long int)(x + 0.5);
    else
        return (long long int)(x - 0.5);
}

long long int llroundf(float x) {
    if (x >= 0)
        return (long long int)(x + 0.5);
    else
        return (long long int)(x - 0.5);
}

long long int llroundl(long double x) {
    if (x >= 0)
        return (long long int)(x + 0.5);
    else
        return (long long int)(x - 0.5);
}

double rint(double x) {
    printf("el no implemento");
    return 0;
}

float rintf(float x) {
    printf("el no implemento");
    return 0;
}

long double rintl(long double x) {
    printf("el no implemento");
    return 0;
}

long int lrint(double x) {
    printf("el no implemento");
    return 0;
}

long int lrintf(float x) {
    printf("el no implemento");
    return 0;
}

long int lrintl(long double x) {
    printf("el no implemento");
    return 0;
}

long long int llrint(double x) {
    printf("el no implemento");
    return 0;
}

long long int llrintf(float x) {
    printf("el no implemento");
    return 0;
}

long long int llrintl(long double x) {
    printf("el no implemento");
    return 0;
}

double nearbyint(double x) {
    printf("el no implemento");
    return 0;
}

float nearbyintf(float x) {
    printf("el no implemento");
    return 0;
}

long double nearbyintl(long double x) {
    printf("el no implemento");
    return 0;
}

double remainder(double numer, double denom) {
    printf("el no implemento");
    return 0;
}

float remainderf(float numer, float denom) {
    printf("el no implemento");
    return 0;
}

long double remainderl(long double numer, long double denom) {
    printf("el no implemento");
    return 0;
}

double remquo(double numer, double denom, int* quot) {
    printf("el no implemento");
    return 0;
}

float remquof(float numer, float denom, int* quot) {
    printf("el no implemento");
    return 0;
}

long double remquol(long double numer, long double denom, int* quot) {
    printf("el no implemento");
    return 0;
}

// float stuff

double copysign(double x, double y) {
    printf("el no implemento");
    return 0;
}

float copysignf(float x, float y) {
    printf("el no implemento");
    return 0;
}

long double copysignl(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

double nan(const char* tagp) {
    printf("el no implemento");
    return 0;
}

double nextafter(double x, double y) {
    printf("el no implemento");
    return 0;
}

float nextafterf(float x, float y) {
    printf("el no implemento");
    return 0;
}

long double nextafterl(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

double nexttoward(double x, long double y) {
    printf("el no implemento");
    return 0;
}

float nexttowardf(float x, long double y) {
    printf("el no implemento");
    return 0;
}

long double nexttowardl(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

// min stuff

double fdim(double x, double y) {
    printf("el no implemento");
    return 0;
}

float fdimf(float x, float y) {
    printf("el no implemento");
    return 0;
}

long double fdiml(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

double fmax(double x, double y) {
    printf("el no implemento");
    return 0;
}

float fmaxf(float x, float y) {
    printf("el no implemento");
    return 0;
}

long double fmaxl(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

double fmin(double x, double y) {
    printf("el no implemento");
    return 0;
}

float fminf(float x, float y) {
    printf("el no implemento");
    return 0;
}

long double fminl(long double x, long double y) {
    printf("el no implemento");
    return 0;
}

// other stuff

double fabs(double x) {
    return (x < 0) ? -x : x;
}

float fabsf(float x) {
    return (x < 0) ? -x : x;
}

long double fabsl(long double x) {
    return (x < 0) ? -x : x;
}

double fma(double x, double y, double z) {
    printf("el no implemento");
    return 0;
}

float fmaf(float x, float y, float z) {
    printf("el no implemento");
    return 0;
}

long double fmal(long double x, long double y, long double z) {
    printf("el no implemento");
    return 0;
}
