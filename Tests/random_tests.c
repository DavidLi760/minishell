#include <stdio.h>

int main() {
    // ANSI escape code for deep blue color (color code 18)
    printf("\033[38;5;18mThis text is deep blue.\033[0m\n");
    // ANSI escape code for deep blue color (color code 19)
    printf("\033[38;5;19mThis text is another shade of deep blue.\033[0m\n");

    // You can try different shades in the blue spectrum:
    for (int i = 17; i <= 210; i++) {
        printf("\033[38;5;%dmDeep Blue Shade %d\033[0m\n", i, i);
    }

    return 0;
}