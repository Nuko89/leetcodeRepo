int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
    int water, limit;
    int maxWater = 0;

    while (i < j){
        if (height[i] > height[j]) limit = height[j];
        else limit = height[i];
        water = limit * (j - i);
        if (water > maxWater) maxWater = water;

        if (height[i] > height[j]) j--;
        else i++;
    }
    
    return maxWater;
}