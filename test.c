#include<stdio.h>
#include <stdbool.h>\

typedef struct {
    int mainBranchCount;
    int unmergedBranchCount;
    int proposedBranchCount;
} CountStruct;

int main(){

int normalSequence[7][3] = {
  {1, 1, 1},
  {0, 1, 1},
  {0, 0, 1},
  {0, 0, 0},
  {0, 0, 1},
  {0, 1, 1},
  {1, 1, 1}
};

int firstLevelBrokenSequence[7][3] = {
  {0, 1, 1},
  {0, 1, 1},
  {0, 0, 1},
  {0, 0, 0},
  {0, 0, 1},
  {0, 1, 1},
  {0, 1, 1}
};

int secondLevelBrokenSequence[7][3] = {
  {1, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 0},
  {0, 0, 1},
  {0, 0, 1},
  {1, 0, 1}
};

int thirdLevelBrokenSequence[7][3] = {
  {1, 1, 0},
  {0, 1, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 1, 0},
  {1, 1, 0}
};

int firstSecondBrokenSequence[7][3] = {
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 0},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1}
};

int FirstThirdBrokenSequence[7][3] = {
  {0, 1, 0},
  {0, 1, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 1, 0},
  {0, 1, 0}
};

int SecondThirdBrokenSequence[7][3] = {
  {1, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {1, 0, 0}
};

int firstLevelNormal[]  = {1, 0, 0, 0, 0, 0, 1};
int secondLevelNormal[] = {1, 1, 0, 0, 0, 1, 1};
int thirdLevelNormal[] =  {1, 1, 1, 0, 1, 1, 1};
	/*for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d  ", *(*(sequence + i) + j));    
        }
        printf("\n");
    }*/

printf("Normal Sequence\n");
runSequence(normalSequence);
printf("\n");
printf("First Level Broken Sequence\n");
runSequence(firstLevelBrokenSequence);
printf("\n");
printf("Second Level Broken Sequence\n");
runSequence(secondLevelBrokenSequence);
printf("\n");
printf("Third Level Broken Sequence\n");
runSequence(thirdLevelBrokenSequence);
printf("\n");
printf("First and Second Level Broken Sequence\n");
runSequence(firstSecondBrokenSequence);
printf("\n");
printf("First and Third Level Broken Sequence\n");
runSequence(FirstThirdBrokenSequence);
printf("\n");
printf("Second and Third Level Broken Sequence\n");
runSequence(SecondThirdBrokenSequence);
}

int stripIsDetected(int firstLevel, int secondLevel, int thirdLevel) {
    return (firstLevel + secondLevel + thirdLevel) > 1;
}

int runSequence(int sequence[7][3]){
  int i;
  int wasStripDetected2 = 0;
  int wasStripDetected3 = 1;
  int stripdetect = 0;
  CountStruct count = {0, 0, 0};
  for (i = 0; i < 7; i++) {
    stripdetect = stripIsDetected(sequence[i][0], sequence[i][1], sequence[i][2]);

    if (stripdetect) {
      wasStripDetected2 = 1;
      count.mainBranchCount++;
    }

    else if (wasStripDetected2) {
      wasStripDetected2 = 0;
      count.unmergedBranchCount++;
    }

    if (wasStripDetected3 != stripdetect) {
      count.proposedBranchCount++;
      }

    wasStripDetected3 = stripdetect;
    }

    printf("Main branch count: %d\n", count.mainBranchCount);
    printf("Unmerged branch count: %d\n", count.unmergedBranchCount);
    printf("Proposed branch count: %d\n", count.proposedBranchCount);
    return 0;
}
