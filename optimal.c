#include<stdio.h>
#include<stdlib.h>

int findOptimalPage(int pages[], int n, int frames[], int currentPos, int maxFrames) {
    int res = -1;
    int farthest = currentPos;
    int i, j;
    
    for (i = 0; i < maxFrames; i++) {
        for (j = currentPos; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    
    if (res == -1) return 0;
    else return res;
}

int main() {
    int i, j;
    int pages[100], frames[100], maxFrames, maxPages, pageFault = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &maxFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &maxPages);

    printf("Enter page references: ");
    for (i = 0; i < maxPages; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < maxFrames; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < maxPages; i++) {
        int currentPos = -1;

        for (j = 0; j < maxFrames; j++) {
            if (frames[j] == pages[i]) {
                currentPos = j;
                break;
            }
        }

        if (currentPos == -1) {
            int pos = findOptimalPage(pages, maxPages, frames, i, maxFrames);
            frames[pos] = pages[i];
            pageFault++;
        }
    }

    printf("Page Faults: %d\n", pageFault);

    return 0;
}
