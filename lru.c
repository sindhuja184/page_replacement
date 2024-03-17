#include <stdio.h>
int main(){
    int pages[100], frames[100], max_frames = 0, max_pages = 0, pagefoults = 0, track[100];
    int n, i, j, k;
    printf("Enter number of frames :");
    scanf("%d", &max_frames);
    printf("Enter the number of pages :");
    scanf("%d", &max_pages);
    for(i = 0 ; i < max_frames; i++){
        frames[i] = -1;
        track[i] = -1;
    }
    printf("Enter the data :");
    for(i = 0 ; i < max_pages ; i++){
        scanf("%d", &pages[i]);
    }
    int currentpage = -1, found = 0;
    for(i = 0 ; i < max_pages ; i++){
        currentpage = pages[i];
        found = 0;
        for(j = 0 ; j < max_frames ; j++){
            if(currentpage == frames[j]){
                found = 1;
                track[j] = i;
                break;
            }
        }
        if(found == 0){
            int min = track[0];
            int index = 0;
            for(j = 1 ; j < max_frames ; j++){
                if(track[j] < min){
                    min = track[j];
                    index = j;
                }
            }
            frames[index] = currentpage;
            track[index] = i;
            pagefoults++;
        }
    }
    printf("Number of pagefaults :%d", pagefoults);
}