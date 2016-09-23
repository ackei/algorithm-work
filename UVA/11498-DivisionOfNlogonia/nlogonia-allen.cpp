#include <cstdio>

char* location(int x0, int y0, int x, int y){
	if (x > x0){
		if (y > y0)
			return "NE";
		else if (y < y0)
			return "SE";
	}
	else if (x < x0) {
		if (y > y0)
			return "NO";
		else if (y < y0)
			return "SO";
	}
	return "divisa";
}

int main(){
	int TC, x0, y0, x, y;
	while (scanf("%d",&TC) && TC){
		scanf("%d %d",&x0,&y0);
		while (TC--){
			scanf("%d %d", &x, &y);
			printf("%s\n",location(x0,y0,x,y));
		}
	}
	return 0;
}
