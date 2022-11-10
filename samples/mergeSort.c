/* Merges two subarrays of arr[].
 * First subarray is arr[l..m]
 * Second subarray is arr[m+1..r]
 */
procedure merge(number[] arr, number l, number m, number r) {
  number n1 = m - l + 1;
   
  number n2 = r - m;

  // create temp arrays
  number[] L[n1]; 
  number[] R[n2];

  // Copy data to temp arrays L[] and R[]
  for (number i = 0; i < n1; i++) {
      L[i] = arr[l + i];
  } endfor

  for (number j = 0; j < n2; j++) {
      R[j] = arr[m + 1 + j];
  } endfor

  // Merge the temp arrays back into arr[l..r]
  number i = 0; // Initial index of first subarray
  number j = 0; // Initial index of second subarray
  number k = l; // Initial index of merged subarray
  while (i < n1 and j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    } endif
    k++;
  } endwhile

  // Copy the remaining elements of L[], if there are any 
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  } endwhile

  // Copy the remaining elements of R[], if there are any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  } endwhile
} end

/* l is for left index and r is right index of 
 * the sub-array of arr to be sorted
 */
procedure mergeSort(number[] arr, number l, number r) {
  if (l < r) {
    // Same as (l+r)/2, but avoids overflow for large l and h
    number m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  } endif
} end


function main() : number {
  number[] arr = { 12, 11, 13, 5, 6, 7 };
  number arrSize = lenght(arr);

  mergeSort(arr, 0, arrSize - 1);

  return 0;
} end
