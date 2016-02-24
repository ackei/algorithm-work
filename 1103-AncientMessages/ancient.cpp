#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define WAS 0
#define ANKH 1
#define AKEHT 2
#define WEDJAT 3
#define SCARAB 4
#define DJED 5

int H, W, T = 1, comp_count, heiro_counts[6];
char img[1 << 8][1 << 8];

char conv[16][5] = {
    {'0', '0', '0', '0', '\0'},
    {'0', '0', '0', '1', '\0'},
    {'0', '0', '1', '0', '\0'},
    {'0', '0', '1', '1', '\0'},
    {'0', '1', '0', '0', '\0'},
    {'0', '1', '0', '1', '\0'},
    {'0', '1', '1', '0', '\0'},
    {'0', '1', '1', '1', '\0'},
    {'1', '0', '0', '0', '\0'},
    {'1', '0', '0', '1', '\0'},
    {'1', '0', '1', '0', '\0'},
    {'1', '0', '1', '1', '\0'},
    {'1', '1', '0', '0', '\0'},
    {'1', '1', '0', '1', '\0'},
    {'1', '1', '1', '0', '\0'},
    {'1', '1', '1', '1', '\0'}
};

char labels[6] = {'W', 'A', 'K', 'J', 'S', 'D'};

int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1},
    order[6] = {ANKH, DJED, WEDJAT, AKEHT, SCARAB, WAS};

void bgfill(int x, int y){
    if(0 > x || x >= H || 0 > y || y >= (W << 2)) return;
    if(img[x][y] != '0') return;
    img[x][y] = 'b';
    for(int i = 0; i < 4; ++i) bgfill(x + dx[i], y + dy[i]);
}

void classify(int x, int y){
    if(x < 0 || x >= H || y < 0 || y >= (W << 2)) return;
    if(img[x][y] == 'b') return;
    if(img[x][y] == '2') return;
    if(img[x][y] == '1') img[x][y] = '2';
    if(img[x][y] == '0'){ ++comp_count; bgfill(x, y); }
    for(int i = 0; i < 4; ++i) classify(x + dx[i], y + dy[i]);
}

int main(){

    while(scanf("%d %d", &H, &W), H && W){
        char hex, *pxl_ptr, *word; int trace = -1;
        for(int h = 0; h < H; ++h){
            pxl_ptr = &img[h][0];
            for(int w = 0; w < W; ++w){
                scanf(" %c", &hex);
                switch(hex){
                    case '0': word = conv[0]; break;
                    case '1': word = conv[1]; break;
                    case '2': word = conv[2]; break;
                    case '3': word = conv[3]; break;
                    case '4': word = conv[4]; break;
                    case '5': word = conv[5]; break;
                    case '6': word = conv[6]; break;
                    case '7': word = conv[7]; break;
                    case '8': word = conv[8]; break;
                    case '9': word = conv[9]; break;
                    case 'a': word = conv[10]; break;
                    case 'b': word = conv[11]; break;
                    case 'c': word = conv[12]; break;
                    case 'd': word = conv[13]; break;
                    case 'e': word = conv[14]; break;
                    case 'f': word = conv[15]; break;
                }
                strcpy(pxl_ptr, word); pxl_ptr += 4;
            }
        }
        fill(heiro_counts, heiro_counts + 6, 0);
        do{ ++trace; } while(img[0][trace] == '1');
        for(int i = 0; i < H; ++i){
            if(img[i][0] == '0') bgfill(i, 0);
            if(img[i][(W << 2) - 1] == '0') bgfill(i, (W << 2) - 1);
        }
        for(int j = 0; j < (W << 2); ++j){
            if(img[0][j] == '0') bgfill(0, j);
            if(img[H - 1][j] == '0') bgfill(H - 1, j);
        }
        for(int i = 0; i < H; ++i)
            for(int j = 0; j < (W << 2); ++j){
                if(img[i][j] == '1'){
                    comp_count = 0; classify(i, j);
                    switch(comp_count){
                        case 0: ++heiro_counts[WAS]; break;
                        case 1: ++heiro_counts[ANKH]; break;
                        case 2: ++heiro_counts[AKEHT]; break;
                        case 3: ++heiro_counts[WEDJAT]; break;
                        case 4: ++heiro_counts[SCARAB]; break;
                        case 5: ++heiro_counts[DJED]; break;
                    }
                }
            }
        printf("Case %d: ", T++);
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < heiro_counts[order[i]]; ++j)
                printf("%c", labels[order[i]]);
        printf("\n");
    }

}
