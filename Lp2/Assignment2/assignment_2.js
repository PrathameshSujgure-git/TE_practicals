const swap = (arr, x, y) => {
  let temp = arr[x];
  arr[x] = arr[y];
  //   console.log(arr);
  arr[y] = temp;
  //   console.log(arr);
};
// console.log(arr);
// swap(arr, 1, 3);
// console.log(arr);

const selectionSort = (arr, n) => {
  //   let n = arr.length;
  //   console.log(n);
  let i, j, min;

  for (i = 0; i < n; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
        swap(arr, min, i);
        // console.log(min);
      }
    }
  }
};
let arr = [3, 2, 5, 6, 7, 4];

selectionSort(arr, arr.length);
console.log(arr);
