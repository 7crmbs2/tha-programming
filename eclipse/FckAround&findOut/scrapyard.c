/*
char viererPasch(int w1, int w2, int w3, int w4, int w5){

int rolls[] = {w1, w2, w3, w4, w5}; //we'll put our rolls in here
	for(int i = 0; i > 5; i++){ // 5 because we only write 5 values into our array (< 5 bc we start at 0 so 0-4
		for (int j = i + 1; j < 5; j++) {
		       if (rolls[i] == rolls[j] && rolls[j] == rolls[j+1] && rolls[j+1] == rolls[j + 2]) {
		         printf("Number %i has been rolled 4 times!", i);
		         return 1;
		       }
		}
	}
return 0;

	int arr[MAX_SIZE];
    int i, j, size, count = 0;

    //Input size of array
    int size = 5;

    //Input elements in array
    printf("Enter elements in array : ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            // If duplicate found then increment count by 1
            if(arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }

    printf("\nTotal number of duplicate elements found in array = %d", count);

}
*/
