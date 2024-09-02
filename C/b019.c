#include <stdio.h>
#include <time.h>

void printProgressBar(int progress, int total) {
    const int barWidth = 50;
    int pos = (int)((double)progress / total * barWidth);

    putchar('[');
    for (int i = 0; i < barWidth; ++i) {
        putchar(i < pos ? '=' : ' ');
    }
    putchar(']');
    printf(" %3d%%", (int)((double)progress / total * 100));

    // ���Ц^�h�A��{��s
    for (int i = 0; i < barWidth + 6; ++i) {
        putchar('\b');
    }
}

void abc(int h) {
    // ... (��l abc �禡�����e����)
}

int main() {
    clock_t START, END;
    START = clock();
    long h = 1000000000;
    double a = 2;
    double b = 3;

    for (int i = 0; i < h; ++i) {
        b = b + 4 / (a * (a + 1) * (a + 2)) - 4 / ((a + 2) * (a + 3) * (a + 4));
        a = a + 4;
        printProgressBar(i, h); // ��ܶi�ױ�
        fflush(stdout);
    }

    b = b * 10000000;
    printf("%f\n", b);
    END = clock();

    printf("����ɶ��G%f ��\n", (double)(END - START) / CLOCKS_PER_SEC);
    return 0;
}
