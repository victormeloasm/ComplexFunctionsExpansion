#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

double power(double base, int exponent) {
    double result = 1.0;
    int i;
    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

Complex complexAdd(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complexSubtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex complexMultiply(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

Complex complexSquareRoot(Complex num) {
    Complex result;
    double mod = sqrt(num.real * num.real + num.imag * num.imag);
    result.real = sqrt((mod + num.real) / 2);
    result.imag = sqrt((mod - num.real) / 2);
    return result;
}

Complex complexPower(Complex base, int exponent) {
    Complex result;
    result.real = 1.0;
    result.imag = 0.0;
    int i;
    for (i = 0; i < exponent; i++) {
        result = complexMultiply(result, base);
    }
    return result;
}

Complex complexLogarithm(Complex num) {
    Complex result;
    result.real = log(sqrt(num.real * num.real + num.imag * num.imag));
    result.imag = atan2(num.imag, num.real);
    return result;
}

int main() {
    int choice;
    int inputType;
    double realInput;
    Complex complexInput;

    printf("Choose the operation:\n");
    printf("1. Calculate square root\n");
    printf("2. Calculate power\n");
    printf("3. Calculate logarithm\n");
    scanf("%d", &choice);

    printf("Choose the input type:\n");
    printf("1. Real\n");
    printf("2. Complex\n");
    scanf("%d", &inputType);

    if (inputType == 1) {
        printf("Enter the real number: ");
        scanf("%lf", &realInput);
    } else if (inputType == 2) {
        printf("Enter the real part: ");
        scanf("%lf", &complexInput.real);
        printf("Enter the imaginary part: ");
        scanf("%lf", &complexInput.imag);
    } else {
        printf("Invalid option!\n");
        return 1;
    }

    if (choice == 1) {
        if (inputType == 1) {
            if (realInput >= 0.0) {
                double result = sqrt(realInput);
                printf("The square root of %.8lf is %.8lf\n", realInput, result);
            } else {
                Complex complexResult = complexSquareRoot((Complex){realInput, 0.0});
                printf("The square root of %.8lf is %.8lf + %.8lfi\n", realInput, complexResult.real, complexResult.imag);
            }
        } else {
            Complex complexResult = complexSquareRoot(complexInput);
            printf("The square root of %.8lf + %.8lfi is %.8lf + %.8lfi\n", complexInput.real, complexInput.imag, complexResult.real, complexResult.imag);
        }
    } else if (choice == 2) {
        int exponent;
        printf("Enter the exponent: ");
        scanf("%d", &exponent);

        if (inputType == 1) {
            double result = power(realInput, exponent);
            printf("%.8lf raised to %d is %.8lf\n", realInput, exponent, result);
        } else {
            Complex complexResult = complexPower(complexInput, exponent);
            printf("%.8lf + %.8lfi raised to %d is %.8lf + %.8lfi\n", complexInput.real, complexInput.imag, exponent, complexResult.real, complexResult.imag);
        }
    } else if (choice == 3) {
        if (inputType == 1) {
            if (realInput > 0.0) {
                double result = log(realInput);
                printf("The logarithm of %.8lf is %.8lf\n", realInput, result);
            } else {
                Complex complexResult = complexLogarithm((Complex){realInput, 0.0});
                printf("The logarithm of %.8lf is %.8lf + %.8lfi\n", realInput, complexResult.real, complexResult.imag);
            }
        } else {
            Complex complexResult = complexLogarithm(complexInput);
            printf("The logarithm of %.8lf + %.8lfi is %.8lf + %.8lfi\n", complexInput.real, complexInput.imag, complexResult.real, complexResult.imag);
        }
    } else {
        printf("Invalid option!\n");
        return 1;
    }
getch();
    return 0;
}
