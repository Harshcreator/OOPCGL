#include<iostream>
#include<graphics.h>
using namespace std;

static int LEFT=1, RIGHT=2, BOTTOM=4, TOP=8, xl, yl, xh, yh;

int getcode(int x, int y){
    int code = 0;
    if(y > yh) code |= TOP;
    if(y < yl) code |= BOTTOM;
    if(x < xl) code |= LEFT;
    if(x > xh) code |= RIGHT;
    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2){
    int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2);
    int accept = 0;

    while(true){
        if((outcode1 | outcode2) == 0){ // Trivially accept
            accept = 1;
            break;
        } else if((outcode1 & outcode2) != 0){ // Trivially reject
            break;
        } else {
            int x, y;
            int temp = outcode1 ? outcode1 : outcode2;

            if(temp & TOP){
                x = x1 + (x2 - x1) * (yh - y1) / (y2 - y1);
                y = yh;
            } else if(temp & BOTTOM){
                x = x1 + (x2 - x1) * (yl - y1) / (y2 - y1);
                y = yl;
            } else if(temp & LEFT){
                y = y1 + (y2 - y1) * (xl - x1) / (x2 - x1);
                x = xl;
            } else if(temp & RIGHT){
                y = y1 + (y2 - y1) * (xh - x1) / (x2 - x1);
                x = xh;
            }

            if(temp == outcode1){
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    if(accept){
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main(){
    int gdriver = DETECT, gmode;

    cout << "Enter bottom left and top right co-ordinates of window: ";
    cin >> xl >> yl >> xh >> yh;

    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;

    initgraph(&gdriver, &gmode, NULL);
    setcolor(BLUE);
    rectangle(xl, yl, xh, yh);
    line(x1, y1, x2, y2);

    cohenSutherland(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
