int trap(int* height, int heightSize) {
  int l = 0;
  int r = heightSize - 1;
  int countWater = 0;
  int lmax = 0, rmax = 0;
  while (l < r) {
    if (height[l] < height[r]) {
      if (height[l] >= lmax) {
        lmax = height[l];
      } else {
        countWater += lmax - height[l];
      }
      l++;
    } else {
      if (height[r] >= rmax) {
        rmax = height[r];
      } else {
        countWater += rmax - height[r];
      }
      r--;
    }
  }
  return countWater;

}