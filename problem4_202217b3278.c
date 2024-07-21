#include <stdio.h>
 
// Function to move disks between rods
void moveDisk(char fromRod, char toRod, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
}
 
// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(fromRod, toRod, 1);
        return;
    }
 
    // Move top n-1 disks from fromRod to auxRod using toRod as auxiliary
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
 
    // Move remaining disk from fromRod to toRod
    moveDisk(fromRod, toRod, n);
 
    // Move the n-1 disks from auxRod to toRod using fromRod as auxiliary
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}
 
int main() {
    int n;
 
    printf("Enter the number of disks: ");
    scanf("%d", &n);
 
    // Call the towerOfHanoi function
    towerOfHanoi(n, 'A', 'C', 'B');
 
    return 0;
}