/*
 * Algorithm:
 * - Reorient the parallelepiped such that at least one point is "on top"
 * - Project the two points to the unfolded plane.
 *
 *   For the reorientation:
 *      We can reorient by a combination of right and forward rotations:
 *
 *      a right rotation:
 *          L' = L
 *          W' = H
 *          H' = W
 *          (x, y, z) -> (x, z, W - y)
 *
 *      a forward rotation:
 *          L' = H
 *          W' = W
 *          H' = L
 *          (x, y, z) -> (z, y, L - x)
 *
 */

#define L 0
#define W 1
#define H 2

#define X 0
#define Y 1
#define Z 2

void rotateRight();
void rotateForward();
int findWalk();
void reorient();

int dimensions[3],
    A[3],
    B[3],
    oldCoord[3];

void rotateForward(){

    for(int i = 0; i < 3; ++i){
        oldCoord[i] = A[i];
    }

    A[X] = oldCoord[Z];
    A[Z] = dimensions[L] - oldCoord[X];

    for(int i = 0; i < 3; ++i){
        oldCoord[i] = B[i];
    }

    B[X] = oldCoord[Z];
    B[Z] = dimensions[L] - oldCoord[X];

    int Lp = dimensions[H],
        Hp = dimensions[L];

    dimensions[L] = Lp;
    dimensions[H] = Hp;

}

void rotateRight(){

    for(int i = 0; i < 3; ++i){
        oldCoord[i] = A[i];
    }

    A[Y] = oldCoord[Z];
    A[Z] = dimensions[W] - oldCoord[Y];

    for(int i = 0; i < 3; ++i){
        oldCoord[i] = B[i];
    }

    B[Y] = oldCoord[Z];
    B[Z] = dimensions[W] - oldCoord[Y];

    int Wp = dimensions[H],
        Hp = dimensions[W];

    dimensions[W] = Wp;
    dimensions[H] = Hp;

}

int findWalk(){

    if(A[Z] != dimensions[H]){
        reorient();
    }

    if(B[X] == 0){ // B is on face 1.
        // The distance is given by (B[Y] - A[Y])^2 + (B[Z] + A[X])^2
        int dy = B[Y] - A[Y],
            dx = B[Z] + A[X];
        return (dy*dy) + (dx*dx);
    } else if(B[X] == dimensions[L]){
    
    }

}

void reorient(){

    if(A[X] == 0){
        rotateForward();
    } else if(A[X] == dimensions[L]){
        rotateForward();
        rotateForward();
        rotateForward();
    } else if(A[Y] == 0){
        rotateRight();
    } else if(A[Y] == dimensions[W]){
        rotateRight();
        rotateRight();
        rotateRight();
    } else if(A[Z] == 0){
        rotateRight();
        rotateRight();
    }

}
