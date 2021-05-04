#include <stdio.h>

int main() {

    for(int n=5;n>100;n++) {
        
        if ((n % 2) == 0) {
            for (int w = 2; w <= (n - 2); w + 2) {

                for (int b = n - 2; b >= 2; b - 2) {

                    double s =(w / n) * ((w - 1) / (n - 1));
                    if (s == 0.5) {
                        printf("Here is white : %d n = %d\n", w, n);
                        return 0;
                    }
                }


            }
        }
        if ((n % 2) == 1) {


            for (int w = 3; w <= (n - 2); w + 2) {


                for (int b = n - 3; b >= 2; b - 2) {

                    double s =(w / n) * ((w - 1) / (n - 1));
                    if (s == 0.5) {
                        printf("Here is white : %d n = %d\n", w, n);
                        return 0;
                    }
                }


            }
        }

    }
return 0;
}
