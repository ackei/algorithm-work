#include <iostream>
#include <string>
#include <vector>

using namespace std;

void eliminateComponent(vector< vector<int> > &image, int x, int y, int size){
	/*image[x][y] = 0;
	if (x > 0 && y > 0 && image[x-1][y-1])
		eliminateComponent(image,x-1,y-1,size);
	if (x > 0 && image[x-1][y])
		eliminateComponent(image,x-1,y,size);
	if (x > 0 && y < size-1 && image[x-1][y+1])
		eliminateComponent(image,x-1,y+1,size);
	if (x> 0 && y > 0 && image[x][y-1])
		eliminateComponent(image,x,y-1,size);
	if (y < size-1 && image[x][y+1])
		eliminateComponent(image,x,y+1,size);
	if (x < size-1 && y > 0 && image[x+1][y-1])
		eliminateComponent(image,x+1,y-1,size);
	if (x < size-1 && image[x+1][y])
		eliminateComponent(image,x+1,y,size);
	if (x < size-1 && y < size-1 && image[x+1][y+1])
		eliminateComponent(image,x+1,y+1,size);*/
	if (x < 0 || x > size-1 || y < 0 || y > size-1)
		return;
	if (!image[x][y])
		return;
	image[x][y] = 0;
	eliminateComponent(image,x-1,y-1,size);
	eliminateComponent(image,x-1,y,size);
	eliminateComponent(image,x-1,y+1,size);
	eliminateComponent(image,x,y-1,size);
	eliminateComponent(image,x,y+1,size);
	eliminateComponent(image,x+1,y-1,size);
	eliminateComponent(image,x+1,y,size);
	eliminateComponent(image,x+1,y+1,size);

}

int main(){
	int size;
	int imageNum = 1;
	while (cin >> size){
		vector< vector<int> > image;
		for (int i = 0; i < size; ++i)
		{
			vector<int> rowVector;
			string row;
			cin >> row;
			for (int j = 0; j < size; ++j){
				rowVector.push_back(row[j]-48); // '0' in ASCII is 48
			}
			image.push_back(rowVector);
		}
		int count = 0;
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				if (image[i][j]){
					eliminateComponent(image,i,j,size);
					count++;
				}
			}
		}
		cout << "Image number " << imageNum++ << " contains " << count << " war eagles." << endl;
	}

	return 0;
}