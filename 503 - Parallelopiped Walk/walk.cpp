#include <iostream>
#include <vector>
using namespace std;


void fillBool(bool* faces, int X, int Y, int Z, int x, int y, int z) {

	for (int i = 0; i < 6; faces[i++] = false);

	if (x == X)
		faces[0] = true;
	if (y == Y)
		faces[1] = true;
	if (z == Z) 
		faces[2] = true;
	if (x == 0)
		faces[3] = true;
	if (y == 0)
		faces[4] = true;
	if (z == 0)
		faces[5] = true;

}

vector<int> findWalks(int X, int Y, int Z, int x0, int y0, int z0, int x1, int y1, int z1) {

	// 0 - x+, 1 - y+, 2 - z+, 0 - x-, 1 - y-, 2 - z-
	bool faces0[6];
	bool faces1[6];

	vector<int> pathlengths;
	
	fillBool(faces0, X, Y, Z, x0, y0, z0);
	fillBool(faces0, X, Y, Z, x1, y1, z1);
	
	int dx = x1 - x0;
	int dy = y1 - y0;
	int dz = z1 - z0;

	int dist;

	// Adjacent Faces case
	
	// x and z
	if ((faces0[0] && faces1[2]) || (faces0[0] && faces1[5]) || (faces0[3] && faces1[2]) || (faces0[3] && faces1[5])) {
		dist = (dx + dz)*(dx + dz) + dy*dy;
		pathlengths.push_back(dist);
	}
	// y and z
	if ((faces0[1] && faces1[2]) || (faces0[1] && faces1[5]) || (faces0[4] && faces1[2]) || (faces0[4] && faces1[5])) {
		dist = (dy + dz)*(dy + dz) + dx*dx;
		pathlengths.push_back(dist);
	}
	// x and y
	if ((faces0[0] && faces1[1]) || (faces0[0] && faces1[4]) || (faces0[3] && faces1[1]) || (faces0[3] && faces1[4])) {
		dist = (dx + dy)*(dx + dy) + dz*dz;
		pathlengths.push_back(dist);
	}

// Opposite Faces Case (Slightly Painful) 
	// Opposite x faces
	if (faces0[0] && faces1[3]) {
		// y+
		dist = ((Y - y0) + X + (Y - y1))*((Y - y0) + X + (Y - y1)) + dz*dz;
		pathlengths.push_back(dist);
		// z+
		dist = ((Z - z0) + X + (Z - z1))*((Z - z0) + X + (Z - z1)) + dy*dy;
		pathlengths.push_back(dist);
		// y-
		dist = (y0 + X + y1)*(y0 + X + y1) + dz*dz;
		pathlengths.push_back(dist);
		// z-
		dist = (z0 + X + z1)*(z0 + X + z1) + dy*dy;
		pathlengths.push_back(dist);
	}
	// Opposite y faces
	if (faces0[1] && faces1[4]) {
		// x+
		dist = ((X - x0) + Y + (X - x1))*((X - x0) + X + (X - x1)) + dz*dz;
		pathlengths.push_back(dist);
		// z+
		dist = ((Z - z0) + Y + (Z - z1))*((Z - z0) + X + (Z - z1)) + dx*dx;
		pathlengths.push_back(dist);
		// x-
		dist = (x0 + Y + x1)*(x0 + Y + x1) + dz*dz;
		pathlengths.push_back(dist);
		// z-
		dist = (z0 + Y + z1)*(z0 + Y + z1) + dx*dx;
		pathlengths.push_back(dist);
	}
	// Opposite z faces
	if (faces0[2] && faces1[5]) {
		// y+
		dist = ((Y - y0) + Z + (Y - y1))*((Y - y0) + Z + (Y - y1)) + dx*dx;
		pathlengths.push_back(dist);
		// x+
		dist = ((X - x0) + Z + (X - x1))*((X - x0) + X + (X - x1)) + dy*dy;
		pathlengths.push_back(dist);
		// y-
		dist = (y0 + Z + y1)*(y0 + Z + y1) + dx*dx;
		pathlengths.push_back(dist);
		// x-
		dist = (x0 + Z + x1)*(x0 + Z + x1) + dy*dy;
		pathlengths.push_back(dist);
	}

	return pathlengths;
}

int findMin(vector<int> pathlengths) {
	
	int min = pathlengths[0];
	
	for (int i = 0; i < pathlengths.size(); i++) {
		if (pathlengths[i] < min) {
			min = pathlengths[i];
		}
	}

	return min;
}

int main() {

	int X, Y, Z, x0, y0, z0, x1, y1, z1;

	vector<int> pathlengths;

	while ( (cin >> X) && (cin >> Y) && (cin >> Z) && (cin >> x0) && (cin >> y0) && (cin >> z0) && (cin >> x1) && (cin >> y1) && (cin >> z1) )
	{		
		cout << "here";
		pathlengths = findWalks(X, Y, Z, x0, y0, z0, x1, y1, z1);
		cout << findMin(pathlengths) << endl;

	}

	return 0;
}
